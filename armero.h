#ifndef ARMERO_H
#define ARMERO_H

#include "thread.h"
#include "inventory.h"
#include "resultProtected.h"
#include <unistd.h>

class Armero : public Thread {
public:
    Armero(Inventory &inventario, ResultProtected &puntos);
    ~Armero();
    void run();
private:
    Inventory &inventario;
    ResultProtected &puntos;
    char material1;
    char material2;
    int cantidad1;
    int cantidad2;
};

#endif
