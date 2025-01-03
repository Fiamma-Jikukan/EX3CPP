#include "Cell.h"

#include <iostream>
#include <ostream>

Cell::Cell(unsigned int x, unsigned int y, unsigned int numOfDrones): x(x), y(y), numOfDrones(numOfDrones) {
}

Cell::Cell(): x(0), y(0), numOfDrones(0) {
}

Cell::~Cell() = default;

Cell::Cell(const Cell &other)
    : x(other.x),
      y(other.y),
      numOfDrones(other.numOfDrones) {
}

Cell::Cell(Cell &&other) noexcept
    : x(other.x),
      y(other.y),
      numOfDrones(other.numOfDrones) {
    other.x = 0;
    other.y = 0;
    other.numOfDrones = 0;
}

Cell &Cell::operator=(const Cell &other) {
    if (this == &other)
        return *this;
    x = other.x;
    y = other.y;
    numOfDrones = other.numOfDrones;
    return *this;
}

Cell &Cell::operator=(Cell &&other) noexcept {
    if (this == &other)
        return *this;
    x = other.x;
    y = other.y;
    numOfDrones = other.numOfDrones;
    other.x = 0;
    other.y = 0;
    other.numOfDrones = 0;
    return *this;
}

unsigned int Cell::getNumOfDrones() const {
    return numOfDrones;
}


unsigned int Cell::getX() const {
    return x;
}

void Cell::setX(const unsigned int x) {
    this->x = x;
}

unsigned int Cell::getY() const {
    return y;
}

void Cell::setY(const unsigned int y) {
    this->y = y;
}

Cell &Cell::operator++() {
    numOfDrones++;
    return *this;
}

Cell &Cell::operator++( int) {
    Cell temp = *this;
    numOfDrones++;
    return temp;
}

Cell &Cell::operator--() {
    numOfDrones--;
    return *this;
}

Cell &Cell::operator--( int) {
    Cell temp = *this;
    numOfDrones--;
    return temp;
}

bool Cell::operator==(const Cell &other) const {
    if (this == &other) {
        return true;
    }
    if (this->x == other.x && this->y == other.y) {
        return true;
    }
    return false;
}

bool Cell::operator!=(const Cell &other) const {
    if (this == &other) {
        return false;
    }
    if (this->x != other.x || this->y != other.y) {
        return true;
    }
    return false;
}

ostream & operator<<(ostream &os, const Cell &other) {
    os << "x: " << other.getX() << ", y: " << other.getY() << "Num of drones in cell: " << other.getNumOfDrones() << endl;
    return os;
}
