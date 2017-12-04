//Christopher Alexman		  CSC 17A		Chapter 16, P. 1022, #03
//
// MINIMUM / MAXIMUM TEMPLATES
//
#include <iostream>
using namespace std;

template <class T>
T Max(T num1, T num2)           //accepts 2 arguments, returns larger of the 2
{
    if(num1 > num2)
        return num1;
    else
        return num2;
}

template <class T>
T Min(T num1, T num2)           //accepts 2 arguments, returns smaller of the 2
{
    if(num2 > num1)
        return num1;
    else
        return num2;
}

int main()
{
    int firstI;                                 //first input by user
    int secondI;                                //second input by user
    
    float firstF;                                 //first input by user
    float secondF;                                //second input by user
    
    char firstC;                                 //first input by user
    char secondC;                                //second input by user
    
    int greaterI;                                //to hold greater value
    int lesserI;                                 //to hold lesser value
    
    float greaterF;                                //to hold greater value
    float lesserF;                                 //to hold lesser value
    
    char greaterC;                                //to hold greater value
    char lesserC;                                 //to hold lesser value
    
    cout << "Time for integer inputs: \n";      //get user inputs
    cout << "Enter input 1: ";
    cin >> firstI;
    cout << "Enter input 2: ";
    cin >> secondI;
    
    greaterI = Max(firstI, secondI);        //send both values, return larger
    lesserI = Min(firstI, secondI);         //send both values, return smaller
    
    cout << "Greater value: " << greaterI << endl;
    cout << "Lesser value: " << lesserI << endl << endl;
    
    cout << "Time for float inputs: \n";        //get user inputs
    cout << "Enter input 1: ";
    cin >> firstF;
    cout << "Enter input 2: ";
    cin >> secondF;
    
    greaterF = Max(firstF, secondF);        //send both values, return larger
    lesserF = Min(firstF, secondF);         //send both values, return smaller
    
    cout << "Greater value: " << greaterF << endl;
    cout << "Lesser value: " << lesserF << endl << endl;
    
    cout << "Time for char inputs: \n";         //get user inputs
    cout << "Enter input 1: ";
    cin >> firstC;
    cout << "Enter input 2: ";
    cin >> secondC;
    
    greaterC = Max(firstC, secondC);        //send both values, return larger
    lesserC = Min(firstC, secondC);         //send both values, return smaller
    
    cout << "Greater value: " << greaterC << endl;
    cout << "Lesser value: " << lesserC << endl << endl;
}