//
// Created by marco on 28/12/2022.
//

#ifndef AEDPROJECT2_AIRPORT_H
#define AEDPROJECT2_AIRPORT_H

#include <string>
#include <cmath>
using namespace std;

class Airport{
private:
    string code;
    string name;
    string city;
    string country; // not sure about this one
    double latitude;
    double longitude;
    int node;
public:
    Airport(string code);
    Airport(string code , string name , string city , string country , double latitude, double longitude);

    const string &getCode() const;
    const string &getName() const;
    const string &getCity() const;
    const string &getCountry() const;
    double getLatitude() const;
    double getLongitude() const;
    int getNode() const;

    void setCode(const string &code);
    void setName(const string &name);
    void setCity(const string &city);
    void setCountry(const string &country);
    void setLatitude(double latitude);
    void setLongitude(double longitude);
    void setNode(int node);

    double distance(const Airport& a2);
};


#endif //AEDPROJECT2_AIRPORT_H
