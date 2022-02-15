#include <iostream>
#include "helperFunctions.h"
#include <initializer_list>
using namespace std;
class MyString
{
private:
	int maxSize;
	int currentSize;
	char *string;
public:
	// Constructor
	MyString(int size = 100);
	MyString(const MyString& obj);
	MyString (const MyString &obj,int start  ,int end);
	
	// Destructor
	~MyString();
	// String work
	void add(const char str);
	int length()const;
	void clear();
	// operators 
	char& operator[](int i);
	const char& operator[](int i)const;
	MyString& operator=(const MyString& rhs);
	MyString operator+(const MyString& obj);
	MyString &operator++();
	MyString operator++(int);
	MyString &operator--();
	MyString operator--(int);
	//Bonus Task
	MyString(initializer_list<char> argu);
	MyString& operator=(initializer_list<char> argu);
};

