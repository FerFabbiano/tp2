#ifndef CARPINTERO_H
#define CARPINTERO_H

#include "inventory.h"
#include "resultProtected.h"
#include <unistd.h>

class Carpintero : public Thread {
public:
    Carpintero(Inventory &inventario, ResultProtected &puntos);
    ~Carpintero();
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
