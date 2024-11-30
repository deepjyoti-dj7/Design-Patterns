#include <iostream>
#include "./include/Vehicle_factory.hpp"

int main() {
    std::string vehicleType;
    std::cout << "Please enter vehicle: ";
    std::cin >> vehicleType;
    
    Vehicle *vehicle = VehicleFactory::getVehicle(vehicleType);
    vehicle->createVehicle();

    return 0;
}