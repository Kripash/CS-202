//Author: Kripash Shrestha
//Project8.h
//Date 5/02/2017

#include <vector> 
#include <iostream>

using namespace std;

const int FIRST = 0;
const int LAST = 99;
const int SIZE = 100;

 
/*Templated partition function for the quicksort vector_research function. This is used in assistance for the partition function. The function will set the target "pivot" as the last element in the entire vector. The function will then set i to the first element - 1. The function will then go in a for loop and swaps the elements based on the logic, if the vec[j] is smaller than the value, which was the value of last element in the vector.*/
template <typename T>
int partition (std::vector<T> &vec, int left, int right){
	
	T value = vec[right];
	int j = 0;
	int i = left -1 ;
	for(j = left ; j <= right; j++){
	    if(vec[j] < value){
		i = i + 1;
		swap(vec[i],vec[j]);
	    }
	}
	swap(vec[i+1],vec[right]);
	return i + 1;
}

/*Templated vector_resort function for quicksorting the randomized vector. The function will check to see if the int corresponding to the element in the vector ( left is smaller than right). If that is the case, the function will call the above functions partition, and then the function will also haave a variable called part, for the return of the partition function to be used. Then the function will recurse itself for values, of left and the return element of partition -1 and then for the other side, the left will be the return of part + 1 and then right would be right. Since this function calls its self, it will recursively work until the recursion stops with a function call when left will be greater than right. Which should happen because every recursion changes value of the parameter int of left and right.*/ 
template <typename T>
void vector_resort(std::vector<T> &vec, int left, int right){
	
	if(left < right){
	   int part = partition(vec, left, right);
	   vector_resort(vec, left, part-1); 
	   vector_resort(vec, part + 1,right);
	}	   
}

/*Templated vector_research function for the binary search for the sorted vector. The function will make compare the values of left and right. If the value of right is smaller than left, then the function will return -1 , since the target element will not be found. The function will then set the int mid to the middle of the vector and use that for comparison. The function will have a passed in of type T value, which will be the value to locate in the vector. The function will first check if vec[mid] is equal to value. If so, then the function will return mid. If not, the function will then check if the value of vec[mid] is greater than value, if so then the function will call itself, but this time, change is so that the right side of the vector will be used by the mid point of the vector-1 for finding the value. Else if the vec[mid] is smaller than the value, then the left side of the function will have mid + 1, with the right side being hte right. This function will recursively work until either the value is found or until the left is greater than the right, which will then return -1, showing that the value cannot be found in the vector */
template <typename T>
int vector_research(std::vector <T> &vec, int left, int right, const T& value){

	if(left > right){
	   return -1;
	}
	else{

	     int middle = (left + right) / 2;
	     if (vec[middle] == value){
		 return middle;
	     }
	     else if(vec[middle] > value){
		     vector_research(vec,left, middle -1,value);

	     }
	     else if (vec[middle] < value){
		  vector_research(vec, middle + 1, right, value);
	     } 
	}
}

/*Templated vecInt function. The function will open the file that the user will enter. This will be stored in a string and accessed through that. The function will store the value of the integer into a local variable and then will pushback that value to the vector passed. The function will do this in a for loop 100 times. Then the function will close the file and the vector will have 100 integers from the file to the vector. */
template <typename T> 
void vecInt(std::vector <T> &vec2, const std::string& inputFile){
	
	int number;
	ifstream openFile;
	openFile.open(inputFile.c_str());
	for(int k = 0;  k < SIZE; k++){
	    openFile >> number;
	    vec2.push_back(number);
	}
	openFile.close();
}

/*Templated vecIntCpy function that takes in two vectors, an original and one to be copied. The function will use the equal assignment operator from the vector STL to copy the data from the original vector to the second vector. */
template <typename T>
void vecIntCpy(std::vector <T> &original, std::vector <T>&copy){

		copy = original;
}





