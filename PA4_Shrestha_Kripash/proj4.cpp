/*
kripash Shrestha
The purpose of this program is copy the a datafile with of 1 agency which has 5 cars and up to 3 sensors and a possible owner. This will done through with the manipulation and data encapsulation of 3 different classes, CarSensors, RentalCars and RentalAgencies. This program will be constructed with while loops, arrays, arrow operators, pointer arithmetic, my own string compare and string copy functions and data encapsulation.
proj4.cpp
*/

#include <iostream>
#include <fstream>
#include "proj4.h"
using namespace std;

//this function will prompt the user to enter an integer as the menu choice of the user.
void user_enter (int &user_enter);


int main(){
    //declares the Rental Agency class.
    RentalAgency rentalagency[1];
    int select = 0;

    do{
     cout << "\n********************\n";
     cout << "\tMenu\n";
     cout << "********************\n";
     cout << "1. Read All Data From File \n";
     cout << "2. Print ALL Data From File \n";
     cout << "3. Estimate Car Rental Cost \n";
     cout << "4. Find The Most Expensive Car \n";
     cout << "5. Print Out Available Cars \n";
     cout << "6. Print Out Total Sensors in Agency \n";
     cout << "7. Find The Most Expensive Available Car \n";
     cout << "8. Exit \n\n";

     //user is prompted to enter a number.
     user_enter(select);
     //calls the functionalities of the menu option based on the user choice.
     switch (select){

     case 1:
	  //calls the ReadAllData function from the RentalAgency class to read the file.
          rentalagency -> ReadAllData(rentalagency);
          cout << "\n";
          break;
     case 2:
	  //calls the PrintAllData function from the RentalAgency class to print the data of the RentalCar class to the console and outputfile.
    	  rentalagency -> PrintAllData(rentalagency);
          break;
     case 3:
	  //calls the EstimateRentalCost function from the RentalAgency class to estimate rental cost of a car that the user prompts.
          rentalagency -> EstimateRentalCost(rentalagency);
    	  cout <<"\n";
          break;
     case 4:
	  //calls the mostExpensive funtion from the RentalAgency class to find the most expensive car in the rental agency fleet.
      	  rentalagency -> mostExpensive(rentalagency);
          cout << "\n";
          break;
     case 5:
	  //calls the PrintAvailableCars functions from the RentalAgency class to print all the available cars of the rental agency fleet.
          rentalagency -> PrintAvailableCars(rentalagency);
    	  cout << "\n";
          break;
     case 6:
	   //calls the PrintSensors functions from the RentalAgency class to print the amount of sensors for each sensor type.
	   rentalagency -> PrintSensors(rentalagency);
	   cout <<"\n";
	   break;
     case 7: 
	   //calls the AvailableExpensive function from the RentalAgency class to find the most expensive available car. The user will then be asked if 	   he/she wishes to rent the car.
	   rentalagency -> AvailableExpensive(rentalagency);
	   cout < "\n";
	   break;
     case 8:
	  //if the user selects this, the program will exit.
          cout << "The program will now exit.\n";
          cout << "\n";
          break;
     default:
	//if the user doesn't select between 1-8 inclusively, it will prompt the user to enter a number between 1-8.
          cout << "Please enter a number between 1-8.\n";
          cout << "\n";
     }
  }
  while (select!= 8);	
    
    
return 0;
}

void user_enter (int &user_enter){

   cout << "Enter your menu selection:";
   cin >> user_enter;

}
