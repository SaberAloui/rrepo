#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class clsString
{
private:
    string _Value;
    char _Letter;
    
public:
    clsString()
    {
        _Value="";
    }
    clsString(string Value)
    {
        _Value = Value;
    }
    void SetValue(string Value)
    {
        _Value=Value;
    }
    string GetValue()
    {
        return _Value;
    }

    static short Length(string S1)
    {
        return S1.length();
    };
    short Length()
    {
        return _Value.length();
    }
    //Function to count word in external string
    static short CountWords(string S1)
    {
        short counter = 0;
        string delim = " "; // delimiter
        short pos = 0;
        string sWord; // define a string variable
        // use find() function to get the position of delimiters
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word
            if (S1 != " ")
            {
                counter++;
            }
            S1.erase(0, pos + delim.length()); /*erase() until position
                and move to next word*/
        }

        if (S1 != " ")
        {
            counter++;//it counts the last word of the string 
        }
        return counter;
    }


    short CountWords()
    {
        return CountWords(_Value);
    }
    static string  UpperFirstLetterOfEachWord(string S1)
    {
        bool IsFirstLetter=true;
        
        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i]!=' '&& IsFirstLetter)
            {
                
            S1[i]= toupper(S1[i]);
            }
            IsFirstLetter=(S1[i]==' '?true : false);
        }
        return S1;
        
    }
    void UpperFirstLetterOfEachWord()
    {
        // no need to return value this function will directly update the object value
        _Value= UpperFirstLetterOfEachWord(_Value);
    }
    
    static string  LowerFirstLetterOfEachWord(string S1)
    {
        bool IsFirstLetter=true;
        
        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i]!=' '&& IsFirstLetter)
            {
                
            S1[i]= tolower(S1[i]);
            }
            IsFirstLetter=(S1[i]==' '?true : false);
        }
        return S1;
        
    }
    void LowerFirstLetterOfEachWord()
    {
        // no need to return value this function will directly update the object value
        _Value=LowerFirstLetterOfEachWord(_Value);
    }
    

    static string  UpperAllString(string S1)
    {
        
        for (short i = 0; i < S1.length(); i++)
        {
            
            S1[i]= toupper(S1[i]);
        
        }
        return S1;
        
    }
    void UpperAllString()
    {
        _Value=UpperAllString(_Value);
    }
    static string LowerAllString(string S2)
    {
        for (short i = 0; i < S2.length(); i++)
        {
            S2[i]=tolower(S2[i]);
        }
        return S2;
        
    }
    void LowerAllString()
    {
        _Value= LowerAllString(_Value);
    }
    static char InvertLetterCase(char char1)
    {
        return isupper(char1)?tolower(char1):toupper(char1);
    };
    static string  InvertAllStringtLettersCase(string S1)
    {
        
        for (short i = 0; i < S1.length(); i++)
        {
        
                
            S1[i]= InvertLetterCase(S1[i]);
        }
        return S1;
        
    }
    void InvertAllStringtLettersCase()
    {
        _Value=InvertAllStringtLettersCase(_Value);
    }
    
    enum enWhatToCount{SmallLetters=0,CapitalLetters=2,All=3};
    
    static short CountLetters(string S1,enWhatToCount WhatToCount=enWhatToCount::All)
    {
        if (WhatToCount==enWhatToCount::All)
        {
            return S1.length();
        }
        short Counter=0;
        for (short  i = 0; i < S1.length(); i++)
        {
            if (WhatToCount==enWhatToCount::CapitalLetters&&isupper(S1[i]))
            {
                Counter++;
            }
            if (WhatToCount==enWhatToCount::SmallLetters&&islower(S1[i]))
            {
                Counter++;
            }
            
        }
            return Counter;
        
        
    }
    short Countletters()
    {
        return CountLetters(_Value,enWhatToCount::All);
    };
    static short CountCapitalLetters(string S1)
    {
        return CountLetters(S1,enWhatToCount::CapitalLetters);
    };
    short CountCapitalLetter()
    {
        return CountCapitalLetters(_Value);
    }
    static short CountSmallLetters(string S1)
    {
        return CountLetters(S1,enWhatToCount::SmallLetters);
    };
    short CountSmallLetters()
    {
        return CountSmallLetters(_Value);
    };
    //split external string and save them in vector 
    static vector <string> Split(string S1,string delim )
    {

        vector <string> vClientData;
        

        short pos = 0;
        string sWord; // define a string variable
        // use find() function to get the position of delimiters
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word
            if (sWord != "")
            {
            vClientData.push_back(sWord);
            }
            S1.erase(0, pos + delim.length()); /*erase() until position
                and move to next word*/
        }

        if (S1 != "")
        {
            vClientData.push_back(S1);//it adds the last word to vector 
        }
        return vClientData;

    
    }

    //split internal  string in object and save them in vector 
    vector <string> Split(string Delim)
    {
        return Split(_Value,Delim);
    };
  
    
    static bool IsVowel(char Ch1)
    {
    Ch1=tolower(Ch1);
    return ((Ch1=='a')||(Ch1=='e')||(Ch1=='i')||(Ch1=='o')||(Ch1=='u'));

    }
    bool IsVowel()
    {
        return IsVowel(_Letter);
    }
    static short CountVowels(string S1)
    {
        short counter=0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (IsVowel(S1[i]))
        {
            counter++;
        }
        }
        return counter;
    }
    short CountVowels()
    {
        return CountVowels(_Value);
    };
    static string JoinString(vector<string> vStrings,string Delim)
    {
        string S2="";
        for (string &Word : vStrings)
        { 
        S2=S2+Word+Delim;
            
        }
        return S2.substr(0,S2.length()-Delim.length());
        
    }
    static string JoinString(string arrString[],short Length,string Delim)
    {
        string S1="";
        for (short i = 0; i < Length; i++)
        {
            S1=S1+arrString[i]+Delim;
        }
        
        return S1.substr(0,S1.length()-Delim.length());
        
    }
    static string ReverseWordInString(string S1)
    {
        string S2="";
        vector<string> vString;
        vString=Split(S1," ");
        //declare iterator
        vector<string>::iterator iter=vString.end();
        while (iter!=vString.begin())
        {
        --iter;
        S2=S2+*iter+" ";
        }
        S2=S2.substr(0,S2.length()-1);//remove the last space 
        return S2;
    };
    void  RevereseWordInString()
    {
        _Value= ReverseWordInString(_Value);
    };

    static string TrimLeft(string  S1)
    { 
        
        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i]!=' ')
            {
            return S1.substr(i,S1.length()-1);

            }   
        } 
        return "";
    }
    
    void TrimLeft()
    {
        _Value=TrimLeft(_Value);
    }
    static string TrimRight(string S1)
    {
        for (short i = S1.length()-1; i >= 0; i--)
        {
            if (S1[i]!=' ')
            {
            return S1.substr(0,i+1);
            }
    
            
        }
        return "";
        
    }
    void TrimRight()
    {
        _Value=TrimRight(_Value);
    }
    static string Trim(string S1)
    {
        return TrimLeft(TrimRight(S1));
    };
    void Trim()
    {
        _Value=Trim(_Value);
    };
    static string RemovePunctuation(string S1)
    {
        string S2="";
        for (short i = 0; i < S1.length(); i++)
        {
            if (!(ispunct(S1[i])))
            {
                S2+=S1[i];
            }
            
        }
        return S2;
        
    }
    void RemovePunctuation()
    {
        _Value= RemovePunctuation(_Value);
    }
    static string ReplaceWord(string S1,string StringToReplace,string sReplaceTo,bool MachCase=true)
    {
        vector<string> vStrings;
        vStrings=Split(S1," ");

        for (string& Word  : vStrings)
        {
        if (MachCase)
        {
            if (Word==StringToReplace)
            {
            Word=sReplaceTo;
            }
            else
            {
                if (LowerAllString(Word)==LowerAllString(StringToReplace))
                {
                Word=sReplaceTo;
                }
            }
            
        }
        
        }
    
        return JoinString(vStrings," ");
    }
    string ReplaceWord(string StringToReplace,string sReplaceTo)
    {
        return ReplaceWord(_Value,StringToReplace,sReplaceTo);
    }


};

