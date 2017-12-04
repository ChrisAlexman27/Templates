//Christopher Alexman		  CSC 17A		Chapter 16, P. 1022, #07
//
// TestScores CLASS
//
#include <iostream>
using namespace std;

class TestScores
{
private:
    int scores[5];              //scores entered by user
    
public:
    int SIZE = 5;
    
    TestScores();               //constructor
    
    TestScores(int []);         //constructor
    
    class Negative              //exception class for below 0
    { };
    
    class Greater               //exception class for above 100
    { };
        
    float average();            //to determine the average
};

TestScores::TestScores()
{
    for(int count = 0; count < SIZE; count++)
    {
        scores[count] = 0;                      //initialize with 0
    }
}

TestScores::TestScores(int s[])
{
    for(int count = 0; count < SIZE; count++)
    {
        scores[count] = s[count];               //store the values
    }
}

float TestScores::average()
{
    float avg;
    
    for(int count = 0; count < SIZE; count++)
    {
        if(scores[count] < 0)
            throw Negative();                   //throw if negative
        else if(scores[count] > 100)
            throw Greater();                    //throw if above 100
        else
            avg += scores[count];   //otherwise add up all scores
    }
    
    return avg / SIZE;              //divide by how many scores were entered
}

int main()
{   
    int scor[5];                    //to hold the scores entered by the user
    
    cout << "You will be entering 5 test scores.\n";
    
    for(int count = 0; count < 5; count++)              //get user input
    {
        cout << "Enter score " << count + 1 << ": ";
        cin >> scor[count];
    }
    
    try
    {
        TestScores check1(scor);
        cout << "Average is: " << check1.average() << endl;
    }
    catch(TestScores::Negative)         //catch the throw, output message
    {
        cout << "Error. No negative values.\n\n";
    }
    catch(TestScores::Greater)          //catch the throw, output message
    {
        cout << "Error. No values greater than 100.\n\n";
    }
}