//Author: Kripash Shrestha

#include <iostream> 
using namespace std;

template <class T> class NodeQueue;
template < class T>
class Node{
   public: 
	//Default ctor for Node class.
	Node(){
	   m_next = NULL;
	}
	//Paramterized ctor for Node class.
	Node(const T& data, Node<T>* next = NULL){
	   m_next = next;
	   m_data = data;
	}
	//getData function for Node class that returns the member m_data;
	T& getData(){
	   return m_data;
	}
	//getData function for Node class that returns the member m_data;
	const T& getData() const{
	   return m_data;
	}
	//friend class for this class, allows access of private members;
	friend class NodeQueue<T>;

   private: 
	Node<T>* m_next;
	T m_data; 
};

template <class T> class Node;
template < class T>
class NodeQueue{
   public:
	NodeQueue();
	NodeQueue(int size, const T& value);
	NodeQueue(const NodeQueue<T>& other);
	~NodeQueue();
	
	NodeQueue& operator = (const NodeQueue<T>& other_nodeQueue);
	
	T& front();
	const T& front() const;
	
	T& back();
	const T& back() const;
	
	void push(const T& value);
	void pop();
	
	int size() const;
	bool empty() const;
	bool full() const;
	void clear();

	 /*friend overloaded << operator of the ArrayQueue class. The function will create a local copy of passed object. The function will then print out the Queue Size, Queue 	   m_front and Queue m_back if the object is not empty.The function will then print and pop the Nodes in the Queue until the size is equal to 0. To print the data, the 		 function will call getData for each Node and then pop it afterwards.If the Queue is empty the function will send a warning to the terminal. */
	friend std::ostream& operator<<(std::ostream& os, const NodeQueue<T>& nodeQueue){

	    
	    Node<T> * current;
	   
	    if(!nodeQueue.empty()){
		NodeQueue <T> temp = nodeQueue;
		os << "The Front is: " << temp.front() << endl;
		os << "The Back is: " << temp.back() << endl;
		os << "The Size is: " << temp.size() << endl;
		
		while(temp.size() != 0){
			current = temp.m_front;
			os << current -> getData() << " ";
			temp.pop();
		}
	    }
	    else{
		 os << "The queue you are trying to print is empty!";
		}
	    os << "\n";
	    return os;

}

   private:
	Node<T>* m_front;
	Node<T>* m_back;
};

//Default constructor for the NodeQueue class. Set m_front and m_back to NUll.
template <class T>
NodeQueue<T>::NodeQueue(){
	m_front = NULL;
	m_back = NULL;
}

/*Parameterized constructor for the NodeQueue class. Dynamically creates a new Node with holding of datatype value and assigns m_front pointer to that. Then the loop will iterate until the passed parameter size has been reached, and it will create a new node each time and assign the memory address of that null to the previous node so that a list is created. Then m_back will point to the last list node and the m_next of that list node will be null.*/
template <class T>
NodeQueue<T>::NodeQueue(int size, const T& value){

	m_front = new Node<T>(value);
	Node<T>* duplicate = m_front;
	for(int i = 0; i < size - 1; i++){
	    Node<T> * holder = new Node<T>(value);
	    duplicate -> m_next = holder;
	    duplicate = holder;
	}
	duplicate -> m_next = NULL;
	m_back = duplicate;
}

/*Copy constructor for the NodeQueue class.Creates a Node pointer that points to the passed object's m_front memory address. Then the function will continue to copy the data and nodes of the other object until there is no more data and nodes to copy. This will all creates a new object. The process of similar to the param constructor, where I create a new node and then assign the data to that node and then i set the memory address of the dynamically created new node to the m_next of the previous node.*/
//template <class T>
template <class T>
NodeQueue<T>::NodeQueue(const NodeQueue<T>& other){

	Node<T> * current = other.m_front; 
	Node<T> * head;
	Node<T> *previous;
	
	if(current != NULL){
	   m_front = new Node<T>(current -> getData()); 
	   previous = m_front;

	   while(current != other.m_back){

		 current = current -> m_next;
		 head = new Node<T>(current -> getData());
		 previous -> m_next = head;
		 previous = head;

	   }
	}
	m_back = previous; 
}

/*Destructor for the NodeQueue class. The function will have a pointer point to the m_front of the list. Then the function will continuously delete all of the nodes until there is nothing left.*/
template <class T>
NodeQueue<T>::~NodeQueue(){

	Node<T> * temp = m_front;
	Node<T> * holder;
	while(temp != NULL){
		holder = temp -> m_next;
		delete temp; 
		temp = holder;
		if(temp == m_back){
		   delete temp;
		   break;
		}
	}
	
}

/*Overloaded =  constructor for the NodeQueue class.Creates a Node pointer that points to the passed object's m_front memory address. Then the function will continue to copy the data and nodes of the other object until there is no more data and nodes to copy. This will all creates a new object. The process of similar to the param constructor, where I create a new node and then assign the data to that node and then i set the memory address of the dynamically created new node to the m_next of the previous node.*/
template <class T>
NodeQueue<T>& NodeQueue<T>::operator = (const NodeQueue<T>& other_nodeQueue){

	Node<T>  * current = other_nodeQueue.m_front; 
	Node<T>  * head;
	Node<T>  *previous;
	
	if(current != NULL){
	   m_front = new Node<T>(current -> getData()); 
	   previous = m_front;

	   while(current != other_nodeQueue.m_back){

		 current = current -> m_next;
		 head = new Node<T>(current -> getData());
		 previous -> m_next = head;
		 previous = head;

	   }
	}
	m_back = previous;
}

//Front function of the NodeQueue class.  The function will return a reference to the front element of the queue,if the queue is not empty. 
template <class T>
T& NodeQueue<T> ::front(){
	if(!this -> empty()){
	return m_front -> getData();
	}
	
}

//Front function of the NodeQueue class.  The function will return a reference to the front element of the queue,if the queue is not empty. 
template <class T>
const T& NodeQueue<T> ::front() const {
	if(!this -> empty()){
	return m_front -> getData();
	}
	
}

//Back function of the NodeQueue class. The function will return a reference to the back element of the queue,if the queue is not empty. 
template <class T>
T& NodeQueue<T> ::back(){
	if(!this -> empty()){
	return m_back -> getData();
	}
	
}

//Back function of the NodeQueue class. The function will return a reference to the back element of the queue,if the queue is not empty. 
template <class T>
const T& NodeQueue<T> ::back() const {
	if(!this -> empty()){
	return m_back -> getData();
	}
	
}

/*Push function for the NodeQueue class.The function will check if the list is empty. If the list is empty, the function will create a new node and set m_front and m_back to that. Then m_front's m_next will point to m_back and m_back's m_next will point to null.
If the list is not empty, the function will create a new node of datatype value. The function will then set the m_next of m_back to the newly created node. The new node's m_next will be set to NULL and then m_back will be set to the new node. 
*/
template <class T>
void NodeQueue<T> ::push(const T& value){
	Node<T>  * current = m_front; 
	Node<T>  * previous = current;
	if(!this -> empty()){
	 /*while(current != m_back){
	      
		previous = current;
		current = current -> m_next;
	
	}*/
	
	previous = new Node<T>(value);
	m_back -> m_next = previous;
	previous -> m_next = NULL;
	m_back = previous;
	}
	else{
	     m_front = new Node <T>(value);
	     m_back = m_front;
	     m_front -> m_next = m_back;
	     m_back -> m_next = NULL;
	}

}

/*Pop function for the NodeQueue class. The function will check if the list is empty. If the list is empty, m_front and m_back will be set to NULL and then the function will send a warning to the terminal. Otherwise the function will set a Node pointer to m_front. Then the new m_front will be the current m_front's m_next. And the previous m_front will be deleted. If the size is equal to one, then the m_front will be set to NULL and m_back will also be set to NULL.
*/
template <class T>
void NodeQueue<T> ::pop(){

     if(!this -> empty()){
	Node<T>  * current = m_front;
	Node<T>  * previous = m_front;
	if(current != m_back){
	m_front = current -> m_next;
	delete previous;
	previous = NULL;
	}
	else if(this -> size() == 1){
		
	        m_front = NULL;
	        m_back = NULL;
        } 
     }   
     else{
	     m_front = NULL;
	     m_back = NULL;
	     cout << "The list is empty and cannot be popped!" << endl;
     }
     
}

/*Size function for the NodeQueue class. The function will check to see if m_front is not equal to null. if it is,  then the function will return 0; other wise, the function will traverse the list until m_back has been reached and it will increment count until the m_back is reached. Then after doing so, the function will return the integer count.*/
template <class T>
int NodeQueue<T> ::size() const{

	Node<T>  * current = m_front;
	int count = 0;
	if(m_front == NULL){
	   return 0;
	}
	while(current != m_back){
	      count ++;
	      current = current -> m_next;
	}
	count++;
	return count;
}

/*Empty function for the NodeQueue class. The function will call the size function and check to see if it is 0. If the size does return 0. the function will return true, otherwise the function will return false.*/
template <class T>
bool NodeQueue<T> ::empty() const{

	if(this -> size() == 0){
	   return true;
	}
	else{
	   return false;
	}
}

//Full function for the NodeQueue class. Since the list can never be full, the function will always return false.
template <class T>
bool NodeQueue<T> ::full() const{

	return false;
}

/*clear function for the NodeQueue class. The function will check to see if the list is not empty. If the list is empty, the function will set m_front and m_back to NULL. If the list is not empty, the function will traverse the list and delete all of the nodes in the list and set them to null and then set m_front and m_back to null. 
*/
template <class T>
void NodeQueue<T> ::clear(){

    Node<T>  * current = m_front;
    Node<T>  * previous = m_front;
    if(!this -> empty()){
	while(current != m_back){
	previous = current -> m_next;
	delete current;
	current = NULL;
	current = previous;
    }

    }
   	   
   m_front = NULL;
   m_back = NULL;
   
     

}



