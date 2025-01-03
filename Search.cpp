#include "Search.h"

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
    bool target_reached = false;
    unsigned int num_of_iterations = 0;
    while (num_of_iterations < maxNumOfIter) {
        for (int i = 0; i < numOfDrones; i++) {
            UpdateDrone(drones[i], i);
        }
        if (ended) {
            break;
        }
        num_of_iterations++;
    }
    EndSearch(num_of_iterations);


}

void Search::EndSearch(unsigned int numOfIterations) {
    // writes the output file, with the positions of all drones

}

void Search::UpdateDrone(Drone &drone, const unsigned int index) {
    drone.moveDrone();

    double distance = drone.getDistance(target);
    double prev_distance = drone.getDistance(drone.getPersonalBest());
    if (distance > prev_distance) {
        drone.setPersonalBest(drone.getPosition());
    }

    const double best_distance = drones[globalBest].getDistance(target);
    if (distance > best_distance) {
        globalBest = index;
    }

    Cell drone_cell = drone.getCurrentCell();
    Cell target_cell = GetTargetCell();
    if (drone_cell == target_cell) {
        ended = true;
    }

}


void Search::updateSpeed(const Drone &drone) {
    srand(time(NULL));
    const double r1 = (((double) rand()) / RAND_MAX);
    const double r2 = (((double) rand()) / RAND_MAX);

    const TDVector personal = drone.getPersonalBest();
    const TDVector velocity = drone.getVelocity();
    const TDVector position = drone.getPosition();
    cout << "r1 = " << r1 << " r2 = " << r2 << endl;

    const TDVector new_speed = (0.25 * velocity) + (r1 * (personal - position)) + (r2 * (drones[globalBest].getPosition() - position));

    drone.setVelocity(new_speed);
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
