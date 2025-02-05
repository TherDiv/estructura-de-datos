#include <iostream>

using namespace std;

struct NODE
{
    int m_data;
    struct NODE *m_pNext;
};

class CCircularLinkedList
{
private:
    NODE *m_pRoot;

public:
    CCircularLinkedList() : m_pRoot(nullptr) {}
    // Method to insert a node at the end

    void Insert(int data)
    {
        NODE *newNode = new NODE;
        newNode->m_data = data;

        if (m_pRoot == nullptr)
        {
            m_pRoot = newNode;
            newNode->m_pNext = m_pRoot;
        }
        else
        {
            NODE *current = m_pRoot;
            while (current->m_pNext != m_pRoot)
            {
                current = current->m_pNext;
            }
            current->m_pNext = newNode;
            newNode->m_pNext = m_pRoot;
        }
    }

    void Print() const
    {
        // Modificacion: Añadir caso si esta vacio

        if (m_pRoot == nullptr)
        {
            cout << "Lista vacia" << endl;
            return;
        }

        NODE *current = m_pRoot;

        // Modificacion: Cambiar a do while

        do
        {
            cout << current->m_data << "->";
            current = current->m_pNext;
        } while (current != m_pRoot);
        cout << "(Inicio)" << endl;
    }

    void Delete(int data) // Tarea modificar el borrar
    {
        if (m_pRoot == nullptr)
        {
            cout << "No hay nodos en la lista" << endl;
            return;
        }

        NODE *current = m_pRoot, *prev = nullptr;

        // Caso especial: Unico nodo
        if (m_pRoot->m_data == data && m_pRoot->m_pNext == m_pRoot)
        {
            delete m_pRoot;
            m_pRoot = nullptr;
            return;
        }

        // Special case: deleting the root node Modificacion: anidar el while
        if (m_pRoot->m_data == data)
        {
            // Modificacion: Encontrar el ultimo nodo
            while (current->m_pNext != m_pRoot)
            {
                current = current->m_pNext;
            }

            NODE *temp = m_pRoot;
            m_pRoot = m_pRoot->m_pNext;
            current->m_pNext = m_pRoot;
            delete temp;
            return;
        }

        // Search for the node to delete (Modificacion convertir while a do while)
        prev = m_pRoot;
        current = m_pRoot->m_pNext;

        do
        {
            // If we found the node (Modificacion: Lo anidamos en el do while)

            if (current->m_data == data)
            {
                prev->m_pNext = current->m_pNext;
                delete current;
                return;
            }

            prev = current;
            current = current->m_pNext;

        } while (current != m_pRoot);

        cout << "Value " << data << " not found in the list!" << endl;
    }
};

int main(int argc, char *argv[])
{
    CCircularLinkedList list;

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