//author: Kripash Shrestha

#include "MyString.h"

//buffer deallocate function that will set the member m_size of an object to 0 and then delete the member m_buffer and then point the m_buffer to NULL. 
void MyString::buffer_deallocate(){
	
	if(m_buffer != NULL){
	m_size = 0;
	delete [] m_buffer;
	m_buffer = NULL; 
	}	
}

//buffer allocate function that will check if the m_buffer meber is not null. It it is not null, the buffer allocate will call buffer_deallocate to make sure that the member m_buffer is NULL. Then then m_size will be updated to the passed parameter of the function and the member m_buffer will be allocated to the size of the passed parameter.
void MyString::buffer_allocate(int size){
	
	if(m_buffer != NULL){
	       buffer_deallocate();
	}	
	m_size = size;	
	m_buffer = new char [m_size];
}

//Default Constructor of the class MyString.Sets member m_size to 0 and the member m_buffer to NULL.
MyString::MyString(){
      
	m_size = 0;
	m_buffer = NULL;
	
}

//paramterized constructor of the class MyString.Sets the member m_buffer to NULL at the beginning then uses my string length function to get the length of the string that is passed and assigns the value to member m_size. Then allocates member equal to the string length for m_buffer and uses my string copy function to copy the string to m_buffer.
MyString::MyString(const char* str){

	m_buffer = NULL;
	m_size = mystrlen(str);
	m_buffer = new char[m_size];
	mycopystring(m_buffer,str);
				
}

//copy constructor of the class MyString. Sets m_buffer to NUll. Gets m_size from the object passed and then assigns it to the new objects m_size. Then allocates m_buffer for the new object my using the size. Lastly, it uses the copy string function to copy the string from the object passed to the new object's m_buffer.
MyString::MyString(const MyString& other_myStr){

	m_buffer = NULL;
	m_size = other_myStr.m_size; 
	buffer_allocate(other_myStr.m_size);
	mycopystring(m_buffer, other_myStr.m_buffer);
	
}

//destructor of the class MyString which will call the buffer_deallocate to destroy the instance of the object and deallocate memory.  
MyString::~MyString(){

	buffer_deallocate();
	
}

// returns the size of the allocated memory by making the local function assign equal to the member m_size and then returns size.
int MyString::size()const{

	int size = m_size;
	return size; 
}

//Assigns the size of the the member m_size to the variable size. If the allocated size is greater than 0, it subtracts one, because there is a null terminator with each string to get the length of the string. If size is equal to 0, then it just returns the size as 0.
int MyString::length()const{

	int size = m_size; 
	if (size > 0){
	size = size - 1;
	}
	return size;
}
//returns the member m_buffer because it is a pointer to a char array of MyString's object data.
const char* MyString::c_str() const{

	return m_buffer;
}

//overloaded << operator that will out stream the object that is passed to the function.More specifically by using the c_str function above.
ostream& operator<< (ostream& os, const MyString& myStr){

	os << myStr.c_str();
}

//overloaded == operator that will use my compare string function to check if the string of the object passed and the object are the same. If they are the same, the function will return true, else it will return false.
bool MyString::operator== (const MyString& other_myStr) const{

	int check;
	
	check = mycompare_string(other_myStr.m_buffer,this -> m_buffer);
	if(check == 0){
	   return true;
	}
	else{
	    return false;    
	}
}

//overloaded = opreator that will copy the string from the object passed to the object. It will make sure that the object's m_buffer is NULL first. Then it will allocate memory equal to the size of the passed object by using m_size. Then it will use my copy string function to copy the string from the passed object's m_buffer to the object's m_buffer. Lastly it will copy the m_size of the passed object's to the object. The function will return the pointer this.
MyString& MyString::operator= (const MyString& other_myStr){

	if ( m_buffer != NULL){
	delete [] m_buffer;
	}
	m_buffer = new char [other_myStr.m_size];
	mycopystring(m_buffer,other_myStr.m_buffer);
	m_size = other_myStr.m_size;
	
	
	return *this; 
}

// overloaded + operator that will concatenate two strings. It will use my string conctenate function to concatenate two strings by using their source and size lengths. The function will add the lengths and assign it to a local variable. The function will then call buffer_allocate function to allocate memory for the new buffer and assign the value of m_size. Then the function will call my copy string function to copy the string concatenated string to the object's string. It will delete the pointer used to hold t he concatenate function and assign it to NULL. The function will return this. 
MyString& MyString::operator+ (const MyString& other_myStr){

	char* cat = mystringcat(m_buffer, other_myStr.m_buffer, length(), other_myStr.size());
	int size = length() + other_myStr.size(); 
	buffer_allocate(size);
	mycopystring(m_buffer, cat);
	
	delete [] cat;
	cat = NULL;

	return *this; 
}

//overloaded [] operator that will access the specific character form the index position passed into the function. It uses brackets to get to the position and then returns that character.
char& MyString::operator[] (int position){

	int i = 0;
	while(i < position){
	      i++;
	}
	return m_buffer[i];
}








