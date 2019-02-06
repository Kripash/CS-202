/* 
Kripash Shrestha
The purpose of this program is copy the a datafile with 10 different cars and then have a user interactive menu that allows the user to read all data from a file, print out all the data for all of the cars, estimate the rental cost of a car, find the most expensive car, and printout the data for all of the available cars. This program will be be completed with an array of structs, switch statements and a do while loop every menu option being its own individual function.
proj2.cpp
*/
#include <iostream>
#include <fstream>
using namespace std;


struct rentalCar{
   
   char make[30];
   char model[30];
   int year;
   float price; 
   bool available;
};

/*
Function Name: user_enter
The function prompts the user to enter the menu selection as an integer.  
Parameter int &user_enter:This is the integer passed by reference that the value the user enters will be stored into.
Pre-Condition: &user_enter is an integer type containing the value 0. This is referenced to the integer "selection" in the main. 
Post-Condition: &user_enter is an integre type contaning the value that the user will enter as their menu choice. This is referenced to the integer "selection" in the main.
the function does not have any return values.
*/

void user_enter (int &user_enter);

/*
Function Name: read_file
The function prompts the user to enter the name of the file that will be used to copy the data of 10 cars. 
Parameter rentalCar cars[]:This is the array of structs that will contain all the data of 10 cars.
Pre-Condition: rentalCar cars[] is an array of structs that has not been intialized. This will contain the data of the 10 cars.
Post-Condition: rentalCar cars[] is an array of structs that will contain the data of the 10 cars from the file that the user inputs. 
the function does not have any return values.
*/

void read_file (rentalCar cars[]);

/*
Function Name: print_data
The function prints all of the data from the array of structs to the terminal.
Parameter rentalCar cars[]:This is the array of structs that contains the data of the 10 cars. This is the array of structs that will be printed to the terminal. A for loop will be used to do this.
Pre-Condition: rentalCar cars[] is an array of structs that has contains the data of the 10 cars that the user has previously inputted. 
Post-Condition: rentalCar cars[] is an array of structs that contains the data of the 10 cars that the user has previous inputted. That is the array of structs that has been printed to the terminal. The array of structs contains no changes to it. 
the function does not have any return values.
*/

void print_data (rentalCar cars[]);

/*
Function Name: estimate_rental_cost
The function prompts the user to select a car (1-10) and also prompts the user to enter the number of days the user wishes to rent the car. The function will then print out the estimated cost of the rental.
Parameter rentalCar cars[]:This is the array of structs that contains the data of the 10 cars. This is the array of structs that will be checked to estimate the rental cost of the car that the user propts.
Pre-Condition: rentalCar cars[] is an array of structs that has contains the data of the 10 cars that the user has previously inputted. 
Post-Condition: rentalCar cars[] is an array of structs that contains the data of the 10 cars that the user has previous inputted. That is the array of structs that will be used to find the car that the user wants to rent. Then the program will find the cars price and multiply it by the amount of days that the user wishes to rent the car. The value will then be printed on the terminal to notify the user. The array of structs contains no changes to it. A for loop will be used to print all of the data from the array of structs to the terminal.
the function does not have any return values.
*/
void estimate_rental_cost (rentalCar cars[]);

/*
Function Name: most_expensive_car
The function checks the price of each individual car and compares it to each other to find the most expensive car in the array of structs. 
Parameter rentalCar cars[]:This is the array of structs that contains the data of the 10 cars. This is the array of structs that will be checked to estimate the most expensive car from the datafile.
Pre-Condition: rentalCar cars[] is an array of structs that has contains the data of the 10 cars that the user has previously inputted. 
Post-Condition: rentalCar cars[] is an array of structs that contains the data of the 10 cars that the user has previous inputted. That is the array of structs that will be used to compare the price of each car.The function will then compare it to the other cars and the lowest values and store the lowest value into a local integer called most_expensive_car. The function will then print the value of the most expensive car to the terminal and notify the user. The array of structs contains no changes to it. A for loop will be used to find the lowest value and compare the values of each car to the lowest value. The integer most_expensive_car will represent the number of the car that corresponds to its location in the array of structs.
the function does not have any return values.
*/

void most_expensive_car (rentalCar cars[]);

/*
Function Name: print_available_cars
The function prints all of the cars that are available from the array of structs to the terminal. 
Parameter rentalCar cars[]:This is the array of structs that contains the data of the 10 cars. This is the array of structs that will be checked to find which cars are available and which cars are not available.
Pre-Condition: rentalCar cars[] is an array of structs that has contains the data of the 10 cars that the user has previously inputted. 
Post-Condition: rentalCar cars[] is an array of structs that contains the data of the 10 cars that the user has previous inputted. That is the array of structs that will be used to find which cars will be availble. There will be a bool check on the cars availbility for each and every car. An if statement in a for loop will be used to do this. If the if statement is true then, it will print the available cars from the array of structs to the terminal. The array of structs contains no changes to it.
the function does not have any return values.
*/

void print_available_cars (rentalCar cars[]);


int main() {

 
  int selection = 0;
  
  rentalCar cars[10];

  // a do-while loop that is used to run the program until the user enters 6.
  do{

     //displays the menu choices every time until the loop stops.
     cout << "\n********************\n";
     cout << "\tMenu\n";
     cout << "********************\n";
     cout << "1. Read Data From File \n";
     cout << "2. Print Data From File \n";
     cout << "3. Estimate Car Rental Cost \n";
     cout << "4. Find The Most Expensive Car \n";
     cout << "5. Print Out Available Cars \n";
     cout << "6. Exit \n\n";

     //user is prompted to enter the menu choice by the call of the function user_enter.
     user_enter(selection);
   
     //switch statement to run the menu choices. Each case is the call of individual functions. 
     switch (selection){

     case 1: 
          read_file(cars);
          cout << "\n";
          break;
     case 2:
	  cout << "\n";
          print_data(cars);
          break; 
     case 3:
          estimate_rental_cost(cars);
          cout << "\n";
          break;
     case 4:
	  most_expensive_car(cars);
	  cout << "\n";
	  break;
     case 5:
	  cout << "\n";
	  print_available_cars (cars);
	  cout << "\n";
	  break;
     case 6: 
	  cout << "The program will now exit.\n";
	  cout << "\n";
	  break;
     default: 
	  cout << "Please enter a number between 1-6.\n";
	  cout << "\n";	    

     } 
  }
  while (selection != 6);



  return 0;

}


void user_enter (int &user_enter){

   cout << "Enter your menu selection:";
   cin >> user_enter; 
   
}


void read_file (rentalCar cars[]){

   
   char inputFile[50];
   cout << "Enter the name of the input file:"; 
   cin >> inputFile;
   inputFile[49] = '\0';
   ifstream openFile;
   openFile.open(inputFile);

  for (int i = 0; i < 10; i++){

	    openFile >> cars[i].year >> cars[i].make >> cars[i].model >> cars[i].price >> cars[i].available;
    }

  openFile.close();

} 


void print_data (rentalCar cars[]){

   char outputFile[50];
   cout << "Enter the name of the output file:";
   cin >> outputFile;
   outputFile[49] = '\0';
   cout << "\n";

   cout << "All of the data for all of the cars: \n\n";
   
   for (int i = 0; i < 10; i++){

	cout << cars[i].year << " " << cars[i].make << " " << cars[i].model << "  $" << cars[i].price << " per day " << boolalpha << " Available:" << cars[i].available << "\n\n";
   }

  ofstream openOutputFile;
  openOutputFile.open(outputFile);
  //open the file with the name provided by the user.
    
   for (int i = 0; i < 10; i++){

	openOutputFile << cars[i].year << " " << cars[i].make << " " << cars[i].model << "  $" << cars[i].price << " per day " << boolalpha << " Available:" << cars[i].available << "\n\n";
   }
   openOutputFile.close(); 
}


void estimate_rental_cost (rentalCar cars[]){


   char outputFile[50];
   cout << "Enter the name of the output file:";
   cin >> outputFile;
   outputFile[49] = '\0';

   int car;
   int days;
   
   cout << "Enter the number of the car you wish to rent:";
   cin >> car;
   cout<< "Enter the number of days you wish to rent:"; 
   cin >> days; 

   float rental_cost = cars[car -1].price * days; 
  
   cout << "The rental would cost you: $" << rental_cost << "\n";

  
   ofstream openOutputFile;
   openOutputFile.open(outputFile);
   //open the file with the name provided by the user.

  
  openOutputFile << "The rental would cost you: $" << rental_cost << "\n";  
    
  openOutputFile.close(); 
}

void most_expensive_car (rentalCar cars[]){

   char outputFile[50];
   cout << "Enter the name of the output file:";
   cin >> outputFile;
   outputFile[49] = '\0';

   int most_expensive_car = 0; 
   
   for (int i = 0; i < 10; i++){

	if (cars[i].price > cars[most_expensive_car].price) {

	    most_expensive_car = i;
	}
   }

   cout << "The most expensive car is the " << cars[most_expensive_car].year << " " << cars[most_expensive_car].make << " " << cars[most_expensive_car].model << " and it would cost $" << cars   [most_expensive_car].price<< " per day. \n";

  
  ofstream openOutputFile;
  openOutputFile.open(outputFile);
  //open the file with the name provided by the user.


   openOutputFile << "The most expensive car is the " << cars[most_expensive_car].year << " " << cars[most_expensive_car].make << " " << cars[most_expensive_car].model << " and it would cost $" << cars   [most_expensive_car].price<< " per day. \n";
    
  openOutputFile.close(); 

}


void print_available_cars (rentalCar cars[]){

   char outputFile[50];
   cout << "Enter the name of the output file:";
   cin >> outputFile;
   outputFile[49] = '\0';

   cout << "\n";

   cout << "All of the data for available cars: \n\n";
   
   for (int i = 0; i < 10; i++){

	if (cars[i].available != false){

	    cout << cars[i].year << " " << cars[i].make << " " << cars[i].model << "  $" << cars[i].price << " per day " << boolalpha << " Available:" << cars[i].available << "\n\n"; 
        }
   }
 
  ofstream openOutputFile;
  openOutputFile.open(outputFile);
  //open the file with the name provided by the user.
 
  for (int i = 0; i < 10; i++){

	if (cars[i].available != false){

	    openOutputFile << cars[i].year << " " << cars[i].make << " " << cars[i].model << "  $" << cars[i].price << " per day " << boolalpha << " Available:" << cars[i].available << "\n\n"; 
        }
   }
       
  openOutputFile.close(); 

}

































