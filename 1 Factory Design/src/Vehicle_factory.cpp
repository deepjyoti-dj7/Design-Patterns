#include <iostream>
#include "../include/Vehicle_factory.hpp"

Vehicle* VehicleFactory::getVehicle(std::string vehicleType){
    Vehicle* vehicle;
    if (vehicleType == "car") {
        vehicle = new Car();
    }
    else if (vehicleType == "bike") {
        vehicle = new Bike();
    }
    return vehicle;
};