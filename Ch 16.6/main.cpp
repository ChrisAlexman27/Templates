//Christopher Alexman		  CSC 17A		Chapter 16, P. 1022, #06
//
// IntArray CLASS EXCEPTION
//
#include <iostream>
using namespace std;

//the IntArray class and functions from chapter 14
class IntArray
{
private:
    int *aptr;                          //pointer to the array
    int arraySize;                      //holds the array size
    
public:
    class subscriptException            //different from original class
    { };                                //for throwing an exception instead
    
    IntArray(int);                      //constructor
    IntArray(const IntArray &);         //copy constructor
    ~IntArray();                        //destructor
    
    int size() const                    //returns the array size
    { return arraySize; }
    
    int &operator[] (const int &);      //overload [] operator
};

//******************************************************************************
// Constructor for IntArray class. Sets the size of the array and allocates 
// memory for it.
//******************************************************************************
IntArray::IntArray(int s)
{
    arraySize = s;
    aptr = new int[s];
    
    for(int count = 0; count < arraySize; count++)
        *(aptr + count) = 0;
}

//******************************************************************************
// Copy constructor for IntArray class
//******************************************************************************
IntArray::IntArray(const IntArray &obj)
{
    arraySize = obj.arraySize;
    aptr = new int[arraySize];
    
    for(int count = 0; count < arraySize; count++)
        *(aptr + count) = *(obj.aptr + count);
}

//******************************************************************************
// Destructor for IntArray class
//******************************************************************************
IntArray::~IntArray()
{
    if(arraySize > 0)
        delete [] aptr;
}

//******************************************************************************
// Overloaded [] operator. This argument is a subscript. This function returns
// a reference to the element in the array indexed by the subscript.
//******************************************************************************
int &IntArray::operator [](const int &sub)
{
    if(sub < 0 || sub >= arraySize)
        throw subscriptException();         //throw exception instead of calling
    return aptr[sub];
}

int main()
{
    const int SIZE = 10;                //size of array
    
    IntArray table(SIZE);               //define an IntArray with 10 elements
    
//store the values in the array
    for(int count = 0; count < SIZE; count++)
        table[count] = count;
    
//display the values in the array
    for(int count = 0; count < SIZE; count++)
        cout << table[count] << " ";
    cout << endl;
    
    try
    {
        table[SIZE + 1] = 0;
    }
    catch(IntArray::subscriptException)
    {
        cout << "ERROR. Out of bounds.";
    }
}