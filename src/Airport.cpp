//
// Created by marco on 28/12/2022.
//
#include "Airport.h"

Airport::Airport(string code) {
    this->code = code;
}

Airport::Airport(string code, string name, string city, string country, double latitude, double longitude) {
    this->code = code;
    this->name = name;
    this->city = city;
    this->country = country;
    this->latitude = latitude;
    this-> longitude = longitude;
    node = 0;
}

const string &Airport::getCode() const {
    return code;
}

void Airport::setCode(const string &code) {
    this->code = code;
}

const string &Airport::getName() const {
    return name;
}

void Airport::setName(const string &name) {
    this->name = name;
}

const string &Airport::getCity() const {
    return city;
}

void Airport::setCity(const string &city) {
    this->city = city;
}

const string &Airport::getCountry() const {
    return country;
}

void Airport::setCountry(const string &country) {
    this->country = country;
}

double Airport::getLatitude() const {
    return latitude;
}

void Airport::setLatitude(double latitude) {
    this->latitude = latitude;
}

double Airport::getLongitude() const {
    return longitude;
}

void Airport::setLongitude(double longitude) {
    this->longitude = longitude;
}

double Airport::distance(double latitude1, double longitude1) const {
    double dLat = (latitude1 - latitude) *
                  M_PI / 180.0;
    double dLon = (longitude1 - longitude) *
                  M_PI / 180.0;

    double lat1 = (latitude) * M_PI / 180.0;
    double lat2 = (latitude1) * M_PI / 180.0;

    double a = pow(sin(dLat / 2), 2) +
               pow(sin(dLon / 2), 2) *
               cos(lat1) * cos(lat2);

    return 6371 * 2 * asin(sqrt(a));
}

int Airport::getNode() const {
    return node;
}

void Airport::setNode(int node) {
    this->node = node;
}

