//
// Created by marco on 28/12/2022.
//

#ifndef AEDPROJECT2_AIRPORT_H
#define AEDPROJECT2_AIRPORT_H

#include <string>
using namespace std;

class Airport{
private:
    string code;
    string name;
    string city;
    string country; // not sure about this one
    double latitude;
    double longitude;
public:
    Airport(string code , string name , string city , string country , double latitude, double longitude);
    string getCode() const;
};


#endif //AEDPROJECT2_AIRPORT_H
