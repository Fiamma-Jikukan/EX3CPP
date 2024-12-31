#ifndef FOREST_H
#define FOREST_H
#include "Cell.h"

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

};


#endif //FOREST_H
