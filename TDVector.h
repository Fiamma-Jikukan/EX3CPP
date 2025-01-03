#ifndef TDVECTOR_H
#define TDVECTOR_H

using namespace std;


class TDVector {
private:
    double x;
    double y;

public:
    TDVector(double x, double y);

    ~TDVector() = default;

    TDVector(const TDVector &other)
        : x(other.x),
          y(other.y) {
    }

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

    friend bool operator==(const TDVector &lhs, const TDVector &rhs) {
        return lhs.x == rhs.x
               && lhs.y == rhs.y;
    }

    friend bool operator!=(const TDVector &lhs, const TDVector &rhs) {
        return !(lhs == rhs);
    }
};


#endif //TDVECTOR_H