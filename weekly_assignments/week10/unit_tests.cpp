#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "vehicle.h"

// Test the Vehicle class
TEST_CASE("Base class Vehicle - Constructor and Destructor") {
    Vehicle v;
    CHECK_NOTHROW(v.Start());
    CHECK_NOTHROW(v.Stop());
}

// Test the Gasoline Vehicle class
TEST_CASE("Gasoline Vehicle - Start, Stop, Fuel Cost, and Miles Per Gallon") {
    Gasoline gas("Gasoline Vehicle");
    CHECK_NOTHROW(gas.Start());
    CHECK_NOTHROW(gas.Stop());

    double miles = 100.0;
    double expectedCost = (miles / 25.0) * 3.5; // 25 mpg, $3.50/gallon
    CHECK(gas.costOfFuel(miles) == doctest::Approx(expectedCost));

    // Test MPG method
    CHECK(gas.gasolineMilesPerGallon() == doctest::Approx(25.0));
}

// Test the Electric Vehicle class
TEST_CASE("Electric Vehicle - Start, Stop, Fuel Cost, and Miles Per Dollar") {
    Electric elec("Electric Vehicle");
    CHECK_NOTHROW(elec.Start());
    CHECK_NOTHROW(elec.Stop());

    double miles = 100.0;
    double expectedCost = (miles/100) * 33.7 * (33.7 * 0.24);
    double expectedMilesPerDollar = 100 / (33.7 * 0.24); // Miles per dollar

    CHECK(elec.costOfFuel(miles) == doctest::Approx(expectedCost));
    CHECK(elec.electricMilesPerDollar() == doctest::Approx(expectedMilesPerDollar));
}

// Test the Hybrid Vehicle class
TEST_CASE("Hybrid Vehicle - Start, Stop, Fuel Efficiency, and Cost Calculation") {
    Hybrid hybrid("Hybrid Vehicle", 0.5); // 50% gasoline, 50% electric
    CHECK_NOTHROW(hybrid.Start());
    CHECK_NOTHROW(hybrid.Stop());

    double miles = 100.0;

    // Check hybrid fuel efficiency
    double expectedEfficiency = ((100 / (33.7 * 0.24)) * 0.5) + ((25.0) * 0.5);
    CHECK(hybrid.fuelEfficiencyPerDollar() == doctest::Approx(expectedEfficiency));

    // Check cost for 100 miles with 50% gas and 50% electric
    double expectedGasCost = (miles / 25.0) * 3.5; // 25 mpg, $3.50/gallon
    double expectedElectricCost = (miles / 100) * 33.7 * (33.7 * 0.24);
    double expectedCost = (expectedElectricCost * (1 - 0.5)) + (expectedGasCost * 0.5);
    CHECK(hybrid.costOfFuel(miles) == doctest::Approx(expectedCost));
}

TEST_CASE("Hybrid Vehicle - 100% Gasoline and 100% Electric") {
    // Test 100% Gasoline
    Hybrid hybrid_gas("Hybrid Gas", 1.0);
    double miles = 100.0;
    double expectedGasCost = (miles / 25.0) * 3.5;
    CHECK(hybrid_gas.costOfFuel(miles) == doctest::Approx(expectedGasCost));

    // Test 100% Electric --> after calculating this should give me around 272.57 as the expected electric cost
    Hybrid hybrid_elec("Hybrid Electric", 0.0);
    CHECK(hybrid_elec.costOfFuel(miles) == doctest::Approx(272.566));
}

TEST_CASE("Gasoline Vehicle - Zero Miles") {
    Gasoline gas("Gasoline Vehicle");
    double miles = 0.0;
    CHECK(gas.costOfFuel(miles) == doctest::Approx(0.0));
}

TEST_CASE("Electric Vehicle - Zero Miles") {
    Electric elec("Electric Vehicle");
    double miles = 0.0;
    CHECK(elec.costOfFuel(miles) == doctest::Approx(0.0));
}

TEST_CASE("Hybrid Vehicle - Zero Miles") {
    Hybrid hybrid("Hybrid Zero Miles", 0.5);
    double miles = 0.0;
    CHECK(hybrid.costOfFuel(miles) == doctest::Approx(0.0));
}

