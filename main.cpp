#include <iostream>

#include "Drone.h"
#include "TDVector.h"
using namespace std;

Drone* GetDrones(const string &input2);
TDVector GetTarget(const string &input1);
unsigned int GetMaxIter(const string &input1);
unsigned int GetGlobalBest(Drone *drones, TDVector target); // returns the index of the drone closest to the target

int main() {
    const TDVector pos(88.1, 5.65);
    const TDVector vel(0.2, 1);

    TDVector vel2(0.33, 88);
    const Drone dr(11, pos, vel, 10);
    const Cell cdr = dr.getCurrentCell();
    const Cell cell(88,5,5);
    cout << (cdr == cell) << endl;
    dr.updateSpeed(pos);
    // Drone dr2 = dr;
    // dr2.setVelocity(5 * vel2);
    // cout << dr << endl;
    // cout << dr2 << endl;


    return 0;
    // main creates the drone array with input and creates a search instance with it
    // update speed gets global best coordinates
}
