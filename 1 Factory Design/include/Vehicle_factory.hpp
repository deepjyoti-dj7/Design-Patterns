#pragma once

#include <iostream>
#include "Bike.hpp"
#include "Car.hpp"

class VehicleFactory {
public:
    static Vehicle* getVehicle(std::string vehicleType);
};