//Author: Kripash Shrestha
//Project8.cpp
//Date 5/02/2017

#include <iostream>
#include <fstream> 
#include <string> 
#include "proj8.h"

using namespace std;


int main(){

	//asks the user to enter the data file to be read and stores it in a string.
	string inputFile;
	cout << "Enter the file to be read: ";
	cin >> inputFile;
	//declares a new vector of type int.
	vector<int> vec;
	//loads the vector with 100 ints from the file to be read. Calls the vecInt function.
	vecInt(vec, inputFile);
	//copies the loaded vector with 100 ints to a second vector.
	vector <int> copy;
	//calls the vecIntCpy function to do so.
	vecIntCpy(vec, copy);
	cout << endl << "The Unsorted Vector!" << endl << endl; 
	for (int i = 0; i < 100; i++){
	     cout << vec[i] << " ";
	}
	cout << endl << endl;
	//calls the vector resort function to sort the array via quicksort.
	vector_resort(vec, FIRST, LAST);
	//random integer value to search for. change to what is valid and invalid if needed.
	int value = 199;
	int invalid = -1;
	
	//calls the vector_research function to use binary search to find the above value.
	int search = vector_research(vec, FIRST, LAST, value);
	//prints out the sorted vector to the terminal.
	cout << endl << "The Sorted Vector!" << endl << endl; 
	for (int i = 0; i < 100; i++){
	     cout << vec[i] << " ";
	}
	int not_found = vector_research(vec, FIRST, LAST, invalid);
	//prints out the element position of the integer that was searched for. Should be found!
	cout << endl << endl << "The element position(0-99) of " << value << " is: " << search << endl;
	//This one should not be found!
	cout << "The element position(0-99) of " << invalid << " is: " << not_found << endl << endl;

}
