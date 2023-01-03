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
#include <string>
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
    void showAirlineMenu();
    void showStartingPointMenu();
    void showDestinationMenu();
    void askWhichPlaceMenu();

    void askForAirport();
    void askForAirline();
    void askInfoToTakeFromAirport(const Airport& airport);

    bool numberOfFlights(const Airport& airport);
    bool numberOfAirlines(const Airport &airport);
    bool numberOfDestinies(const Airport &airport);
    bool numberOfDestinyCountries(const Airport &airport);
    bool numberReachable(const Airport &airport);
    bool airportsReachable(const Airport &airport, int number_of_flights);
    bool citiesReachable(const Airport &airport, int number_of_flights);
    bool countriesReachable(const Airport &airport, int amount_of_flights);

    void startingPoint();
    void destination();

    void askForAirportStartingPoint();
    void askForAirportDestination();
    void askForCityStartingPoint();
    void askForCityDestination();
    void askForLocationStartingPoint();
    void askForLocationDestination();

    double haversineCalculateDistance(double latitude, double longitude, double latitude1, double longitude1);

    void airline();
};

#endif //AEDPROJECT2_FLIGHTMANAGER_H
//podiamos perguntar se queriam listar por exemplo as airlines, ou os flights