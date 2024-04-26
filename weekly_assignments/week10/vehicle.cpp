#include "vehicle.h"
#include <iostream>

using namespace std;

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

double Gasoline::gasolineMilesPerGallon() { //fuel efficiency 
    return 20.0; 
}

double Gasoline::costOfFuel(double miles) { 
    return 2.50;
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

double Electric::electricMilesPerDollar() { //fuel efficiency
    return 20.0;
}

double Electric::costOfFuel(double miles) {
    return 0.24;
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
