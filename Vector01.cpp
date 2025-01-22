/*
* fecha : 19/01/2025
*/

#include <iostream>
using namespace std;

int gVect[100]; // Buffer to save the elements
int gnCount=0; // Counter to know the number of elements used

void Insert(int elem)
{
	if( gnCount < 100 ) // we can only insert if there is space
		gVect[gnCount++] = elem; // Insert the element at the end
}

void Display()
{
	cout << "Elementos en el arreglo: ";
	for (int i = 0; i < gnCount; i++)
	{
		cout << gVect[i] << " ";
	}
	cout << endl;
	cout << "Cantidad de elementos almacenados:" << gnCount <<endl;
}

int Search(int elem)
{
   for (int i = 0; i < gnCount; i++)
   {
      if (gVect[i] == elem)
      {
         return i;
      }
   }
   return -1;
}

void Delete(int elem)
{
   int n = Search(elem);
   if (n == -1)
   {
      cout << "Elemento no encontrado: " << elem << endl;
      return;
   }
   for (int i = n; i < gnCount - 1; i++)
   {
      gVect[i] = gVect[i + 1];
   }
   gnCount--;
   cout << "Se borro: " << elem << endl;
}

int main(int argc, char *argv[])
{
	Insert(10);  // Insert element 10
	Insert(20);  // Insert element 20
	Insert(30);  // Insert element 30

	Display();  // Display the elements in the array

	Delete(20);

	Display();

	return 0;
}

/****************
Tarea 1 es borrar

	gVect : 10, 20, 30

    Delete(20)
	Se supone que primero deben buscar el elemento Search()

	gVect : 10, 30

*****************/
