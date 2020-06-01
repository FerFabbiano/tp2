#ifndef CARPINTERO_H
#define CARPINTERO_H

#include "productores.h"

class Carpintero : public Productores {
public:
    Carpintero(Inventory &inventory, ResultProtected &puntos);
    ~Carpintero();
};

#endif
