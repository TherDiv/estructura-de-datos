#include <iostream>
using namespace std;

template <typename T>

struct NODE
{
	T m_data; 
	NODE *m_pNext;
	NODE *m_pPrev;
};

template <typename T>

class CDoublyLinkedList
{
	private:
		NODE<T> *m_pRoot; 
		NODE<T> *m_pTail;
	public:

        // Constructor
		CDoublyLinkedList() : m_pRoot(nullptr), m_pTail(nullptr) {}

        // Destructor
        ~CDoublyLinkedList();

        // Insertar nodos
        void Insert(T data);  
        void Delete(T data); 
        void Print() const;
}; 

	// Implementacion de destructor

	template <typename T>

	CDoublyLinkedList<T>::~CDoublyLinkedList() {
		NODE<T> *current = m_pRoot;
		while (current != nullptr){
			NODE<T> *next = current ->m_pNext;
			delete current;
			current = next;
		}
	}

		// Method to insert a node at the end
		
		template <typename T>

		void CDoublyLinkedList<T>::Insert(T data) 
		{
			NODE<T>* newNode = new NODE<T>;
            
            if (!newNode){
                cout << "Error: No se pudo asignar la memoria al nuevo nodo" << endl;
                return;
            }

			newNode->m_data = data;
			newNode->m_pNext = nullptr;
			newNode->m_pPrev = nullptr;
			
			if (m_pRoot == nullptr) 
			{
				m_pRoot = newNode;
				m_pTail = newNode;
			} 
			else 
			{
				m_pTail->m_pNext = newNode;  // El siguiente nodo del último nodo será el nuevo nodo
				newNode->m_pPrev = m_pTail;  // El anterior nodo del nuevo nodo será el último nodo
				m_pTail = newNode;  // Ahora, m_pTail apunta al nuevo nodo
			}
		}

		template <typename T>

		void CDoublyLinkedList<T>::Print() const 
		{
			NODE<T>* current = m_pRoot;
			while (current != nullptr) 
			{
				cout << current->m_data << " -> ";
				current = current->m_pNext;
			}
			cout << "nullptr" << endl;
		}
		
		template <typename T>

		void CDoublyLinkedList<T>::Delete(T data) 
		{
			if (m_pRoot == nullptr){
				cout << "La lista esta vacia. No se puede eliminar" << endl;
				return;
			}

			NODE<T>* current = m_pRoot;

			while (current != nullptr && current->m_data != data){
				current = current->m_pNext;
			}

			if (current == nullptr){
				cout << "El valor " << data << " no esta en la lista" << endl;
				return;
			}

			if (current == m_pRoot){
				m_pRoot = current->m_pNext;
				if (m_pRoot != nullptr){
					m_pRoot -> m_pPrev = nullptr;
				} else {
					m_pTail = nullptr; // La lista se quedara vacia
				}
			} else if (current == m_pTail){
				m_pTail = current->m_pPrev;
				if (m_pTail != nullptr){
					m_pTail -> m_pNext = nullptr;
				}
			} else { // El elemento se encuentra en el medio
				current -> m_pPrev -> m_pNext = current -> m_pNext;
				current -> m_pNext -> m_pPrev = current -> m_pPrev;
			}

			delete current;
		}



int main(int argc, char *argv[]) 
{
	CDoublyLinkedList<int> list;
	
	// Insert some elements
	list.Insert(10);
	list.Insert(20);
	list.Insert(30);
	list.Insert(5);
	
	// Print the list
	list.Print();
	
	cout << "Deleting 20 from the list." << endl;
	
	list.Delete(20);
	list.Print();
	
	
	return 0;
}