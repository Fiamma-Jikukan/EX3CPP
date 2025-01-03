#include "TDVector.h"

#include <cmath>


TDVector::TDVector(double x, double y): x(x), y(y) {
}

double TDVector::getX() const {
    return x;
}

double TDVector::getY() const {
    return y;
}

void TDVector::setX(const double x) {
    this->x = x;
}

void TDVector::setY(const double y) {
    this->y = y;
}

TDVector TDVector::operator+(const TDVector &other) const {
    return TDVector(x + other.x, y + other.y);
}

TDVector TDVector::operator-(const TDVector &other) const {
    return TDVector(x - other.x, y - other.y);
}

TDVector operator*(const double scalar, const TDVector &vec) {
     return TDVector(vec.getX() * scalar, vec.getY() * scalar);
}

double operator*(const TDVector &vec1, const TDVector &vec2) {
    const double x = (vec1.getX() - vec2.getX()) * (vec1.getX() - vec2.getX());
    const double y = (vec1.getY() - vec2.getY()) * (vec1.getY() - vec2.getY());
    return sqrt(x + y);
}
