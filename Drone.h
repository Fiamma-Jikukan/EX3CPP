#ifndef DRONE_H
#define DRONE_H
#include <ostream>

#include "Cell.h"
#include "TDVector.h"

using namespace std;


class Drone {
private:
    unsigned int id;
    TDVector position;
    TDVector velocity;
    TDVector personalBest;

public:
    Drone();

    // big five
    Drone(unsigned int id, TDVector position, TDVector velocity, TDVector personalBest);

    ~Drone();

    Drone(const Drone &other);

    Drone &operator=(const Drone &other);

    Drone(Drone &&other) noexcept;

    Drone &operator=(Drone &&other) noexcept;


    unsigned int getId() const;

    TDVector getPosition() const;

    void setPosition(const TDVector &position);

    TDVector getVelocity() const;

    void setVelocity(const TDVector &velocity) const;

    TDVector getPersonalBest() const;

    void setPersonalBest(const TDVector &personalBest);

    Cell getCurrentCell() const;

    void updateSpeed(const TDVector &globalBest) const;

    void moveDrone();

    double getDistance(const TDVector &target) const; // returns distance from target cell


    friend ostream &operator<<(std::ostream &os, const Drone &drone);
};


#endif //DRONE_H
