#ifndef COCINERO_H
#define COCINERO_H

#include "inventory.h"
#include "resultProtected.h"
#include <unistd.h>
#include <map>

class Cocinero : public Thread {
public:
    Cocinero(Inventory &inventory, ResultProtected &puntos);
    ~Cocinero();
    void run();
private:
    Inventory &inventory;
    ResultProtected &puntos;
    std::map<char, int> materials;
};

#endif
