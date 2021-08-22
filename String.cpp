#include"String.h"
#include<iostream>

using namespace std;

using namespace HomeMadeString;

// Default constructor (without arguments):

String::String()
{
	elementNum = 0;
	pData = new char [elementNum];
}

// Copy constructor:
String::String(const String& theOther)
{
	elementNum = theOther.elementNum;
	pData = new char[elementNum];
	for (int i = 0; i < elementNum;i++)
	{
	     pData[i] = theOther.pData[i];
	}

	pData[elementNum] = '\0';
}

// Conversion constructor that expects a char* with '\0' at the end
// This constructor is responsible for the conversion char*-> String
String::String(const char* str)
{
	elementNum = 0;

	while (str[elementNum] != '\0')
	{
		elementNum++;
	}

	pData = new char[elementNum + 1];

	for (int i = 0; i < elementNum;i++)
	{
		pData[i] = str[i];
	}

	pData[elementNum] = '\0';
}


// Constructor with a char (c) and an int parameter (times)
// This constructor creates a string that contains 'times' pieces of the character c
// e.g. if c='$' and times=5 then String="$$$$$"
String::String(char c, int times)
{
	elementNum = times;
	for (int i = 0; i < elementNum; i++)
	{
		pData[i] = c;
	}
}

//Destructor
String::~String()
{
	elementNum = 0;
	delete[] pData;
}


// Copies the string to the buffer and terminates it with '\0' (string terminating character)
// Memory allocation for the buffer is to be done by a caller
void String::getStr(char* pBuff)
{
	for (int i = 0;i < elementNum;i++)
	{
		pBuff[i] = pData[i];
	}
	pBuff[elementNum]= '\0';
}


// Writes the string to the given stream		
void String::print(std::ostream& os)
{
	for (int i = 0;i < elementNum;i++)
	{
		os << pData[i];
	}
}


// Returns with the character at the given position, othewise 0
char String::getChar(int pos)
{
	if (pData == NULL)
	{
		return 0;
	}

	for (int i = 0;i < elementNum;i++)
	{
		if (pos == i)
		{
			return pData[i];
		}
	}
	return 0;
}


// Returns with a concatenated string
 String String::concatenate(const String string1, const String string2)
{
	String string3;
    string3.elementNum = string1.elementNum + string2.elementNum;
	string3.pData = new char[string3.elementNum];

		int index = 0;

		for (int i = 0;i < string1.elementNum;i++)
		{
			string3.pData[index] = string1.pData[i];
			index++;
		}
		for (int i = 0;i < string2.elementNum;i++)
		{
			string3.pData[index] = string2.pData[i];
			index++;
		}
		return string3;
}


 // Compares two strings
bool String::compare(const String string1, const String string2)
{
	if (string1.elementNum != string2.elementNum)
	{
		return false;
	}

	for (int i = 0;i < string1.elementNum;i++)
	{
		if (string1.pData[i] != string2.pData[i])
		{
			return false;
		}
	}
	return true;
}


//Without static keyword
bool String::compare(const String& string1)
{
	if (elementNum != string1.elementNum)
	{
		return false;
	}

	for (int i = 0;i < string1.elementNum;i++)
	{
		if (pData[i] != string1.pData[i])
		{
			return false;
		}
	}
	return true;
}


// Copies string2 to string1
 void String::copy(String &string1,const String string2)
 {
	 string1.elementNum = string2.elementNum;
	 for (int i = 0;i < string2.elementNum;i++)
	 {
		 string1.pData[i] = string2.pData[i];
	 }
	 
 }
