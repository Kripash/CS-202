//author: Kripash Shrestha
//The objective of this project is to test my ability to create and use Array Lists and NodeLists dynamic structures. I will need to be able to manipulate list-based dynamic data structures, classes, pointers, and iostream to all extents.

#include <iostream>

#include "ArrayList.h"
#include "NodeList.h"

using namespace std;

int main(){

  //Test Driver Code
  cout << endl << endl << endl;
  cout << "ARRAY LIST TEST" << endl;

  //intialized the DataTypes for the test driver by using the param ctor.
  cout << "DataType Intialize" << endl;
  DataType temporary(1, 1.1 );
  DataType value(2,2.2);
  DataType value2(3,3.3);
  DataType value3(4,4.4);
  DataType value4(5,5.5);

  DataType invalid;
  DataType *ptr;

  //Calls the default ctor of ArrayList for the ArrayList test.
  cout << endl;
  cout << "Default Ctor" << endl;
  ArrayList test;
  cout << test << endl;

  //Calls the param ctor of ArrayList for the ArrayList holder and creates of size 1 and of DataType temporary.
  cout << "Param Ctor" << endl;
  ArrayList holder(1,temporary);
  cout << holder << endl;

  //Calls the copy constructor of ArrayList for the new object called copy and copies from the object holder.
  cout << endl << "Copy Constructor" << endl;
  ArrayList copy(holder);
  cout << copy << endl;

  //Calls the overloaded = operator of ArrayList for the object test and assigns it from the object holder.
  test = holder;
  cout << endl << "Overloaded = Operator" << endl;
  cout << test << endl;

  //Calls the default ctor of ArrayList for the object called test.
  cout << endl << "Default Ctor" << endl;
  ArrayList fail;
  cout << fail << endl;

  //Calls the insertAfter function to insert the DataType value2 after the target temporary and the DataType value4 after the target value2.
  cout << endl << "Insert After Test." << endl;
  ptr =holder.insertAfter(temporary,value2);
  cout << holder << "\n" << *ptr << "  was added.\n"<< endl;
  ptr = holder.insertAfter(value2,value4);
  cout << holder << "\n" << *ptr << " was added.\n"<< endl;

  //Calls the insertBefore function to insert the DataType value before the target value2 and the DataType value3 before the target value4.
  cout << endl << "Insert Before Test." << endl;
  ptr = holder.insertBefore(value2,value);
  cout << holder << "\n" << *ptr << " was added.\n"<< endl;
  ptr = holder.insertBefore(value4,value3);
  cout << holder << "\n" << *ptr << " was added.\n"<< endl;

  //Calls the removeforward function to remove the DataType target value3 from the arraylist holder.
  cout << endl << "Remove Forward Test" << endl;
  cout << "getting rid of {4,4.4}." << endl;
  ptr = holder.removeForward(value3);
  cout << holder << endl;
  //Calls the removeBackward function to remove the DataType target value2 from the arraylist holder.
  cout << endl << "Remove Backward Test" << endl;
  cout  << "getting rid of {3,3.3}." << endl;
  ptr = holder.removeBackward(value2);
  cout << holder << endl;

  //Calls the copy constructor of ArrayList for the new object called copy2 and copies from the object holder.
  cout << endl << "copy constructor" << endl;
  ArrayList copy2(holder);
  cout << copy2 << endl;

  //Calls the overloaded = operator of ArrayList for the object test and assigns it from the object holder.
  test = holder;
  cout << endl << "overloaded = operator" << endl;
  cout << test << endl;

  //Calls the first and last functions to find the first and last elements of the arraylist holder.
  cout << endl << "First and Last test" << endl;
  cout << "The first element is: " << *holder.first() << endl;
  cout << "The last element is: " << *holder.last() << endl;


  //Calls the find function for the DataType target value and checks if the return pointer and previous pointer are null or not.
  cout << endl << "Find Test" << endl;
  DataType *previous = NULL;


  ptr = holder.find(value, previous,NULL);
  if(ptr != NULL){
	cout << "Target is not null." << endl;
  }
  else {
	cout << "Target is null." << endl;
  }
  if(previous != NULL){
	cout << "Previous is not null." << endl;
  }
  else {
	cout << "Previous is null." << endl;
  }

  //Calls the clear function from ArrayList class to clear the object that was coped.
  cout << endl << "Clear test" << endl;
  copy.clear();

  // Calls the empty function to check if the objects fail and holder are empty. Fail should be empty and holder should not be empty.
  cout << endl << "Is the object fail empty?: ";
  cout << boolalpha << fail.empty();
  cout << endl << "Is the object holder empty?: ";
  cout << boolalpha <<  holder.empty() << endl;

  //Calls the empty function to check the size of the object fail and holder.
   cout << endl << "Size of the fail list: ";
  cout << fail.size();
  cout << endl << "Size of the holder list: ";
  cout << holder.size() << endl;

  //Calls the overloaded [] operator to find the 3rd element in the holer object.
  cout << "The third element of the list is now: " << holder[2] << endl;

  //test Driver for the NodeList
  cout << endl << endl << endl;
  cout << "NODE LIST TEST" << endl;
  cout << endl;
  //Calls the default ctor for the NodeList object nodeList.
  NodeList nodeList;
  //Calls the param ctor for the NodeList object nodeList2, for a size of 1 and of DataType values temporary.
  cout << "Param CTOR" << endl;
  NodeList nodeList2(1, temporary);
  cout << nodeList2 << endl;
  //calls the copy ctor for the NodeList object copyctor and copies it from nodeList2.
  cout << endl << "COPY CTOR" << endl;
  NodeList copyctor(nodeList2);
  cout << copyctor << endl;
  //calls the overloaded = operator for the NodeList object equal and assigns it from nodeList2.
  cout << endl << "Equal Operator" << endl;
  NodeList equal;
  equal = nodeList2;
  cout << equal << endl;

  //Calls the insertAfter function to add the DataTypes value 4 and value2 after the target DataType temporary is found.
  cout << endl << "INSERT AFTER" << endl;
  equal.insertAfter(temporary, value4);
  equal.insertAfter(temporary,value2);
  cout << equal << endl << value2 << " and " << value4 << " was added." << endl;

  //Calls the insertBefore function to add the DataTypes value before the target value2 and the DataType value3 before the target value4.
  cout << endl << "INSERT BEFORE" << endl;
  equal.insertBefore(value2,value);
  equal.insertBefore(value4,value3);
  cout << equal << endl << value << " and " << value3 << " was added." << endl;

  //Calls the first and last function to find the first and last element to print out the memory address of the first and last element of the NodeList object equal.
  cout << endl << "The memory address of the first element is: ";
  Node * first = equal.first();
  Node * last = equal.last();
  cout << first;
  cout << endl << "The memory address of the last element is: ";
  cout << last << endl;

  //Calls the find function to find the memory addresses of the DataTypes value4 and value2 from the NodeList object equal.
  cout << endl << "FIND TEST" << endl;
  Node * prev_holder = NULL;
  cout << equal.find(value4, prev_holder,NULL) << " found " << value4 << endl;
  cout << equal.find(value2, prev_holder,NULL) << " found " << value2 << endl;

  //Calls the size function from the NodeList object to find the size of the NodeList object equal.
  cout << endl << "Size Test" << endl;
  cout << "The list size is now: " << equal.size() << endl;

  //Calls the overloaded [] operator to find the 3rd element in the NodeList object equal.
  cout << endl << "The 3rd node is: " << endl;
  cout << equal[2] << endl;

  //Calls the remove forward function to remove the DataType value from the NodeList object equal.
  cout << endl << "Removing elements!" << endl << endl;
  equal.removeForward(value);
  cout << equal;

  //Calls the remove backward function to remove the DataType value3 from the NodeList object equal.
  cout << endl << value << " was removed." << endl << endl;
  equal.removeBackward(value3);
  cout << equal;
  cout << endl << value3 << " was removed." << endl << endl;

  //Calls the size function from the NodeList class to find the size of the NodeList object equal.
  cout << "The list size is now: " << equal.size() << endl;

  //Calls the clear function from the NodeList class to clear the NodeList for the NodeList object equal.
  cout << endl << "Clear Test" << endl;
  equal.clear();
  cout << equal;

  //Calls the size function from the NodeList class to find the size of the NodeList object equal.
  cout << "The size of the list after being cleared is: ";
  cout << equal.size() << endl;

  //calls the empty test to find out whether the clear test worked or not to see if the NodeList object equal is empty or not.
  cout << endl << "Empty test" << endl << "Is the list empty? " <<boolalpha << equal.empty() << endl << endl;





  return 0;


}
