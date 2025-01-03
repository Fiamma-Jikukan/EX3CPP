#include <iostream>
#include <fstream>
#include <valarray>


#include "Drone.h"
#include "Search.h"
#include "TDVector.h"
using namespace std;

Drone *GetDrones(const string &input2);

TDVector GetTarget(const string &input1);

unsigned int GetMaxIter(const string &input1);

unsigned int GetNumOfDrones(const string &input1);

unsigned int GetGlobalBest(const Drone *drones, const TDVector &target, unsigned int num_of_drones);

// returns the index of the drone closest to the target

double CalculateDistance(const TDVector &a, const TDVector &b);

int main(int argc, char **argv) {
    // if (argc != 2) {
    //     cerr << "Usage: ./a.out <input file>" << endl;
    //     return 1;
    // }
    // GetDrones(argv[2]);

    const TDVector target = GetTarget("config.dat");
    cout << target << endl;
    unsigned int maxIter = GetMaxIter("config.dat");
    Drone *drones = GetDrones("init.dat");
    unsigned int numOfDrones = GetNumOfDrones("init.dat");
    const unsigned int globalBest = GetGlobalBest(drones, target, numOfDrones);
    Forest forest;
    for (unsigned int i = 0; i < numOfDrones; i++) {
        forest.addDroneToCell(drones[i].getPosition());
    }
    Search search(maxIter, numOfDrones, drones, forest, globalBest, target, false);
    cout << search << endl;

    search.StartSearch();


    return 0;
}

Drone *GetDrones(const string &input2) {
    ifstream input_drones(input2);
    // function that validate init file
    unsigned int num_of_drones;
    input_drones >> num_of_drones;
    Drone *drones = new Drone[num_of_drones];
    for (unsigned int drone = 0; drone < num_of_drones; drone++) {
        double pos_x, pos_y, vel_x, vel_y;
        input_drones >> pos_x >> pos_y >> vel_x >> vel_y;
        TDVector pos = TDVector(pos_x, pos_y);
        TDVector vel = TDVector(vel_x, vel_y);
        const Drone d(drone, pos, vel, pos);
        drones[drone] = d;
    }
    return drones;
}

unsigned int GetNumOfDrones(const string &input1) {
    ifstream input_drones(input1);
    unsigned int num_of_drones;
    input_drones >> num_of_drones;
    return num_of_drones;
}

TDVector GetTarget(const string &input1) {
    ifstream input_target(input1);
    double target_x, target_y;
    input_target >> target_x >> target_y;
    TDVector target(target_x, target_y);
    return target;
}

unsigned int GetMaxIter(const string &input1) {
    ifstream input_target(input1);
    double target_x, target_y, max_iter;
    input_target >> target_x >> target_y >> max_iter;
    return max_iter;
}

unsigned int GetGlobalBest(const Drone *drones, const TDVector &target, const unsigned int num_of_drones) {
    unsigned int closest_drone_index = 0;
    double closest_distance = CalculateDistance(drones[0].getPosition(), target);
    for (unsigned int drone = 0; drone < num_of_drones; drone++) {
        double distance = CalculateDistance(drones[drone].getPosition(), target);
        if (distance < closest_distance) {
            closest_distance = distance;
            closest_drone_index = drone;
        }
    }
    return closest_drone_index;
}

double CalculateDistance(const TDVector &a, const TDVector &b) {
    const double x = (a.getX() - b.getX()) * (a.getX() - b.getX());
    const double y = (a.getY() - b.getY()) * (a.getY() - b.getY());
    return sqrt(x + y);
}
