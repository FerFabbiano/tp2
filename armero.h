#ifndef ARMERO_H
#define ARMERO_H

#include "inventory.h"
#include "resultProtected.h"
#include <unistd.h>
#include <map>

class Armero : public Thread {
public:
    Armero(Inventory &inventory, ResultProtected &puntos);
    ~Armero();
    void run();
private:
    Inventory &inventory;
    ResultProtected &puntos;
    std::map<char, int> materials;
};

#endif
