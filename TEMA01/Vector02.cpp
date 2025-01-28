/*
* fecha : 19/01/2025
*/

#include <iostream>
using namespace std;

int *gpVect = NULL; // Dynamic buffer to save the elements int
int gnCount = 0; // Counter to know the number of used elements int
int gnMax = 0; // Variable containing the size of the allocated

void Resize();

void Insert(int elem)
{
	if( gnCount == gnMax ) // There is no space at this moment for elem
		Resize(); // Resize the vector before inserting elem
	gpVect[gnCount++] = elem; // Insert the element at the end of the sequence
}

void Resize()
{
	const int delta = 5; // Used to increase the vector size
	int *pTemp, i;
	pTemp = new int[gnMax + delta]; // Alloc a new vector
	for(i = 0 ; i < gnMax ; i++) // Transfer the elements
		pTemp[i] = gpVect[i]; // we can also use the function memcpy
	delete [ ] gpVect; // delete the old vector
	gpVect = pTemp; // Update the pointer
	gnMax += delta; // The Max has to be increased by delta
}

void Display()
{
	cout << "Elementos en el arreglo: ";
	for (int i = 0; i < gnCount; i++)
	{
		cout << gpVect[i] << " ";
	}
	cout << endl;
	cout << "Cantidad de elementos almacenados:" << gnCount <<endl;
}

int Search(int elem)
{
   for (int i = 0; i < gnCount; i++)
   {
      if (gpVect[i] == elem)
      {
         return i;
      }
   }
   return -1;
}

void Delete(int elem)
{
   int index = Search(elem);
   if (index == -1)
   {
      cout << "Elemento no encontrado: " << elem << endl;
      return;
   }
   for (int i = index; i < gnCount - 1; i++)
   {
      gpVect[i] = gpVect[i + 1];
   }
   gnCount--;
   cout << "Se borro: " << elem << endl;
}

int main(int argc, char *argv[])
{
	Insert(10);  // Insert element 10
	Insert(20);  // Insert element 20
	Insert(30);  // Insert element 30
	Insert(40);  // Insert element 30
	Insert(50);  // Insert element 30

	Display();  // Display the elements in the array

	Insert(60);  // Insert element 30

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
