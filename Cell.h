#ifndef CELL_H
#define CELL_H

using namespace std;


class Cell {
private:
    unsigned int x;
    unsigned int y;
    unsigned int numOfDrones;

public:
    Cell(unsigned int x, unsigned int y, unsigned int numOfDrones);

    Cell();

    ~Cell();

    Cell(const Cell &other);

    Cell(Cell &&other) noexcept;

    Cell &operator=(const Cell &other);

    Cell &operator=(Cell &&other) noexcept;

    unsigned int getX() const;

    void setX(unsigned int x);

    unsigned int getY() const;

    void setY(unsigned int y);

    unsigned int getNumOfDrones() const;

    Cell &operator++();

    Cell &operator++( int);

    Cell &operator--();

    Cell &operator--( int);
    bool operator==(const Cell &other) const;
};


#endif //CELL_H
