#pragma once
#pragma warning (disable : 4996)

#include<iostream>
#include<string>
#include "clsString.h"
using namespace std;
class clsDate
{
private:
 
public:
    short _Day=1;
    short _Month=1;
    short _Year=1900;
 
    clsDate()
    {
        time_t t=time(0);
        tm* now = localtime(&t);
        _Year=now->tm_year+1900;
        _Month=now->tm_mon+1;
        _Day=now->tm_mday;
    };
    clsDate(string sDate)
    {
        vector  <string> vDate;
        vDate=clsString::Split(sDate,"/");
        _Day=stoi(vDate.at(0));
        _Month=stoi(vDate.at(1));
        _Year=stoi(vDate.at(2));
 
    };
    clsDate(short Day,short Month ,short Year)
    {
        _Day=Day;
        _Month=Month;
        _Year=Year;
    }
    clsDate(short DaysOrderInYear,short Year)
    {
       clsDate  Date1=GetDateFromDayOrderInYear(DaysOrderInYear,Year);
       _Day=Date1.Day();
       _Month=Date1.Month();
       _Year=Date1.Year();
    }
    void SetDay(short Day)
    {
        _Day=Day;
    }
    short Day()
    {
        return _Day;
    }

    void SetMonth(short Month)
    {
        _Month=Month;
    }
    short Month()
    {
        return _Month;
    }

    void SetYear(short Year)
    {
        _Year=Year;
    }
    short Year()
    {
        return _Year;
    }

    void Print()
    {
        cout<<DateToString()<<endl;
    }
    static  string DateToString(clsDate Date)
    {
        return to_string(Date._Day)+'/'+to_string(Date._Month)+'/'+to_string(Date._Year);
    }


    string DateToString()
    {
        return DateToString(*this);
    }
    static clsDate GetSystemDate()
    {
        //System Date
        time_t t=time(0);
        tm* now = localtime(&t);
        short Day,Month,Year;

        Year=now->tm_year+1900;
        Month=now->tm_mon+1;
        Day=now->tm_mday;
        return clsDate(Day,Month,Year);
        
    }
    static  bool IsleapYear(short Year)
    {
        // if year is divisible by 4 not by 100
        //or if year is divible by 400
        // then it is a leap year 
        return (Year%4==0&&Year%100 !=0)||(Year%400==0);
        
    }
    bool IsLeapYear()
    {
        return IsleapYear(_Year);
    }
    static short NumberOFDaysInYear(short Year)
    {
        return IsleapYear(Year)?365:364;
    }
    short NumberOFDaysInYear()
    {
        return NumberOFDaysInYear(_Year);
    }    
    
    static short NumberOFHoursInYear(short Year)
    {
        return NumberOFDaysInYear(Year)*24;
    }
    short NumberOFHoursInYear()
    {
        return NumberOFHoursInYear(_Year);
    }    
    
    static short NumberOFMinutesInYear(short Year)
    {
        return NumberOFHoursInYear(Year)*60;
    }
    short NumberOFMinutesInYear()
    {
        return NumberOFMinutesInYear(_Year);
    }
    
    static short NumberOFSecondsInYear(short Year)
    {
        return NumberOFMinutesInYear(Year)*60;
    }
    short NumberOFSecondsInYear()
    {
        return NumberOFSecondsInYear(_Year);
    }

    static short NumberOFDaysInMonth(short Year ,short Month)
    {
    if (Month<1||Month>12)
    {
        return 0;
    }
    int NumberOfDays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    
    return (Month==2)?(IsleapYear(Year)?29:28):NumberOfDays[Month-1];
    }
    short NumberOFDaysInMonth()
    {
        return NumberOFDaysInMonth(_Year,_Month);
    }

    static  int NumberOFHoursInMonth(short Year,short Month)
    {
        return NumberOFDaysInMonth(Year,Month)*24;
    }
    int NumberOFHoursInMonth()
    {
        return NumberOFHoursInMonth(_Year,_Month);
    }

    static  int NumberOFMinutesInMonth(short Year,short Month)
    {
        return NumberOFHoursInMonth(Year,Month)*60;
    }
    int NumberOFMinutesInMonth()
    {
        return NumberOFMinutesInMonth(_Year,_Month);
    }

    static int NumberOFSecondsInMonth(short Year,short Month)
    {
        return NumberOFMinutesInMonth(Year, Month)*60;
    }
    int NumberOFSecondsInMonth()
    {
        return NumberOFSecondsInMonth(_Year,_Month);
    }

    static short DayOfweekOrder(short Day,short Month,short Year)
    {
        short a,y,m;
        a=(14-Month)/12;
        y=Year-a;
        m=Month+(12*a)-2;
        //Gregorien 
        //0:sun 1:Mon 2:Tue ... etc
        return (Day+y+(y/4)-(y/100)+(y/400)+(31*m)/12)%7;
    }
    short DayOfweekOrder()
    {
        return DayOfweekOrder(_Day,_Month,_Year);
    } 
    
    static string ShortMonthName(short MonthNumber)
    {
    
    string Months[12]={"Jan","Feb","Mar",
                        "Apr","May","June",
                        "July","Aug","Sep",
                        "Oct","Nov","Dec"};
        return Months[MonthNumber-1];
    }
    string ShortMonthName()
    {
        return ShortMonthName(_Month);
    }

    static string DayShortName(short DayOfWeekOrder)
    {
        string arrDayNames[]={"Sun","Mon","Tue","Wed","Thur","Fri","Sat"};

        return arrDayNames[DayOfWeekOrder];
    }
    string DayShortName()
    {
        return DayShortName(_Month);
    }
    
    static void PrintMonthCalendar(short Month,short Year)
    {
        int NumberOfDays;
        //Index of the day from 0 to 6
        int Current=DayOfweekOrder(1,Month,Year);
        NumberOfDays=NumberOFDaysInMonth(Year,Month);

        //print the current Month names
        printf("\n------------------%s--------------------\n\n",ShortMonthName(Month).c_str());

        //print the columns 
        printf("  Sun  Mon  Tue  Wed  Thur  Fri  Sat \n");
        //print appropriate spaces
        int i;
        for ( i = 0; i < Current; i++)
            printf("     ");
        for (int  j = 1; j <= NumberOfDays; j++)
        {
        printf("%5d",j);

        if (++i==7)
        {
            i=0;
            printf("\n");
        }
        
        }

        printf("\n-----------------------------------------\n");
    }
    void PrintMonthCalendar()
    {
        PrintMonthCalendar(_Month,_Year);
    }
    
    static void PrintYearCalendar(short Year)
    {
        cout<<"-------------------------------------------\n";
        cout<<"\t\tCalendar - "<<Year<<endl;
        cout<<"-------------------------------------------\n";
        for (short i = 1; i <= 12; i++)
        {
            PrintMonthCalendar(i,Year);
            printf("\n");
        }
        
    }
    void PrintYearCalendar()
    {
        PrintYearCalendar(_Year);
    }
    
    static short DaysFromTheBeginingOfTheYear(short Day,short Year,short Month)
    {
        short TotalDays=Day;
        for (short i = 1; i < Month; i++)
        {
        TotalDays+= NumberOFDaysInMonth(Year,i);
        }

        return TotalDays;
        
    }
    short DaysFromTheBeginingOfTheYear()
    {
        short TotalDays=_Day;
        for (short i = 1; i <_Month; i++)
        {
        TotalDays+= NumberOFDaysInMonth(_Year,i);
        }

        return TotalDays;
    }
    
    static clsDate GetDateFromDayOrderInYear(short DaysOrderInYear,short Year)
    {
    clsDate Date;
    short RemainingDays=DaysOrderInYear;
    short MonthDays=0;

    Date._Year=Year;
    Date._Month=1;
    while (true)
    {
        MonthDays=NumberOFDaysInMonth(Year,Date._Month);
        if (RemainingDays>MonthDays)
        {
            RemainingDays-=MonthDays;
            Date._Month++;
            
        }
        else
        {
            Date._Day=RemainingDays;
            break;
        }   
    }
    return Date;
    }

    void  AddDays(short Days)
    {
        short RemainingDays=Days+DaysFromTheBeginingOfTheYear(_Day,_Year,_Month);
        short MonthDays=0;
        _Month=1;

        while (true)
        {
            MonthDays=NumberOFDaysInMonth( _Year ,_Month);
            if (RemainingDays>MonthDays)
            {
                RemainingDays-=MonthDays;
                _Month++;
                if (_Month>12)
                {
                    _Month=1;
                    _Year++;
                }
                cout<<"Date.Month "<<_Month<<endl;
                cout<<"Date.Year "<<_Year<<endl;
                
            }
            else
            {
                _Day=RemainingDays;
                break;
            }
            
        }
    }
   
    static bool IsDate1BeforeDate2(clsDate Date1,clsDate Date2)
    {
    
        return  (Date1._Year<Date2._Year)? true:((Date1._Year==Date2._Year)
        ?(Date1._Month<Date2._Month?true:(Date1._Month==Date2._Month?
        Date1._Day<Date2._Day:false)):false);

        
    }
    bool IsDate1BeforeDate2(clsDate Date2)
    {
        //note: *this sends the current object :-)
        return IsDate1BeforeDate2(*this,Date2);
    }
    
    static bool IsDate1EqualToDate2(clsDate Date1,clsDate Date2)
    {
    return (Date1._Year==Date2._Year)?((Date1._Month==Date2._Month)
    ?((Date1._Day==Date2._Day)?true:false):false):false;
    }
    bool IsDate1EqualToDate2(clsDate Date2)
    {
        return IsDate1EqualToDate2(*this,Date2);
    }
   
    static bool  IsLastDayInMonth(clsDate Date)
    {
    return (Date._Day==NumberOFDaysInMonth(Date._Year,Date._Month));
    }
    bool IsLastDayInMonth()
    {
        return IsLastDayInMonth(*this);
    }
    
    static bool  IsLastMonthInYear(short  Month)
    {
    return Month==12;
    }

    static clsDate  AddOneDay(clsDate Date)
    {
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date._Month))
        {
            Date._Day=1;
            Date._Month=1;
            Date._Year++;
        }
        else
        {
            Date._Day=1;
            Date._Month++;
        }
        
    }
    else
    {
        Date._Day++;
    }
    return Date;
    }
    void AddOneDay()
    {
        *this= AddOneDay(*this);
    }
    
    static void SwapDates(clsDate& Date1,clsDate& Date2)
    {
        clsDate TempDate;
        TempDate=Date1;
        Date1=Date2;
        Date2=TempDate;   
    };
    static bool IsValidDate(clsDate Date)
    {
        if (Date._Day<1||Date._Day>31)
            return false;
        if (Date._Month<1||Date._Month>12)
            return false;

        if (Date._Month==2)
        {
            if (IsleapYear(Date._Year))
            {
                if (Date._Day>29)
                return false; 
            }
            else
            {
                if (Date._Day>28)
                {
                return false;
                }
            }
        }
        short DaysMonth=NumberOFDaysInMonth(Date._Year,Date._Month);
        if (Date._Day>DaysMonth)
        {
            return false;
        }
        return true;
    }
    bool IsValid()
    {
        return IsValidDate(*this);
    }
    static int GetDiffrenceInDays(clsDate Date1,clsDate Date2,bool IncludeEndDay=false)
    {
    int Days=0;
    int SwapFalgValue=1;
    if (!IsDate1BeforeDate2(Date1,Date2))
    {
        //Swap Dates
        SwapDates(Date1,Date2);
        SwapFalgValue=-1;
    }
    while (IsDate1BeforeDate2(Date1,Date2))
    {
        Days++;
        Date1=AddOneDay(Date1);
    }

    return IncludeEndDay? ++Days*SwapFalgValue:Days*SwapFalgValue;
    }
    
    int GetDiffrenceInDays(clsDate Date2,bool IncludeEndDay=false)
    {
        return GetDiffrenceInDays(*this,Date2,IncludeEndDay);
    }
    static short CalculateMyAgeInDays(clsDate DateOFBirth)
    {
        return GetDiffrenceInDays(DateOFBirth,clsDate::GetSystemDate(),true);
    }

    //above no need to have nonstatic function for the object becouse it does not depend 
    //on any data from it 
    static clsDate  IncreaseDateByOneWeek(clsDate & Date)
    {
    
    for (short  i = 0; i < 7; i++)
    {
        Date=AddOneDay(Date);

    }
    return Date;
    }
    void IncreaseDateByOneWeek()
    {
         IncreaseDateByOneWeek(*this);
    }
    
    static clsDate IncreaseDateByXWeek(short Weeks,clsDate& Date)
    {
    for (short  i = 0; i < Weeks; i++)
    {
        Date=IncreaseDateByOneWeek(Date);

    }
    return Date;
    }
    void IncreaseDateByXWeek(short weeks)
    {
        IncreaseDateByXWeek(weeks,*this);
    }
    clsDate IncreaseDateByOneMonth(clsDate& Date)
    {
    
        if (IsLastMonthInYear(Date._Month))
        {
            Date._Month=1;
            Date._Year++;
        }
        else
        {
            Date._Month++;
        }
        //last check day in date should exceed max in the current month 
        //example if date is 31/1/2022 Increasing one month should not be 31/2/2022
        //it should be 28/2/2022
        short NumberOfDayInCurrentMonth=NumberOFDaysInMonth(Date._Year,Date._Month);
        if (Date._Day>NumberOfDayInCurrentMonth)
        {
        Date._Day=NumberOfDayInCurrentMonth;
        }
        
        return Date;
    }
    void IncreaseDateByOneMonth()
    {
        IncreaseDateByOneMonth(*this);
    }
    
    clsDate IncreaseDateByXDay(short Days,clsDate& Date)
    {
        for (short i = 0; i < Days; i++)
        {
            Date=AddOneDay(Date);
        }
        return Date;
        
    }
    void IncreaseDateByXDay(short Days)
    {
        IncreaseDateByXDay(Days,*this);
    }
   
    clsDate IncreaseDateByXMonths(short Months,clsDate& Date)
    {
    for (short  i = 0; i < Months; i++)
    {
        Date=IncreaseDateByOneMonth(Date);

    }
    return Date;
    
    }
    void IncreaseDateByXMonths(short Months)
    {
        IncreaseDateByXMonths(Months,*this);
    }

    
    clsDate IncreaseDateByOneYear(clsDate& Date)
    {
    for (short  i = 0; i < 12; i++)
    {
        Date=IncreaseDateByOneMonth(Date);

    }
    return Date;
    
    }
    void IncreaseDateByOneYear()
    {
        IncreaseDateByOneYear(*this);
    }
    
    clsDate IncreaseDateByXYear(short Years,clsDate& Date)
    {
    for (short  i = 0; i < Years; i++)
    {
        Date=IncreaseDateByOneYear(Date);

    }
    return Date;
    
    }
    void IncreaseDateByXYear(short Years)
    {
        IncreaseDateByXYear(Years,*this);
    }


 
    clsDate IncreaseDateByAddingOneDecade(clsDate& Date)
    {
    //Periode of 10 Years 
    Date._Year+=10;
    return Date;
    
    }
    void IncreaseDateByAddingOneDecade()
    {
        IncreaseDateByAddingOneDecade(*this);
    }
    
    clsDate IncreaseDateByAddingXDecades(short Decade ,clsDate& Date)
    {
    for (short  i = 0; i < Decade*10; i++)
    {
        Date=IncreaseDateByOneYear(Date);

    }
    return Date;
    
    }
    void IncreaseDateByAddingXDecades(short Decade)
    {
        IncreaseDateByAddingXDecades(Decade,*this);
    }

    clsDate IncreaseDateByAddingOneCentury(clsDate& Date)
    {
    //Periode of 100 Years
    Date._Year+=100;
    return Date;
    
    }
    void IncreaseDateByAddingOneCentury()
    {
        IncreaseDateByAddingOneCentury(*this);
    }
    

    clsDate IncreaseDateByAddingOneMillenuim(clsDate& Date)
    {

    //Periode of 1000 Years
    Date._Year+=1000;
    return Date;
    
    }
    void IncreaseDateByAddingOneMillenuim()
    {
        IncreaseDateByAddingOneMillenuim(*this);
    }
    
    static bool  IsFirstDayInMonth(clsDate Date)
    {
    return (Date._Day==1);
    }
    bool IsFirstDayInMonth()
    {
        return IsFirstDayInMonth(*this);
    }
    static bool  IsFirstMonthInYear(short  Month)
    {
    return Month==1;
    }
    bool IsFirstMonthInYear()
    {
        return IsFirstMonthInYear(_Month);
    }

 
    static clsDate  DecreaseDateByOneDay(clsDate Date)
    {
    if (IsFirstDayInMonth(Date))
    {
        if (IsFirstMonthInYear(Date._Month))
        {
            Date._Day=31;
            Date._Month=12;
            Date._Year--;
        }
        else
        {
            Date._Month--;
            Date._Day=NumberOFDaysInMonth(Date._Year ,Date._Month);
        }
        
    }
    else
    {
        Date._Day--;
    }
    
    
    return Date;

    }
     static clsDate  DecreaseDateByOneWeek(clsDate & Date)
    {
    
    for (short  i = 0; i < 7; i++)
    {
        Date=DecreaseDateByOneDay(Date);

    }
    return Date;
    }
    void DecreaseDateByOneWeek()
    {
         DecreaseDateByOneWeek(*this);
    }
    
    static clsDate DecreaseDateByXWeek(short Weeks,clsDate& Date)
    {
    for (short  i = 0; i < Weeks; i++)
    {
        Date=DecreaseDateByOneWeek(Date);

    }
    return Date;
    }
    void DecreaseDateByXWeek(short weeks)
    {
        DecreaseDateByXWeek(weeks,*this);
    }
    clsDate DecreaseDateByOneMonth(clsDate& Date)
    {
    
        if (Date._Month==1)
        {
            Date._Month=12;
            Date._Year--;
        }
        else
        {
            Date._Month--;
        }
        //last check day in date should exceed max in the current month 
        //example if date is 31/1/2022 Increasing one month should not be 31/2/2022
        //it should be 28/2/2022
        short NumberOfDayInCurrentMonth=NumberOFDaysInMonth(Date._Year,Date._Month);
        if (Date._Day>NumberOfDayInCurrentMonth)
        {
        Date._Day=NumberOfDayInCurrentMonth;
        }
        
        return Date;
    }
    void DecreaseDateByOneMonth()
    {
        DecreaseDateByOneMonth(*this);
    }
    
    clsDate DecreaseDateByXDay(short Days,clsDate& Date)
    {
        for (short i = 0; i < Days; i++)
        {
            Date=DecreaseDateByOneDay(Date);
        }
        return Date;
        
    }
    void DecreaseDateByXDay(short Days)
    {
        DecreaseDateByXDay(Days,*this);
    }
   
    clsDate DecreaseDateByXMonths(short Months,clsDate& Date)
    {
    for (short  i = 0; i < Months; i++)
    {
        Date=DecreaseDateByOneMonth(Date);

    }
    return Date;
    
    }
    void DecreaseDateByXMonths(short Months)
    {
        DecreaseDateByXMonths(Months,*this);
    }

    static clsDate DecreaseDateByOneYear(clsDate & Date)
    {
        Date._Year--;
        return Date;
    }
    

    void DecreaseDateByOneYear()
    {
        DecreaseDateByOneYear(*this);
    }
    
    clsDate DecreaseDateByXYear(short Years,clsDate& Date)
    {
    for (short  i = 0; i < Years; i++)
    {
        Date=DecreaseDateByOneYear(Date);

    }
    return Date;
    
    }
    void DecreaseDateByXYear(short Years)
    {
        DecreaseDateByXYear(Years,*this);
    }


 
    clsDate DecreaseDateByAddingOneDecade(clsDate& Date)
    {
    //Periode of 10 Years 
    Date._Year-=10;
    return Date;
    
    }
    void DecreaseDateByAddingOneDecade()
    {
        DecreaseDateByAddingOneDecade(*this);
    }
    
    clsDate DecreaseDateByAddingXDecades(short Decade ,clsDate& Date)
    {
    for (short  i = 0; i < Decade*10; i++)
    {
        Date=DecreaseDateByOneYear(Date);

    }
    return Date;
    
    }
    void DecreaseDateByAddingXDecades(short Decade)
    {
        DecreaseDateByAddingXDecades(Decade,*this);
    }

    clsDate DecreaseDateByAddingOneCentury(clsDate& Date)
    {
    //Periode of 100 Years
    Date._Year-=100;
    return Date;
    
    }
    void DecreaseDateByAddingOneCentury()
    {
        DecreaseDateByAddingOneCentury(*this);
    }
    

    clsDate DecreaseDateByAddingOneMillenuim(clsDate& Date)
    {

    //Periode of 1000 Years
    Date._Year-=1000;
    return Date;
    
    }
    void DecreaseDateByAddingOneMillenuim()
    {
        DecreaseDateByAddingOneMillenuim(*this);
    }
   static  bool IsEndOfWeek(clsDate Date)
    {
        return DayOfweekOrder(Date._Day,Date._Month,Date._Year)==6;
    }
    bool IsEndOfWeek()
    {
        return IsEndOfWeek(*this);
    }
   static  bool IsWeekend(clsDate Date)
    {   
        //weekends are Fri And Sat
        short DayIndex=DayOfweekOrder(Date._Day,Date._Month,Date._Year);
        return (DayIndex==5||DayIndex==6);
    }
    bool IsWeekend()
    {
        return IsWeekend(*this);
    }
   static  bool IsBusinessDay(clsDate Date)
    {
        //Weekends are Son , Mon ,Wed And Thur

        //shorter Method is Invert the IsWeekend this Will Save updating code
        return !IsWeekend( Date);
    }
    bool IsBusinessDay()
    {
        return IsBusinessDay(*this);
    }
    

    short DaysUntilEndOfWeek(clsDate Date)
    {
        return 6-DayOfweekOrder(Date._Day,Date._Month,Date._Year);
    }
    short DaysUntilEndOfWeek()
    {
        return DaysUntilEndOfWeek(*this);
    }
    short DaysUntilEndOfMonth(clsDate Date)
    {
        clsDate EndOfMonDate;
        EndOfMonDate._Day=NumberOFDaysInMonth(Date._Year,Date._Month);
        EndOfMonDate._Month=Date._Month;
        EndOfMonDate._Year=Date._Year;
        return GetDiffrenceInDays(Date,EndOfMonDate,false);
    }
    short DaysUntilEndOfMonth()
    {
        return DaysUntilEndOfMonth(*this);
    }
    short DaysUntilEndOfYear(clsDate Date)
    {
        clsDate EndOfYearDate;
        EndOfYearDate._Day=31;
        EndOfYearDate._Month=12;
        EndOfYearDate._Year=Date._Year;

        return GetDiffrenceInDays(Date,EndOfYearDate,false);
    }
    short DaysUntilEndOfYear()
    {
        return DaysUntilEndOfYear(*this);
    }    
    //  i added this method to calculate business days between 2 days 

    
    static short CalculateVacationDays(clsDate DateFrom,clsDate DateTo)
    {
        short Days=0;
        while (IsDate1BeforeDate2(DateFrom, DateTo))
        {
            if (IsBusinessDay( DateFrom))
                Days++;   

            DateFrom=AddOneDay(DateFrom);
        }
        return Days;
    }
    static short CalculateBusinessDays(clsDate DateFrom,clsDate DateTo)
    {
        short Days=0;
        while (IsDate1BeforeDate2(DateFrom, DateTo))
        {
            if (IsBusinessDay( DateFrom))
                Days++;   

            DateFrom=AddOneDay(DateFrom);
        }
        return Days;
    }
    static clsDate CalculateVacationReturnDate(clsDate Date,short VacationDays)
    {
        short WeekEndCounter=0;
        //in case the data is weekend keep adding one day until you reach business 
        //we get rid of all weekends before the first business day 
        while (IsWeekend(Date))
        {
            Date=AddOneDay( Date);
        }
        //here e increase the vacation dates to add all weekends to it 
        
        for (int  i = 1; i <= VacationDays+WeekEndCounter; i++)
        {
            if (IsWeekend(Date))
            WeekEndCounter++;
            
            Date=AddOneDay( Date);
        }
        // in case  the return date is week end keep adding one day until you reach business
        
            while (IsWeekend(Date))
        {
            Date=AddOneDay( Date);
        }
        return Date;
        
    }
    static bool IsDate1AfterDate2(clsDate Date1,clsDate Date2)
    {
        return (!IsDate1BeforeDate2(Date1, Date2)&&!IsDate1EqualToDate2(Date1, Date2));
    }
     bool IsDate1AfterDate2(clsDate Date2)
    {
        return IsDate1AfterDate2(*this,Date2);
    }
    enum enDateCompare {Before=-1,Equal=0,After=1};
    static enDateCompare CompareDates(clsDate Date1,clsDate Date2)
    {
        if (IsDate1BeforeDate2( Date1, Date2))
            return enDateCompare::Before;
        if (IsDate1EqualToDate2( Date1, Date2))
            return enDateCompare::Equal;
        /*if (IsDate1AfterToDate2(Date1,Date2))
            return enDateCompare::After;*/
        //this is faster
        return enDateCompare::After;
    
    }
    enDateCompare CompareDates(clsDate Date2)
    {
        return CompareDates(*this,Date2);
    }
    static string GetSystemDateTimeToString()
    {
        //System dateTime string 
        time_t t=time(0);
        tm* now = localtime(&t);
        short Day,Month,Year,Hour,Minute,Second;

        Year=now->tm_year+1900;
        Month=now->tm_mon+1;
        Day=now->tm_mday;
        Hour=now->tm_hour;
        Minute=now->tm_min;
        Second=now->tm_sec;

        return (to_string(Day)+"/"+to_string(Month)+"/"+
        to_string(Year)+" - "+to_string(Hour)+":"
        +to_string(Minute)+":"+to_string(Second));
    }



    



};
