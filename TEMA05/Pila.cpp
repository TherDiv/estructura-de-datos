/*
* nomPrograma: Pila
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

// Clase para la pila
class Stack {
private:
   NODE* m_pTop;

public:
   Stack() : m_pTop(nullptr) {}  // Constructor que inicializa la pila vacía

   // Método para insertar un nodo en la pila (Push)
   void Insertar(int data) {
      NODE* newNode = new NODE;
      newNode->m_data = data;
      newNode->m_pNext = m_pTop;
      m_pTop = newNode;
      cout << "Elemento " << data << " insertado en la pila." << endl;
   }

   // Método para borrar un nodo de la pila (Pop)
   void Borrar() {
      if (m_pTop == nullptr) {
         cout << "La pila está vacía, no se puede borrar." << endl;
         return;
      }
      NODE* temp = m_pTop;
      m_pTop = m_pTop->m_pNext;
      cout << "Elemento " << temp->m_data << " borrado de la pila." << endl;
      delete temp;
   }

   // Método para imprimir el contenido de la pila
   void Imprimir() const {
      if (m_pTop == nullptr) {
         cout << "La pila está vacía." << endl;
         return;
      }

      NODE* current = m_pTop;
      cout << "Contenido de la pila: ";
      while (current != nullptr) {
         cout << current->m_data << " -> ";
         current = current->m_pNext;
      }
      cout << "nullptr" << endl;
   }
};

int main() {
   Stack stack;

   // Insertar elementos en la pila
   stack.Insertar(10);
   stack.Insertar(20);
   stack.Insertar(30);

   // Imprimir la pila
   stack.Imprimir();

   // Borrar elementos de la pila
   stack.Borrar();
   stack.Imprimir();

   stack.Borrar();
   stack.Imprimir();

   stack.Borrar();
   stack.Imprimir();

   stack.Borrar();

   return 0;
}