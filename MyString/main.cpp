#include <iostream>
#include "MyString.h"
#include <vector>


int main() 
{
	// Copy and move assignment
	/*MyString a {"Hello"};              
	MyString b;                             
	b = a;      

	a.display();
	b.display();

	b = "This is a test";    
	b.display();

	MyString empty;                      
   	MyString larry("Larry");          
    	MyString stooge {larry};             
    	MyString stooges;   

	empty.display(); 

	empty = stooge;     
	stooges = "This is another test.";          
    
    	empty.display();             
    	larry.display();                      
    	stooge.display();       
	stooges.display();	*/  


	
	//Test with vector and move constructor
	/*std::vector<MyString> stooges_vec;
    	stooges_vec.push_back("Larry");        	// Move constructor
    	stooges_vec.push_back("Moe");		// Move constructor
    	stooges_vec.push_back("Curly");       	// Move constructor     

	std::cout << "=== Loop 1 ==================" << std::endl;
    	for (const MyString &s: stooges_vec) 
       		s.display();
        
    	std::cout << "=== Loop 2 ==================" << std::endl;
    	for (MyString &s: stooges_vec)
        	s = "Changed";           	// move assignment
        
   	std::cout << "=== Loop 3 ==================" << std::endl;
    	for (const MyString &s: stooges_vec) 
        	s.display();      */       

	// Test with negation operator
	/*MyString a{"HoLa a ToDoS"};
	a.display();
	MyString b;
	b = -a;
	b.display();     */

	// Test with pre and post operators
	/*MyString a{"This is a test"};
	a.display();
	MyString b{"This is another test"};
	b.display();
	MyString c;
	a++;
	a.display();
	++b;
	b.display();*/

	//Testing equality and inequality
	/*MyString a{"Hello"};
	MyString b{"Bye"};
	MyString c{a};

	std::cout << boolalpha << std::endl;
	std::cout << (a == b) << std::endl;
	std::cout << (a == c) << std::endl;*/

	//Testing with concatenate operators
	/*MyString first("Hola ");
	MyString second("a todos ");
	first = first + second + "los visitantes";
	first.display();*/

	// Testing compare operators
	/*MyString x("Small string");
	MyString y("This is a larger string");

	std::cout << std::boolalpha << std::endl;
	std::cout << (x < y) << std::endl;
	std::cout << (x > y) << std::endl;
	std::cout << (x > y) << std::endl;
	std::cout << (x < y) << std::endl;*/

	// Testing the insertion and extractor operator
	/*MyString a("Hello");
	std::cout << a << std::endl;
	std::cout << "Say hello in spanish: ";
	std::cin >> a;
	std::cout << "\nHello in spanish is: " << a << std::endl;*/

	return 0;  
}
