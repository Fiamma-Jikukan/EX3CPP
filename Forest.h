#ifndef FOREST_H
#define FOREST_H
#include <ostream>

#include "Cell.h"
#include "TDVector.h"

constexpr unsigned int FOREST_WIDTH = 72;
constexpr unsigned int FOREST_HEIGHT = 42;


class Forest {
private:
    Cell **cells;

public:
    Forest();

    ~Forest();

    void FreeData() const;

    Forest(const Forest &other);

    Forest(Forest &&other) noexcept;

    Forest & operator=(const Forest &other);

    Forest & operator=(Forest &&other) noexcept;

    unsigned int operator()(unsigned int x, unsigned int y) const;

    void addDroneToCell(const TDVector& xy) const;

    void removeDroneFromCell(const TDVector& xy) const;

    friend std::ostream& operator<<(std::ostream& os, const Forest& forest);

};


#endif //FOREST_H
