#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "vehicle.h"

TEST_CASE("Test Vehicle Base Class") {
    Vehicle baseVehicle;
    CHECK_NOTHROW(baseVehicle.Start());
    CHECK_NOTHROW(baseVehicle.Stop());
    CHECK(baseVehicle.costOfFuel(100) == 0);
}

TEST_CASE("Test Gasoline Class") {
    Gasoline gasVehicle("GasCar");

    SUBCASE("Test Start and Stop") {
        CHECK_NOTHROW(gasVehicle.Start());
        CHECK_NOTHROW(gasVehicle.Stop());
    }

    SUBCASE("Test Fuel Efficiency") {
        CHECK(gasVehicle.gasolineMilesPerGallon() == 20.0);
    }

    SUBCASE("Test Cost of Fuel") {
        double miles = 100.0;
        CHECK(gasVehicle.costOfFuel(miles) == 2.50);
    }
}

TEST_CASE("Test Electric Class") {
    Electric electricVehicle("ElectricCar");

    SUBCASE("Test Start and Stop") {
        CHECK_NOTHROW(electricVehicle.Start());
        CHECK_NOTHROW(electricVehicle.Stop());
    }

    SUBCASE("Test Fuel Efficiency") {
        CHECK(electricVehicle.electricMilesPerDollar() == 20.0);
    }

    SUBCASE("Test Cost of Fuel") {
        double miles = 100.0;
        CHECK(electricVehicle.costOfFuel(miles) == 0.24);
    }
}

TEST_CASE("Test Hybrid Class") {
    Hybrid hybridVehicle("HybridCar", 0.5); // 50% gas, 50% electric

    SUBCASE("Test Start and Stop") {
        CHECK_NOTHROW(hybridVehicle.Start());
        CHECK_NOTHROW(hybridVehicle.Stop());
    }

    SUBCASE("Test Fuel Efficiency Per Dollar") {
        double expectedEfficiency = (20.0 * 0.5 + 20.0 * 0.5);
        CHECK(hybridVehicle.fuelEfficiencyPerDollar() == doctest::Approx(expectedEfficiency));
    }

    SUBCASE("Test Cost of Fuel") {
        double miles = 100; // this one is calculated in the main function and the answer should be 2.74
        CHECK(hybridVehicle.costOfFuel(miles) == doctest::Approx(2.74));
    }
}
