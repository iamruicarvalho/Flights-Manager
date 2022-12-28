//
// Created by marco on 28/12/2022.
//

#ifndef AEDPROJECT2_FLIGHTMANAGER_H
#define AEDPROJECT2_FLIGHTMANAGER_H

#include "Airport.h"
#include <unordered_set>
#include <fstream>
#include <iostream>
#include <sstream>

struct airportHash
{
    // TODO
    int operator() (const Airport& airport) const {
        int res = 1;
        for (char t : airport.getCode()){
            res*=t;
        }
        return res;
    }

    // TODO
    bool operator() (const Airport& a1, const Airport& a2) const {
        return a1.getCode() == a2.getCode();
    }
};

typedef unordered_set<Airport,airportHash,airportHash> airportTable;

class FlightManager{
    private:
        airportTable airports;
        // unordered_set<City> cities; não sei se temos que ter isto
    public:
        void lerFicheiros();
};

#endif //AEDPROJECT2_FLIGHTMANAGER_H
