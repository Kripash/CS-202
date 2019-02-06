/*
kripash Shrestha
The purpose of this program is to create my own string class. This will be helpful for me as I will learn to allocate and deallocate objects.
proj5.cpp
*/

#include "MyString.cpp"



int main(){

 //test 1
 MyString ms_default(); 
 //test 2
 MyString ms_parametrized("MyString parametrized constructor!"); 
 //test 3
 MyString ms_copy(ms_parametrized); 
 //test 4 
 MyString* ms_Pt = new MyString("MyString to be deleted…"); 
 delete ms_Pt; 
 ms_Pt =NULL; 
 //test 5 and 6
 MyString ms_size_length("Size and length test"); 
 cout << ms_size_length.size() << endl; 
 cout << ms_size_length.length() << endl;
 //test 7 
 MyString ms_toCstring("C-String equivalent successfully obtained!"); 
 cout << ms_toCstring.c_str() << endl; 
 //test 8
 MyString ms_same1("The same"), ms_same2("The same"); 
 if (ms_same1==ms_same2)   
	cout << "Same success" << endl; 
 MyString ms_different("The same (NOT)"); 
 if (!(ms_same1==ms_different))   
	cout << "Different success" << endl;
 // test 9
 MyString ms_assign("Before assignment");
 ms_assign = MyString("After performing assignment");
 // test 10
 MyString ms_append1("The first part"); 
 MyString ms_append2(" and the second"); 
 MyString ms_concat = ms_append1+ ms_append2;
 //test 11
 MyString ms_access("Access successful (NOT)"); 
 ms_access[17] = 0;
 //test 12
 cout << ms_access << endl;

}




