#include "carpintero.h"
#include <utility>

Carpintero::Carpintero(Inventory &inventory, ResultProtected &puntos) 
    : Productores(inventory, puntos){
    this->materials.insert(std::pair<char,int>('H',1));
    this->materials.insert(std::pair<char,int>('M', 3));
    this-> points_of_benefit = 2;
}

Carpintero::~Carpintero(){}
