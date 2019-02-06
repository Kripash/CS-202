//author: Kripash Shrestha

#include <iostream>
using namespace std;

#include "ArrayList.h"


/*
This function grows the arraylist by the int addsize passed to the parameter. The function adds add size to the current max size to get a new max size. The function then, copies the data into a holder, deletes the current array if it isnt null and allocates memory for the new max size. The function copies the data of the holder into the current array. The m_size is not changed.
*/
void ArrayList::grow(int addsize){

	ArrayList holder = *this;	
	if(m_array != NULL){
	   delete [] m_array;
	}
	m_maxsize = addsize + m_maxsize;
	m_array = new DataType [m_maxsize];
	for(int i = 0; i < m_maxsize; i++){
	    m_array[i] = holder.m_array[i];
	}	
}

/*
This function trims the arraylist to the size that represents the current m_size of the object. The function will first copy the data into a holder and delete the array if is not null. Thee, the function will set the maxsize equal to the m_size and allocate memory for the new maxsize. The function will then only copy the valid data from the set to the newly allocated arraylist. 
*/
void ArrayList::trim(){

	ArrayList holder = *this;
	
	int i = 0;
	int j = 0;

	/*for(i = 0; i < m_maxsize; i++){
	    if((holder.m_array + i)!= NULL){
	    temp[j] = holder.m_array[i];
	    j++;
	    }
	}*/
	
	if(m_array!= NULL){
	   delete [] m_array;
	}

	//DataType * temp = new DataType [m_size];
	m_maxsize = m_size;
	
	m_array = new DataType [m_maxsize];
	for(i = 0; i < m_maxsize; i++,j++){
	    if(holder.m_array + i != NULL){
	       m_array[i] = holder.m_array[j];
	    }
	    if(holder.m_array + j == NULL){
		j++;
	    }
	}
		
}

/*
Default constructor for the ArrayList class, that intializes m_array to NULL, m_size to 0 and m_maxsize to 0;
*/
ArrayList::ArrayList(){

	m_array = NULL;
	m_size = 0;
	m_maxsize = 0;
}


/*
Parameterized constructor for the ArrayList class. The function will set m_size to 0 and first and set m_maxsize to the passed parameter int size. The function will then allocate memory for the new m_maxsize and then copy the data from the second passed parameter, which is a DataType value. All the elements will contain the same data and the m_size will be updated to the amount of data that is valid in the ArrayList.
*/
ArrayList::ArrayList(int size, const DataType& value){

	m_size = 0;
	m_maxsize = size;
	m_array = new DataType [m_maxsize];
	for(int i = 0; i < m_maxsize; i++){
	    m_array[i] = value;
	}
	for(int j = 0; j < m_maxsize; j++){
	    if((m_array + j) != NULL){
	       m_size++;
	    }
	}
}

/*
Copy Constructor for the ArrayList class. The function gets m_array to null. The function will take the size and m_max size of the passed object and set it to the new object. The function will allocation memory for m_array to its new max size and then copy the data from the the passed object to the newly created boject's m_array.
*/
ArrayList::ArrayList(const ArrayList& other){

	m_array = NULL;
	m_size = other.m_size;
	m_maxsize = other.m_maxsize;
	m_array = new DataType [m_maxsize];
	for (int i = 0; i < other.m_maxsize; i++){
	     m_array[i] = other.m_array[i];
	}
}

/*
Destructor for the ArrayList class. The function deletes [] m_array of the object.
*/
ArrayList::~ArrayList(){

	delete [] m_array;
}

/*
Overloaded = operator function for the ArrayList class. The function will check to see if the object's m_array is null and then delete m_array based on that. The function will set the object's m_size and m_maxsize to that of the parameter passed object. The function will allocate memory for the object's m_array based on the other object's m_maxsize and then copy the data from the other object's m_array to the object's m_array.
*/
ArrayList& ArrayList::operator= (const ArrayList& other_arrayList){
	
	if(m_array != NULL){
	   delete[] m_array;
	}
	m_array = new DataType [other_arrayList.m_maxsize];
	m_size = other_arrayList.m_size;
	m_maxsize = other_arrayList.m_maxsize;
	for (int i = 0; i < other_arrayList.m_maxsize; i++){
		m_array[i] = other_arrayList.m_array[i];
	}

	return *this;
}

/*
First function of the ArrayList class. This function finds the first valid element of the ArrayList and retuns it. If there is no valid element in the ArrayList object, the function will return null.
*/
DataType* ArrayList::first(){

	DataType * ptr;
	ptr = NULL;
	int i = 0;
	for(i= 0; i < m_maxsize; i++){
	    if((m_array + i)!= NULL){
		ptr = m_array + i;
		break;
	    }		
	}
	
	return ptr;
}

/*
First function of the ArrayList class. This function finds the first valid element of the ArrayList and retuns it. If there is no valid element in the ArrayList object, the function will return null.
*/
const DataType* ArrayList::first() const {

	DataType * ptr;
	ptr = NULL;
	int i = 0;
	for(i = 0; i < m_maxsize; i++){
	    if((m_array + i)!= NULL){
		ptr = m_array + i;
		break;
	    }		
	}
	
	return ptr;
}

/*
Last function of the ArrayList class. This function finds the last valid element of the ArrayList and retuns it. The function iterates a for loop to the amount of m_maxsize of the object. The function will find a valid element in m_array and have a pointer point to it. The function updates the pointer to the last valid element from the for loop and then stops once the m_maxsize has been reached. The function will then return the pointer to the last valid element it found. If there is no valid element in the object, the function will return null.
*/
DataType* ArrayList::last(){

	DataType * ptr;
	ptr = NULL;
	int i = 0;
	for(i = 0; i < m_maxsize; i++){
	    if((m_array + i)!= NULL){
		ptr = m_array + i;
	    }		
	}
	
	return ptr;
}

/*
Last function of the ArrayList class. This function finds the last valid element of the ArrayList and retuns it. The function iterates a for loop to the amount of m_maxsize of the object. The function will find a valid element in m_array and have a pointer point to it. The function updates the pointer to the last valid element from the for loop and then stops once the m_maxsize has been reached. The function will then return the pointer to the last valid element it found. If there is no valid element in the object, the function will return null.
*/
const DataType* ArrayList::last() const {

	DataType * ptr;
	ptr = NULL;
	int i = 0;
	for(i = 0; i < m_maxsize; i++){
	    if((m_array + i)!= NULL){
		ptr = m_array + i;
	    }		
	}
	
	return ptr;
}

/*
This is the find function of the ArrayList class. This function will take in parameters of a DataType target, a DataType pointer and a const DataType pointer start. Because the third parameter was extra functionality, i have ignored that part for the algorithm. The function will check to see if the target is valid, if it is null, the function will return null and set previous to null. The function will check if the first element contains the DataTpe target, and then will return the first DataType and set previous to null. If none of those logics are true, the function will then continue to find an array element that matches the DataType and then return that array element. The previous array element will be continuously updated to the array element that is before the currently tested array element.
*/
DataType* ArrayList::find(const DataType& target, DataType* &previous, const DataType* const start ){

 
	DataType * ptr;
	ptr = NULL;
	int i = 0;
	for(i = 0; i < m_maxsize; i++){
	    if(((m_array[i]) == target )){
		ptr = m_array + i;
		break;
	    }
	}
	    
	if( i != 0 && ptr != NULL){
		    previous = ptr - 1;
	}
	else if ( i == 0 && ptr != NULL){
		     previous = NULL;
	}
	else if ( ptr == NULL){
		previous = NULL;
	}

	/*cout << "find i:" << i << endl;
	cout << "find prev:" << previous << endl;
	cout << "find ptr:" << ptr << endl;*/
	
	return ptr;
}

/*
This is the find function of the ArrayList class. This function will take in parameters of a DataType target, a DataType pointer and a const DataType pointer start. Because the third parameter was extra functionality, i have ignored that part for the algorithm. The function will check to see if the target is valid, if it is null, the function will return null and set previous to null. The function will check if the first element contains the DataTpe target, and then will return the first DataType and set previous to null. If none of those logics are true, the function will then continue to find an array element that matches the DataType and then return that array element. The previous array element will be continuously updated to the array element that is before the currently tested array element.
*/
const DataType* ArrayList::find(const DataType& target, const DataType* &previous, const DataType* const start ) const {

	DataType * ptr;
	ptr = NULL;
	int i = 0;
	for(i = 0; i < m_maxsize; i++){
	    if(((m_array[i]) == target )){
		ptr = m_array + i;
		break;
	    }
	}
	    
	if( i != 0 && ptr != NULL){
		    previous = ptr - 1;
	}
	else if ( i == 0 && ptr != NULL){
		     previous = ptr;
	}
	else if ( ptr == NULL){
		previous = NULL;
	}
	/*cout << "find i:" << i << endl;
	cout << "find prev:" << previous << endl;
	cout << "find ptr:" << ptr << endl;*/
	
	return ptr;
}

/*
This is the insertAfter function of the ArrayList class. This function will take in parameters of a DataType target, a DataType value and a int count. Because the third parameter was extra functionality, i have ignored that part for the algorithm. The function will check to see if the target is valid, if it is null, the function will return null and set previous to null. The function check if the m_size is equal to 0. If it is, the function will return null since there is no data in m_array. The function will then check if m_size is equal to m_maxsize, if it is, the function will copy the data of the array into a temporary array and then call the grow function to increase the array by 1. The function will then copy the temporary array into m_array until the target is found, then the function will insert the DataType value into that element slot and continue to copy the data from where it previously left off. A similar algorithm is used if there is open slots in m_array, the function will move over data to make sure the DataType value can be added after the target element. The function will return the element it inserted, or null if it fails.
*/
DataType* ArrayList::insertAfter(const DataType& target, const DataType& value, int count){

	DataType * ptr;
	ptr = NULL;
	DataType * ptr2; 
	ptr2 = NULL;
	int i = 0;
	DataType * pointer = NULL;
	DataType *null = NULL;
	

	DataType * temp = new DataType [m_maxsize];

	DataType * previous = NULL;
	
			
	if (m_size == 0){
	    return null;
	    
	}	

	else if (m_size == m_maxsize){
	    for (i = 0; i < m_maxsize; i++){
		temp[i] = m_array[i];
	    }
	    grow(1);	
	    ptr = find(target, previous);
	    if (ptr == NULL){
		return ptr;
	    }
	    ptr2 = m_array;
	 	    
	    ptr++;
	    pointer = ptr;
	       
	    for( i = 0; ptr2 != ptr; ptr2++ , i++){
	        m_array[i] = temp[i];
	    }
	       
	    m_array[i] = value;
	    
	    i++;    
	    for(i=i; i < m_maxsize; i++){
		m_array[i] = temp[i-1];
	    }
	    if(pointer != NULL){
	       m_size++;
	    }

	    
	}
	else if(m_size < m_maxsize && m_size > 0){
	
		ptr = find(target, previous);
		ptr2 = m_array;
		if((m_array + (m_maxsize - 1)) != ptr){
		   ptr++;
		}
		if(ptr == NULL){
		   pointer = ptr;
	           *ptr = value;
		   if(pointer != NULL){
	           m_size++;
	        }
		}
		else{
		     for (i = 0; i < m_maxsize; i++){
			temp[i] = m_array[i];
	    	     }
		     grow(1);
		     ptr = find(target, previous);
		     ptr2 = m_array;
		     ptr++;
		     for( i = 0; ptr2 != ptr; ptr2++ , i++){
	        	m_array[i] = temp[i];
	    	     }
		     m_array[i] = value;
		     i++;
		     for(i=i; i < m_maxsize; i++){
			m_array[i] = temp[i-1];
	   	     }
	    	     if(pointer != NULL){
	                m_size++;
	             }    
		}
	} 
	
	return pointer;
}


/*
This is the insertBefore function of the ArrayList class. This function will take in parameters of a DataType target, a DataType value and a int count. Because the third parameter was extra functionality, i have ignored that part for the algorithm. The function will check to see if the target is valid, if it is null, the function will return null and set previous to null. The function check if the m_size is equal to 0. If it is, the function will return null since there is no data in m_array. The function will then check if m_size is equal to m_maxsize, if it is, the function will copy the data of the array into a temporary array and then call the grow function to increase the array by 1. The function will then copy the temporary array into m_array until the target is found, then the function will insert the DataType value into the element slot before the target and then continue to copy the data from where it previously left off. A similar algorithm is used if there is open slots in m_array, the function will move over data to make sure the DataType value can be added after the target element. The function will return the element it inserted, or null if it fails.
*/
DataType* ArrayList::insertBefore(const DataType& target, const DataType& value, int count){

	DataType * ptr;
	ptr = NULL;
	DataType * ptr2; 
	ptr2 = NULL;
	int i = 0;
	DataType * pointer = NULL;
	DataType *null = NULL;
	

	DataType * temp = new DataType [m_maxsize];

	DataType * previous = NULL;
		
		
	if (m_size == 0){
	    return null;
	    
	}	

	else if (m_size == m_maxsize){
	    for (i = 0; i < m_maxsize; i++){
		temp[i] = m_array[i];
	    }
	    grow(1);	
	    ptr = find(target, previous);
	    if (ptr == NULL){
		return ptr;
	    }
	    ptr2 = m_array;
	    
	    pointer = ptr;
	      
	    for( i = 0; ptr2 != ptr; ptr2++ , i++){
	        m_array[i] = temp[i];
	    }
	       
	    m_array[i] = value;
	    
	    i++;    
	    for(i = i; i < m_maxsize; i++){
		m_array[i] = temp[i-1];
	    }
	   
	    if(pointer != NULL){
	       m_size++;
	    }
	}
	else if(m_size < m_maxsize && m_size > 0){
	
		ptr = find(target, previous);
		ptr2 = m_array;
		
		if (m_array == ptr){
		    for (i = 0; i < m_maxsize; i++){
			temp[i] = m_array[i];
	    	    }
		    grow(1);
		    ptr = find(target, previous);
		    ptr2 = m_array;
		    i = 0;
		    m_array[i] = value;
		    i++;
		    for(i = i; i < m_maxsize; i++){
			m_array[i] = temp[i-1];
	   	     }

		}

		else if((m_array) != ptr){
		   ptr--;
		}
		if(ptr == NULL){
		   pointer = ptr;
	           *ptr = value;
		   if(pointer != NULL){
	           m_size++;
	    	   }
		}

		else{
		     for (i = 0; i < m_maxsize; i++){
			temp[i] = m_array[i];
	    	     }
		     grow(1);
		     ptr = find(target, previous);
		     ptr2 = m_array;
		     ptr--;
		     for( i = 0; ptr2 != ptr; ptr2++ , i++){
	        	m_array[i] = temp[i];
	    	     }
		     m_array[i] = value;
		     i++;
		     for(i = i; i < m_maxsize; i++){
			m_array[i] = temp[i-1];
	   	     }
	    	     if(pointer != NULL){
	                 m_size++;
	    	     }	     
		}
	} 

	return pointer;
}

/*
This is the removeForward function of the ArrayList class. This function will take in parameters of a DataType target, a int count. Because the second parameter was extra functionality, i have ignored that part for the algorithm. The function will check to see if the target is valid, if it is null, the function will return null and set previous to null. The function iterate to the size of the m_maxsize and then continues until it finds the valid target.the function will then copy data and stop when it reaches the target element and then removes it by calling the trim function. The function will move around elements if necessary for propery array relocation. The function will return a pointer to the element after the one it removed if it was successful or null if the removed element was the last one in the arraylist.
*/
DataType *ArrayList::removeForward(const DataType& target, int count){
	DataType * ptr = NULL;
	int i = 0;
	int j = 0;
	/*DataType *previous = NULL;
	DataType *ptr2 = NULL;
	DataType *pointer = NULL;
	//DataType * set = NULL;

	DataType * temp = new DataType [m_maxsize];

	for (i = 0; i < m_maxsize; i++){
	     temp[i] = m_array[i];
	}

        if(m_size == m_maxsize){
	   ptr = find(target,previous);
	   pointer = ptr;
	   ptr++;
	   ptr2 = m_array;
	   if(ptr == NULL){
	     return NULL;
	   }
	   for( i = 0; ptr2 != ptr; ptr2++ , i++){
	        m_array[i] = temp[i];
	    }
	    
	    delete (m_array + i);
	    m_size = m_size - 1;
	    
	    i++;    
	    for(i = i; i < m_maxsize; i++){
		m_array[i] = temp[i];
	    }
	    trim();
	}*/	
	for(i = 0; i < m_maxsize; i++){
	    if(m_array[i] == target){
	       break;
	    }
	}
	j = i;
	for(i= i; i< m_maxsize; i++){
	    m_array[i] = m_array[i+1];
	}
	int original_size = m_maxsize;
	m_size--;
	trim();
	//m_size++;
	if( j == original_size){
	   return ptr;
	}
	else{
	   ptr = m_array+(j);
	   return ptr;
	}
	return ptr;
}

/*
This is the removeBackward function of the ArrayList class. This function will take in parameters of a DataType target, a int count. Because the second parameter was extra functionality, i have ignored that part for the algorithm. The function will check to see if the target is valid, if it is null, the function will return null and set previous to null. The function iterate to the size of the m_maxsize and then continues until it finds the valid target.the function will then copy data and stop when it reaches the target element and then removes it by calling the trim function. The function will move around elements if necessary for propery array relocation. The function will return a pointer to the element beforethe one it removed if it was successful or null if the removed element was the first one in the arraylist.
*/
DataType *ArrayList::removeBackward(const DataType& target, int count){

	DataType * ptr = NULL;
	int i = 0;
	int j = 0;
	
	for(i = 0; i < m_size; i++){
	    if(m_array[i] == target){
	       break;
	    }
	}
	j = i;
	for(i= i; i<m_size; i++){
	    m_array[i] = m_array[i+1];
	}
	//int original_size = m_size;
	m_size--;
	trim();
	//m_size++;
	if( j == 0){
	   return NULL;
	}
	else{
	   ptr = m_array+(j-1);
	   return ptr;
	}
	return ptr;
}

/*
This is the size function of the ArrayList class. The function will return the m_size of the current object.
*/
int ArrayList::size() const{

	return m_size;

}

/*
This the empty function of the ArrayList Class. The function will check to see if the m_size member variable of the object is equal to 0. If the m_size member variable is equal to 0, the function will return true, else it will return false. 
*/
bool ArrayList::empty() const{

     	if(m_size == 0){
	   return true;
	}
	else{
	   return false;
	}
}

/*
This the clear function of the ArrayList Class. The function will check to see if m_array is null. If it is not, the function will delete m_array and then set it to null. The function will then cout if the list is empty or not based on the test if m_array == null or not. 
*/
void ArrayList::clear(){

	if(m_array != NULL){
		delete [] m_array;
	}
	m_array = NULL; 

	if(m_array == NULL){
	   cout << "The list is empty." << "\n";
	}
	else{
	  cout << "Clearing failed." << "\n";
	}
}

/*
Operator << overloaded friend function. The function will take the arguments os and the arraylist that will be printed to the screen. The function will print out the members m_maxsize and m_size of the object to the screen. The function will then iterate through the object's m_array and print out every single element of the array.
*/
std::ostream& operator << (std::ostream& os, const ArrayList& arrayList){

        os << "max size: " << arrayList.m_maxsize << "\n";
	os << "size: " << arrayList.m_size << "\n";
	for(int i = 0; i < arrayList.m_maxsize; i++){
		os << arrayList.m_array[i] << "\n";
	}
	return os;
}	

/*
This is the overloaded [] operator function for the ArrayList class. The function will take in a parameter of int position and iterate a loop to the position and increments i at the same time. The function will then return the element of m_array[i].
*/
DataType& ArrayList:: operator[](int position){

	int i = 0;
	while( i < position){
		i++;
	}
	return m_array[i];
}

/*
This is the overloaded [] operator function for the ArrayList class. The function will take in a parameter of int position and iterate a loop to the position and increments i at the same time. The function will then return the element of m_array[i].
*/
const DataType& ArrayList:: operator[](int position) const {

	int i = 0;
	while( i < position){
		i++;
	}
	return m_array[i];
}






