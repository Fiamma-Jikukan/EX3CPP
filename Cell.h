#ifndef CELL_H
#define CELL_H


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

    Cell &operator++(unsigned int);

    Cell &operator--();

    Cell &operator--(unsigned int);
};


#endif //CELL_H
