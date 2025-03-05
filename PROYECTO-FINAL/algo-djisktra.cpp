#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef pair<int, int> Par; // {latencia, estacion}

class RedTelecom {
private:
    int N;
    vector<vector<Par>> adj;

public:
    RedTelecom(int estaciones = 0) {
        if (estaciones < 0) {
            cout << "\nError: Numero de estaciones invalido. Debe ser mayor o igual a 0.\n";
            exit(EXIT_FAILURE);
        }
        N = estaciones;
        adj.resize(N);
    }

    void agregarConexion(int a, int b, int latencia) {
        if (a < 0 || a >= N || b < 0 || b >= N) {
            cout << "\nError: Estacion fuera de rango. Debe estar entre 0 y " << N - 1 << "\n";
            return;
        }
        if (latencia <= 0) {
            cout << "\nError: La latencia debe ser mayor a 0.\n";
            return;
        }
        adj[a].push_back({b, latencia});
        adj[b].push_back({a, latencia});
    }

    vector<int> encontrarRutaOptima(int origen, int destino) {
        if (origen < 0 || origen >= N || destino < 0 || destino >= N) {
            cout << "\nError: Estacion de origen o destino fuera de rango.\n";
            return {};
        }

        for (auto conexion : adj[origen]) {
            if (conexion.first == destino) {
                return {origen, destino};
            }
        }

        vector<int> distancia(N, numeric_limits<int>::max());
        vector<int> previo(N, -1);
        distancia[origen] = 0;

        priority_queue<Par, vector<Par>, greater<Par>> pq;
        pq.push({0, origen});

        while (!pq.empty()) {
            int costo_actual = pq.top().first;
            int estacion_actual = pq.top().second;
            pq.pop();

            if (costo_actual > distancia[estacion_actual]) continue;

            if (estacion_actual == destino) {
                vector<int> ruta;
                for (int i = destino; i != -1; i = previo[i]) {
                    ruta.push_back(i);
                }
                reverse(ruta.begin(), ruta.end());
                return ruta;
            }

            for (auto vecino : adj[estacion_actual]) {
                int estacion_vecina = vecino.first;
                int latencia = vecino.second;
                int nueva_distancia = distancia[estacion_actual] + latencia;

                if (nueva_distancia < distancia[estacion_vecina]) {
                    distancia[estacion_vecina] = nueva_distancia;
                    previo[estacion_vecina] = estacion_actual;
                    pq.push({nueva_distancia, estacion_vecina});
                }
            }
        }

        return {};
    }

    int calcularLatenciaTotal(const vector<int>& ruta) {
        int latencia_total = 0;
        for (size_t i = 0; i < ruta.size() - 1; ++i) {
            for (auto conexion : adj[ruta[i]]) {
                if (conexion.first == ruta[i + 1]) {
                    latencia_total += conexion.second;
                    break;
                }
            }
        }
        return latencia_total;
    }

    void mostrarRed() {
        cout << "\nMapa de la Red de Telecomunicaciones:\n";
        cout << "Estaciones creadas: ";
        for (int i = 0; i < N; i++) {
            cout << "Estacion " << i;
            if (i < N - 1) cout << ", ";
        }
        cout << "\n";

        for (int i = 0; i < N; i++) {
            cout << "Estacion " << i;
            for (auto vecino : adj[i]) {
                cout << " -(" << vecino.second << "ms)-> Estacion " << vecino.first;
            }
            cout << "\n";
        }
    }
};

void menu() {
    cout << "\nSeleccione una opcion:\n";
    cout << "1. Crear un nuevo grafo y definir conexiones.\n";
    cout << "2. Usar un grafo de ejemplo.\n";
    cout << "Opcion: ";
}
int main() {
    int opcion;
    menu();
    cin >> opcion;

    while (cin.fail() || (opcion != 1 && opcion != 2)) {
        cout << "\nError: Opcion invalida. Ingrese 1 o 2: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> opcion;
    }

    int N = 0, E;
    RedTelecom red;

    if (opcion == 1) {
        cout << "\nIngrese el numero de estaciones de telecomunicaciones: ";
        cin >> N;

        while (cin.fail() || N <= 0) {
            cout << "\nError: Numero de estaciones invalido. Ingrese un numero valido: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> N;
        }

        red = RedTelecom(N);

        cout << "\nIngrese el numero de conexiones entre estaciones: ";
        cin >> E;

        while (cin.fail() || E < 0) {
            cout << "\nError: Numero de conexiones invalido. Ingrese un numero valido: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> E;
        }

        cout << "\nIngrese las conexiones en el formato: Estacion A Estacion B Latencia (en ms)\n";
        for (int i = 0; i < E; i++) {
            int a, b, latencia;
            cout << "Conexion " << i+1 << ": ";
            cin >> a >> b >> latencia;
            red.agregarConexion(a, b, latencia);
        }
    } else {
        N = 10;
        red = RedTelecom(N);
        red.agregarConexion(0, 1, 5);
        red.agregarConexion(0, 2, 10);
        red.agregarConexion(1, 3, 15);
        red.agregarConexion(1, 4, 20);
        red.agregarConexion(2, 5, 25);
        red.agregarConexion(2, 6, 30);
        red.agregarConexion(3, 7, 35);
        red.agregarConexion(4, 8, 40);
        red.agregarConexion(5, 9, 45);
        red.agregarConexion(6, 9, 50);
        red.agregarConexion(7, 8, 55);
        red.agregarConexion(8, 9, 60);
        red.agregarConexion(1, 2, 10);  
    }

    red.mostrarRed();

    int origen, destino;
    cout << "\nIngrese la estacion de origen: ";
    cin >> origen;
    cout << "Ingrese la estacion de destino: ";
    cin >> destino;

    vector<int> ruta = red.encontrarRutaOptima(origen, destino);

    if (ruta.empty()) {
        cout << "\nNo hay conexion disponible entre las estaciones.\n";
    } else {
        cout << "\nRuta optima:\n";
        for (size_t i = 0; i < ruta.size(); i++) {
            cout << "  Estacion " << ruta[i];
            if (i < ruta.size() - 1) cout << " -> ";
        }
        
        int latencia_total = red.calcularLatenciaTotal(ruta);
        cout << "\nLatencia total: " << latencia_total << " ms\n";
    }

    return 0;
}