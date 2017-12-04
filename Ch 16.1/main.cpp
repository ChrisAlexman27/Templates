//Christopher Alexman		  CSC 17A		Chapter 16, P. 1022, #01
//
// DATE EXCEPTIONS
//
#include <iostream>
using namespace std;

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

int main()
{
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
    
    return 0;
}

