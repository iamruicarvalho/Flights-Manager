#include <iostream>
#include "src/FlightManager.h"

void showMenu();

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
                break;
            case 2:
                break;
            case 3:
                keepRunning = false;
                break;
            default:
                cout << "!!Invalid Input!!\n\n";
        }
    }
}

void showMenu(){
    cout << "=======================\n";
    cout << "| Menu :              |\n";
    cout << "| 1- Best Trajectory  |\n";
    cout << "| 2- Airport Info     |\n";
    cout << "| 3- Quit             |\n";
    cout << "=======================\n";
    cout << "Pick an option:";
}
