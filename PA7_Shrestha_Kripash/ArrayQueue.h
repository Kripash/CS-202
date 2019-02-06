//Author: Kripash Shrestha

#include <iostream> 


const int ARRAY_MAX = 1000;

template < class T > 
class ArrayQueue{
   public:

	ArrayQueue();
	ArrayQueue(int size, const T& value);
	ArrayQueue(const ArrayQueue<T>& other);
	~ArrayQueue();

	ArrayQueue<T>& operator = (const ArrayQueue<T>& other_arrayQueue);

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
	
	  /*friend overloaded << operator of the ArrayQueue class. The function will create a local copy of passed object. The function will then print out the Array Size, Array 	    Index and Value for m_front and Array Index and Value for m_back if the object is not empty. The array will then set a local integer equal to m_front. The function will 		  print out the value of that m_array[front]. The function will then pop the queue. This process will be repeated until the queue is empty. If the Queue is empty at the 	   start, the function will send out a warning to the terminal.*/
	friend std::ostream& operator<< (std::ostream& os, const ArrayQueue<T>& arrayQueue){
		
	   
	   ArrayQueue <T> temp;
	   if(!arrayQueue.empty()){
		temp = arrayQueue;
		os << "Array Size: " << arrayQueue.m_size << "\n";
		os << "Array Index Front: " << arrayQueue.m_front << " and the Value is " << arrayQueue.front() << " "<< "\n";
		os << "Array Index Back: " << arrayQueue.m_back << " and the Value is " << arrayQueue.back() << " "<< "\n";
		int front = arrayQueue.m_front;
	
		while(temp.size() != 0){
			front = temp.m_front;
			os << temp.m_array[front] << " ";
			temp.pop();
		}
	    }
	    else{
		 os << "The array you are trying to print is empty!";
		}
	    os << "\n";
	
		return os;

	}	
	
   private:
	T m_array[ARRAY_MAX];
	int m_front;
	int m_back;
	int m_size;
};

/*Default constructor for the ArrayQueue class. Set m_front and m_size to 0. m_back is set to -1 because to push an empty array, i have to start with element 0 as the first data point.*/
template <class T>
ArrayQueue<T>::ArrayQueue(){
	
	m_size = 0;
	m_front = 0;
	m_back = -1;
}

/*parameterized constructor for the ArrayQueue class. sets m_size equal to size. Sets m_front to be the 0th element and then loops up to the integer of size and assigns value to each element and thenassign m_back to the last element that contains the value.*/
template <class T>
ArrayQueue<T>::ArrayQueue(int size, const T& value){

	m_size = size;
	m_front = 0;
	int i = 0;
	for(i = 0; i < size; i++){
	    m_array[i] = value;
	    m_back = i;
	}
}

//Copy constructor for the ArrayQueue class. Takes in an instance of one object and will instantiate a new queue object.sets m_size equal to size. Sets m_front to be the 0th element and then loops up to the integer of size and assigns value to each element and thenassign m_back to the last element that contains the value.*/
template <class T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& other){

	m_size = other.m_size;
	m_front = other.m_front;
	m_back = other.m_back;
	int i = 0;
	for(i = 0; i < ARRAY_MAX ; i++){
	    m_array[i] = other.m_array[i]; 
	}
}
//destructor for the ArrayQueue class. Will destroy the instance of the queue objhect. not needed to implement.
template <class T>
ArrayQueue<T>::~ArrayQueue(){
	
}

/*Overloaded = operator for the ArrayQueue class. Assign a new value to the calling object based on the condiutions. If the passed object is empty, the m_size, m_back and m_front will be copied, but the data in the array will not be copied. Else the object will contain m_back,m_front and m_size of the passed objectand will also contain the data of the m_array member from the passed object. The function will return *this. */
template <class T>
ArrayQueue<T>& ArrayQueue<T>::operator= (const ArrayQueue<T>& other_arrayQueue){

	if(other_arrayQueue.m_size == 0){
	   m_size = other_arrayQueue.m_size;
	   m_front = other_arrayQueue.m_front;
	   m_back = other_arrayQueue.m_back;
	   
	}
	
	else{
	 
	   m_size = other_arrayQueue.m_size;
	   m_front = other_arrayQueue.m_front;
	   m_back = other_arrayQueue.m_back;
	   for(int i = 0; i < ARRAY_MAX ; i++){

		m_array[i] = other_arrayQueue.m_array[i];
	   }
	   
	}

	return *this;
}

//front function for the ArrayQueue class. The function will return a reference to the front element of the queue,if the queue is not empty. 
template <class T>
T& ArrayQueue<T>::front(){

	if(!this -> empty()){
	return m_array[m_front];
	}
}

//front function for the ArrayQueue class. The function will return a reference to the front element of the queue,if the queue is not empty. 
template <class T>
const T& ArrayQueue<T>::front() const {
	if(!this -> empty()){
	return m_array[m_front];
	}
}

//back function for the ArrayQueue class. The function will return a reference to the back element of the queue,if the queue is not empty. 
template <class T>
T& ArrayQueue<T>::back(){
	if(!this -> empty()){
	return m_array[m_back];
	}
}

//Size function for the ArrayQueue class. The function will return the member m_size of the calling object. 
template <class T>
int ArrayQueue<T>::size() const {

	return m_size;
}

//back function for the ArrayQueue class. The function will return a reference to the back element of the queue,if the queue is not empty. 
template <class T>
const T& ArrayQueue<T>::back() const {
	if(!this -> empty()){
	return m_array[m_back];
	}
}

/*Push function for the ArrayQueue class.The function will check if the the function is full. If it is, the function will issue a warning to the terminal. Otherwise the function will set m_back equal to ((m_back + 1) % ARRAY_MAX). That pretty much increment the value by 1 , but if it exceeds ARRAY_MAX,then the function will set m_back to 0. Then the function will set m_array[m_back] equal to the passed parameter value. The function will increment the size of the queue by 1;*/
template <class T>
void ArrayQueue<T>::push(const T& value){

	if(this->full()){
	   cout << "The array is full and cannot be pushed!" << endl;

	}
	else{
	    
	   m_back = ((m_back + 1) % ARRAY_MAX);
	   m_array[m_back] = value;
	   m_size++;
	}
}

/*Pop function for the ArrayQueue class. The function will check if the function is empty. The function will issue a warning the the terminal. Otherwise the function will set m_front equal to m_front = ((m_front + 1) % ARRAY_MAX);. That pretty much increment the value by 1 , but if it exceeds ARRAY_MAX,then the function will set m_front to 0. Then the function will decrement the size by 1. */
template <class T>
void ArrayQueue<T>::pop(){

	if(this -> empty()){
	   cout << "The array is empty and cannot be popped!" << endl;
	}
	else{
	     m_front = ((m_front + 1) % ARRAY_MAX);
	     m_size--;
	}

}

//Empty function for the ArrayQueue class. The function will return true if the calling object's member m_size is 0, other wise the function will return false.
template <class T>
bool ArrayQueue<T>::empty() const{

	if(m_size == 0){
	   return true;
	}
	else{
	   return false;
	}
}

//Full function for the ArrayQueue class. The function will return true if the calling object's member m_size is equal to the const int ARRAY_MA, other wise it will return false.
template <class T>
bool ArrayQueue<T>::full() const{

	if(m_size == ARRAY_MAX){
	   return true;
	}
	else{
	   return false;
	}

}

/*Clear function for the ArrayQueue class. The function does not return anything but sets m_size to 0, m_front to 0 and m_back to -1. Identical to the default constructor, where novalid data exists in the object.*/
template <class T>
void ArrayQueue<T>::clear(){

	m_size = 0;
	m_front = 0;
	m_back = -1;

}




