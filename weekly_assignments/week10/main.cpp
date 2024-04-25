#include <iostream>
#include "vehicle.h"

int main() {
    // Basic Vehicle
    std::cout << "Testing Vehicle\n";
    Vehicle vehicle("Basic Vehicle");
    vehicle.Start();
    vehicle.Stop();

    // Gasoline Vehicle
    std::cout << "\nTesting Gasoline Vehicle\n";
    Gasoline gasoline("Gasoline Vehicle");
    gasoline.Start();
    gasoline.Stop();

    double miles = 100.0;
    double gasCost = gasoline.costOfFuel(miles);
    std::cout << "Cost of fuel for " << miles << " miles (Gasoline): $" << gasCost << "\n";

    // Electric Vehicle
    std::cout << "\nTesting Electric Vehicle\n";
    Electric electric("Electric Vehicle");
    electric.Start();
    electric.Stop();

    double electricCost = electric.costOfFuel(miles);
    std::cout << "Cost of fuel for " << miles << " miles (Electric): $" << electricCost << "\n";

    double electricMilesPerDollar = electric.electricMilesPerDollar();
    std::cout << "Miles per dollar (Electric): " << electricMilesPerDollar << "\n";

    // Hybrid Vehicle with 50% Gas and 50% Electric
    std::cout << "\nTesting Hybrid Vehicle (50% Gas, 50% Electric)\n";
    Hybrid hybrid("Hybrid Vehicle", 0.5);
    hybrid.Start();
    hybrid.Stop();

    double hybridCost = hybrid.costOfFuel(miles);
    std::cout << "Cost of fuel for " << miles << " miles (Hybrid): $" << hybridCost << "\n";

    double hybridEfficiency = hybrid.fuelEfficiencyPerDollar();
    std::cout << "Fuel efficiency per dollar (Hybrid): " << hybridEfficiency << "\n";

    // Hybrid Vehicle with 75% Gas and 25% Electric
    std::cout << "\nTesting Hybrid Vehicle (75% Gas, 25% Electric)\n";
    Hybrid hybrid75("Hybrid 75% Gas", 0.75);
    hybrid75.Start();
    hybrid75.Stop();

    double hybrid75Cost = hybrid75.costOfFuel(miles);
    std::cout << "Cost of fuel for " << miles << " miles (Hybrid 75% Gas): $" << hybrid75Cost << "\n";

    // Hybrid Vehicle with 25% Gas and 75% Electric
    std::cout << "\nTesting Hybrid Vehicle (25% Gas, 75% Electric)\n";
    Hybrid hybrid25("Hybrid 25% Gas", 0.25);
    hybrid25.Start();
    hybrid25.Stop();

    double hybrid25Cost = hybrid25.costOfFuel(miles);
    std::cout << "Cost of fuel for " << miles << " miles (Hybrid 25% Gas): $" << hybrid25Cost << "\n";

    return 0;
}
