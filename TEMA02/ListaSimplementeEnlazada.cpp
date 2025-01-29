#include <iostream>
using namespace std;

template <typename T>
struct NODE
{
   T m_data;
   NODE<T> *m_pNext;
};

template <typename T>
class CLinkedList
{
   private:
      NODE<T> *m_pRoot;
   public:
      CLinkedList() : m_pRoot(nullptr) {}

      void Insert(T data)
      {
         NODE<T>* newNode = new NODE<T>;
         newNode->m_data = data;
         newNode->m_pNext = nullptr;

         if (m_pRoot == nullptr)
         {
            m_pRoot = newNode;
         }
         else
         {
            NODE<T>* current = m_pRoot;
            while (current->m_pNext != nullptr)
            {
               current = current->m_pNext;
            }
                current->m_pNext = newNode;
         }
      }

      void InsertAtBeginning(T data)
      {
         NODE<T>* newNode = new NODE<T>;
         newNode->m_data = data;
         newNode->m_pNext = m_pRoot;
         m_pRoot = newNode;
      }

      void Print() const
      {
         NODE<T>* current = m_pRoot;
         while (current != nullptr)
         {
            cout << current->m_data << " -> ";
            current = current->m_pNext;
         }
         cout << "nullptr" << endl;
      }

      void Delete(T data)
      {
         if (m_pRoot == nullptr)
            return;

         if (m_pRoot->m_data == data)
         {
            NODE<T>* temp = m_pRoot;
            m_pRoot = m_pRoot->m_pNext;
            delete temp;
            return;
         }

         NODE<T>* current = m_pRoot;
         while (current->m_pNext != nullptr && current->m_pNext->m_data != data)
         {
            current = current->m_pNext;
         }

         if (current->m_pNext != nullptr)
         {
            NODE<T>* temp = current->m_pNext;
            current->m_pNext = current->m_pNext->m_pNext;
            delete temp;
         }
         else
         {
            cout << "Value " << data << " not found in the list!" << endl;
         }
      }
};

int main()
{
   cout << "Lista de ENTEROS:\n" << endl;

   CLinkedList<int> list;

   list.Insert(10);
   list.Insert(20);
   list.Insert(30);
   list.Insert(5);

   // Print the list
   list.Print();

   cout << "Insertando 100 al inicio." << endl;
   list.InsertAtBeginning(100);
   list.Print();

   cout << "Deleting 20 from the list." << endl;
   list.Delete(20);
   list.Print();

   cout << "\n\n";

   cout << "Lista de LETRAS (STRING):\n" << endl;

   CLinkedList<string> lists;

   lists.Insert("a");
   lists.Insert("b");
   lists.Insert("c");
   lists.Insert("d");

   // Print the list
   lists.Print();

   cout << "Insertando Hola al inicio." << endl;
   lists.InsertAtBeginning("Hola");
   lists.Print();

   cout << "Deleting c from the list." << endl;
   lists.Delete("c");
   lists.Print();

   cout << "\n\n";

   cout << "Lista de DECIMALES:\n" << endl;

   CLinkedList<double> listd;

   listd.Insert(1.1);
   listd.Insert(1.2);
   listd.Insert(1.3);
   listd.Insert(1.4);

   // Print the list
   listd.Print();

   cout << "Insertando 1.0 al inicio." << endl;
   listd.InsertAtBeginning(1.0);
   listd.Print();

   cout << "Deleting 1.3 from the list." << endl;
   listd.Delete(1.3);
   listd.Print();

   return 0;
}
