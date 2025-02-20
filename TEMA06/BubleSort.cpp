#include <iostream>
using namespace std;

// Definición de la clase CVector
class CVector 
{
private:
	int* m_pVect; // Puntero al arreglo
	int m_nCount; // Número de elementos en uso
	int m_nMax;   // Capacidad máxima del arreglo
	int m_nDelta; // Incremento para redimensionar
	
	// Función para inicializar las variables
	void Init(int delta) 
	{
		m_nCount = 0;
		m_nMax   = delta;
		m_nDelta = delta;
		m_pVect  = new int[m_nMax]; // Crear el arreglo dinámico
	}
	
	// Función para redimensionar el arreglo si se sobrepasa la capacidad
	void Resize() 
	{
		m_nMax += m_nDelta; // Aumentar el tamaño máximo
		int* temp = new int[m_nMax]; // Crear un nuevo arreglo más grande
		for (int i = 0; i < m_nCount; i++) 
		{
			temp[i] = m_pVect[i]; // Copiar los elementos al nuevo arreglo
		}
		delete[] m_pVect; // Liberar la memoria del arreglo anterior
		m_pVect = temp; // Apuntar al nuevo arreglo
	}
	
public:
		// Constructor
		CVector(int delta = 10) 
		{
			Init(delta);
		}
		
		// Método para insertar un elemento al final del vector
		void Insert(int elem) 
		{
			if (m_nCount == m_nMax) 
			{ // Verificar si se ha alcanzado la capacidad máxima
				Resize(); // Redimensionar el vector
			}
			m_pVect[m_nCount++] = elem; // Insertar el elemento y aumentar el contador
		}
		
		// Método para mostrar los elementos del vector
		void Display() 
		{
			for (int i = 0; i < m_nCount; i++) 
			{
				cout << m_pVect[i] << " ";
			}
			cout << endl;
		}
		
		// Método para ordenar el vector usando el algoritmo Bubble Sort
		void BubbleSort() 
		{
			bool swapped;
			for (int i = 0; i < m_nCount - 1; i++) 
			{
				swapped = false;
				for (int j = 0; j < m_nCount - i - 1; j++) 
				{
					if (m_pVect[j] > m_pVect[j + 1]) 
					{
						// Intercambiar los elementos
						int temp = m_pVect[j];
						m_pVect[j] = m_pVect[j + 1];
						m_pVect[j + 1] = temp;
						swapped = true;
					}
				}
				// Si no se hicieron intercambios, el arreglo ya está ordenado
				if (!swapped) break;
			}
		}
		
		// Método para ordenar el vector usando el algoritmo Selection Sort

        void SelectionSort(){
            for(int i = 0; i < m_nCount -1; i++){
                int minIndex = i;
                for (int j = i + 1; j < m_nCount; j++){
                    if(m_pVect[j] < m_pVect[minIndex]){
                        minIndex = j;
                    }
                    if (minIndex != i){
                        int temp = m_pVect[i];
                        m_pVect[i] = m_pVect[minIndex];
                        m_pVect[minIndex] = temp;
                    }
                }
            }
        }

        int Partition(int low, int high){
            int pivot = m_pVect[high];
            int i = low-1;
            for (int j = low; j < high; j++){
                if (m_pVect[j] < pivot){
                    i++;
                    int temp = m_pVect[i];
                    m_pVect[i] = m_pVect[j];
                    m_pVect[j] = temp;
                }
            }
            int temp = m_pVect[i + 1];
            m_pVect[i + 1] = m_pVect[high];
            m_pVect[high] = temp;
            return i + 1;
        }

        void QuickSort(int low, int high) {
            if (low < high){
                int pi = Partition(low, high);
                QuickSort(low, pi -1);
                QuickSort(pi + 1, high);
            }
        }
        
        int GetCount() const{
            return m_nCount;
        }

		// Destructor para liberar la memoria
		~CVector() 
		{
			delete[] m_pVect;
		}
};

// Función principal
int main() 
{
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
	
	// Ordenar el vector usando Bubble Sort
	gVect.BubbleSort();
	
	cout << "Después de ordenar (BubleSort): ";
	gVect.Display(); // Mostrar los elementos después de ordenar
	
	CVector gVect2;

	// Insertar algunos elementos en el vector
	gVect2.Insert(10);
	gVect2.Insert(20);
	gVect2.Insert(30);
	gVect2.Insert(5);
	gVect2.Insert(50);
	gVect2.Insert(15);
	
	cout << "Antes de ordenar: ";
	gVect2.Display(); // Mostrar los elementos antes de ordenar
	
	// Ordenar el vector usando Bubble Sort
	gVect2.SelectionSort();
	
	cout << "Después de ordenar (SelectionSort): ";
	gVect2.Display(); // Mostrar los elementos después de ordenar
	
    CVector gVect3;

    // Insertar algunos elementos en el vector
	gVect3.Insert(10);
	gVect3.Insert(20);
	gVect3.Insert(30);
	gVect3.Insert(5);
	gVect3.Insert(50);
	gVect3.Insert(15);
	
	cout << "Antes de ordenar: ";
	gVect3.Display(); // Mostrar los elementos antes de ordenar
	
	// Ordenar el vector usando Bubble Sort
	gVect3.SelectionSort();
	
	cout << "Después de ordenar (SelectionSort): ";
	gVect3.Display(); // Mostrar los elementos después de ordenar
	
	return 0;
}