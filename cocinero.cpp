#include "cocinero.h"
#include <utility>

Cocinero::Cocinero(Inventory &inventory, ResultProtected &puntos) 
    : Productores(inventory, puntos){
    this->materials.insert(std::pair<char,int>('T', 2));
    this->materials.insert(std::pair<char,int>('C', 1));
    this->points_of_benefit = 5;
}

Cocinero::~Cocinero(){}
