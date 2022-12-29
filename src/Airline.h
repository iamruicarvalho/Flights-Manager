
//
// Created by marco on 28/12/2022.
//

#ifndef AEDPROJECT2_AIRLINE_H
#define AEDPROJECT2_AIRLINE_H

#include <string>

using namespace std;

class Airline{
private:
    string code;
    string name;
    string callsign;
    string country;
public:
    Airline(string code , string name , string callsign , string country);

    const string &getCode() const;
    const string &getName() const;
    const string &getCallsign() const;
    const string &getCountry() const;

    void setCode(const string &code);
    void setName(const string &name);
    void setCallsign(const string &callsign);
    void setCountry(const string &country);

    bool operator<(const Airline& a2) const;
};

#endif //AEDPROJECT2_AIRLINE_H
