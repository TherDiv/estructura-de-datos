#include <iostream>
using namespace std;

// Definición de la clase CVector
class CVector {
private:
	int* m_pVect; // Puntero al arreglo
	int m_nCount; // Número de elementos en uso
	int m_nMax;   // Capacidad máxima del arreglo
	int m_nDelta; // Incremento para redimensionar
	
	// Función para inicializar las variables
	void Init(int delta) {
		m_nCount = 0;
		m_nMax = delta;
		m_nDelta = delta;
		m_pVect = new int[m_nMax]; // Crear el arreglo dinámico
	}
	
	// Función para redimensionar el arreglo si se sobrepasa la capacidad
	void Resize() {
		m_nMax += m_nDelta; // Aumentar el tamaño máximo
		int* temp = new int[m_nMax]; // Crear un nuevo arreglo más grande
		for (int i = 0; i < m_nCount; i++) {
			temp[i] = m_pVect[i]; // Copiar los elementos al nuevo arreglo
		}
		delete[] m_pVect; // Liberar la memoria del arreglo anterior
		m_pVect = temp; // Apuntar al nuevo arreglo
	}
	
public:
		// Constructor
		CVector(int delta = 10) {
			Init(delta);
		}
		
		// Método para insertar un elemento al final del vector
		void Insert(int elem) {
			if (m_nCount == m_nMax) { // Verificar si se ha alcanzado la capacidad máxima
				Resize(); // Redimensionar el vector
			}
			m_pVect[m_nCount++] = elem; // Insertar el elemento y aumentar el contador
		}
		
		// Método para mostrar los elementos del vector
		void Display() {
			for (int i = 0; i < m_nCount; i++) {
				cout << m_pVect[i] << " ";
			}
			cout << endl;
		}
		
		// Función de búsqueda binaria recursiva
		int BinarySearchRecursive(int left, int right, int target) 
		{
			if (left <= right) 
			{
				int mid = left + (right - left) / 2;
				
				// Si el elemento se encuentra en el medio
				if (m_pVect[mid] == target) 
				{
					return mid; // Elemento encontrado
				}
				
				// Si el elemento es menor que el del medio, buscar en la mitad izquierda
				if (m_pVect[mid] > target) 
				{
					return BinarySearchRecursive(left, mid - 1, target);
				}
				
				// Si el elemento es mayor que el del medio, buscar en la mitad derecha
				return BinarySearchRecursive(mid + 1, right, target);
			}
			
			return -1; // Elemento no encontrado
		}
		
		// Función de búsqueda binaria iterativa
		int BinarySearchIterative(int target){
            int left = 0;
            int right = m_nCount -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (m_pVect[mid] == target){
                    return mid;
                }
                if (m_pVect[mid] > target){
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return -1;
        }
		
		// Getter para obtener la cantidad de elementos en el vector
		int GetCount() const 
		{
			return m_nCount;
		}
		
		// Destructor para liberar la memoria
		~CVector() {
			delete[] m_pVect;
		}
};

// Función principal
int main() {
	CVector gVect; // Crear un objeto CVector
	
	// Insertar algunos elementos en el vector
	gVect.Insert(5);
	gVect.Insert(10);
	gVect.Insert(15);
	gVect.Insert(20);
	gVect.Insert(30);
	gVect.Insert(50);
	
	cout << "Elementos en el vector: ";
	gVect.Display(); // Mostrar los elementos antes de la búsqueda
	
	// Buscar un elemento (ejemplo: 20)
	int target = 20;
	int result = gVect.BinarySearchRecursive(0, gVect.GetCount() - 1, target);
	
	// Verificar si el elemento fue encontrado
	if (result != -1) 
	{
		cout << "Elemento " << target << " encontrado en la posición (recursivo): " << result << endl;
	} 
	else 
	{
		cout << "Elemento " << target << " no encontrado." << endl;
	}

	// Busqueda Binaria Iterativa
    // Buscar un elemento (ejemplo: 50)
	target = 20;
	result = gVect.BinarySearchIterative(target);
	
	// Verificar si el elemento fue encontrado
	if (result != -1) 
	{
		cout << "Elemento " << target << " encontrado en la posición (iterativo): " << result << endl;
	} 
	else 
	{
		cout << "Elemento " << target << " no encontrado." << endl;
	}

	return 0;
}