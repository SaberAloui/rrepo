#pragma once
#include <iostream>
#include "queue"
#include <stack>
#include "clsDate.h"
using namespace std;

class clsQueueLine
{
private:
    short _TotalTickets=0;
    short _AverageServeTime=0;
    string _Prefix="";

    class clsTicket
    {
    private:
        short _Number=0;
        string _Prefix;
        string _TicketTime;
        short _WaitingClients=0;
        short _AverageServeTime=0;
        short _ExpectedServeTime=0;

    public:
        clsTicket(string Prefix,short Number,
        short WaitingClients,short AverageServeTime)
        {
            _Number=Number;
            _Prefix=Prefix;
            _TicketTime=clsDate::GetSystemDateTimeToString();
            _WaitingClients=WaitingClients;
            _AverageServeTime=AverageServeTime;
        }
        string Prefix()
        {
            return _Prefix;
        }
        short Number()
        {
            return _Number;
        }
        string FullNumber()
        {
            return _Prefix+to_string(_Number);
        }
        string TicketTime()
        {
            return _TicketTime;
        }
        short WaitingClients()
        {
            return _WaitingClients;
        }
        short ExpectedServeTime()
        {
            return _AverageServeTime+_WaitingClients;
        }
        void Print()
        {
            cout<<"\n\t\t\t -----------------------\n";
            cout<<"\t\t\t\t   "<<FullNumber();
            cout<<"\n\n\t\t\t "<<_TicketTime;
            cout<<"\n\t\t\t   Waiting Clients = "<<_WaitingClients;
            cout<<"\n\t\t\t   Serve Time In";
            cout<<"\n\n\t\t\t "<<ExpectedServeTime()<<"Minunts ";
            cout<<"\n\t\t\t  --------------------------\n";

        }
    };
public:
    queue <clsTicket> QueueLine;
    clsQueueLine(string Prefix,short AverageServeTime)
    {
        _Prefix=Prefix;
        _TotalTickets=0;
        _AverageServeTime=AverageServeTime;
    }
    void IssueTicket()
    {
        _TotalTickets++;
        clsTicket Ticket(_Prefix,_TotalTickets,WaitingClients(),_AverageServeTime);
        QueueLine.push(Ticket);
    }
    int WaitingClients()
    {
        return QueueLine.size();
    }
    string WhoIsNext()
    {
        if (QueueLine.empty())
            return "No Clients Lefts ";
        else
            return QueueLine.front().FullNumber();
        
    }
    bool ServeNextClient()
    {
        if(QueueLine.empty())
            return false;
        
        QueueLine.pop();
        return true;
    }
    short ServedClients()
    {
        return _TotalTickets-QueueLine.size();
    }
    void PrintInfo()
    {
        cout<<"\n\t\t\t\t -------------------\n"; 
        cout<<"\n\t\t\t\t  Queue Info";
        cout<<"\n\t\t\t\t -------------------\n"; 
        cout<<"\n\t\t\t     Prefix ="<<_Prefix;
        cout<<"\n\t\t\t     Total Tikects  ="<<_TotalTickets;
        cout<<"\n\t\t\t     ServedClients  ="<<ServedClients();
        cout<<"\n\t\t\t     Waiting Clients="<<WaitingClients();
        cout<<"\n\t\t\t\t -------------------\n"; 
        cout<<"\n";
    }
    void PrintTicketLineRTl()
    {
        if (QueueLine.empty())
            cout<<"\n\t\t Tickets: No Tickets ";
        else 
            cout<<"\n\t\t Tickets: ";
        queue <clsTicket> TempQueueLine =QueueLine;
        while(!TempQueueLine.empty())
        {
            clsTicket Ticket =TempQueueLine.front();

            cout<<"  "<<Ticket.FullNumber()<<"<-- ";
            TempQueueLine.pop();
        }

    }
    void PrintTicketLineLRT()
    {
        if (QueueLine.empty())
            cout<<"\n\t\t Tickets: No Tickets ";
        else 
            cout<<"\n\t\t Tickets: ";
        queue <clsTicket> TempQueueLine =QueueLine;
        stack <clsTicket> TempStackLine;
        while(!TempQueueLine.empty())
        {
            TempStackLine.push(TempQueueLine.front());
            TempQueueLine.pop();
        }
        while(!TempQueueLine.empty())
        {
            clsTicket Ticket =TempStackLine.top();
            

            cout<<"  "<<Ticket.FullNumber()<<"--> ";
            TempQueueLine.pop();
        }
        cout<<"\n";
    }
    bool PrintAllTickets()
    {
        if (QueueLine.empty())
        {
            return false;
        }
        
        queue <clsTicket> TempQueueLine=QueueLine;

        while (!TempQueueLine.empty())
        {
            TempQueueLine.front().Print();
            TempQueueLine.pop();
        }
            return true;
        
    }
};
