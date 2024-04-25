#include "vehicle.h"

Vehicle::Vehicle() {
    cout << "Constructor(): Vehicle" << endl;
}

Vehicle::Vehicle(string name) : name(name), weight(0) {
    cout << "Constructor(string name): Vehicle" << endl;
}

Vehicle::~Vehicle() {
    cout << "Destructor: Vehicle" << endl;
}

void Vehicle::Start() {
    cout << "Vehicle START" << endl;
}

void Vehicle::Stop() {
    cout << "Vehicle STOP" << endl;
}

double Vehicle::costOfFuel(double miles) {
    return 0;
}



Gasoline::Gasoline(string name) : Vehicle(name) {
    cout << "Constructor: Gasoline" << endl;
}

Gasoline::~Gasoline() {
    cout << "Destructor: Gasoline" << endl;
}

void Gasoline::Start() {
    cout << "Gasoline Vehicle START" << endl;
}

void Gasoline::Stop() {
    cout << "Gasoline Vehicle STOP" << endl;
}

double Gasoline::gasolineMilesPerGallon() {
    return 25.0; 
}

double Gasoline::costOfFuel(double miles) {
    double gallonsNeeded = miles / gasolineMilesPerGallon();
    double costPerGallon = 3.50; // Assume $3.50 per gallon
    return gallonsNeeded * costPerGallon;
}



Electric::Electric(string name) : Vehicle(name) {
    cout << "Constructor: Electric" << endl;
}

Electric::~Electric() {
    cout << "Destructor: Electric" << endl;
}

void Electric::Start() {
    cout << "Electric Vehicle START" << endl;
}

void Electric::Stop() {
    cout << "Electric Vehicle STOP" << endl;
}

double Electric::electricMilesPerDollar() {
    double costPer33_7kWh = 33.7 * 0.24; // Cost per 33.7 kWh
    return 100 / costPer33_7kWh; // Miles per dollar
}

double Electric::costOfFuel(double miles) {
    double costPer33_7kWh = 33.7 * 0.24; // Cost per 33.7 kWh
    double kWhNeeded = (miles / 100) * 33.7;
    return kWhNeeded * costPer33_7kWh;
}



Hybrid::Hybrid(string name, double percentGas) 
    : Electric(name), Gasoline(name), percentGas(percentGas) {
    cout << "Constructor: Hybrid" << endl;
}

Hybrid::~Hybrid() {
    cout << "Destructor: Hybrid" << endl;
}

void Hybrid::Start() {
    cout << "Hybrid START" << endl;
}

void Hybrid::Stop() {
    cout << "Hybrid STOP" << endl;
}

double Hybrid::fuelEfficiencyPerDollar() {
    double electricEfficiency = electricMilesPerDollar();
    double gasolineEfficiency = gasolineMilesPerGallon();
    
    // Calculate weighted average based on percentGas
    return (electricEfficiency * (1 - percentGas)) + (gasolineEfficiency * percentGas);
}

double Hybrid::costOfFuel(double miles) {
    double electricCost = Electric::costOfFuel(miles * (1 - percentGas));
    double gasolineCost = Gasoline::costOfFuel(miles * percentGas);
    return electricCost + gasolineCost;
}
