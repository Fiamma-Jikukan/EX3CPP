#include "Forest.h"

Forest::Forest(): cells(new Cell *[FOREST_WIDTH]) {
    for (int i = 0; i < FOREST_WIDTH; i++) {
        cells[i] = new Cell[FOREST_HEIGHT];
    }
    for (int i = 0; i < FOREST_WIDTH; i++) {
        for (int j = 0; j < FOREST_HEIGHT; j++) {
            cells[i][j].setX(i);
            cells[i][j].setY(j);
        }
    }
}

void Forest::FreeData() const {
    for (int i = 0; i < FOREST_WIDTH; i++) {
        delete[] cells[i];
    }
    delete[] cells;
}

Forest::~Forest() {
    FreeData();
}

Forest::Forest(const Forest &other)
    : cells(new Cell *[FOREST_WIDTH]) {
    for (int i = 0; i < FOREST_WIDTH; i++) {
        cells[i] = new Cell[FOREST_HEIGHT];
        for (int j = 0; j < FOREST_HEIGHT; j++) {
            cells[i][j] = other.cells[i][j];
        }
    }
}

Forest::Forest(Forest &&other) noexcept
    : cells(other.cells) {
    other.cells = nullptr;
}

Forest &Forest::operator=(const Forest &other) {
    if (this == &other) {
        return *this;
    }
    FreeData();
    cells = new Cell *[FOREST_WIDTH];
    for (int i = 0; i < FOREST_WIDTH; i++) {
        cells[i] = new Cell[FOREST_HEIGHT];
        for (int j = 0; j < FOREST_HEIGHT; j++) {
            cells[i][j] = other.cells[i][j];
        }
    }
    return *this;
}

Forest &Forest::operator=(Forest &&other) noexcept {
    if (this == &other) {
        return *this;
    }
    FreeData();
    cells = other.cells;
    other.cells = nullptr;
    return *this;
}

unsigned int Forest::operator()(const unsigned int x, const unsigned int y) const {
    return cells[y][x].getNumOfDrones();
}
