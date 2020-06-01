#ifndef COCINERO_H
#define COCINERO_H

#include "productores.h"

class Cocinero : public Productores {
public:
    Cocinero(Inventory &inventory, ResultProtected &puntos);
    ~Cocinero();
};

#endif
