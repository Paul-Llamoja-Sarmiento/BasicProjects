#include "MyString.h"
#include <iostream>
#include <cstring>
#include <cctype>


// No-args constructor
MyString::MyString()
	: str(nullptr)
{
	str = new char[1];
	*str = '\0';
}


// Overloaded constructor
MyString::MyString(const char *s)
	: str(nullptr)
{
	if(s == nullptr)
	{
		str = new char[1];
		*str = '\0';
	}

	else
	{
		str = new char[std::strlen(s) + 1];
		std::strcpy(str , s);
	}
}


// Copy constructor
MyString::MyString(const MyString &source) 
	: str(nullptr)
{
	str = new char[std::strlen(source.str) + 1];
	std::strcpy(str , source.str);
}


// Move constructor
MyString::MyString(MyString &&source)
	: str(source.str)
{
	source.str = nullptr;
	std::cout << "Move constructor used." << std::endl;
}


// Destructor
MyString::~MyString()
{
	/*if(str == nullptr) 
        	std::cout << "Calling destructor for Mystring : nullptr" << std::endl; 
	
	else 
        	std::cout << "Calling destructor for Mystring : " << str << std::endl;*/

	delete [] str;
}


// Copy assingnment
MyString &MyString::operator=(const MyString &rhs)
{
	std::cout << "Copy Assignment" << std::endl;

	if(this == &rhs)
		return *this;

	else
	{
		delete [] str;
		str = new char[std::strlen(rhs.str) + 1];
		std::strcpy(str , rhs.str);
		return *this;
	}
}


// Move assingnment
MyString &MyString::operator=(MyString &&rhs)
{
	std::cout << "Move Assignment" << std::endl;

	if(this == &rhs)
		return *this;

	else
	{
		delete [] str;
		str = rhs.str;
		rhs.str = nullptr;
		return *this;
	}
}


// "Negation" - make lowercase
MyString operator-(const MyString &obj)
{
	char *buff = new char[std::strlen(obj.str) + 1]; 
	std::strcpy(buff , obj.str);

	for(size_t i{} ; i < std::strlen(buff) ; i++)
		buff[i] = std::tolower(buff[i]);

	MyString temp(buff);
	delete [] buff;
	return temp;
}


//Pre-increment - adds an "O" at the end and then operates
MyString &operator++(MyString &obj)
{
	char *buff = new char[std::strlen(obj.str) + 2];
	std::strcpy(buff , "O");
	std::strcat(buff , obj.str);

	delete [] obj.str;
	obj.str = buff;
	buff = nullptr;
	return obj;
}	


// Post-increment - operates and then adds an "O" at the end
MyString operator++(MyString &obj , int)
{
	MyString temp{obj};
	++obj;
	return temp;
}


// Equality
bool operator==(const MyString &lhs , const MyString &rhs)
{
	return (std::strcmp(lhs.str , rhs.str) == 0);
}


// Inequality
bool operator!=(const MyString &lhs , const MyString &rhs)
{
	return !(lhs == rhs);
}


// Concatenate
MyString operator+(const MyString &lhs , const MyString &rhs)
{
	size_t buffSize = std::strlen(lhs.str) + 
			  std::strlen(rhs.str) + 1;
	char *buff = new char[buffSize];
	std::strcpy(buff , lhs.str);
	std::strcat(buff , rhs.str);
	MyString temp(buff);
	delete [] buff;
	return temp;
}


// Concatenate + assignment
MyString &operator+=(MyString &lhs , const MyString &rhs)
{
	lhs = lhs + rhs;
	return lhs;
}


// Less than - compare the length
bool operator<(const MyString &lhs , const MyString &rhs)
{
	return (std::strlen(lhs.str) < std::strlen(rhs.str));	
}


// Greater than - compare the length
bool operator>(const MyString &lhs , const MyString &rhs)
{
	return !(lhs < rhs);	
}


//Insertion operator
std::ostream &operator<<(std::ostream &os , const MyString &obj)
{
	os << obj.str;
	return os;
}


std::istream &operator>>(std::istream &is , MyString &obj)
{
	char *buff = new char[1000];
	is >> buff;
	obj = MyString(buff);
	delete [] buff;
	return is;	
}


// "Repeat" a string
MyString operator*(const MyString &lhs , const int &n)
{
	size_t buffSize = (std::strlen(lhs.str) * n) + 1;
	char *buff = new char[buffSize];
	
	std::strcpy(buff , lhs.str);
	for(size_t i{} ; i < n - 1 ; i++)
		std::strcat(buff , lhs.str);

	MyString temp(buff);
	delete [] buff;
	return temp;
}


// "Repeat" a string + assignment
MyString &operator*=(MyString &lhs , const int &n)
{
	lhs = lhs * n;
	return lhs;
}	


// Display
void MyString::display() const
{
	std::cout << str << " : " << get_length() << std::endl;
}


// Length getter
int MyString::get_length() const
{
	return std::strlen(str);
}

// String getter
const char *MyString::get_str() const
{
	return str;
}
