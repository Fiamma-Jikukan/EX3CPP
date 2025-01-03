#include "Drone.h"

#include <cmath>
#include <iostream>
#include <utility>


Drone::Drone(): id(0), position(TDVector(0, 0)), velocity(TDVector(0, 0)), personalBest(0, 0) {
}

Drone::Drone(const unsigned int id, TDVector position, TDVector velocity, TDVector personalBest) : id(id),
    position(std::move(position)), velocity(std::move(velocity)), personalBest(std::move(personalBest)) {
}

Drone::~Drone() = default;

Drone::Drone(const Drone &other) : id(other.id), position(other.position), velocity(other.velocity),
                                   personalBest(other.personalBest) {
}

Drone &Drone::operator=(const Drone &other) {
    if (this == &other) {
        return *this;
    }
    id = other.id;
    position = other.position;
    velocity = other.velocity;
    personalBest = other.personalBest;
    return *this;
}

Drone::Drone(Drone &&other) noexcept
    : id(other.id),
      position(move(other.position)),
      velocity(move(other.velocity)),
      personalBest(move(other.personalBest)) {
    other.id = 0;
}

Drone &Drone::operator=(Drone &&other) noexcept {
    id = other.id;
    position = move(other.position);
    velocity = move(other.velocity);
    personalBest = move(other.personalBest);
    other.id = 0;
    return *this;
}

unsigned int Drone::getId() const {
    return id;
}

TDVector Drone::getPosition() const {
    return position;
}

void Drone::setPosition(const TDVector &position) {
    this->position = position;
}


void Drone::setVelocity(const TDVector &velocity) const{
    this->velocity = velocity;
}

TDVector Drone::getVelocity() const {
    return velocity;
}

TDVector Drone::getPersonalBest() const {
    return personalBest;
}

void Drone::setPersonalBest(const TDVector &personalBest) {
    this->personalBest = personalBest;
}

Cell Drone::getCurrentCell() const {
    const int x = position.getX();
    const int y = position.getY();
    Cell cell(x, y, 0);
    return cell;
}

void Drone::updateSpeed(const TDVector &globalBest) const {
    srand(time(NULL));
    double r1 = (((double) rand()) / RAND_MAX);
    double r2 = (((double) rand()) / RAND_MAX);
    cout << "r1 = " << r1 << " r2 = " << r2 << endl;
    TDVector new_speed = (0.25 * velocity) + (r1 * (personalBest - position)) + (r2 * (globalBest - position));

}

double Drone::getDistance(const TDVector &target) const {
    const double x_distance = position.getX() - target.getX();
    const double y_distance = position.getY() - target.getY();
    return sqrt(x_distance*x_distance + y_distance*y_distance);
}

void Drone::moveDrone() {
    position.setX(position.getX() + velocity.getX());
    position.setY(position.getY() + velocity.getY());
}



ostream &operator<<(std::ostream &os, const Drone &drone) {
    os << "Drone number " << drone.id << " is in coordinate: " << drone.getPosition().getX() << ", " << drone.
            getPosition().getY() << " moving at speed " << drone.getVelocity().getX() << ", " << drone.getVelocity().
            getY()
            << endl;
    return os;
}
