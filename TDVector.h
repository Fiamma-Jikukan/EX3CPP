#ifndef TDVECTOR_H
#define TDVECTOR_H
#include <ostream>

using namespace std;


class TDVector {
private:
    double x;
    double y;

public:
    TDVector(double x, double y);

    ~TDVector() = default;

    TDVector(const TDVector &other) = default;

    TDVector(TDVector &&other) noexcept
        : x(other.x),
          y(other.y) {
        other.x = 0;
        other.y = 0;
    }

    TDVector &operator=(const TDVector &other) {
        if (this == &other)
            return *this;
        x = other.x;
        y = other.y;
        return *this;
    }

    TDVector &operator=(TDVector &&other) noexcept {
        if (this == &other)
            return *this;
        x = other.x;
        y = other.y;
        other.x = 0;
        other.y = 0;
        return *this;
    }

    double getX() const;

    double getY() const;

    void setX(double x);

    void setY(double y);

    TDVector operator+(const TDVector &other) const;

    TDVector operator-(const TDVector &other) const;

    friend TDVector operator*(double scalar, const TDVector &vec);

    friend double operator*(const TDVector &vec1, const TDVector &vec2);
    // returns distance between 2 points

    friend bool operator==(const TDVector &lhs, const TDVector &rhs) {
        return lhs.x == rhs.x
               && lhs.y == rhs.y;
    }

    friend bool operator!=(const TDVector &lhs, const TDVector &rhs) {
        return !(lhs == rhs);
    }

    friend ostream &operator<<(ostream &os, const TDVector &vec) {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }
};



#endif //TDVECTOR_H
