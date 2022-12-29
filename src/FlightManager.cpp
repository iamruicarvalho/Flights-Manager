//
// Created by marco on 28/12/2022.
//
#include "FlightManager.h"


void FlightManager::lerFicheiros() {
    ifstream airports_file;
    airports_file.open("../resources/airports.csv");
    if (!airports_file.is_open()){
        cout << "File not found\n";
        return;
    }
    string line;
    getline(airports_file,line);
    while(getline(airports_file, line)){
        string code , name , city , country;
        double latitude , longitude;
        istringstream ss(line);
        getline(ss,code,',');
        getline(ss,name , ',');
        getline(ss,city , ',');
        getline(ss,country,',');
        getline(ss,country,',');
        ss >>  latitude;
        ss.ignore(1);
        ss >> longitude;
        Airport airport(code , name , city , country , latitude , longitude);
        airports.insert(airport);
    }
    airports_file.close();
    cout << "There is " << airports.size() <<  " airports!\n";

    ifstream airlines_file;
    airlines_file.open("../resources/airlines.csv");
    if (!airlines_file.is_open()){
        cout << "File not found\n";
        return;
    }
    getline(airlines_file,line);
    while(getline(airlines_file, line)){
        string code , name , callsign , country;
        istringstream ss(line);
        getline(ss,code,',');
        getline(ss,name , ',');
        getline(ss,callsign,',');
        getline(ss,country);

        Airline airline(code , name , callsign , country);
        airlines.insert(airline);
    }
    airlines_file.close();
    cout << "There is " << airlines.size() <<  " airlines!\n";

    ifstream flights_file;
    flights_file.open("../resources/flights.csv");
    if (!flights_file.is_open()){
        cout << "File not found\n";
        return;
    }
    flights = Graph(airports.size(),true);
    getline(flights_file,line);
    while(getline(flights_file, line)){
        string source , target , airline;
        istringstream ss(line);
        getline(ss,source,',');
        getline(ss,target , ',');
        getline(ss,airline);
    }
    flights_file.close();
}

FlightManager::FlightManager() {

}

