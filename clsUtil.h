#pragma once 
#include <iostream>
#include "clsDate.h"
using namespace std;
class clsUtil
{
private:

public:
    static void Srand()
    {
    srand((unsigned)time(NULL));
    };
    static int RandomNumber(int from,int to)
    {
        int random=rand()%(to-from)+from;
        return random;
    };
    enum enCharType{SmallLetter=1,CapitalLetter=2,Digit=3,MixChars=4,SpeciallLetter=5};
    static char GetRandomCharacter(enCharType Chartype)
    {
    switch(Chartype)
    {
        case enCharType::SmallLetter:
        return char(RandomNumber(97,122));
        break;
        case enCharType::Digit:
        return char(RandomNumber(48,57));
        break;
        case enCharType::CapitalLetter:
        return char(RandomNumber(65,90));
        break;
        case enCharType::SpeciallLetter:
        return char(RandomNumber(33,47));
        break;
        case enCharType::MixChars:
        return GetRandomCharacter((enCharType)RandomNumber(1,3));
        break;
    }
    }
    static string GenerateWord(enCharType Chartype,short Length)
    {
        string word;
        for(int i=1;i<=Length;i++)
        {
            word=word+GetRandomCharacter(Chartype);
        }
        return word;
    }
    static string GenerateKey(enCharType CharType)
    {
        string key;
    
            key=GenerateWord(CharType,4)+"_";
            key=key+GenerateWord(CharType,4)+"_";
            key=key+GenerateWord(CharType,4)+"_";
            key=key+GenerateWord(CharType,4);

        return key;
    }
    static void GenerateKeys(int numberOfKey,enCharType CharType)
    {
        for(int i=1;i<=numberOfKey;i++)
        {
            cout<<"Key"<<"["<<i<<"] = "<<GenerateKey(CharType)<<endl;
        }
    
    }
    static void Swap(int& a,int& b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    static void Swap(double& a,double& b)
    {
        double temp=a;
        a=b;
        b=temp;
    }
    static void Swap(string& a,string& b)
    {
        string temp=a;
        a=b;
        b=temp;
    }
    static void Swap(clsDate& Date1,clsDate& Date2)
    {
    clsDate TempDate;
    TempDate._Year=Date1._Year;
    TempDate._Month=Date1._Month;
    TempDate._Day=Date1._Day;

    Date1._Year=Date2._Year;
    Date1._Month=Date2._Month;
    Date1._Day=Date2._Day;

    Date2._Year=TempDate._Year;
    Date2._Month=TempDate._Month;
    Date2._Day=TempDate._Day;
    


    }
    static void ShuffleArray(int Arrlength,int arr[100])
    {
        for(int i=0;i<Arrlength;i++)
        {
            swap(arr[RandomNumber(1,Arrlength)-1],arr[RandomNumber(1,Arrlength)-1]);
        }
    }
    static void FillArrayWithRandomNumbers(int Array[100],int Arrlength,int From,int To)
    {
        for(int i=0;i<Arrlength;i++)
        {
            Array[i]=RandomNumber(From,To);
        }
    }
    static void FillArrayWithRandomWords(string Array[100],int Arrlength,enCharType CharType,int WordLength)
    {
        for(int i=0;i<Arrlength;i++)
        {
            Array[i]=GenerateWord(CharType,WordLength);
        }
    }
    static void FillArrayWithRandomKeys(string Array[100],int Arrlength,enCharType CharType)
    {
        for(int i=0;i<Arrlength;i++)
        {
            Array[i]=GenerateKey(CharType);
        }
    }
    static void PrintArray(int Array[100],int Arrlength)
    {
        for(int i=0;i<Arrlength;i++)
        {
            cout<<Array[i]<<" ";
        }
    }
    static void PrintMatrix(int Rows,int Colums,int Matrix[100][100])
    {
        for(int i=0;i<Rows;i++)
        {
            for(int j=0;j<Colums;j++)
            {
                cout<<Matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    static void PrintArray(string Array[100],int Arrlength)
    {
        for(int i=0;i<Arrlength;i++)
        {
            cout<<Array[i]<<" "<<endl;
        }
    }
    static string NumberToText(int Number)
    {
        if (Number==0)
        {
            return "";
        }
        if (Number>=1&&Number<=19)
        {
            string arr[] = {"","One","Two","Three","Four","Five","Six","Seven",
            "Eight","Nine ","Ten","Eleven","Twelve","Thirteen","FourTeen","Fifteen"
            ,"Sixteen","Seventeen","Eighteen","Nineteen"};

            return arr[Number]+" ";
        }
        if (Number>=20&&Number<=99)
        {
            string arr[]={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

            return arr[Number/10]+" "+NumberToText(Number%10);
        }
        if (Number>=100&&Number<=199)
        {
            return "One Hundred "+NumberToText(Number%100);
        }
        if (Number>=200&&Number<=999)
        {
            return NumberToText(Number/100)+"Hundreds "+NumberToText(Number%100);
        }
        if (Number>=1000&&Number<=1999)
        {
            return "One Thousand "+NumberToText(Number%1000);
        }
        if (Number>=2000&&Number<=999999)
        {
            return NumberToText(Number/1000)+"Thousands "+NumberToText(Number%1000);
        }
        if (Number>=1000000&&Number<=1999999)
        {
            return "One Million "+NumberToText(Number%1000000);
        }
        if (Number>=2000000&&Number<=999999999)
        {
            return NumberToText(Number/1000000)+"Millions "+NumberToText(Number%1000000);
        }
        if (Number>=1000000000&&Number<=1999999999)
        {
            return "One Billion "+NumberToText(Number%1000000000);
        }
        else
        {
            return NumberToText(Number/1000000000)+"Billions "+NumberToText(Number%1000000000);
        }
    
        
        
        
    }
    static string Tabs(short NumberOfTabs)
    {
        string t="";
        for (int  i = 1; i < NumberOfTabs; i++)
        {
            t=t+"\t";
            cout<<t;
        }
        return t;
    }
    static string EncryptText(string Text,short EncryptKey=2)
    {
        
        for(int i=0;i<=Text.length();i++)
        {
            Text[i]=char((int)Text[i]+EncryptKey);
        }
        return Text;
    }
    static string DecryptText(string Text,short EncryptKey=2)
    {
        
        for(int i=0;i<=Text.length();i++)
        {
            Text[i]=char((int)Text[i]-EncryptKey);
        }
        
        return Text;
    }
    static bool BinarySearch(int arr[],int from ,int to,int Number)
    {
        if (to<from)
            return false;
        int Mid=(from+to)/2;
        if (arr[Mid]==Number)
            return true;
        else if (arr[Mid]>Number)
            return BinarySearch(arr,from,Mid-1,Number);
        else 
            return BinarySearch(arr,Mid+1,to,Number);
    }
    static bool BinarySearch(vector <int>& V,int from ,int to,int Number)
    {
        if (to<from)
            return false;
        int Mid=(from+to)/2;
        if (V[Mid]==Number)
            return true;
        else if (V[Mid]>Number)
            return BinarySearch(V,from,Mid-1,Number);
        else 
            return BinarySearch(V,Mid+1,to,Number);
    }
    static bool SearchInSorted(int arr[],int To,int Number)
    {
        if (BinarySearch(arr,0,To-1,Number))
            return true;
        else 
            return false;
    }
    

    




};



