//
// Created by marco on 28/12/2022.
//
#include "Airport.h"

Airport::Airport(string code, string name, string city, string country, double latitude, double longitude) {
    this->code = code;
    this->name = name;
    this->city = city;
    this->country = country;
    this->latitude = latitude;
    this-> longitude = longitude;
}

string Airport::getCode() const {
    return code;
}



