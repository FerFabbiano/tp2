#ifndef COCINERO_H
#define COCINERO_H

#include "thread.h"
#include "inventory.h"
#include "resultProtected.h"
#include <unistd.h>

class Cocinero : public Thread {
public:
    Cocinero(Inventory &inventario, ResultProtected &puntos);
    ~Cocinero();
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