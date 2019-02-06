#ifndef PROJ4
#define PROJ4
#include <iostream>
#include <fstream>
/*
kripash Shrestha
The purpose of this program is copy the a datafile with of 1 agency which has 5 cars and up to 3 sensors and a possible owner. This will done through with the manipulation and data encapsulation of 3 different classes, CarSensors, RentalCars and RentalAgencies. This program will be constructed with while loops, arrays, arrow operators, pointer arithmetic, my own string compare and string copy functions and data encapsulation. This is the header file of the proj4.cpp and will contain functions and classes needed for the cpp file.
proj4.h
*/
using namespace std;
//CarSensor class, contains private memebers and constructors with functions. Necessary for our ADT RentalCar.
class CarSensor
{
    public:
        CarSensor();
        CarSensor(const CarSensor& object);
       
        CarSensor(char * source, float extracost);
	//The following are get and set methods. 
	//gets member m_type;
        char * getType(){
            return m_type;
        }
	//sets member m_type;
        void setType(char * source) {
            copystring(m_type, source);
        }
	//gets member m_extracost;
        float getExtraCost() {
            return m_extracost;
        }
	//sets member m_extracost;
        void setExtraCost(float val) {
            m_extracost = val;
        }
	//gets member gps_cnt;
        static int getGps_Cnt(){
            return gps_cnt;
        }
	//sets member gps_cnt;
        void setGps_Cnt(){
            gps_cnt++;
        }
	//gets member camera_cnt;
        static int getCamera_Cnt(){
            return camera_cnt;
        }
	//sets member camera_cnt;
        void setCamera_Cnt(){
            camera_cnt++;
        }
	//gets member lidar_cnt;
        static int getLidar_Cnt(){
            return lidar_cnt;
        }
	//sets member lidar_cnt;
        void setLidar_Cnt(){
            lidar_cnt++;
        }
	//gets member radar_cnt;
        static int getRadar_Cnt(){
            return radar_cnt;
        }
	//sets member radar_cnt;
        void setRadar_Cnt(){
            radar_cnt++;
        }
	//resets all of the static int sensors to 0;
	void resetSensor_Cnt(){
	     gps_cnt = 0;
	     camera_cnt = 0;
	     lidar_cnt = 0;
	     radar_cnt = 0;
	}
	

    protected:

    private:
        char m_type[50];
        float m_extracost;
        static int gps_cnt;
        static int camera_cnt;
        static int lidar_cnt;
        static int radar_cnt;
        void copystring(char * destination, const char * source);
};


//Default Constructor for the CarSensor class.
CarSensor::CarSensor(){
    m_type[0] = '\0';
    m_extracost = 0;
}

//intialize static int variables.
int CarSensor::gps_cnt = 0;
int CarSensor::camera_cnt = 0;
int CarSensor::lidar_cnt = 0;
int CarSensor::radar_cnt = 0;

//paramterialized constructor for the CarSensor class.
CarSensor::CarSensor(char * source, float extracost){

    copystring(m_type, source);
    m_extracost = extracost;

}

//copy constructor for the CarSensor class.
CarSensor::CarSensor(const CarSensor& carsensor){
    
    copystring(m_type, carsensor.m_type);
    m_extracost = carsensor.m_extracost;
}

//copy string function for the CarSensorclass.
void CarSensor::copystring(char * destination, const char * source) {

    while (*source) {
      *destination = *source;
      source++;
      destination++;
   }
   *destination = '\0';
}
//RentalCar class, contains private memebers and constructors with functions. Necessary for our ADT RentalAgency.
class RentalCar : public CarSensor
{
    public:
        RentalCar();
	RentalCar(char * make, char * model, int year, float tank, float baseprice, float finalprice, bool available, char * owner);
        RentalCar(const RentalCar& rentalcar);
	
	//gets member m_make.
        char * getMake(){
            return m_make;
        }
	//sets member m_make using copy string function.
        void setMake(char * source){
             copystring(m_make, source);
        }
	// gets member m_model.
        char * getModel(){
            return m_model;
        }
	//sets member m_model using copy string function.
        void setModel(char * source){
            copystring(m_model, source);
        }
	//gets member year.
        int getYear(){
            return m_year;
        }
	//sets member year.
        void setYear(int val){
            m_year = val;
        }
	//gets member tank.
        float getTank(){
            return m_tank;
        }
	//sets member tank.
        void setTank(float val){
            m_tank = val;
        }
	//gets class type array Car Sensor. the member is m_sensors.
        CarSensor * getSensors(){
            return m_sensors;
        }
	//gets member base price.
        float getBasePrice(){
            return m_baseprice;
        }
	//sets member base price.
        void setBasePrice(float val){
            m_baseprice = val;
        }
	//sets member final price.
        void setFinalPrice(float val){
	    m_finalprice = val;
	}
	//gets member final price.
        float getFinalPrice(){
            return m_finalprice;
        }
	//gets member available.
        bool getAvailable(){
            return m_available;
        }
	//sets member available.
        void setAvailable(bool val){
            m_available = val;
        }
	//gets member owner.
        char * getOwner(){
            return m_owner;
        }
	//sets member owner.
        void setOwner(char * source){
            copystring(m_owner, source);
        }
	//overloaded print function/
	void print(){
	    print(cout);
	}
	//sets number of sensors per car.
	void setNumSensors(unsigned int val){

		m_numsensors = val;	
	}
	//gets number of sensors per car.
	unsigned int getNumSensors() {
		return m_numsensors;
	}
	
	//adds a car sensor to the class.
	void addCarSensor();
	//print function to print all members of our class.
	void print (ostream& out) {
	    
	    out << "Year: " << m_year<< "\n";
	    out << "Make: " << m_make << "\n";
	    out << "Model: " << m_model << "\n";
	    out << "Maximum Tank: " << m_tank << "\n";
	    out << "Sensors: " ;
	    CarSensor * sensor_pt = m_sensors;		
	    for (int i = 0; i < m_numsensors ; ++i, ++sensor_pt){
		out << sensor_pt -> getType(); out << " ";	    
            }  		
	    out << "\n";
	    out << "Base Price: $" << m_baseprice << "\n";
	    out << "Final Price: $" << m_finalprice << "\n";
	    out << "Available: " << boolalpha << m_available << "\n";
	    out << "Owner: " << m_owner << "\n";
	    out << "\n";
	
	}
	//use to estimate cost of rental car.
	float estimate_cost(int days) const;
	//updates the price of the rental car to final price.
	void updatePrice(CarSensor * sensors);
	//adds car sensor to a car.
	void addCarSensor(char*name, int cost);
	//adds lessee to a car if the user wants to rent car.
	void addLessee(char*name);
	//string compare function using pointer arithmetic.
	int compare_string(char * first, char *second);

    protected:

    private:
        char m_make[30];
        char m_model[30];
        int m_year;
        float m_tank;
        CarSensor m_sensors[3];
        float m_baseprice;
        float m_finalprice;
        bool m_available;
        char m_owner[30];
	unsigned int m_numsensors;
        void copystring(char * destination, const char * source);
	
};
//default constructor for RentalCar class.
RentalCar::RentalCar()
{
     m_model[0] = m_make[0] = m_owner[0] = '\0';
     m_year = 0;
     m_tank = 0;
     m_available = false;
     m_tank = 0;
     //m_sensors[3];
     m_baseprice = 0;
     m_finalprice = 0;
}
//parameterized constructor for RentalCar class.
RentalCar::RentalCar(char * make, char * model, int year, float tank, float baseprice, float finalprice, bool available, char * owner){

	  copystring(m_make, make);
	  copystring(m_model, model);
	  copystring(m_owner, owner);
	  m_year = year;
	  m_tank = tank;
	  m_baseprice = baseprice;
	  m_finalprice = finalprice;
	  m_available = available; 
}
//copy constructor for RentalCar class.
RentalCar::RentalCar(const RentalCar& rentalcar)
{
    copystring(m_model, rentalcar.m_model);
    copystring(m_make, rentalcar.m_make);
    copystring(m_owner, rentalcar.m_owner);
    m_year = rentalcar.m_year;
    m_tank = rentalcar.m_tank;
    m_available = rentalcar.m_available;
    m_baseprice = rentalcar.m_baseprice;
    m_finalprice = rentalcar.m_finalprice;
    
}

//copy string for RentalCar class.
void RentalCar::copystring(char * destination, const char * source) {

    while (*source) {
      *destination = *source;
      ++source;
      ++destination;
   }
   *destination = '\0';
}
//update price function that updates the member final price of the car.
void RentalCar::updatePrice(CarSensor * sensors){
    
    float cost = 0;
    CarSensor * ptr; 
    ptr = sensors;   
    for (int i = 0; i < 3; i++, ptr++){

	 cost = cost + ptr -> getExtraCost(); 
   }
    cost = cost + getBasePrice();
    m_finalprice = cost;

}
//calculates the estimated cost of the rental car.
float RentalCar::estimate_cost(int days) const {

     return m_finalprice * days;

}
//compare string function used for determining car sensor value for setting extra cost. 
int RentalCar::compare_string(char *first, char *second) {
   while (*first == *second) {
      if (*first == '\0' || *second == '\0')
         break;
 
      first++;
      second++;
     }
 
   if (*first == '\0' && *second == '\0')
      return 0;
   else
      return -1;
}
//function used to add a car sensor to the class type CarSensors.
void RentalCar::addCarSensor(char*name, int cost){

	
     char array[5] = "none";
     int i;     
     CarSensor * sensor_pt = m_sensors;
     for( i = 0; i < 3; i++, sensor_pt++){
	 if ( sensor_pt -> getType() == '\0'){
	      sensor_pt -> setType(name);
	      sensor_pt -> setExtraCost(cost); 
	      break;
	 }
	 if ((compare_string(sensor_pt -> getType(), array ) != 0 )){
	     sensor_pt -> setType(name);
	     sensor_pt -> setExtraCost(cost); 
	     break;
	 }	 	 
     }         
}
//function that uses a pointer to add the name of a lessee to an available car the user wishes to rent.
void RentalCar::addLessee(char*name){
     setOwner(name);
     bool available = 0;
     setAvailable(available);
}
//RentalAgency class, contains private memebers and constructors with functions. Necessary for our entire program.
class RentalAgency : public RentalCar
{
    public:
        RentalAgency();
	RentalAgency(char * name, int * zip);
	//reads all of the data from the file.
	void ReadAllData (RentalAgency* rentalAgency);
	//prints all of the data from the class.
	void PrintAllData (RentalAgency* rentalAgency);
	//prints how many of each sensors there are by type.
	void PrintSensors(RentalAgency* rentalAgency);
	//prints the available cars.
	void PrintAvailableCars(RentalAgency* rentalAgency);
	//estimates the rental cost of the car multiplying by the days the user wishes to rent by.
	void EstimateRentalCost(RentalAgency* rentalAgency);
	//finds the most expensive car that is in the class.
	void mostExpensive(RentalAgency* rentalAgency);
	//finds the most avaialble expensive car and asks the user if they want to rent, and updates the lessee/owner name if they want to rent.
	void AvailableExpensive(RentalAgency* rentalAgency);

	//gets the member name of agency.
        char * getName(){
            return m_name;
        }
	//sets the name of the agency.
        void setName(const char * source){
            copystring(m_name, source);
        }
	//gets the zip code of agency.
        int * getZipcode(){           
	   return m_zipcode;
        }
	//sets the zip code of agency.
        void setZipcode(int * zip){	    
    	    int * zip_pt = zip;
    	    int * ptr = m_zipcode;
     	    for(int z=0;z<5;z++,zip_pt++,ptr++){	 
	 	*ptr = *zip_pt;
	    }
	}
	//gives access to the member m_inventory which is RentalCar class type.
        RentalCar * getInventory(){
            return m_inventory;
        }
	//ny own string compare function. returns 0 if the strings are identical, if not then 01.
	int compare_string(char * first, char *second);
	//my overloaded operator for the m_inventory class.
	RentalCar& operator[] (const int index);
    protected:

    private:
        char m_name[30];
        int m_zipcode[5];
        RentalCar m_inventory[5];
        void copystring(char * destination, const char * string);
};
//default constructor for the RentalAgency class.
RentalAgency::RentalAgency()
{
   m_name[30] = '\0';
   m_zipcode[5];

}
//used to copy a string from the constant source to a destination.
void RentalAgency::copystring(char * destination, const char * source) {

    while (*source) {
      *destination = *source;
      source++;
      destination++;
   }
   *destination = '\0';
}
//the overloaded opreator function to get access and write to m_inventory class.
RentalCar& RentalAgency::operator[] (const int index){
	return m_inventory[index];
}
//my own string compare function, used to compare 2 strings, returns 0 if the strings are identical, if not returns -1.
int RentalAgency::compare_string(char *first, char *second) {
   while (*first == *second) {
      if (*first == '\0' || *second == '\0')
         break;
 
      first++;
      second++;
     }
 
   if (*first == '\0' && *second == '\0')
      return 0;
   else
      return -1;
}

/*My read all data from file function as mentioned above. Takes a RentalAgency class as a parameter. Gets the input name of the file and then reads the data from the file and stores it into the members of all the classes using class functions via pointer arithmetic and arrow operators.
*/
void RentalAgency::ReadAllData (RentalAgency* rentalAgency){


   char inputFile[50];
   cout << "Enter the name of the input file:";
   cin >> inputFile;
   inputFile[49] = '\0';
   ifstream openFile;
   openFile.open(inputFile);

   
   char name[30];
   char make[30];
   char model[30];
   int year;
   float tank;
   float price;
   bool available;
   char owner[30];
   int i = 0;
   int z = 0;
   char sensor[10]; 
   int zip[5];
   float cost = 0;
   float extracost = 0;
   float base = 0;

       
   openFile >> name;
   setName(name);
   //cout << name << " ";
   openFile.get();  
   int * num_array_pt = zip;
   for(z=0;z<5;z++,num_array_pt++){
	//since .get() gets the ascii value of the digit we subtract it by the ascii value of 0
	*num_array_pt = openFile.get()-'0';
	//cout << *num_array_pt;
   }
   //cout << "\n";
   num_array_pt = zip;
   setZipcode(zip);  
    
   RentalCar * inventory_pt = rentalAgency -> m_inventory;    
   RentalCar * false_pt = rentalAgency -> m_inventory;  
    for( i = 0; i < 5; i++, false_pt++){
	CarSensor * false1 = false_pt -> getSensors(); 
	for(int j=0;j<3;j++,false1++){
	      false1 -> resetSensor_Cnt();
	}
    }

   unsigned int sensor_counter = 0;
   
   //increments for the rental car, stores the data into the RentalCar classes.
   for( i = 0; i < 5; i++, inventory_pt++){

	CarSensor * car_sensor_pt = inventory_pt -> getSensors();
	cost = 0;
	extracost = 0;
	sensor_counter = 0;
	openFile >> year >> make >> model >> tank >> price; 
	
	inventory_pt -> setYear(year);	
	inventory_pt -> setMake(make);
	inventory_pt -> setModel(model);
	inventory_pt -> setTank(tank);
	inventory_pt -> setBasePrice(price);
	openFile.get();
	openFile.get();
	
     //increments for the car sensors. maximum of 3. uses string compare and copy string functions with pointer arithmetic.
     for(int j=0;j<3;j++,car_sensor_pt++){
	
	openFile >> sensor;
	char *sensor_pt = sensor;
	char revised_sensor[10] = {'\0'};

	char *revised_pt = revised_sensor;
	char *orig_revised_pt = revised_pt;

	char strgps[4] = {'g','p','s','\0'};
	char *str1_pt = strgps;
	char strcamera[7] = {'c','a','m','e','r','a','\0'};
	char *str2_pt = strcamera;
	char strlidar[6] = {'l','i','d','a','r','\0'};
	char *str3_pt = strlidar;
	char strradar[6] = {'r','a','d','a','r','\0'};
	char *str4_pt = strradar;
	char strnone[6] = {'n','o','n','e','\0'};
	char *str5_pt = strnone;
	int k=0 ;	
	for( ;k<10;k++,sensor_pt++,revised_pt++){
		if(*sensor_pt == '}'){
		   *revised_pt = '\0';						
		   break;
		}
		else if(*sensor_pt == '\0'){
			*revised_pt = '\0';
			break;
		}
		else{
			*revised_pt = *sensor_pt;			
		}
	}
	if (k != 0){
		++sensor_counter;
	}

	
	//compares strings to assign the value of the member extra cost.
	if (compare_string(revised_sensor,str1_pt)== 0){
		cost = 5.0;
		car_sensor_pt->setGps_Cnt();		
	}
	else if (compare_string(revised_sensor,str2_pt)== 0){
		cost = 10.0;
		car_sensor_pt->setCamera_Cnt();
	}
	else if (compare_string(revised_sensor,str3_pt)== 0){
		cost = 15.0;
		car_sensor_pt->setLidar_Cnt();
	}
	else if (compare_string(revised_sensor,str4_pt)== 0){
		cost = 20.0;
		car_sensor_pt->setRadar_Cnt();
	}
	else {
		cost = 0.0;
	}

	car_sensor_pt->setType(revised_sensor);		
	car_sensor_pt->setExtraCost(cost);
	extracost = cost + extracost;
	
	inventory_pt -> setNumSensors(sensor_counter);
	if(*sensor_pt == '}'){
		break;
	}
     }

     base = inventory_pt -> getBasePrice();
     extracost = extracost + base;
     inventory_pt -> setFinalPrice(extracost);
     openFile >> available; 
     inventory_pt -> setAvailable(available);
     if (available == 0){
	openFile >> owner;
     }
     else{ 
	owner[0]= '\0';
	}
     inventory_pt -> setOwner(owner);
  }
  openFile.close();
}
/*function that takes in an output file that is entered by the user and prints all of the member functions of RentalCar class to the console and the output file. This will also read in the name of agency and zipcode of the RentalAgency and print that out to console and the output file.*/
void RentalAgency::PrintAllData (RentalAgency* rentalAgency){

	char outputFile[50];
   	cout << "Enter the name of the output file:";
  	cin >> outputFile;
   	outputFile[49] = '\0';
	ofstream openOutputFile;
   	openOutputFile.open(outputFile);
	//standard cout for a stream and then prints the name of the agency and the zipcode of the agency.
	cout <<"All Data for All Cars \n\n";
	openOutputFile <<"All Data for All Cars \n\n"; 
	cout<< rentalAgency -> getName();
	int * zip   = rentalAgency -> getZipcode();
	cout << " ";
	for(int j = 0; j < 5; j++, zip++){
		cout << * zip;
	}
	cout << "\n";
	cout << "\n";
	//This is used to print all the data to the console and to the outputfile.
	RentalCar * inventory_pt = rentalAgency -> m_inventory;
	CarSensor * car_sensor_pt = inventory_pt -> getSensors();
	for(int i = 0; i < 5; i++, inventory_pt++){
		inventory_pt->print(cout);
		inventory_pt->print(openOutputFile);
		CarSensor * car_sensor_pt = inventory_pt -> getSensors();
		for(int z=0;z<3;z++,car_sensor_pt++){
		}
	}
	openOutputFile.close();
	
}
//prints the amount of sensors there are in the agency fleet by the sensor type/name.
void RentalAgency::PrintSensors(RentalAgency* rentalAgency){

	char outputFile[50];
   	cout << "Enter the name of the output file:";
  	cin >> outputFile;
   	outputFile[49] = '\0';
	ofstream openOutputFile;
   	openOutputFile.open(outputFile);
	//used to access the static int for the rental sensors.	
	RentalCar * inventory_pt = rentalAgency -> m_inventory;
	CarSensor * car_sensor_pt = inventory_pt -> getSensors();
	for(int i = 0; i < 5; i++, inventory_pt++){
		CarSensor * car_sensor_pt = inventory_pt -> getSensors();
		for(int z=0;z<3;z++,car_sensor_pt++){
		}
	}
	//prints out the values of the static int by sensor type to the console.
	cout << "Sensor Counts \n";
	cout << "Amount of GPS Sensors: " << car_sensor_pt -> getGps_Cnt() <<  "\n";
	cout << "Amount of Camera Sensors: " << car_sensor_pt -> getCamera_Cnt() << "\n";
	cout << "Amount of Lidar Sensors: "<< car_sensor_pt -> getLidar_Cnt() << "\n";
	cout << "Amount of Radar Sensors: " << car_sensor_pt -> getRadar_Cnt() << "\n";
 	//prints out the values of the static int by sensor type to the outputfile.
	openOutputFile << "Sensor Counts \n";
	openOutputFile << "Amount of GPS Sensors: " << car_sensor_pt -> getGps_Cnt() <<  "\n";
	openOutputFile << "Amount of Camera Sensors: " << car_sensor_pt -> getCamera_Cnt() << "\n";
	openOutputFile << "Amount of Lidar Sensors: "<< car_sensor_pt -> getLidar_Cnt() << "\n";
	openOutputFile << "Amount of Radar Sensors: " << car_sensor_pt -> getRadar_Cnt() << "\n";
	openOutputFile.close();
}
//prints the available cars from the agency fleet and car types. Look for the bool value to be true and then prints.
void RentalAgency::PrintAvailableCars(RentalAgency* rentalAgency){
	
	char outputFile[50];
   	cout << "Enter the name of the output file:";
  	cin >> outputFile;
   	outputFile[49] = '\0';
	ofstream openOutputFile;
   	openOutputFile.open(outputFile);
	//standard cout for a stream and then prints the name of the agency and the zipcode of the agency.
	cout <<"All Data for Available Cars \n\n";
	openOutputFile <<"All Data for Available Cars \n\n";
	cout<< rentalAgency -> getName();
	int * zip   = rentalAgency -> getZipcode();
	cout << " ";
	for(int j = 0; j < 5; j++, zip++){
		cout << * zip;
	}
	cout << "\n";
	cout << "\n";
	RentalCar * inventory_pt = rentalAgency -> m_inventory;
	CarSensor * car_sensor_pt = inventory_pt -> getSensors();
	for(int i = 0; i < 5; i++, inventory_pt++){
	    //if statement that checks if the bool value is true to print the car data to the console and outputfile.
	    if((inventory_pt-> getAvailable())!= false){
		inventory_pt->print(cout);
		inventory_pt->print(openOutputFile);
		CarSensor * car_sensor_pt = inventory_pt -> getSensors();
		for(int z=0;z<3;z++,car_sensor_pt++){
		}
	    }
	}	

	openOutputFile.close();
}
/*Makes a user choose a car and then makes the car pointer point to that car. The user decides the car choice by 1-5 rather than by string. The user will then put how many days they wish to rent the car after being prompted to do so. The function will then multiple the final price of the car by the days wished to be rent and then print that value to the console and outputfile.
*/
void RentalAgency::EstimateRentalCost(RentalAgency* rentalAgency){

	char outputFile[50];
   	cout << "Enter the name of the output file:";
  	cin >> outputFile;
   	outputFile[49] = '\0';
	ofstream openOutputFile;
   	openOutputFile.open(outputFile);

	int car = 0;
	int days = 0;
	float rental;
	//prompts the user to enter the car that he/she wishes to rent, based on numbers 1-5.
	cout << "Enter the number of the car you wish to rent (Enter a number from 1 - 5): ";
   	cin >> car;
	//prompts the user to enter the amount of days that he/she wishes to rent the car.
   	cout<< "Enter the number of days you wish to rent: ";
   	cin >> days;
	//points to the car that the user wishes to rent and gets the value of its final price.
	RentalCar * inventory_pt = rentalAgency -> m_inventory;
	CarSensor * car_sensor_pt = inventory_pt -> getSensors();
	for(int i = 0; i < car; i++, inventory_pt++){
		rental = inventory_pt-> getFinalPrice();
		CarSensor * car_sensor_pt = inventory_pt -> getSensors();
		for(int z=0;z<3;z++,car_sensor_pt++){
		}
	}
	//prints the rental cost multiplied by the days to the console and outputfile.	
	cout << "The Rental would could you: $" << rental * days << "\n";
	openOutputFile << "The Rental would could you: $" << rental * days << "\n";

	openOutputFile.close();
}
//finds the most expensive car in the agency fleet by using 2 pointers and pointer arithmetic. Prints the data of the most expensive car to the console and to the outputfile. 
void RentalAgency::mostExpensive(RentalAgency* rentalAgency){
	
	char outputFile[50];
   	cout << "Enter the name of the output file:";
  	cin >> outputFile;
   	outputFile[49] = '\0';
	ofstream openOutputFile;
   	openOutputFile.open(outputFile);
	//uses the 2 pointers to find the most expensive car.
	RentalCar * inventory_pt = rentalAgency -> m_inventory;
	RentalCar * expensive = rentalAgency -> m_inventory;
	//increments a pointer so that they arent pointing to the same car at the beginning. 
	inventory_pt ++;	
	for(int i = 0; i < 4; i++, inventory_pt++){
		//if the finalprice of the second car is greater than the first car, the pointer will be moved to the second car. And so on until the 			loop stops.  
		if ((inventory_pt-> getFinalPrice()) > (expensive -> getFinalPrice())){
			expensive = inventory_pt;
		}
	}
	//prints the data members of the most expensive car to the outputfile and the console.	
	cout << "This is the most expensive car: \n";
	expensive -> print(cout);
	openOutputFile << "This is the most expensive car: \n";
	expensive -> print(openOutputFile);

	openOutputFile.close();
}
/*finds the most expensive car that is available to the console and outputfile. Then asks the user if he/she wishes to rent the car. If the user enters yes, the owner of that car will be updated to the name that the user enters after being prompted to do so. If no, the function will just stop. This checks for 2 statements, the availability of the car and if the pointer to the second car is larger than the pointer value of the first car.*/
void RentalAgency::AvailableExpensive(RentalAgency* rentalAgency){

	char outputFile[50];
   	cout << "Enter the name of the output file:";
  	cin >> outputFile;
   	outputFile[49] = '\0';
	ofstream openOutputFile;
   	openOutputFile.open(outputFile);

	RentalCar * inventory_pt = rentalAgency -> m_inventory;
	RentalCar * expensive = rentalAgency -> m_inventory;
	float test;	
	int counter =0;	
	/*increments the first pointer to find the first available car and pointers to that car for its final price value. Also increments the counter 		to see how many times the loop later will need to be iterated.*/
	while(inventory_pt -> getAvailable() == false){
	      inventory_pt++;
	      counter++;
	}
	//sets the second pointer to the pointer address of the first pointer.
	expensive = inventory_pt;	
	//increents the first pointer to make sure that the 2 pointers are not pointing to the same object for comparison.
	inventory_pt++;
	//increments the counter once more for loop iteration since the first pointer was incremented once more.
	counter++;
	//for loop that iterates from the counter value to the amount of rental car possible.
	for(int i = counter; i < (5); i++, inventory_pt++){
		/*checks if the car is available and also checks if the final price of the first prointer is larger than the second price.
		If that is the case then the second pointer will point to the first pointer and then the loop will continue iteration. */
		if (((inventory_pt-> getFinalPrice()) > (expensive -> getFinalPrice())) && (inventory_pt -> getAvailable() == true)){
			expensive = inventory_pt;
		
		}
	   
	}
	//prints the data members of the most expensive available car to the console and the outputfile.	
	cout << "This is the most expensive available car: \n";
	expensive -> print(cout);
	openOutputFile << "This is the most expensive available car: \n";
	expensive -> print(openOutputFile);
	// array used to hold the users answer, either yes or no.
	char user[5];
	//asks if the user would like to rent the car.
	cout << "Would you like to rent the car(yes or no)? ";
	cin >> user;
	//string array that says yes to compare the usres answer to the prompt.
	char stryes[4] = {'y','e','s','\0'};
	char *yes = stryes;
	//holds the name of the lessee to assign to the car's member owner.
	char firstname[15];
	//if the user enters yes, the user will be prompted for a first name and then the first name will be added to the car's owner member.
	if(compare_string(yes,user) == 0){
		cout << "What is your first name? ";
		cin >> firstname;
		expensive -> addLessee(firstname);
	}

	openOutputFile.close();		
}





#endif // PROJ4_H
