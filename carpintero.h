#ifndef CARPINTERO_H
#define CARPINTERO_H

#include "inventory.h"
#include "resultProtected.h"
#include <unistd.h>

class Carpintero : public Thread {
public:
    Carpintero(Inventory &inventory, ResultProtected &puntos);
    ~Carpintero();
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
