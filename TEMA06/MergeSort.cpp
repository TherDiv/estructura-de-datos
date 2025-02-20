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
		
		// Método para fusionar dos subarreglos ordenados
		void Merge(int left, int mid, int right) 
		{
			int n1 = mid - left + 1;
			int n2 = right - mid;
			
			int* L = new int[n1];
			int* R = new int[n2];
			
			// Copiar los datos a los subarreglos L[] y R[]
			for (int i = 0; i < n1; i++)
				L[i] = m_pVect[left + i];
			for (int j = 0; j < n2; j++)
				R[j] = m_pVect[mid + 1 + j];
			
			// Fusionar los subarreglos
			int i = 0; // Índice inicial de L[]
			int j = 0; // Índice inicial de R[]
			int k = left; // Índice inicial de m_pVect[]
			while (i < n1 && j < n2) 
			{
				if (L[i] <= R[j]) 
				{
					m_pVect[k] = L[i];
					i++;
				} 
				else 
				{
					m_pVect[k] = R[j];
					j++;
				}
				k++;
			}
			
			// Copiar los elementos restantes de L[] si los hay
			while (i < n1) 
			{
				m_pVect[k] = L[i];
				i++;
				k++;
			}
			
			// Copiar los elementos restantes de R[] si los hay
			while (j < n2) 
			{
				m_pVect[k] = R[j];
				j++;
				k++;
			}
			
			delete[] L;
			delete[] R;
		}
		
		// Método para ordenar el vector usando Merge Sort recursivo
		void MergeSort(int left, int right)   //[2 3] [7 4 ]  [6 3 12 11] 
		{
			if (left < right) 
			{
				int mid = left + (right - left) / 2; // Encontrar el punto medio
				MergeSort(left, mid);  // Ordenar la mitad izquierda
				MergeSort(mid + 1, right); // Ordenar la mitad derecha
				Merge(left, mid, right); // Fusionar las dos mitades
			}
		}
		
        int Partition(int low, int high){
            int pivot = m_pVect[high];
            int i = low - 1;
            for (int j = low; j < high; j++){
                if(m_pVect[j] < pivot){
                    i++;
                    int temp = m_pVect[i];
                    m_pVect[i] = m_pVect[j];
                    m_pVect[j] = temp;
                }
            }
            int temp = m_pVect[i + 1];
            m_pVect[i + 1] = m_pVect[high];
            m_pVect[high] = temp;
            return i + i;
        }

		//QuickSort
        void QuickSort(int low, int high){
            if (low < high){
                int pi = Partition(low, high);
                QuickSort(low, pi - 1);
                QuickSort(pi + 1, high);
            }
        }
		
		// Getter para obtener la cantidad de elementos en el vector
		int GetCount() const {
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
	gVect.Insert(10);
	gVect.Insert(20);
	gVect.Insert(30);
	gVect.Insert(5);
	gVect.Insert(50);
	gVect.Insert(15);
	
	cout << "Antes de ordenar: ";
	gVect.Display(); // Mostrar los elementos antes de ordenar
	
	// Ordenar el vector usando Merge Sort recursivo
	gVect.MergeSort(0, gVect.GetCount() - 1);
	
	cout << "Después de ordenar (QuickSort): ";
	gVect.Display(); // Mostrar los elementos después de ordenar
	
	return 0;
}