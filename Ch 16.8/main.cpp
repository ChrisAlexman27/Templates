//Christopher Alexman		  CSC 17A		Chapter 16, P. 1023, #08
//
// SimpleVector MODIFICATION
//
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int arrSize;
    int input;
    
    vector<int> vect;
    
    cout << "How many values to input for the vector: ";
    cin >> arrSize;
    
    for(int count = 0; count < arrSize; count++)
    {
        cout << "Enter input " << count + 1 << ": ";
        cin >> input;
        vect.push_back(input);          //insert input into vector
    }
    
    cout << "\nHere are the things you entered in: ";
    
    for(int count = 0; count < vect.size(); count++)
    {
        cout << vect[count] << " ";
    }
    
    cout << "\n\nHere it is with the last element taken off: ";
    
    vect.pop_back();
    
    for(int count = 0; count < vect.size(); count++)
    {
        cout << vect[count] << " ";
    }
}