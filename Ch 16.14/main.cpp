//Christopher Alexman		  CSC 17A		Chapter 16, P. 1023, #14
//
// TEST SCORE VECTOR
//
#include <iostream>
#include <iomanip>
#include <vector>           //for vectors
using namespace std;

void sortS(vector<int> score, int size);
float average(vector<int> score, int size);

int main()
{
    int size;                   //how many test scores the user will enter
    float avg;                  //average of the scores
    float inputSc;              //input of the score
    
    vector<int> scores;         //define a vector object
    
    cout << "Number of scores to be entered: ";
    cin >> size;
    
    for(int count = 0; count < size; count++)
    {
        cout << "Enter score " << count + 1 << ": ";
        cin >> inputSc;
        
        scores.push_back(inputSc);      //inserts the inputSc value into vector
    }
    
    sortS(scores, size);
    
    cout << "\nThe sorted test scores are: ";
    for(int count = 0; count < size; count++)
    {
        cout << scores.at(count); //return value of the element located at count
        cout << " ";
    }
    
    avg = average(scores, size);
    
    cout << setprecision(2) << fixed;           //formats to 2 decimal places
    
    cout << "\n\nThe average of all the test scores is: " << avg;
}

void sortS(vector<int> score, int size)
{ 
// I tried the sort algorithm but the #include <algorithm> didn't work
//    sort(score.begin(0), score.end());
}

float average(vector<int> score, int size)
{
    float avg;
    
    for(int count = 0; count < size; count++)
    {
        avg += score.at(count);
    }
    
    return avg / size;
}