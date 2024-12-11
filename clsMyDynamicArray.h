#pragma once
#include <iostream>

using namespace std;

template <class T>
class clsDaynamicArray 
{

protected:
    int _Size;
    T*_TempArray;


public:
    T * OriginalArray;
    clsDaynamicArray(int Size=0)
    {
        if (Size<0)
        {
            Size=0;
        }
        
        _Size=Size;
        OriginalArray=new T[_Size];
    }
    ~clsDaynamicArray()
    {
        delete[] OriginalArray;
    }

    bool SetItem(int Index,int Value)
    {
        if (Index>=_Size||_Size<0)
        {
            return false;
        }
        
        OriginalArray[Index]=Value;
        return true;
    }
    int Size()
    {
        return _Size;
    }
    void PrintList()
    {
        for (int  i = 0; i < Size(); i++)
        {
            cout<<OriginalArray[i]<<" ";
        }
        cout<<"\n";
        
    }
    bool IsEmpty()
    {
        return (_Size==0?true:false);
    }

    void Resize(int NewSize)
    {
        if (NewSize<0)
            NewSize=0;

        //limit the Orginal size to the new size if it is less
        if (NewSize<_Size)
        {
            _Size=NewSize;
        }
        _TempArray=new T[NewSize];
        //copy all data from original array until the size
        for (int  i =0; i <_Size; i++)
        {
            _TempArray[i]=OriginalArray[i];
        }
        _Size=NewSize;
        delete[] OriginalArray;

        OriginalArray=_TempArray;
        
    }
    void Reverse()
    {
         _TempArray=new T[_Size];
        //copy all data from original array until the size
        for (int  i =0; i <_Size; i++)
        {
            _TempArray[i]=OriginalArray[i];
        }
        delete[] OriginalArray;
        OriginalArray=_TempArray;
    }
    void Clear()
    {
        _Size=0;
        _TempArray= new T[0];
        delete[] OriginalArray;
        OriginalArray = _TempArray;
    }
    bool DeleteItemAt(int Index)
    {
        if (Index<0||Index>_Size)
            return false;
        
        _Size--;
        _TempArray=new T[_Size];

        //Copy all before Index
        for (int i=0; i <Index; i++)
        { 
            _TempArray[i]=OriginalArray[i];
           
        }
        //Copy all after Index
        for (int i=Index+1; i <_Size+1; i++)
        { 
            _TempArray[i-1]=OriginalArray[i];
        }

        delete[] OriginalArray;
        OriginalArray=_TempArray;
        return true;

    }
    void DeleteFirstItem()
    {
        DeleteItemAt(0);
    }
    void DeleteLastItem()
    {
        DeleteItemAt(_Size-1);
    }
    int Find(T Value)
    {
        for (int  Index =0; Index <_Size; Index++)
        {
            if (OriginalArray[Index]==Value)
                return Index;
        }
        return -1;
    }
    bool DeleteItem(T Value)
    {   
        int Index=Find(Value);

        if (Index==-1)
          return false;
    
        DeleteItemAt(Index);
        return true;
    }
    bool InsertAt(int Index,T Value)
    {
         if (Index<0||Index>_Size)
            return false;
        _Size++;
        _TempArray=new T[_Size];
          //Copy all before Index
        for (int i=0; i <Index; i++)
        { 
            _TempArray[i]=OriginalArray[i];
           
        }
        _TempArray[Index]=Value;
        //Copy all after Index
        for (int i=Index; i <_Size-1; i++)
        { 
            _TempArray[i+1]=OriginalArray[i];
        }

        delete[] OriginalArray;
        OriginalArray=_TempArray;
        return true;
        
    }
    bool InsertAtBeginning(T Value)
    {
        
        return InsertAt(0,Value);
    }
    bool InsertBefore(int Index,T Value)
    {
        if (Index<1)
        {
            return InsertAt(0,Value);
        }
        else
        return InsertAt(Index-1,Value);
    }
    bool InsertAfter(int Index,T Value)
    {
        if (Index>=_Size)
        {
            return InsertAt(_Size-1,Value);
        }
        else
        return InsertAt(Index+1,Value);
    }
    bool InsertAtEnd(T Value)
    {
        return InsertAt(_Size,Value);
    }
    T GetItem(int Index)
    {
        return OriginalArray[Index];
    }

};