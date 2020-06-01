#ifndef ARMERO_H
#define ARMERO_H

#include "productores.h"

class Armero : public Productores {
public:
    Armero(Inventory &inventory, ResultProtected &puntos);
    ~Armero();
};

#endif
