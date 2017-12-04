//Christopher Alexman		  CSC 17A		Chapter 16, P. 1022, #02
//
// TIME FORMAT EXCEPTIONS
//
#include <iostream>
using namespace std;

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

int main()
{
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
    
    return 0;
}