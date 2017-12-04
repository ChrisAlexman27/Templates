//Christopher Alexman		  CSC 17A		Chapter 16, P. 1023, #09
//
// SearchableVector MODIFICATION
//
#include <iostream>
using namespace std;

template <class T>
class SimpleVector
{
private:
    T *aptr;
    int arraySize;              //number of elements in the array
    void memError();            //handles memory allocation errors
    void subError();		//handles subscripts out of range
 
public:
    SimpleVector()                          //default constructor
        { aptr = 0; arraySize = 0; }
    
    SimpleVector(int);                      //constructor
    
    SimpleVector(const SimpleVector &);     //copy constructor
        
    ~SimpleVector();                        //destructor
    
    int size() const                        //accessor to return the array size
        { return arraySize; }
    
    T getElementAt(int position);           //accessor to return a specific element
        
    T &operator[](const int &);             //overloaded [] operator
    
};  

//******************************************************************************
// Constructor for SimpleVector class. Sets the size of the array and allocates
// memory for it.
//******************************************************************************
template <class T>
SimpleVector<T>::SimpleVector(int s)
{
    arraySize = s;
    
    try
    {
        aptr = new T [s];
    }
    catch (bad_alloc)
    {
        memError();
    }
    
    for(int count = 0; count < arraySize; count++)
        *(aptr + count) = 0;
}

//******************************************************************************
// Copy constructor for SimpleVector class
//******************************************************************************
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
//copy the array size
    arraySize = obj.arraySize;
    
//allocate memory for the array
    aptr = new T[arraySize];
    if(aptr == 0)
        memError();
    
//copy the elements of obj's array
    for(int count = 0; count < arraySize; count++)
        *(aptr + count) = *(obj.aptr + count);
}

//******************************************************************************
// Destructor for SimpleVector class
//******************************************************************************
template <class T>
SimpleVector<T>::~SimpleVector()
{
    if(arraySize > 0)
        delete [] aptr;
}

//******************************************************************************
// memError function. Displays an error message and terminates the program when
// memory allocation fails
//******************************************************************************
template <class T>
void SimpleVector<T>::memError()
{
    cout << "ERROR. Cannot allocate memory.\n";
    exit(EXIT_FAILURE);
}

//******************************************************************************
// subError function. Displays an error message and terminates the program when
// memory allocation fails
//******************************************************************************
template <class T>
void SimpleVector<T>::subError()
{
    cout << "ERROR. Subscript out of range.\n";
    exit(EXIT_FAILURE);
}

//******************************************************************************
// getElementAt function. The argument is a subscript. This function returns
// the value stored at the subscript in the array
//******************************************************************************
template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
    if(sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}

//******************************************************************************
// overloaded [] operator. The argument is a subscript. This function returns
// a reference to the element in the array indexed by the subscript
//******************************************************************************
template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
    if(sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}

////////////////////////////////////////////////////////////////////////////////
//start of the SearchableVariable vector

template <class T>
class SearchableVector : public SimpleVector<T>
{
public:
    SearchableVector() : SimpleVector<T>()              //default constructor
    { };
    
    SearchableVector(int size) : SimpleVector<T>(size)  //constructor
    { };
    
    SearchableVector(const SearchableVector &);         //copy constructor
        
    int findItem(const T);                          //accessor to find \ an item
};

//******************************************************************************
// Copy constructor
//******************************************************************************
template <class T>
SearchableVector<T>::SearchableVector(const SearchableVector &obj) :
                     SimpleVector<T>(obj.size())
{
    for(int count = 0; cout < this->size(); count++)
        this->operator [](count) = obj[count];
}

//******************************************************************************
// findItem function
// This function searches for item. If item is found the subscript is returned.
// Otherwise -1 is returned.
//******************************************************************************
template <class T>
int SearchableVector<T>::findItem(const T item)
{
    int first = 0;
    int middle;
    int last = this->size()-1;
    int position = -1;
    bool found = false;
    
    while(!found && first <= last)
    {
        middle = (first + last) / 2;
        if (this->getElementAt(middle) == item)
        {
            position = middle;
            found = true;
        }
        else if (this->getElementAt(middle) > item)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }
    return position;
}

int main()
{
    const int SIZE = 10;
    int count;
    int result;
    
    SearchableVector<int> intTable(SIZE);
    SearchableVector<float> floatTable(SIZE);
    
    for(count = 0; count < SIZE; count++)
    {
        intTable[count] = (count * 2);
        floatTable[count] = (count * 2.14);
    }
    
    cout << "These values are in intTable:\n";
    for(count = 0; count < SIZE; count++)
        cout << intTable[count] << " ";
    cout << endl << endl;
    
    cout << "These values are in floatTable:\n";
    for(count = 0; count < SIZE; count++)
        cout << floatTable[count] << " ";
    cout << endl << endl;
    
    cout << "Searching for the value 6 in the intTable:\n";
    result = intTable.findItem(6);
    if(result == -1)
        cout << "6 was not found in intTable" << endl << endl;
    else
        cout << "6 was found at subscript " << result << endl << endl;
    
    cout << "Searching for the value 12.84 in the floatTable:\n";
    result = floatTable.findItem(12.84);
    if(result == -1)
        cout << "12.84 was not found in intTable" << endl << endl;
    else
        cout << "12.84 was found at subscript " << result << endl << endl;
}