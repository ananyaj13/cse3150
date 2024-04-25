#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    double weight;
    string name;

public:
    Vehicle();
    Vehicle(string name);
    virtual ~Vehicle();

    virtual void Start();
    virtual void Stop();

    virtual double costOfFuel(double miles);
};

class Gasoline : public virtual Vehicle {
public:
    Gasoline(string name);
    virtual ~Gasoline();

    void Start() override;
    void Stop() override;

    double gasolineMilesPerGallon();
    double costOfFuel(double miles) override;
};

class Electric : public virtual Vehicle {
public:
    Electric(string name);
    virtual ~Electric();

    void Start() override;
    void Stop() override;

    double electricMilesPerDollar();
    double costOfFuel(double miles) override;
};

class Hybrid : public Electric, public Gasoline {
private:
    double percentGas; // Percentage of hybrid vehicle using gas

public:
    Hybrid(string name, double percentGas);
    virtual ~Hybrid();

    void Start() override;
    void Stop() override;

    double fuelEfficiencyPerDollar();
    double costOfFuel(double miles) override;
};

#endif 
