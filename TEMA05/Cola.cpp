/*
* nomPrograma: Cola
* descripcion:
*
*
*
* author: CASTRO CONTRERAS, Luis Alejandro
* fecha : 05/02/2025
*/
#include <iostream>
using namespace std;

// Estructura del nodo
struct NODE {
    int m_data;
    NODE* m_pNext;
};

// Clase para la cola
class Queue {
private:
    NODE* m_pFront;
    NODE* m_pRear;

public:
    Queue() : m_pFront(nullptr), m_pRear(nullptr) {}  // Constructor que inicializa la cola vacía

    // Método para insertar un nodo en la cola (Enqueue)
    void Insertar(int data) {
        NODE* newNode = new NODE;
        newNode->m_data = data;
        newNode->m_pNext = nullptr;

        if (m_pRear == nullptr) {
            m_pFront = newNode;
            m_pRear = newNode;
        } else {
            m_pRear->m_pNext = newNode;
            m_pRear = newNode;
        }
        cout << "Elemento " << data << " insertado en la cola." << endl;
    }

    // Método para borrar un nodo de la cola (Dequeue)
    void Borrar() {
        if (m_pFront == nullptr) {
            cout << "La cola está vacía, no se puede borrar." << endl;
            return;
        }
        NODE* temp = m_pFront;
        m_pFront = m_pFront->m_pNext;

        if (m_pFront == nullptr) {
            m_pRear = nullptr;
        }

        cout << "Elemento " << temp->m_data << " borrado de la cola." << endl;
        delete temp;
    }

    // Método para imprimir el contenido de la cola
    void Imprimir() const {
        if (m_pFront == nullptr) {
            cout << "La cola está vacía." << endl;
            return;
        }

        NODE* current = m_pFront;
        cout << "Contenido de la cola: ";
        while (current != nullptr) {
            cout << current->m_data << " -> ";
            current = current->m_pNext;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    Queue queue;

    // Insertar elementos en la cola
    queue.Insertar(10);
    queue.Insertar(20);
    queue.Insertar(30);

    // Imprimir la cola
    queue.Imprimir();

    // Borrar elementos de la cola
    queue.Borrar();
    queue.Imprimir();

    queue.Borrar();
    queue.Imprimir();

    queue.Borrar();
    queue.Imprimir();

    queue.Borrar();

    return 0;
}