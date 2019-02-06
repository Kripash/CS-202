//Author: Kripash Shrestha

#include <iostream>
#include "NodeQueue.h"
#include "ArrayQueue.h"

using namespace std;


int main(){

int value1 = 1;
int value2 = 2;
int value3 = 3;


ArrayQueue<int>* invalid = new ArrayQueue<int>;
ArrayQueue<int> valid_value1(5,value1);


//default ctor test for ArrayQueue
cout << endl << "ARRAYQUEUE TEST!" << endl <<endl << "Default Ctor Test" << endl;
cout << *invalid << endl;
//param ctor test for ArrayQueue
cout << "Param Ctor Test" << endl;
cout << valid_value1 << endl;
 //copy ctor test for ArrayQueue, copies param ctor
cout << "Copy Ctor Test" << endl;
ArrayQueue<int> copy(valid_value1);
cout << copy << endl;
//overloaded = operator test for ArrayQueue, = the copied object
cout << "Overloaded = Operator Test" << endl;
ArrayQueue<int> equal;
equal = copy;
cout << equal << endl; 
//Creates a queue of 1000 size. 
cout << "Creating a max queue!" << endl;
ArrayQueue<int> Max(1000,value1);
//should issue a warning to the terminal saying the array is full and cannot be pushed
cout << "Trying to push a full queue!" << endl;
Max.push(value1);
//leaves one element in the queue
cout << "Popping 999 elements from the array!" << endl;
for(int i = 0; i < ARRAY_MAX-1; i++){
Max.pop();
}
//puses value2
cout << Max << endl;
cout << "Pushing value2" << endl;
Max.push(value2);
cout << Max << endl;
//pushes value 3
cout << "Pushing value3" << endl;
Max.push(value3);
cout << Max << endl;

//another queue test that will be deleted later , should be empty at first.
cout << "Invalid Array Queue Test (Will be deleted)" << endl;
//issues warning to terminal saying that the array is empty and cannot be printed
cout << *invalid << endl;
//puses value1
cout << "Pushing value1" << endl;
invalid -> push(value1);
cout << *invalid << endl;
//pushes value2
cout << "Pushing value2" << endl;
invalid -> push(value2);
cout << *invalid << endl;
//pushes value3
cout << "Pushing value3" << endl;
invalid -> push(value3);
cout << *invalid << endl;
//pops the first element
cout << "Popping" << endl;
invalid -> pop();
cout << *invalid << endl;
//pops again
cout << "Popping" << endl;
invalid -> pop();
cout << *invalid << endl;
//copies the array of invalid and then prints it
cout << "Copy Ctor Test" << endl;
copy = *invalid;
cout << copy << endl;
//clears the copied object
cout << "Clearing the copied object!" << endl;
copy.clear();
//tries to pring the cleared object, should issue warning
cout << "Trying to print the invalid array after it has been cleared!" << endl;
cout << "Array Size: " << copy.size() << "\n";
cout << "Is the array empty? " << boolalpha << copy.empty() << endl;
cout << copy << endl;
//pops the remaining data from the invalid object
invalid -> pop();
//tries to print the empty object, should issue warning.
cout << "Trying to print the invalid array after it has been emptied!" << endl;
cout << "Array Size: " << invalid -> size() << "\n";
cout << "Is the array empty? " << boolalpha << invalid -> empty() << endl;
//tries to pop an empty queue, should issue warning
invalid -> pop();
cout << *invalid << endl;
//deletes the empty queue
delete invalid;

//Test for the nodequeue
cout << endl << endl << endl;
cout << "NODEQUEUE TEST!" << endl << endl;
//default ctor
NodeQueue<int>  test;
NodeQueue<int>  param (3,value1);
NodeQueue<int>  Size1 (1, value1);
//param ctor test
cout << "Param Constructor" << endl;
cout << param << endl;
NodeQueue<int>  copyctor(param);
//copies the param ctor
cout << "Copy Constructor" << endl;
cout << copyctor << endl;
//= overloaded operator test, = the copied object
NodeQueue<int>  equalctor = copyctor;
cout << "Overloaded Equal Operator" << endl;
cout << equalctor << endl;
//pushing queue for value2
cout << "Pushing elements at the back!" << endl;
equalctor.push(value2);
cout << equalctor << endl;
//pushing queue for value3
equalctor.push(value3);
cout << equalctor << endl;
//popping elements (pops twice)
cout << "Popping elements from the front!" << endl;
equalctor.pop();
cout << equalctor << endl;
equalctor.pop();
cout << equalctor << endl;
//uses = operator to create the copied object. should be completely emptied after popped
cout << "Popping elements to completely remove!" << endl;
Size1 = equalctor;
cout << Size1 << endl;
Size1.pop();
cout << Size1 << endl;
Size1.pop();
cout << Size1;
Size1.pop();
Size1.pop();
cout << Size1 << endl;

//should issue warning for trying to pop an empty list
cout << endl << "Trying to pop an empty list!" << endl;
test.pop();
//pushes a list that is empty.
cout << "Now the list will be pushed!" << endl;
//push value1
test.push(value1);
cout << test << endl;
//push value2
test.push(value2);
cout << test << endl;
//size of the modified list, should be 2. and is false, the list is not empty.
cout << "The size of the list you just tried to pop is: " << test.size() << endl;
cout << "Is the current list empty? " << boolalpha << test.empty() << endl;


cout << endl << "Clearing the equalctor that has been printed below!" << endl;
//clears the object. size should be 0 and should be true since list is empty.
cout << equalctor << endl;
equalctor.clear();
cout << "Clearing the equalctor list!" << endl;
cout << "The size of the list is: " << equalctor.size() << endl;
cout << "Is the current list empty? " << boolalpha << equalctor.empty() << endl;;

//Size1 list that was emptied through pop earlier, should print out the size to be 0, and should be true since the list is empty. 
cout << endl << "Trying to print out an empty list (Size1 list)!" << endl;
cout << "The size of the list is: " << Size1.size() << endl;
cout << "Is the current list empty? " << boolalpha << Size1.empty() << endl;
//checks size of an object that has size 3.
cout << endl << "Checking size of the copyctor list (should not be empty)!" << endl;
cout << "The size of the list is: " << copyctor.size() << endl;
cout << "Is the current list empty? " << boolalpha << copyctor.empty() << endl;
cout << copyctor << endl;




return 0;
}

