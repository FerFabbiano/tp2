#ifndef ARMERO_H
#define ARMERO_H

#include "inventory.h"
#include "resultProtected.h"
#include <unistd.h>

class Armero : public Thread {
public:
    Armero(Inventory &inventory, ResultProtected &puntos);
    ~Armero();
    void run();
private:
    Inventory &inventory;
    ResultProtected &puntos;
    char material1;
    char material2;
    int cantidad1;
    int cantidad2;
};

#endif
