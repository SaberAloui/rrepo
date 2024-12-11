#pragma once
#include <iostream>
#include "clsDbleLinkedList.h"
using namespace std;

template <class T>
class clsMyQueue 
{
protected:
    
    clsDbleLinkedList<T> _MyList;
public:

    void Pusch(T Item)
    {
        _MyList.InsertAtEnd(Item);
    }
    void Print()
    {
        _MyList.PrintList();
    }
    int Size()
    {
       return _MyList.Size();
    }
    T Front()
    {
       return _MyList.GetItem(0);
    }
    T Back()
    {
       return _MyList.GetItem(Size()-1);
    }
    void pop()
    {
        _MyList.DeleteFirstNode();
    }
    bool IsEmpty()
    {
        return _MyList.IsEmpty();
    }
    T GetItem(int Index)
    {
        return _MyList.GetItem(Index);
    }
    void Reverse()
    {
        _MyList.Reverse();
    }
    void UpdateItem(int Index,T NewValue)
    {
        _MyList.UpdateItem(Index,NewValue);
    }
    void InsertAfer(int Index,T NewValue)
    {
        _MyList.InsertAfter(Index,NewValue);
    }
    void InsertAtFront( T Value)
    {
        _MyList.InsertAtBeginning(Value);
    }
    void InsertAtBack(T Value)
    {
        _MyList.InsertAtEnd(Value);
    }
    void Clear()
    {
        _MyList.Clear();
    }
};
