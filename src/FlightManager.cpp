//
// Created by marco on 28/12/2022.
//
#include "FlightManager.h"

void FlightManager::lerFicheiros() {
    cout << "Loading airports...\n";
    ifstream airports_file;
    airports_file.open("../resources/airports.csv");
    if (!airports_file.is_open()){
        cout << "File not found\n";
        return;
    }
    list<Airport> temp;
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
        temp.push_back(airport);
    }
    airports_file.close();
    cout << "There is " << temp.size() <<  " airports!\n";

    cout << "Loading airlines...\n";
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

    cout << "Loading flights...\n\n";
    ifstream flights_file;
    flights_file.open("../resources/flights.csv");
    if (!flights_file.is_open()){
        cout << "File not found\n";
        return;
    }
    flights = Graph(temp.size(),true);
    auto ptr = temp.begin();
    for (int i = 1 ; i<=temp.size();i++){
        flights.setAirport(i,ptr->getCode());
        ptr->setNode(i);
        ptr++;
    }
    for (const Airport& airport : temp)
        airports.insert(airport);
    getline(flights_file,line);
    while(getline(flights_file, line)){
        string source,target,airline;
        istringstream ss(line);
        getline(ss,source,',');
        getline(ss,target,',');
        getline(ss,airline);
        auto source_pointer = airports.find(Airport(source));
        auto target_pointer = airports.find(Airport(target));
        flights.addEdge(source_pointer->getNode(),target_pointer->getNode(),airline);
    }
    flights_file.close();
}

FlightManager::FlightManager() : flights(0){}


void FlightManager::askForAirport() {
    cout << "What is the code of the airport that you want information about?\n";
    string code;
    cin >>code;
    if (cin.fail()){
        cin.clear();
        cin.ignore(256,'\n');
        code = "";
    }
    Airport airport(code);
    auto airport_pointer = airports.find(airport);
    if (airport_pointer == airports.end()) {
        cout << "Invalid Input!\n";
        return;
    }
    askInfoToTakeFromAirport(*airport_pointer);
}

void FlightManager::askInfoToTakeFromAirport(const Airport& airport) {
    bool keepRunning = true;
    while(keepRunning){
        showAirportInfoMenu();
        int option;
        cin >> option;
        if (cin.fail()){
            cin.clear();
            cin.ignore(256,'\n');
            option = 0;
        }
        switch (option){
            case 1:
                keepRunning = numberOfFlights(airport);
                break;
            case 2:
                keepRunning = numberOfAirlines();
                break;
            case 3:
                keepRunning = numberOfDestinies();
                break;
            case 4:
                keepRunning = numberReachable();
                break;
            case 5:
                return;
            default :
                cout << "Invalid Input!\n";
        }

    }
}

bool FlightManager::numberOfFlights(const Airport& airport) {
    int node = airport.getNode();
    flights
    return flights.getFlights(node).size();
}


//------------------------Menus-------------------------------
void FlightManager::showAirportInfoMenu() {
    cout << "======================================\n";
    cout << "| Options :                          |\n";
    cout << "| 1- Number of flights               |\n";
    cout << "| 2- Number of airlines with         |\n";
    cout << "|    flights from this airport       |\n";
    cout << "| 3- Numbers of different destinies  |\n";
    cout << "| 4- Number of places reachable      |\n";
    cout << "| 5- Go back                         |\n";
    cout << "======================================\n";
    cout << "Pick an option:";
}

