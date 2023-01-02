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
    bool numberOfAirlines(const Airport &airport);
    bool numberOfDestinies(const Airport &airport);
    bool numberOfDestinyCountries(const Airport &airport);
    bool numberReachable(const Airport &airport);
    void askWhichPlaceMenu();
    bool airportsReachable(const Airport &airport, int number_of_flights);
    bool citiesReachable(const Airport &airport, int number_of_flights);
    bool countriesReachable(const Airport &airport, int amount_of_flights);

    void startingPoint();

    void destination();

    void showStartingPointMenu();

    void askForAirportStartingPoint();

    void askForCityStartingPoint();

    void askForLocationStartingPoint();

    void showDestinationMenu();

    void askForAirportDestination();

    double haversineCalculateDistance(double latitude, double longitude, double latitude1, double longitude1);

    void askForCityDestination();

    void askForLocationDestination();

    void showAirlineMenu();

    void airline();

    void askForAirline();
};

#endif //AEDPROJECT2_FLIGHTMANAGER_H
