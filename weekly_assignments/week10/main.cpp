#include "vehicle.h"
#include <iostream>

int main() {
    std::string vehicleName = "Hybrid Supercar";
    double percentGas = 0.5; // 50% gasoline, 50% electric
    
    Hybrid hybrid(vehicleName, percentGas);

    // Test the basic functionality
    hybrid.Start();
    
    std::cout << "Fuel efficiency per dollar: " << hybrid.fuelEfficiencyPerDollar() << std::endl;
    
    double distance = 100; // 100 miles to calculate cost
    double fuelCost = hybrid.costOfFuel(distance);
    
    std::cout << "Cost of fuel for 100 miles: $" << fuelCost << std::endl;
    
    hybrid.Stop();
    
    return 0;
}
