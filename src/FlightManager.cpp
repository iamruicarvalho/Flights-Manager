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
                keepRunning = numberOfAirlines(airport);
                break;
            case 3:
                keepRunning = numberOfDestinies(airport);
                break;
            case 4:
                keepRunning = numberOfDestinyCountries(airport);
                break;
            case 5:
                keepRunning = numberReachable(airport);
                break;
            case 6:
                return;
            default :
                cout << "Invalid Input!\n";
        }

    }
}

bool FlightManager::numberOfFlights(const Airport& airport) {
    int node = airport.getNode();
    list<pair<int , string>> flights_and_destination = flights.getFlights(node);
    cout << "There is " << flights_and_destination.size()<< " flights that leave airport " <<
            airport.getName() << ".\n";
    /*
    for (pair<int,string> p : flights_and_destination){
        cout << " - " << p.first << "(" << p.second << ")\n";
    }
     */
    return true;
}

bool FlightManager::numberOfAirlines(const Airport &airport) {
    int node = airport.getNode();
    list<pair<int , string>> flights_and_destination = flights.getFlights(node);
    set<string> airlines;
    for (pair<int,string> p : flights_and_destination){
        airlines.insert(p.second);
    }
    cout<< "There is " <<  airlines.size() << " different airlines that have flights that leave airport "<<
        airport.getName() << ".\n";
    return true;
}
bool FlightManager::numberOfDestinies(const Airport &airport) {
    int node = airport.getNode();
    list<pair<int , string>> flights_and_destination = flights.getFlights(node);
    set<int> airport_nodes;
    for (pair<int,string> p : flights_and_destination){
        airport_nodes.insert(p.first);
    }
    cout<< "There is " <<  airport_nodes.size() << " different destinies that the flights from airport "<<
        airport.getName() << " have.\n";
    return true;
}

bool FlightManager::numberOfDestinyCountries(const Airport &airport) {
    int node = airport.getNode();
    list<pair<int , string>> flights_and_destination = flights.getFlights(node);
    set<int> airport_nodes;
    for (pair<int,string> p : flights_and_destination){
        airport_nodes.insert(p.first);
    }
    set<string> countries;
    for (int airport_node : airport_nodes){
        string airport_code = flights.getAirport(airport_node);
        Airport temp_airport (airport_code);
        auto airport_pointer = airports.find(temp_airport);
        countries.insert(airport_pointer->getCountry());
    }
    cout<< "There is " <<  countries.size() << " different countries that the flights from airport "<<
        airport.getName() << " go to.\n";
    return true;
}

bool FlightManager::numberReachable(const Airport &airport) {
    cout << "What is the maximum amount of flights that we should consider?\n";
    int amount_of_flights;
    cin >>amount_of_flights;
    if (cin.fail()){
        cin.clear();
        cin.ignore(256,'\n');
        amount_of_flights = -1;
    }
    if (amount_of_flights <= 0 ) {
        cout << "Invalid Input!\n";
        return true;
    }
    bool keepRunning = true;
    while(keepRunning){
        askWhichPlaceMenu();
        int option;
        cin >> option;
        if (cin.fail()){
            cin.clear();
            cin.ignore(256,'\n');
            option = 0;
        }
        switch (option){
            case 1:
                keepRunning = airportsReachable(airport , amount_of_flights);
                break;
            case 2:
                keepRunning = citiesReachable(airport,amount_of_flights);
                break;
            case 3:
                keepRunning = countriesReachable(airport,amount_of_flights);
                break;
            case 4:
                return true;
            default :
                cout << "Invalid input!\n";
        }
    }
}
bool FlightManager::airportsReachable(const Airport &airport, int number_of_flights) {
    int node = airport.getNode();
    list<string> airports_reachable = flights.getAirportsReachable(node , number_of_flights);
    cout << "There are " << airports_reachable.size() << " airports reachable from airport " << airport.getName() <<
            " with, at max, " <<number_of_flights << " flights!\n";
    return true;
}
bool FlightManager::citiesReachable(const Airport &airport, int number_of_flights) {
    int node = airport.getNode();
    list<string> airports_reachable = flights.getAirportsReachable(node , number_of_flights);
    set<pair<string,string>> cities_reachable;
    for (const string& airport_code : airports_reachable){
        Airport temp_airport(airport_code);
        auto airport_pointer = airports.find(temp_airport);
        cities_reachable.insert({airport_pointer->getCity(),airport_pointer->getCountry()});
    }
    cout << "There are " << cities_reachable.size() << " cities reachable from airport " << airport.getName() <<
         " with, at max, " <<number_of_flights << " flights!\n";
    return true;
}
bool FlightManager::countriesReachable(const Airport &airport, int amount_of_flights) {
    int node = airport.getNode();
    list<string> airports_reachable = flights.getAirportsReachable(node , amount_of_flights);
    set<string> countries_reachable;
    for (const string& airport_code : airports_reachable){
        Airport temp_airport(airport_code);
        auto airport_pointer = airports.find(temp_airport);
        countries_reachable.insert(airport_pointer->getCountry());
    }
    cout << "There are " << countries_reachable.size() << " countries reachable from airport " << airport.getName() <<
         " with, at max, " <<amount_of_flights << " flights!\n";
    return true;
}
//------------------------Menus-------------------------------
void FlightManager::showAirportInfoMenu() {
    cout << "======================================\n";
    cout << "| Options :                          |\n";
    cout << "| 1- Number of flights               |\n";
    cout << "| 2- Number of airlines with         |\n";
    cout << "|    flights from this airport       |\n";
    cout << "| 3- Number of different destinies   |\n";
    cout << "| 4- Number of different destiny     |\n";
    cout << "|    countries                       |\n";
    cout << "| 5- Number of places reachable      |\n";
    cout << "| 6- Go back                         |\n";
    cout << "======================================\n";
    cout << "Pick an option:";
}

void FlightManager::askWhichPlaceMenu() {
    cout << "======================================\n";
    cout << "| Options :                          |\n";
    cout << "| 1- Number of airports reachable    |\n";
    cout << "| 2- Number of cities reachable      |\n";
    cout << "| 3- Number of countries reachable   |\n";
    cout << "| 4- Go back                         |\n";
    cout << "======================================\n";
    cout << "Pick an option:";
}
















