//Christopher Alexman		  CSC 17A		Chapter 16, P. 1022, #04
//
// ABSOLUTE VALUE TEMPLATE
//
#include <iostream>
#include <cmath>            //for the absolute value, abs
using namespace std;

template <class T>
T AbsoluteValue(T input)        //
{
    return abs(input);    //abs returns the absolute value of the argument given
}

int main()
{
    int input;
    int absV;
    
    cout << "Enter an int, get the absolute value of it back: ";
    cin >> input;
    
    absV = AbsoluteValue(input);
    
    cout << "\nThe absolute value of " << input << " is " << absV;
}