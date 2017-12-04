//Christopher Alexman		  CSC 17A		
//
// TEMPLATES ASSIGNMENT
//
#include <iostream>         //general input / output
#include <iomanip>          //for formating after the decimal
#include <vector>           //for vectors
#include <cmath>            //for the abs()
using namespace std;

void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();

int main()
{
    int input = 0;
    
    cout << "TEMPLATES ASSIGNMENT\n--------------------";
    
    do
    {
        cout << "\n\nHere are the problems to select from:\n";
        cout << "1.  Problem 16.1\n";
        cout << "2.  Problem 16.2\n";
        cout << "3.  Problem 16.3\n";
        cout << "4.  Problem 16.4\n";
        cout << "5.  Problem 16.5\n";
        cout << "6.  Problem 16.6\n";
        cout << "7.  Problem 16.7\n";
        cout << "8.  Problem 16.8\n";
        cout << "9.  Problem 16.9\n";
        cout << "10. Problem 16.14\n";
        
        cout << "\nEnter your choice(Enter 0 to exit): ";
        cin >> input;
        
        if(input > 0 && input < 11)
            cout << endl << endl << "PROBLEM #" << input << endl << endl;
        else
            cout << endl << endl << "GOODBYE" << endl << endl;
        
        switch(input)
        {
            case 1: problem1(); break;
            case 2: problem2(); break;
            case 3: problem3(); break;
            case 4: problem4(); break;
            case 5: problem5(); break;
            case 6: problem6(); break;
            case 7: problem7(); break;
            case 8: problem8(); break;
            case 9: problem9(); break;
            case 10: problem10(); break;
        }
    }while(input != 0);
}

////////////////////////////////////////////////////////////////////////////////
// PROBLEM 1
////////////////////////////////////////////////////////////////////////////////

//Date class declaration
class Date
{
    private:
        int month;
        int day;
        int year;
    public:
        class InvalidMonth
            { };                        //the exception class for the month
        class InvalidDay
            { };                        //the exception class for the day
        
        void setMnth(int);              //mutator functions
        void setDay(int);
        void setYear(int);
        
        int getMnth() const;            //accessor functions
        int getDay() const;
        int getYear() const;
        
        void print1();     //print functions
        void print2();
        void print3();
    
};

//******************************************************************************
// setMnth assigns a value to the month member                                 *
//******************************************************************************
void Date::setMnth(int m)
{
    if(m < 1 || m > 12)                 //if these values are passed
    {
        throw InvalidMonth();           //throw the exception
    }
    else
    {
        month = m;
    }
}

//******************************************************************************
// setDay assigns a value to the day member                                   *
//******************************************************************************
void Date::setDay(int d)
{
    if(d < 1 || d > 31)                 //if these values are passed
    {
        throw InvalidDay();             //throw the exception
    }
    else
    {
        day = d;
    }
}

//******************************************************************************
// setYear assigns a value to the year member                                  *
//******************************************************************************
void Date::setYear(int y)
{
    year = y;
}

//******************************************************************************
// getMnth returns the value in the month member                               *
//******************************************************************************
int Date::getMnth() const
{
    return month;
}

//******************************************************************************
// getDayu returns the value in the day  member                               *
//******************************************************************************
int Date::getDay() const
{
    return day;
}

//******************************************************************************
// getYear returns the value in the year member                                *
//******************************************************************************
int Date::getYear() const
{
    return year;
}

//******************************************************************************
// print1 prints the date in the first form.                                   *
//******************************************************************************
void Date::print1()
{
    cout << month << "/" << day << "/" << year << endl;
}

//******************************************************************************
// print2 prints the date in the second form.                                  *
//******************************************************************************
void Date::print2()
{
    string monName;
    
//determine which month was inputted, assign to proper name
    if(month == 1)
        monName = "January";
    else if (month == 2)
        monName = "February";
    else if (month == 3)
        monName = "March";
    else if (month == 4)
        monName = "April";
    else if (month == 5)
        monName = "May";
    else if (month == 6)
        monName = "June";
    else if (month == 7)
        monName = "July";
    else if (month == 8)
        monName = "August";
    else if (month == 9)
        monName = "September";
    else if (month == 10)
        monName = "October";
    else if (month == 11)
        monName = "November";
    else
        monName = "December";
    
    cout << monName << " " << day << ", " << year << endl;
}

//******************************************************************************
// print3 prints the date in the third form.                                   *
//******************************************************************************
void Date::print3()
{
    string monName;
    
//determine which month was inputted, assign to proper name
    if(month == 1)
        monName = "January";
    else if (month == 2)
        monName = "February";
    else if (month == 3)
        monName = "March";
    else if (month == 4)
        monName = "April";
    else if (month == 5)
        monName = "May";
    else if (month == 6)
        monName = "June";
    else if (month == 7)
        monName = "July";
    else if (month == 8)
        monName = "August";
    else if (month == 9)
        monName = "September";
    else if (month == 10)
        monName = "October";
    else if (month == 11)
        monName = "November";
    else
        monName = "December";
    
    cout << day << " " << monName << " " << year;
}

void problem1()
{
//Christopher Alexman		  CSC 17A		Chapter 16, P. 1022, #01
//
// DATE EXCEPTIONS
//
    
//define an instance of the Date class
    Date info;
    
//create local variables for month, day, and year
    int monthh;
    int dayy;
    int yearr;
    
//get the month, day, and year from the user; use input validation
    cout << "Enter the month: ";
    cin >> monthh;
    
    cout << "Enter the day: ";
    cin >> dayy;
    
    cout << "Enter the year: ";
    cin >> yearr;
    
    cout << endl;
   
    try                                     //store values, catch any exceptions
    {
//store the 3 values in the info object
        info.setMnth(monthh);
        info.setDay(dayy);
        info.setYear(yearr);
    
//output the dates in the 3 different ways
        info.print1();
        info.print2();
        info.print3();
    }
    
    catch(Date::InvalidMonth)                       //output if throw activated
    {
        cout << "ERROR. Month range is 1-12.\n";
    }
        
    catch(Date::InvalidDay)                         //output if throw activated
    {
        cout << "ERROR. Day range is 1-31,\n";
    }
}

////////////////////////////////////////////////////////////////////////////////
// PROBLEM 2
////////////////////////////////////////////////////////////////////////////////

class Time                  //the Time class
{
    protected:              //protect, but can be accessed by derived classes
        int hour;
        int minute;
        int second;
    
    public:
        Time()              //constructor, initialize to 0
        {
            hour = 0;
            minute = 0;
            second = 0;
        }
        Time(int h, int m, int s)       //set all the values
        {
            hour = h;
            minute = m;
            second = s;
        }
    
        int gethour() const     //accessor functions, return values from members
            { return hour; }
    
        int getMin() const
            { return minute; }
    
        int getSec() const
            { return second; }
};

class MilTime:public Time             //MilTime class derived from Time class
{
    private:
        int milHrs;                     //military hours and seconds
        int milSec;
    
    public:
        MilTime(int hours, int scnds)             //constructor, set values
        {
            milHrs = hours;
            milSec = scnds;
        }
        
        class BadHour                       //exception class for the hours
            { };
        class BadSeconds                    //exception class for the seconds
            { };
    
        void setTime(int mH, int mS);      //mutator function
    
        int getHour();                     //accessor functions
        int getHr();
    
}; 

void MilTime::setTime(int mH, int mS)
{
    if(mH > 2359 || mH < 0)
    {
        throw BadHour();                //throw if out of range
    }
    else
    {
        milHrs = mH;                    //otherwise assign value
    }
    
    if(mS > 59 || mS < 0)
    {
        throw BadSeconds();             //throw if out of range
    }
    else
    {
        milSec = mS;                    //otherwise assign value
        
        hour = (milHrs / 100);          //convert values
        minute = (milHrs % 100);
        second = milSec;
    }
}

int MilTime::getHour()
{
    return milHrs;
}

int MilTime::getHr()
{
    return hour % 12;                   //divide by 12 to get standard hour
}

void problem2()
{
//Christopher Alexman		  CSC 17A		Chapter 16, P. 1022, #02
//
// TIME FORMAT EXCEPTIONS
//
    
    int hr;             //the hour variable
    int sec;            //the seconds variable
    
    MilTime time1(0, 0);                //initialize to 0
    
    cout << "Enter military time: ";        //get user input
    cin >> hr;
    
    cout << "Enter the seconds: ";
    cin >> sec;
    
    try
    {
        time1.setTime(hr, sec);

        cout << "Military time: " << time1.getHour() << " hours ";
        cout << time1.getSec() << " sec" << endl;

        if(time1.gethour()/12 == 1)    
        {
            cout << "Civilian time: " << time1.getHr() << ":";

            if(time1.getMin() == 0)     //if no minutes
            {
                cout << time1.getMin() << "0:";
                cout << time1.getSec() << " PM" << endl;
            }
            else
            {
                cout << time1.getMin() << ": ";
                cout << time1.getSec() << " PM" << endl;
            }
        }

        else
        {
            cout << "Civilian time: " << time1.getMin() << ":";

            if(time1.getMin() == 0)         //if no minutes
            {
                cout << time1.getMin() << "0" << " AM" << endl;
            }
            else
            {
                cout << time1.getMin() << ": ";
                cout << time1.getSec() << " AM" << endl;
            }
        }
    }
    
    catch(MilTime::BadHour)        //catch the bad hour, output error message
    {
        cout << "\nERROR. Hours input from 0 to 2359";
    }
    catch(MilTime::BadSeconds)     //catch the bad seconds, output error message
    {
        cout << "\nERROR. Seconds input from 0 to 59";
    }
}

////////////////////////////////////////////////////////////////////////////////
// PROBLEM 3
////////////////////////////////////////////////////////////////////////////////

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

void problem3()
{
//Christopher Alexman		  CSC 17A		Chapter 16, P. 1022, #03
//
// MINIMUM / MAXIMUM TEMPLATES
//
    
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

////////////////////////////////////////////////////////////////////////////////
// PROBLEM 4
////////////////////////////////////////////////////////////////////////////////

template <class T>
T AbsoluteValue(T input)        //
{
    return abs(input);    //abs returns the absolute value of the argument given
}

void problem4()
{
//Christopher Alexman		  CSC 17A		Chapter 16, P. 1022, #04
//
// ABSOLUTE VALUE TEMPLATE
//
    
    int input;
    int absV;
    
    cout << "Enter an int, get the absolute value of it back: ";
    cin >> input;
    
    absV = AbsoluteValue(input);
    
    cout << "\nThe absolute value of " << input << " is " << absV;
}

////////////////////////////////////////////////////////////////////////////////
// PROBLEM 5
////////////////////////////////////////////////////////////////////////////////

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

void problem5()
{
//Christopher Alexman		  CSC 17A		Chapter 16, P. 1022, #05
//
// TOTAL TEMPLATE
//
    
    int size;
    
    cout << "How many ints will you enter: ";
    cin >> size;
    
    cout << "The total: " << Total(size);
}

////////////////////////////////////////////////////////////////////////////////
// PROBLEM 6
////////////////////////////////////////////////////////////////////////////////

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

void problem6()
{
//Christopher Alexman		  CSC 17A		Chapter 16, P. 1022, #06
//
// IntArray CLASS EXCEPTION
//
    
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

////////////////////////////////////////////////////////////////////////////////
// PROBLEM 7
////////////////////////////////////////////////////////////////////////////////

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

void problem7()
{
//Christopher Alexman		  CSC 17A		Chapter 16, P. 1022, #07
//
// TestScores CLASS
//
    
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

////////////////////////////////////////////////////////////////////////////////
// PROBLEM 8
////////////////////////////////////////////////////////////////////////////////

void problem8()
{
//Christopher Alexman		  CSC 17A		Chapter 16, P. 1023, #08
//
// SimpleVector MODIFICATION
//
    
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

////////////////////////////////////////////////////////////////////////////////
// PROBLEM 9
////////////////////////////////////////////////////////////////////////////////

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

void problem9()
{
//Christopher Alexman		  CSC 17A		Chapter 16, P. 1023, #09
//
// SearchableVector MODIFICATION
//
    
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

////////////////////////////////////////////////////////////////////////////////
// PROBLEM 10
////////////////////////////////////////////////////////////////////////////////

void sortS(vector<int> score, int size);
float average(vector<int> score, int size);

void problem10()
{
//Christopher Alexman		  CSC 17A		Chapter 16, P. 1023, #14
//
// TEST SCORE VECTOR
//
    
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

