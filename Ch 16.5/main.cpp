//Christopher Alexman		  CSC 17A		Chapter 16, P. 1022, #05
//
// TOTAL TEMPLATE
//
#include <iostream>
using namespace std;

template <class T>
T Total (T size)
{
    T total;
    T input;
    int count = 0;
    
    do
    {
        cout << "Enter input " << count + 1 << ": ";
        cin >> input;
        total += input;             //increments total with the += operator
        count++;
    } while(size > count);
    
    return total;
}

int main()
{
    int size;
    
    cout << "How many ints will you enter: ";
    cin >> size;
    
    cout << "The total: " << Total(size);
}