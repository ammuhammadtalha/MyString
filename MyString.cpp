#include "MyString.h"
MyString::MyString(initializer_list<char> argu)
{
	currentSize = 0;
	maxSize = argu.size();
	string = new char[maxSize];
	for (auto i = argu.begin(); i < argu.end(); i++)
	{
		string[currentSize++] = *i;
	}

}
MyString& MyString::operator=(initializer_list<char> argu)
{
	currentSize = 0;
	maxSize = argu.size();
	string = new char[maxSize];
	for (auto i = argu.begin(); i < argu.end(); i++)
	{
		string[currentSize++] = *i;
	}
	return *this;
}
MyString::MyString(int size)
{
	maxSize = size;
	currentSize = 0;
	string = new char[maxSize];
}
void   MyString::add(const char str)
{
	if (currentSize < maxSize)
	{
		string[currentSize] = str;
		currentSize++;
	}
	else
	{
		char* temp = nullptr;
		temp = new char[maxSize + 1];
		maxSize++;
		for (int i = 0; i < currentSize; i++)
		{
			temp[i] = string[i];
		}
		temp[currentSize] = str;
		currentSize++;
		delete[]string;
		string = nullptr;
		string = temp;
	}
}
MyString::MyString(const MyString& obj, int start, int end)
{
	if (end == 0 || start >= end)
	{
		maxSize = obj.length() - (start - 1);
		deepCopy(string, obj.string, start, end);
		currentSize = strLength(string);
	}
	else 
	{
		maxSize = end - (start - 1);
		deepCopy(string, obj.string, start, end);
		currentSize = strLength(string);
		
	}
}
MyString::~MyString()
{
	if (string != nullptr)
	{
		delete[]string;
		string = nullptr;
	}
}
int MyString::length()const
{
	return currentSize;
}
void MyString::clear()
{
	int size = currentSize;
	for (int i = 0; i < size; i++)
	{
		string[i] = '\0';
	}
	currentSize = 0;
}

char& MyString::operator[](int i)
{
	if (i >= 0 && i < currentSize)
	{
		return string[i];
	}
	else
	{
		cout << " You have entered wrong index number " << endl;
	}
}
const char& MyString::operator[](int i)const
{
	if (i >= 0 && i < currentSize)
	{
		return string[i];
	}
	else
	{
		cout << " You have entered wrong index number " << endl;
	}
}
MyString MyString::operator+(const MyString& obj)
{
	MyString temp(currentSize + obj.currentSize);
	
	for (int i=0; i < currentSize; i++)
	{
		temp.add(string[i]);
	}
	for (int j = 0; j < obj.currentSize; j++)
	{
		temp.add(obj.string[j]);
	}
	return temp;
}
MyString& MyString::operator=(const MyString& rhs)
{
	if (this != &rhs)
	{
			delete[] string;
			string = nullptr;
			currentSize = rhs.currentSize;
			maxSize = rhs.maxSize;
			string = new char[rhs.maxSize];
			for (int i = 0; i < rhs.currentSize; i++)
			{
				string[i] = rhs.string[i];
			}
	}
		return *this;
}
MyString& MyString::operator++()
{
	int size = length();
	for (int i = 0; i < size; i++)
	{
		string[i] = string[i] + 1;
	}  
	return *this;
}
MyString MyString::operator++(int)
{
	MyString result = *this;
	++* this;
 
	return result;
}
MyString& MyString::operator--()
{
	for (int i = 0; i < length(); i++)
	{
		string[i] = string[i] - 1;
	}
    return *this;
}
MyString MyString::operator--(int)
{
	MyString result = *this;
	--* this;
	return result;
}
MyString :: MyString(const MyString& obj) :currentSize(obj.currentSize), maxSize(obj.maxSize)
{
	string = new char[obj.maxSize];
	for (int i = 0; i < obj.currentSize; i++)
	{
		string[i] = obj.string[i];
	}

}
/*
We always return pre-increment operator by reference if we don't return it by reference then the value will
increment only once and the original value will not change . if we call pre-increment with cascade then the value returned will be the copy of
original and the original one will be unchanged
// Code Explaination: -
MyString MyString::operator++()
{
	for (int i = 0; i < length(); i++)
	{
		string[i] = string[i] + 1;
	}
	return *this;
}
Let Suppose our string is str1 = A B C D
we call pre-increment operator ++str1;
it will not change to B C D E
but if again we call ++str1
then it will not change to the B C D E because the value was changed
it will again print B C D E
in c++ it allow it as cascade 
such as ++ ++ ++ a or ((++a)++a)++a
We also return pre-decrement operator(--) and copy-assignment operator(=) 
because they can be used as cascade so we have to make it as return by reference
-- -- -- a or ((--a)--a)--a
and 
(obj1 = obj2)=obj3;
if we don't return value by refernce then it will return the old value 
Why we overload indexing operator([]) twice ?
we overload the index operator twice because in case of constant object we don't want 
to change the value of the object that's why we create a constant function for non-constant 
objects and this function returns the original value so we can change it.
*/