//author: Kripash Shrestha

#include "NodeList.h"
#include <iostream>
using namespace std;

/*
Default constructor for the NodeList class, that intializes m_head to null.
*/
NodeList::NodeList(){
	
	m_head = NULL;
}

/*
Parameterized constructor for the NodeList class, that intializes nodes equal to the size and sets the data for each node to be equal to passed parameter known as value. Each node's m_next will point to the next node, until the loop stops and then the last node's m_next will be set to NULL.
*/
NodeList::NodeList(int size, const DataType& value){

	m_head = new Node(value);
	Node * duplicate = m_head;
	for(int i = 0; i < size - 1; i++){
	    Node * holder = new Node(value);
	    duplicate -> m_next = holder;
	    duplicate = holder;
	}
	duplicate -> m_next = NULL;
}

/*
Copy constructor for the NodeList class.Checks that the nodelist being passed is valid and then copies the data of each single node to newly created nodes. The nodes will be linked together to create a nodelist. Each node's m_next will point to the next node, until the loop stops and then the last node's m_next will be set to NULL.
*/
NodeList::NodeList(const NodeList& other){

	Node * other_current = other.m_head;
	Node * head_ptr;
	Node * previous;


	if (other_current != NULL) {
		m_head = new Node(other_current -> m_data);		
		previous = m_head;
		
		//cout << other_current -> getData() << "\n";
		while(other_current != NULL){
	
			if(other_current -> getNext() != NULL)  {
				other_current = other_current -> getNext();
				head_ptr = new Node(other_current -> m_data);
				previous -> setNext(head_ptr);	
				previous = head_ptr;
			}   else {
				break;
			}
			
		}
	}
	
	
}


/*
Destructor for the NodeList class. It will go through every single node and delete the node. Before deleting the node it is pointing, it will temporarly point to the next node in the nodelist and then delete the current node and then move to the next node. It will do this until there is nothing else to be deleted.
*/
NodeList::~NodeList(){

	Node * temp;
	temp = m_head;
	Node * holder;
	while(temp != NULL){
	     holder = temp -> m_next;
	     delete temp;
	     temp = holder;
	}
}

/*
Operator = function for the NodeList class. The function wil take a nodeList as the parameter argument and then copy the data of the passed nodelist to the newly created NodeList. The nodes will be linked together to create a nodelist. Each node's m_next will point to the next node, until the loop stops and then the last node's m_next will be set to NULL. The algorithm and method is a duplicate of the copy constructor.
*/
NodeList& NodeList::operator= (const NodeList& other_nodeList){
	
	Node * other_current = other_nodeList.m_head;
	Node * head_ptr;
	Node * previous;

	if (other_current != NULL) {
		m_head = new Node(other_current -> m_data);		
		previous = m_head;
		
		//cout << other_current -> getData() << "\n";
		while(other_current != NULL){
	
			if(other_current -> getNext() != NULL)  {
				other_current = other_current -> getNext();
				head_ptr = new Node(other_current -> m_data);
				previous -> setNext(head_ptr);	
				previous = head_ptr;
			} else {
				break;
			}
			
		}
	}
	
	return *this;
}

/*
Operator << overloaded friend function. The function will take the arguments os and the nodelist that will be printed to the screen. The nodelist will use the getData() function of the NodeList class to get the data of the current node and put it to the stream. Then the variable temp will use the getNext() function to access the next node in the list.
*/
std::ostream& operator << (std::ostream& os, const NodeList& nodeList){

	Node * temp;
	temp = nodeList.m_head;
	
	while(temp!= NULL){

	     os << temp -> getData() << "\n";
	   
	     temp = temp -> getNext();
	}
	return os;
}

/*
First function of the NodeList class. This function checks to see if m_head of the nodelist is null or not. If m_head is null, the function returns null, else it returns the Node m_head; 
*/
Node * NodeList::first(){
	if(m_head !=NULL){
	return m_head;
	}
	else{
	return NULL;
	}
}

/*
First function of the NodeList class. This function checks to see if m_head of the nodelist is null or not. If m_head is null, the function returns null, else it returns the Node m_head; 
*/
const Node * NodeList::first() const{

	if(m_head !=NULL){
	return m_head;
	}
	else{
	return NULL;
	}
}

/*
Last function of the NodeList class. This function constantly checks to see if the current node is valid or not. The function runs until it finds a node that has a member m_next pointing to null. The function will then returns the Node that it stops on or it returns null if the entire node list is not valid.
*/
Node * NodeList::last(){
	
	Node * current = m_head;

	while(current != NULL){

		if(current -> getNext() != NULL){
		   current = current -> getNext();
		}  
		else{
		    return current;
		}     
	}

	return NULL;
}

/*
Last function of the NodeList class. This function constantly checks to see if the current node is valid or not. The function runs until it finds a node that has a member m_next pointing to null. The function will then returns the Node that it stops on or it returns null if the entire node list is not valid.
*/
const Node * NodeList::last() const{

	Node * current = m_head;

	while(current != NULL){

		if(current -> getNext() != NULL){
		   current = current -> getNext();
		}  
		else{
		    return current;
		}     
	}

	return NULL;
}

/*
This is the find function of the NodeList class. This function will take in parameters of a DataType target, a Node pointer and a const Node pointer start. Because the third parameter was extra functionality, i have ignored that part for the algorithm. The function will check to see if the target is valid, if it is null, the function will return null and set previous to null. The function will check if the first node contains the DataTpe target, and then will return the first node and set previous to null. If none of those logics are true, the function will then continue to find a node element that matches the DataType and then return that node element. The previous node will be continuously updated to the node that is before the currently tested node.
*/
Node* NodeList::find(const DataType& target, Node* &previous, const Node* const start){

	Node * current = m_head;

	 
	
	if(current == NULL){
	   previous = NULL;
	   return NULL;
	}
	
	if(current -> getData() == target){
	   
	   previous = NULL;
	   return current;	
	}
	else{

	     while(current != NULL){
		if(current -> getData() == target){
		   return current;   
		} 
		previous = current;
	     	current = current -> getNext();
		continue;
		
	     }
	}
	
	return NULL;
}

/*
This is the find function of the NodeList class. This function will take in parameters of a DataType target, a Node pointer and a const Node pointer start. Because the third parameter was extra functionality, i have ignored that part for the algorithm. The function will check to see if the target is valid, if it is null, the function will return null and set previous to null. The function will check if the first node contains the DataTpe target, and then will return the first node and set previous to null. If none of those logics are true, the function will then continue to find a node element that matches the DataType and then return that node element. The previous node will be continuously updated to the node that is before the currently tested node.
*/
const Node* NodeList::find(const DataType& target, const Node* &previous, const Node* const start) const {

	Node * current = m_head;
	
	if(current == NULL){
	   previous = NULL;
	   return NULL;
	}
	
	if(current -> getData() == target){
	   
	   previous = NULL;
	   return current;	
	}
	else{

	     while(current != NULL){
		if(current -> getData() == target){
		   return current;  
		} 
		previous = current;
	     	current = current -> getNext();
		continue;
		
	     }
	}
	
	return NULL;
}

/*
This is the insertAfter function of the NodeList class. This function will take in parameters of a DataType target, a DataType value and a int count. Because the third parameter was extra functionality, i have ignored that part for the algorithm. The function will check to see if the target is valid, if it is null, the function will return null and set previous to null. The function will then continue to find a node element that matches the DataType and then a new node will be created. The current node's m_next member will be stored in the newly created node's m_next member variable. The new node's memory address will be stored in the current node's m_next member. The Data for the new node created will be the same as the second passed parameter value. The function will return the node it inserted or NULL if it has failed.
*/
Node* NodeList::insertAfter(const DataType& target, const DataType& value, int count ){

	Node * current = m_head;

	if(current == NULL){
	   return NULL;
	}
	while(current != NULL){

	    if((current -> getData()) == target){
		Node * temporary = new Node(value);
		
		temporary->setNext( current -> getNext() );
		current -> setNext(temporary);
		return temporary;
 	    }

	   current = current -> getNext();


	} 

	return NULL;
}

/*
This is the insertBefore function of the NodeList class. This function will take in parameters of a DataType target, a DataType value and a int count. Because the third parameter was extra functionality, i have ignored that part for the algorithm. The function will check to see if the target is valid, if it is null, the function will return null and set previous to null. The function will then continue to find a node element that matches the DataType and then a new node will be created. The current node's address will be stored in the  newly created node's m_next member variable. The new node's memory address will be stored in the previous node's m_next member. The Data for the new node created will be the same as the second passed parameter value. The function will return the node it inserted or NULL if it has failed.
*/
Node* NodeList::insertBefore(const DataType& target, const DataType& value, int count ){


	
	if(m_head == NULL){
	   return NULL;
	}

	Node * current = m_head;

	if((m_head -> getData()) == target){
	
	    Node * temporary = new Node(value);
	    temporary -> m_next = current;
	    m_head = temporary;
	    return temporary; 

	}

	else{
	    
	     for(int i = 0; i < size(); i++){

		 if(current -> m_next -> getData() == target){
			
			Node * temporary = new Node(value);
			temporary -> m_next = current -> m_next;
			current -> m_next = temporary;
			return temporary;   
		 }
		current = current -> m_next;
	     }
	    		
	}
	return NULL;
}

/*
This is the rremoveForward function of the NodeList class. This function will take in parameters of a DataType target and a int count. Because the secondparameter was extra functionality, i have ignored that part for the algorithm. The function will check to see if the target is valid, if it is null, the function will return null and set previous to null. The function will then continue to find a node element that matches the DataType and then stores the value of the found node's m_next to a variable. The function will then delete the found node and then replace the previous node's m_next member with the m_next member variable of the deleted node. If the first node is the target node, the function will delete that node and then set the next node as the m_head of the node and return the new node. The function will return the node that was after the node that was removed. If the node removed was the last of the list, the function will return NULL.
*/
Node * NodeList::removeForward(const DataType& target, int count){

	Node * current = m_head;
	if(m_head == NULL){
	   return NULL;
	}

	if((m_head -> getData()) == target){
	
	   Node * temporary = m_head -> m_next;
	   delete current;
	   m_head = temporary; 
	   return m_head;
	
	}
	    	
	for(int i = 0; i < size(); i++){

	    if(current -> m_next -> getData() == target){
		
		Node * temporary = current -> m_next -> m_next;
	    	delete current -> m_next;
	    	current -> m_next = temporary;
	    	if(temporary == NULL){
			return NULL;
	        }
		return temporary;
	   }
	   
		
	    current = current -> m_next;
	}
	    		
	
	return NULL;
}

/*
This is the removeBackward function of the NodeList class. This function will take in parameters of a DataType target and a int count. Because the second parameter was extra functionality, i have ignored that part for the algorithm. The function will check to see if the target is valid, if it is null, the function will return null and set previous to null. The function will then continue to find a node element that matches the DataType and then stores the value of the found node's m_next to a variable. The function will then delete the found node and then replace the previous node's m_next member with the m_next member variable of the deleted node. If the first node is the target node, the function will delete that node and then set the next node as the m_head of the node and return the new node. The function will return the node that was after the node that was removed. If the node removed was the last of the list, the function will return NULL.
*/
Node * NodeList::removeBackward(const DataType& target, int count){

	Node * current = m_head;
	
	if((m_head -> getData()) == target){
	
	   Node * temporary = current -> m_next;
	   delete current;
	   m_head = temporary; 
	   return NULL;
	
	}
	for(int i = 0; i < size(); i++){

	    if(current -> m_next -> getData() == target){
		
		Node * temporary = current -> m_next -> m_next;
	    	delete current -> m_next;
	    	current -> m_next = temporary;
		return current;
	   }
	    current = current -> m_next;
	}
	
	return NULL;

}

/*
Operator [] function for the NodeList class. The function will take a position as the parameter. The function will loop the amount of times equal to the position and update the current node until the loop stops. Then the function will return the DataType of the node by using the getData function. 
*/
DataType& NodeList:: operator[](int position){
	
	Node * current = m_head;
	int counter;
	for(counter = 0; counter < position; ++counter){
	    current = current -> m_next;
	}
	return (current -> getData());
}

/*
Operator [] function for the NodeList class. The function will take a position as the parameter. The function will loop the amount of times equal to the position and update the current node until the loop stops. Then the function will return the DataType of the node by using the getData function. 
*/
const DataType& NodeList:: operator[](int position) const {

	Node * current = m_head;
	int counter;
	for(counter = 0; counter < position; ++counter){
	    current = current -> m_next;
	}
	return (current -> getData());

}

/*
This the size function of the NodeList Class. The function will find the size of the object NodeList. The function will loop until it reaches a node that has it's m_next member variable equal to null. This signifies that it is the end of the node list and then it will return the counter that has been incremented every single loop to return the size of the nodelist. 
*/
int NodeList::size() const{

	Node * current = m_head;
	int counter = 0;
	while(current != NULL){
	
 	      counter++;
	      if(current -> getNext() != NULL){
		  current = current -> getNext();
		  
	      }
	      else{
		   break;
	      }

	}
	return counter;
}

/*
This the clear function of the NodeList Class. The function will temporarily hold the m_next member variable of m_head and delete m_head and set it to null. the function will then loop through to each node and increment to each node's m_next member variable until it is null and delete every node. The function does not return anything. 
*/
void NodeList::clear(){

	
	Node * temp;
	temp = m_head;
	Node * holder;
	
	if(m_head -> getNext() == NULL){
	    delete m_head;
	}
	else{
	
	    /*cout << "head delete" << endl;
	    holder = temp -> getNext();
	    cout << temp << endl;
	    cout << holder << endl;
	    delete temp;
	    //m_head = NULL;
	    temp = holder;
	    cout << temp << endl;*/
	    
	    temp = m_head->getNext();
	    delete m_head;
	    m_head = NULL;
	}
	  
	while(temp != NULL){
	     holder = temp -> getNext();
	     //temp -> setNext(NULL); 
	     delete temp;
	     temp = holder;	     	     
	}
		
	/*if (m_head == NULL){	
	   cout << "The list has been cleared!" << endl;
	}
	else{
	   cout << "The list did not get cleared!" << endl;
	}*/
}

/*
This the empty function of the NodeList Class. The function will check to see if the nodelist is empty or not. The function will check the m_head of the nodeList to check if it is null or not to figure out if the list is null or not. If m_head is null, the function will return true, else it will return false.
*/
bool NodeList::empty() const{

	if(m_head == NULL){
	   return true;	
	}
        else{
	   return false;
	}


}






























