//author: Kripash Shrestha

#include <iostream>
using namespace std;

//My string length function to be used for the size and length functions/ portion of the project.
int mystrlen(const char* source){

      int c = 0;
      while(*source!='\0'){
	   c++;
	   *source++;
      }
      return c + 1;
}
	
//My copy string function to be used to copy the string from a const source to a destination. Used in multiple functions such as copy constructor and parameterized constructor to copy the value from source to m_buffer.
void mycopystring(char * destination, const char * source) {

    while (*source) {
      *destination = *source;
      source++;
      destination++;
   }
   *destination = '\0';
}

//My compare string function that will be used in the == overloaded operator function to check if two strings are equal. If they are equal, the function will return 0, if they are not equal, the function will return -1;
int mycompare_string(char *first, char *second) {
   while (*first == *second) {
      if (*first == '\0' || *second == '\0')
         break;
 
      first++;
      second++;
     }
 
   if (*first == '\0' && *second == '\0')
      return 0;
   else
      return -1;
}

//my string concatenate function that will take the source of two strings and their lengths and then concatenate the two strings using brackets. The function will return a pointer to the newly concatenated string.
char* mystringcat(const char * first, const char * second, int size1, int size2){
   
   int size = size1 + size2;
   char * cat =  new char [size];
   int i = 0;
   for( i = 0; i < size1; i++){
      cat[i] = first[i];
   }  
   
   int j = i;
   for( i = 0; i < size2; i++, j++){
        cat[j] = second[i];
   }
  
   cat[j+1] = '\0';
   cout << cat << endl;
   
   return cat;
   
}



class MyString{

    public:
      MyString();
      MyString(const char* str);
      MyString(const MyString& other_myStr);
      ~MyString();

      int size() const;
      int length() const;
      const char* c_str() const;
      
      bool operator== (const MyString& other_myStr) const;
      MyString& operator= (const MyString& other_myStr);
      MyString& operator+ (const MyString& other_myStr);
      char& operator[] (int position);

friend ostream& operator<< (ostream& os, const MyString& myStr);
      
    private: 
      void buffer_deallocate();
      void buffer_allocate(int size);

      char *m_buffer;
      int m_size;
};
 
