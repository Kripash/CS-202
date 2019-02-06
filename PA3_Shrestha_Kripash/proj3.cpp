/*
kripash Shrestha
The purpose of this program is copy the a datafile with 10 different cars and then have a user interactive menu that allows the user to read all data from a file, print out all the data for all of the cars, estimate the rental cost of a car, find the most expensive car, and printout the data for all of the available cars. This program will be be completed with an array of structs, switch statements and a do while loop every menu option being its own individual function. This is expanded on project 2 by the addition of the RentalCar class and the use of pointer arithmetic rather than array manipulation. 
proj3.cpp
*/
#include <iostream>
#include <fstream>

using namespace std;

//RentalCar class, contains private memebers and public constructors with functions. Necessary for our ADT structure RentalAgencies. 
class RentalCar{

   private: 
  
   char m_make[30];
   char m_model[30];
   int m_year;
   float m_price;
   bool m_available;

   //copies the strings from one location to another. 
   void copystring(char * destination, const char * string);
   

  public:
    //Default Constructor
    RentalCar() {
      m_model[0] = m_make[0] = '\0';
      m_year = 0;
      m_price = 0;
      m_available = false;
    }
     
   float RentalCost (int days);

    //Parameterized Constructor
    RentalCar(char* make, char* model, int year, float price, bool available)
    {
      copystring(m_make, make);
      copystring(m_model, model);
      m_year = year;
      m_price = price;
      m_available = available;
    }

    //Get and set methods
    //gets the value of member make
    const char* getMake() const {
      return m_make;
    }

    //sets the value of member make
    void setMake(char* make) {
      copystring(m_make, make);
    }

    //gets the value of member model
    const char* getModel() const {
      return m_model;
    }

    //sets the value of member model
    void setModel(char* model) {
      copystring(m_model, model);
    }

    //gets the value of member year
    int getYear() const {
      return m_year;
    }

     //sets the value of member year
    void setYear(int year) {
      m_year = year;
    }

    //gets the value of member price
    float getPrice() const {
      return m_price;
    }
 
     //sets the value of member price
    void setPrice(float price) {
      m_price = price;
    }

    //gets the value of member available
    bool isAvailable() const {
      return m_available;
    }

     //sets the value of member available
    void setAvailable(bool available) {
      m_available = available;
    }

    //Print method
    void print() const {
      print(cout);
    }

    //Overloaded print method
    //Will be used to print to any output stream like file
    void print(ostream& out) const {
      out << m_year << " " << m_make << " " << m_model
          << " $" << m_price << " per day Available: " << boolalpha << m_available << "\n";
    }

    //estimates the cost of a certain rental car
    float estimateCost(int days) const {
      return m_price * days;
    }
};

//Rental Agency structure
struct RentalAgency {
  char name[30];
  int zipCode[5];
  RentalCar inventory[5];

};


/*
Function Name: user_enter
The function prompts the user to enter the menu selection as an integer.
Parameter int &user_enter:This is the integer passed by reference that the value the user enters will be stored into.
Pre-Condition: &user_enter is an integer type containing the value 0. This is referenced to the integer "selection" in the main.
Post-Condition: &user_enter is an integer type contaning the value that the user will enter as their menu choice. This is referenced to the integer "selection" in the main.
the function does not have any return values.
*/

void user_enter (int &user_enter);

/*
Function Name: read_file
The function prompts the user to enter the name of the file that will be used to copy the data of the given file.The function will then copy the data from that file to the structure and class members.
Parameter RentalAgency * rentalAgencies :This is the pointer to the array of structs that contains the class RentalCar.
Parameter int& length : this is used as a counter to count many times to loop the for loops. Is initially how many cars are in a certain agency.
Pre condition: The function will have a value of length and a strcture and class that has not been intialized. 
Post condition: The function will intialize the structure and class using the RentalAgency pointer and other pointers that are local to the function. I will use pointer arithmetic and nested for loops to intialize the structure and class. The set methods will be used to initialize the structure and arrays.
the function does not have any return values.
*/

void read_file (RentalAgency* rentalAgencies, int& length);

/*
Function Name: print_data
The function prints all of the data from the array of structs to the terminal.
Parameter RentalAgency * rentalAgencies :This is the pointer to the array of structs that contains the class RentalCar.
Parameter int& length : this is used as a counter to count many times to loop the for loops. Is initially how many cars are in a certain agency.
Pre condition: The function will have a value of length and a strcture and class that have been intialized by the read file function.
Post condition: The function will use the get method via local pointers and pointer arithmetic in nested for loops to retrieve the data from the structure and class and display it to the terminal and output it to a file. The first for loop will increment every agency and the second one will increment to every location of the car to use the get method function to get all the data.
the function does not have any return values.
*/

void print_data (RentalAgency* rentalAgencies, int& length);

/*
Function Name: estimate_rental_cost
The function prompts the user to select an agency (1-3) and a car (1-5) and also prompts the user to enter the number of days the user wishes to rent the car. The function will then print out the estimated cost of the rental.
Parameter RentalAgency * rentalAgencies :This is the pointer to the array of structs that contains the class RentalCar.
Parameter int& length : this is used as a counter to count many times to loop the for loops. Is initially how many cars are in a certain agency.
Pre condition: The function will have a value of length and a strcture and class that have been intialized by the read file function.
Post condition: The function will use the get method via local pointers and pointer arithmetic in nested for loops to retrieve the data from the structure and class and display it to the terminal and output it to a file. The first for loop will increment to the location of the agency , the second one will increment to the location of the car and then use the get method to get the price of the car and then multiply it by the amount of days that the user wishes to rent.
the function does not have any return values.
*/
void estimate_rental_cost (RentalAgency* rentalAgencies, int& length);

/*
Function Name: most_expensive_car
The function checks the price of each individual car and compares it to each other to find the most expensive car in the array of structs.
Parameter RentalAgency * rentalAgencies :This is the pointer to the array of structs that contains the class RentalCar.
Parameter int& length : this is used as a counter to count many times to loop the for loops. Is initially how many cars are in a certain agency.
Pre condition: The function will have a value of length and a strcture and class that have been intialized by the read file function.
Post condition: The function will use the get method via local pointers and pointer arithmetic in nested for loops to retrieve the data from the structure and class and display it to the terminal and output it to a file. The first for loop will increment a local pointer to the location of the agency , the second one will increment to the location of the car and then use the get method to get the price of the car then compare it to a second local pointer that will point to the location of the agency and the location of the car of the highest valued car so far.
the function does not have any return values.
*/

void most_expensive_car (RentalAgency* rentalAgencies, int& length);

/*
Function Name: print_available_cars
The function prints all of the cars that are available from the array of structs to the terminal.
Parameter RentalAgency * rentalAgencies :This is the pointer to the array of structs that contains the class RentalCar.
Parameter int& length : this is used as a counter to count many times to loop the for loops. Is initially how many cars are in a certain agency.
Pre condition: The function will have a value of length and a strcture and class that have been intialized by the read file function.
Post condition: The function will have a value of length and a strcture and class that have been intialized by the read file function.
Post condition: The function will use the get method via local pointers and pointer arithmetic in nested for loops to retrieve the data from the structure and class and display it to the terminal and output it to a file. The first for loop will increment every agency and the second one will increment to every location of the car to use the get method function to get all the data. However, an if statement will be used with the isAvailable function to check if the car is available or not. The function will only print cars that are available.
the function does not have any return values.
*/

void print_available_cars (RentalAgency* rentalAgencies, int& length);



int main() {


  int selection = 0;

  RentalAgency rentalAgencies[5];
  int length = 0;
  // a do-while loop that is used to run the program until the user enters 6.
  do{

     //displays the menu choices every time until the loop stops.
     cout << "\n********************\n";
     cout << "\tMenu\n";
     cout << "********************\n";
     cout << "1. Read All Data From File \n";
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
          read_file(rentalAgencies, length);
          cout << "\n";
          break;
     case 2:
          print_data(rentalAgencies, length);
          break;
     case 3:
          estimate_rental_cost(rentalAgencies, length);
          cout << "\n";
          break;
     case 4:
      	  most_expensive_car(rentalAgencies, length);
          cout << "\n";
          break;
     case 5:
          print_available_cars (rentalAgencies, length);
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

void RentalCar::copystring(char * destination, const char * string) {

    while (*string) {
      *destination = *string;
      string++;
      destination++;
   }
   *destination = '\0';
}


void user_enter (int &user_enter){

   cout << "Enter your menu selection:";
   cin >> user_enter;

}


void read_file (RentalAgency* rentalAgencies, int& length){


   char inputFile[50];
   cout << "Enter the name of the input file:";
   cin >> inputFile;
   inputFile[49] = '\0';
   ifstream openFile;
   openFile.open(inputFile);

   char make[30];
   char model[30];
   int year;
   float price;
   bool available;
   int i = 0;
   int z = 0;
   int * num_array_pt;
   

    for(i = 0; i < 3; i++, rentalAgencies++) {
      openFile >> rentalAgencies -> name; 
      openFile.get();
      num_array_pt = rentalAgencies -> zipCode;
      for(z=0;z<5;z++,num_array_pt++){
		//since .get() gets the ascii value of the digit we subtract it by the ascii value of 0
		*num_array_pt = openFile.get()-'0';
	}
      RentalCar * inventory_pt = rentalAgencies -> inventory;

      //cout << "\nReading" << rentalAgencies[i].name << " " << zip << "\n";
      int j = 0;
        for (j = 0; j < 5; j++, inventory_pt++) {
          openFile >> year >> make >> model >> price >> available;
          //cout << year << " " << make << " " << model << " " << price << " " << available << "\n";
          inventory_pt->setMake(make);
          inventory_pt->setModel(model);
          inventory_pt->setPrice(price);
          inventory_pt->setYear(year);
          inventory_pt->setAvailable(available);
          
        }
        
        length++;
    }

  openFile.close();
}


void print_data (RentalAgency* rentalAgencies, int& length){

   char outputFile[50];
   cout << "Enter the name of the output file:";
   cin >> outputFile;
   outputFile[49] = '\0';
   cout << "\n";
   int i = 0;
   int z = 0;
   ofstream openOutputFile;
   openOutputFile.open(outputFile);
   

   cout << "All of the data for all of the cars: \n\n";

   for(i = 0; i < 3; i++, rentalAgencies++) {
       cout << rentalAgencies -> name;
       cout << " ";
       openOutputFile << rentalAgencies -> name;
       openOutputFile << " ";
       int * zip_pt = rentalAgencies -> zipCode;
       for(z=0;z<5;z++,zip_pt++){
		
		cout << * zip_pt;
		openOutputFile << * zip_pt;
	}
       
       cout << "\n";
       openOutputFile << "\n";
      
      RentalCar * inventory_pt = rentalAgencies -> inventory;

      //cout << "\nReading" << rentalAgencies[i].name << " " << zip << "\n";
      int j = 0;
        for (j = 0; j < 5; j++, inventory_pt++) {
          
          //cout << year << " " << make << " " << model << " " << price << " " << available << "\n";
          inventory_pt -> print(cout);
	  inventory_pt -> print(openOutputFile);
          
        }
        openOutputFile << "\n";
	cout << "\n";
        
        length++;
    }
   openOutputFile.close();
}

float RentalCar::RentalCost (int days){

	return m_price * days;
}

void estimate_rental_cost (RentalAgency* rentalAgencies, int& length){

   char outputFile[50];
   cout << "Enter the name of the output file:";
   cin >> outputFile;
   outputFile[49] = '\0';

   int car;
   int days;
   int agency;
   float rental_cost = 0;

   cout << "Enter the rental agency you wish to rent from (Enter a number from 1 - 3): ";
   cin >> agency; 
   cout << "Enter the number of the car you wish to rent (Enter a number from 1 - 5): ";
   cin >> car;
   cout<< "Enter the number of days you wish to rent: ";
   cin >> days;

   
   int i = 0, j = 0;
   for (i = 0; i < agency-1; rentalAgencies++, i++){
   }
   RentalCar * inventory_pt = rentalAgencies -> inventory;
   for(j = 0; j < car; j++ , inventory_pt++){
  	  rental_cost = inventory_pt -> RentalCost(days);
	}

   cout << "The rental would cost you: $" << rental_cost << "\n";


   ofstream openOutputFile;
   openOutputFile.open(outputFile);
   //open the file with the name provided by the user.


  openOutputFile << "The rental would cost you: $" << rental_cost << "\n";

  openOutputFile.close();




}

void most_expensive_car (RentalAgency* rentalAgencies, int& length){

   char outputFile[50];
   cout << "Enter the name of the output file:";
   cin >> outputFile;
   outputFile[49] = '\0';

  
    int i = 0;
    int j = 0;
    float max_so_far = 0;
    const char * car;
    char * agency ;
    int year = 0;
    const char * make;
    int * zip;
    RentalCar * inventory_pt = rentalAgencies -> inventory;
    

    for (i = 0; i < 3; i++, rentalAgencies++){
	 inventory_pt = rentalAgencies -> inventory;
	 for(j = 0; j < 5; j++,inventory_pt++){

	     if ((inventory_pt -> getPrice()) > max_so_far){
		     max_so_far = inventory_pt -> getPrice();
		     zip = rentalAgencies -> zipCode;
		     make = inventory_pt -> getMake();
		     agency = rentalAgencies -> name;
		     year = inventory_pt -> getYear();
		     car = inventory_pt -> getModel();  		     
	     }
         }
   } 

  ofstream openOutputFile;
  openOutputFile.open(outputFile);
  //open the file with the name provided by the user.

   
   cout << "The most expensive car is the " << year << " " << make << " " << car << " and it would cost $" << max_so_far << " per day. It is available at the " << agency << " agency." << "\n";
   openOutputFile << "The most expensive car is the " << year << " " << make << " " << car << " and it would cost $" << max_so_far << " per day.It is available at the " << agency << " agency." << "\n";
   openOutputFile.close();


}


void print_available_cars (RentalAgency* rentalAgencies, int& length){

   char outputFile[50];
   cout << "Enter the name of the output file:";
   cin >> outputFile;
   outputFile[49] = '\0';

   cout << "\n";

   cout << "All of the data for available cars: \n\n";

   ofstream openOutputFile;
   openOutputFile.open(outputFile);

   int i = 0;
   int z = 0;

   for(i = 0; i < 3; i++, rentalAgencies++) {
       cout << rentalAgencies -> name;
       cout << " ";
       openOutputFile << rentalAgencies -> name;
       openOutputFile << " ";
       int * zip_pt = rentalAgencies -> zipCode;
       for(z=0;z<5;z++,zip_pt++){
		
		cout << * zip_pt;
		openOutputFile << * zip_pt;
	}
       cout <<"\n";
       openOutputFile << "\n";
      
      RentalCar * inventory_pt = rentalAgencies -> inventory;

      //cout << "\nReading" << rentalAgencies[i].name << " " << zip << "\n";
      int j = 0;
        for (j = 0; j < 5; j++, inventory_pt++) {
             
	     if ((inventory_pt -> isAvailable()) != false){
        
                 inventory_pt -> print(cout);
	         inventory_pt -> print(openOutputFile);
	     }
          
        }
        openOutputFile << "\n";
	cout << "\n";
   }
  openOutputFile.close();


}













