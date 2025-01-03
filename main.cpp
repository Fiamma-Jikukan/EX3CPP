#include <iostream>
#include <fstream>
#include <valarray>


#include "Drone.h"
#include "Search.h"
#include "TDVector.h"
using namespace std;

bool validateConfig(const string &config);

bool validateInit(const string &init);

bool validateOutput(const string &output);

Drone *GetDrones(const string &input2);

TDVector GetTarget(const string &input1);

unsigned int GetMaxIter(const string &input1);

unsigned int GetNumOfDrones(const string &input1);

unsigned int GetGlobalBest(const Drone *drones, const TDVector &target, unsigned int num_of_drones);

// returns the index of the drone closest to the target

double CalculateDistance(const TDVector &a, const TDVector &b);

int main(int argc, char **argv) {
    if (argc != 4) {
        cerr << "Error; invalid input" << endl;
        return 1;
    }

    bool validConfig = validateConfig(argv[1]);
    bool validInit = validateInit(argv[2]);
    bool validOutput = validateOutput(argv[3]);
    if (!validConfig || !validInit || !validOutput) {
        cerr << "Error; invalid input" << endl;
        return 1;
    }

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
    string output = argv[3];
    Search search(maxIter, numOfDrones, drones, forest, globalBest, target, false, output);
    cout << search << endl;

    search.StartSearch();


    return 0;
}

bool validateConfig(const string &config) {
    ifstream config_file(config);
    if (!config_file.is_open()) {
        return false;
    }
    double target_x, target_y;
    if (!(config_file >> target_x >> target_y)) {
        return false;
    }
    if (target_x < 0 || target_y < 0 || target_x > FOREST_WIDTH || target_y > FOREST_HEIGHT) {
        return false;
    }
    int max_iter;
    if (!(config_file >> max_iter) || max_iter < 0) {
        return false;
    }
    double extra_line;
    if (config_file >> extra_line) {
        return false;
    }
    return true;
}

bool validateInit(const string &init) {
    ifstream init_file(init);
    if (!init_file.is_open()) {
        return false;
    }
    unsigned int num_of_drones;
    if (!(init_file >> num_of_drones)) {
        return false;
    }
    if (num_of_drones <= 0) {
        return false;
    }
    for (unsigned int i = 0; i < num_of_drones; i++) {
        double pos_x, pos_y, vel_x, vel_y;
        if (!(init_file >> pos_x >> pos_y >> vel_x >> vel_y)) {
            return false;
        }
        if (pos_x < 0 || pos_x > FOREST_WIDTH || pos_y < 0 || pos_y > FOREST_HEIGHT) {
            return false;
        }
    }
    double extra_data;
    if (init_file >> extra_data) {
        return false;
    }
    return true;
}

bool validateOutput(const string &output) {
    ofstream output_file(output);
    if (!output_file.is_open()) {
        return false;
    }
    return true;
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
