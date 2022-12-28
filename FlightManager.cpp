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

    cout << "There is " << airports.size() <<  " airports!\n";
}

