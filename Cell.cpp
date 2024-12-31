#include "Cell.h"

Cell::Cell(unsigned int x, unsigned int y, unsigned int numOfDrones): x(x), y(y), numOfDrones(numOfDrones) {
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
    return *this;
}

unsigned int Cell::getNumOfDrones() const {
    return numOfDrones;
}


unsigned int Cell::getX() const {
    return x;
}

unsigned int Cell::getY() const {
    return y;
}

Cell & Cell::operator++() {
    numOfDrones++;
    return *this;
}

Cell & Cell::operator++(unsigned int) {
    Cell temp = *this;
    numOfDrones++;
    return temp;
}

Cell & Cell::operator--() {
    numOfDrones--;
    return *this;
}

Cell & Cell::operator--(unsigned int) {
    Cell temp = *this;
    numOfDrones--;
    return temp;
}
