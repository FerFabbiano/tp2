#ifndef CARPINTERO_H
#define CARPINTERO_H

#include "inventory.h"
#include "resultProtected.h"
#include <unistd.h>
#include <map>

class Carpintero : public Thread {
public:
    Carpintero(Inventory &inventory, ResultProtected &puntos);
    ~Carpintero();
    void run();
private:
    Inventory &inventory;
    ResultProtected &puntos;
    std::map<char, int> materials;
};

#endif
