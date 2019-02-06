/* 
Kripash Shrestha
The purpose of this program is to read in the first 10 names from a file into a two dimensional character array, output the names to the terminal, sort the list of names and then output the sorted names to the terminal and to a file.
proj1.cpp
*/

#include <iostream>
#include <fstream>
using namespace std; 


/*
Function Name:copyNames
The function copies the names from array to array1. 
Parameter char array[10][50]: This is the array that will have the names from the input file.This array will be used to copy the names to the second array.
Parameter char array1[10][50]: This is the array that will contain the copied names from the first array. 
Pre-Condition: array[10][50] must contain the names from the input file. array1[10[50] must not not contain anything inside. 
Post-Condition: array[10]50] will still contain the list of names from the input file. array1[10][50] will also contain the list of names from the input file, except through copying from array[10][59].
the function does not have any return values.
*/

void copyNames(char array[10][50], char array1[10][50]);

/*
Function Name:find_smallest_string_length
The function compares the string length of two rows/words in a given array and finds the smallest string length. The function will then return the smallest string length from the two given array rows.
Parameter char array1[50]: This is the first row that the function will check. A for loop will stop after it reaches the null terminator of that row and will have an integer value of j that will contain the length of the string.
Parameter char array2[50]: This is the second row that the function will check. A for loop will stop after it reaches the null terminator of that row and will have an integer value of k that will contain the length of the string.
Pre-Condition: string1[50] must be an array row that must have a name ended by a null terminator. string2[50] must also be an array row that must have a name ended by a null terminator.
Post-Condition: string1[50] will be a row (name) from the array, and will be used to get the string length of that name/array. string2[50] will be a row (name) from the array, and will be used to get the string length of that name/array. The string lengths will be compared and then the function will return the smaller string length.
the function will return the smaller string length from the two compared rows/arrays as an integer.
*/

int find_smallest_string_length (char string1[50], char string2[50]);

/*
Function Name: find_string_length 
The function finds the string length of the given array row.
Parameter char array[50]: This is the array row that the function will use to find the string length. A for loop will run until it finds a null terminator in the array row. The value of the string length will be stored in integer j. 
Pre-Condition: array[50] must be the array row that must have a name ended by a null terminator.
Post-Condition: array[50] will be the same array roww that is ended by a null terminator. The array row will be used to calculate the string length of the name so that it can be used properly.
the function will return the string length of the array row as an integer. The function will return the string length - 1 because we do need to loop it and do not need the consider the null terminator in this case.
*/

int find_string_length (char array[50]);

/*
Function Name: my_string_compare_and_alphabetize
the function will compare the rows of a given 2D array and alphabetize them properly. 
Parameter char array[10][50]: This is the array that the function will use to check the logic of each array row and column and make sure that is alphabetized properly.
Pre-Condition: array[10][50] must be a 2D array with 10 rows and 50 columns with the list of names from the input file. This list is most likely not in alphabetical order.
Post-Condition: array[10]50] will be a 2D array with 10 rows and 50 columns with the same list of names from the input file. This 2D array will now be arranged in alphabetical order.
the function does not have any return values.
*/

void my_string_compare_and_alphabetize (char array[10][50]);




int main(){
 
  char inputFile[50];
  cout << "Enter the name of the input file:";
  cin >> inputFile;
  inputFile[49] = '\0';
  char unsortedList[10][50];
  char sortedList[10][50];
  ifstream openFile;
  openFile.open(inputFile);
  //open the file with the name provided by the user. 
   
  //copy the first 10 names from the file to the array unsortedList.  
  for (int i = 0; i < 10; i++){
                 
       openFile.getline(unsortedList[i], 50 ,'\n');	
       unsortedList[i][49] = '\0';	
  }
  
  
  openFile.close();

  //prints the first 10 names from the file to the terminal.
  for (int j = 0; j < 10; j++){

       cout << unsortedList[j] << "\n";
  }

  //copies the list of name from unsortedList to the second array called sortedList.
  copyNames(unsortedList, sortedList);

  //calls the following funtion to rearrange the array sortedList alphabetically.
  my_string_compare_and_alphabetize(sortedList);
  
  char outputFile[50];
  cout << "Enter the name of the output file:";
  cin >> outputFile;
  outputFile[49] = '\0';
  ofstream openOutputFile;
  openOutputFile.open(outputFile);
  //open the file with the name provided by the user.

  //print the alphbetically sorted names from the array sortedList to the output file.
  for (int k = 0; k < 10; k++){

       openOutputFile << sortedList[k] << "\n";
  }



  openOutputFile.close(); 

  //print the alphabetically sorted list to the terminal. 
  for (int l = 0; l < 10; l++){

       cout << sortedList[l] << "\n"; 
  }
    
  return 0;
}



void copyNames(char array[10][50], char array1[10][50]){
   
   for (int i = 0; i < 10; i++){

     for (int j = 0; j < 50; j++){
	  array1[i][j] = array[i][j];
     }

   }

   for (int k = 0; k < 10; k++){

        array1[k][49] = '\0';
   }

}


int find_smallest_string_length (char string1[50], char string2[50]){
   
   int value = 0;
   int compare = 0;
   int j, k = 0;
   int smallest_string = 0;


   for (j = 0; string1[j] != '\0'; j++);
	
   for (k = 0; string2[k] != '\0'; k++);
	       
   if (j < k){
       smallest_string = j;
       
   }
   else 
       smallest_string = k;
          
   return smallest_string;
   
}


int find_string_length (char array[50]){

   int j = 0;

   for (j = 0; array[j] != '\0'; j++);

   return j - 1;
}


void my_string_compare_and_alphabetize (char array[10][50]){

    int k , min_string_length;
    for (int i = 0; i < 9; i++){
	 for (int j = 0; j < 9 - i; j++){
	      min_string_length = find_smallest_string_length(array[j], array[j+1]);
	      for (k = 0; k < min_string_length; ++k){
		   if (array[j+1][k] < array[j][k]){
		       swap(array[j], array[j+1]);
		       break;
		   }
	           else if (array[j+1][k] > array[j][k]){
			    break; 
		   }
	      }
	      if (k == min_string_length && ((find_string_length(array[j])) > (find_string_length(array[j+1])))){
		  swap(array[j],array[j+1]);
	
	      }
	 }
    }
}







