#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class MyString
{
	
	//Overloaded operators as friend global functions
	friend MyString operator-(const MyString &obj);				// "Negation" - make lowercase
	friend MyString &operator++(MyString &obj);				// Pre-increment - adds an "O" at the beginning
	friend MyString &operator++(MyString &obj , int);			// Post-increment - adds an "O" at the end
	friend bool operator==(const MyString &lhs , const MyString &rhs);	// Equality
	friend bool operator!=(const MyString &lhs , const MyString &rhs);	// Inequality
	friend MyString operator+(const MyString &lhs , const MyString &rhs);	// Concatenate
	friend bool operator<(const MyString &lhs , const MyString &rhs);	// Less than - compare the length
	friend bool operator>(const MyString &lhs , const MyString &rhs);	// Greater than - compare the length


	public:

	MyString();				// No-args constructor
	MyString(const char *s);		// Overloaded constructor
	MyString(const MyString &source);	// Copy constructor
	MyString(MyString &&source);		// Move constructor
	~MyString();				// Destructor

	//Overloaded operators as class member functions
	MyString &operator=(const MyString &rhs);	// Copy assignment
	MyString &operator=(MyString &&rhs);		// Move assignment
	

	void display() const;			

	int get_length() const;			// Getters
	const char *get_str() const;


	private:

	char *str;				// Pointer to char[] that holds a C-Style string

};

#endif
