#include "Search.h"

#include <fstream>
#include <iostream>

// Search::Search(unsigned int numOfDrones, Drone *drones, Forest &forest, unsigned int globalBest,
//                TDVector &target): numOfDrones(numOfDrones), drones(drones), forest(forest), globalBest(globalBest),
//                                   target(target) {
// }

Search::~Search() {
    delete []drones;
}


// Search::Search(const Search &other): drones(other.drones), globalBest(other.globalBest), target(other.target) {
// }
//
// Search & Search::operator=(const Search &other) {
//     if (this == &other) {
//         return *this;
//     }
//     drones = other.drones;
//     globalBest = other.globalBest;
//     target = other.target;
//     return *this;
// }
//
// Search::Search(Search &&other) noexcept {
//
//
// }
//
// Search & Search::operator=(Search &&other) noexcept {
// }

void Search::StartSearch() {
    srand(time(NULL));
    unsigned int num_of_iterations = 0;
    cout << forest << endl;

    while (num_of_iterations < 10000) {
        for (int i = 0; i < numOfDrones; i++) {
            UpdateDrone(drones[i], i);
        }

        if (ended) {
            break;
        }
        num_of_iterations++;
        cout << endl;

    }
    cout << forest << endl;



    EndSearch(5);
}

void Search::EndSearch(unsigned int numOfIterations) {
    ofstream outfile("final.dat");
    outfile << numOfIterations << "\n";
    for (int i = 0; i < numOfDrones; i++) {
        outfile << drones[i].getPosition().getX() << " " << drones[i].getPosition().getY() << "\n";
    }
}

void Search::UpdateDrone(Drone &drone, const unsigned int index) {
    const TDVector old_position = drone.getPosition();
    const Cell old_cell = drone.getCurrentCell();
    const double prev_distance = drone.getDistance(target);

    drone.moveDrone();

    const double new_distance = drone.getDistance(target);
    if (new_distance < prev_distance) {
        drone.setPersonalBest(drone.getPosition());
    }

    const double current_best_distance = drones[globalBest].getDistance(target);
    if (new_distance < current_best_distance) {
        globalBest = index;
    }

    const Cell new_cell = drone.getCurrentCell();


    if (old_cell != new_cell) {
        const TDVector new_position = drone.getPosition();
        forest.removeDroneFromCell(old_position);
        forest.addDroneToCell(new_position);
    }
    Cell target_cell = GetTargetCell();
    if (new_cell == target_cell) {
        ended = true;
    }

    updateSpeed(drone);
}


void Search::updateSpeed(Drone &drone) {
    const double r1 = (((double) rand()) / RAND_MAX);
    const double r2 = (((double) rand()) / RAND_MAX);

    const TDVector personal = drone.getPersonalBest();
    const TDVector velocity = drone.getVelocity();
    const TDVector position = drone.getPosition();
    const TDVector global_position = drones[globalBest].getPosition();

    cout << "personal: " << personal << " velocity: " << velocity << " position: " << position << " global position: "
            << global_position << endl;

    cout << "r1 = " << r1 << " r2 = " << r2 << endl;

    const TDVector new_speed = (0.25 * velocity) + (r1 * (personal - position)) + (r2 * (global_position - position));
    // cout << " from update speed, old speed: " << velocity.getX() << "," << velocity.getY() << endl;
    drone.setVelocity(new_speed);
    // cout << " from update speed, new speed: " << drone.getVelocity().getX() << "," << drone.getVelocity().getY() << endl;
}

unsigned int Search::GetGlobalBest() const {
    return globalBest;
}

TDVector Search::GetTarget() {
    return target;
}

void Search::UpdateGlobalBest(const unsigned int newGlobalBest) {
    globalBest = newGlobalBest;
}

Cell Search::GetTargetCell() const {
    const int x = target.getX();
    const int y = target.getY();
    Cell cell(x, y, 0);
    return cell;
}

std::ostream &operator<<(std::ostream &os, const Search &search) {
    for (unsigned int i = 0; i < search.GetNumOfDrones(); i++) {
        os << search.drones[i];
        if (search.globalBest == i) {
            os << "this is the global best drone" << endl;
        }
    }
    return os;
}
