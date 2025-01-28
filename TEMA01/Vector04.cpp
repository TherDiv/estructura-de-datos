/*
* fecha : 22/01/2025
*/

#include <iostream>
using namespace std;

//ClassCVectordefinition
class CVector
{
private:
	int*m_pVect, //Pointertothebuffer
		m_nCount, //Controlhowmanyelementsareactuallyused
		m_nMax, //Control howmanyareallocatedasmaximum
		m_nDelta; //Tocontrolthegrowing
	void Init(int delta);// Initourprivatevariables,etc
	void Resize(); // Resizethevectorwhenoccursanoverflow
public:
	CVector(int delta=10); //Constructor
    ~CVector();
	void Insert(int elem); //Insertanewelement
	//Moremethodsgohere
    void Display();  
};

void CVector::Init(int delta)
{
    m_pVect = nullptr;
    m_nCount = 0;
    m_nMax = 0;
    m_nDelta = delta;
}

void CVector::Resize()
{
    int newMax = m_nMax + m_nDelta; 
    int *pTemp = new int[newMax];  

    for (int i = 0; i < m_nCount; i++)
        pTemp[i] = m_pVect[i];

    delete[] m_pVect;  
    m_pVect = pTemp;   
    m_nMax = newMax;   
}
 
// Constructor
CVector::CVector(int delta) 
{
    Init(delta); // Inicializar
}

// Destructor
CVector::~CVector() 
{
    delete[] m_pVect; // Liberar memoria 
}


void CVector::Insert(int elem)
{
	if(m_nCount==m_nMax) //Verifytheoverflow
		Resize(); //Resizethevectorbeforeinsertingelem
	m_pVect[m_nCount++] = elem;//Inserttheelementattheend
}

void CVector::Display()
{
    cout << "ELementos en el vector: ";
    for (int i = 0; i < m_nCount; i++)
        cout << m_pVect[i] << " ";
    cout << endl;
    cout << "Cantidad de elementos almacenados: " << m_nCount << endl;
}

int main() {
	
    CVector gVect(5); // Creamos un vector

    gVect.Insert(10);
    gVect.Insert(20);
    gVect.Insert(30);

    cout << "Estado del vector despues de insertar elementos: " << endl;
    gVect.Display();

	return 0;
}

/****************
Tarea 1 es insertar

gVect : 10, 20, 30


*****************/