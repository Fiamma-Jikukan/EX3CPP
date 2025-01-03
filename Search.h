#ifndef SEARCH_H
#define SEARCH_H
#include "Drone.h"
#include "Forest.h"

class Search {
private:
    unsigned int maxNumOfIter;
    unsigned int numOfDrones;
    Drone *drones;
    Forest forest;
    unsigned int globalBest; // the index of the drone that is closest to the target
    TDVector target;
    bool ended; // indicates if the target was reached or the maximum num of iteration was reached

public:
    // Search(unsigned int numOfDrones,Drone *drones, Forest &forest, unsigned int globalBest, TDVector &target);
    Search(unsigned int max_num_of_iter, unsigned int num_of_drones, Drone *drones, const Forest &forest,
           unsigned int global_best, const TDVector &target, bool ended)
        : maxNumOfIter(max_num_of_iter),
          numOfDrones(num_of_drones),
          drones(drones),
          forest(forest),
          globalBest(global_best),
          target(target),
          ended(ended) {
    }


    ~Search();

    // Search(const Search &other);
    //
    // Search &operator=(const Search &other);
    //
    // Search(Search &&other) noexcept;
    //
    // Search &operator=(Search &&other) noexcept;

    void StartSearch();

    void EndSearch(unsigned int numOfIterations);

    void UpdateDrone(Drone &drone, unsigned int index);

    void updateSpeed(const Drone &drone);

    unsigned int GetGlobalBest() const;

    TDVector GetTarget();

    void UpdateGlobalBest(unsigned int newGlobalBest);

    Cell GetTargetCell() const;
};


#endif //SEARCH_H
