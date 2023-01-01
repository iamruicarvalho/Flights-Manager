#include <iostream>
#include "src/FlightManager.h"

void showMenu();

void bestTrajectory(FlightManager& h);

void showBestTrajectoryMenu();

void showAirportInfoMenu();

void askForAirport(FlightManager& h);

using namespace std;
int main() {
    FlightManager h;
    h.lerFicheiros();
    bool keepRunning = true;
    while(keepRunning){
        showMenu();
        int option;
        cin >> option;
        if (cin.fail()){
            cin.clear();
            cin.ignore(256,'\n');
            option = 0;
        }
        switch (option){
            case 1:
                bestTrajectory(h);
                break;
            case 2:
                h.askForAirport();
                break;
            case 3:
                keepRunning = false;
                break;
            default:
                cout << "!!Invalid Input!!\n\n";
        }
    }
}

void bestTrajectory(FlightManager& h) {
    bool keepRunning = true;
    while(keepRunning){
        showBestTrajectoryMenu();
        keepRunning = false;
    }
}

//-----------------------Menus-----------------------------------

void showMenu(){
    cout << "=======================\n";
    cout << "| Menu :              |\n";
    cout << "| 1- Best Trajectory  |\n";
    cout << "| 2- Airport Info     |\n";
    cout << "| 3- Quit             |\n";
    cout << "=======================\n";
    cout << "Pick an option:";
}

void showBestTrajectoryMenu() {
    cout << "========================\n";
    cout << "| Options :            |\n";
    cout << "| 1- Normal            |\n";
    cout << "| 2- Specify local     |\n";
    cout << "| 3- Specify airlines  |\n";
    cout << "| 4- Specify local and |\n";
    cout << "|    airlines          |\n";
    cout << "| 5- Go back           |\n";
    cout << "========================\n";
    cout << "Pick an option:";
}
