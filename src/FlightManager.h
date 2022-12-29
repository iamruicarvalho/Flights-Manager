//
// Created by marco on 28/12/2022.
//

#ifndef AEDPROJECT2_FLIGHTMANAGER_H
#define AEDPROJECT2_FLIGHTMANAGER_H

#include "Airport.h"
#include "Airline.h"
#include <unordered_set>
#include <fstream>
#include <iostream>
#include <sstream>
#include <set>
#include "graph.h"


typedef unordered_set<Airport,airportHash,airportHash> airportTable;

class FlightManager{
    private:
        airportTable airports;
        set<Airline> airlines;
        Graph flights;
    public:
        FlightManager();
        void lerFicheiros();
        void showAirportInfoMenu();
        void askForAirport();
        void askInfoToTakeFromAirport(const Airport& airport);
        bool numberOfFlights(const Airport& airport);

};

#endif //AEDPROJECT2_FLIGHTMANAGER_H
