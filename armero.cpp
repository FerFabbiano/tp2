#include "armero.h"
#include <utility>

Armero::Armero(Inventory &inventory, ResultProtected &points) 
    : Productores(inventory, points){
    this->materials.insert(std::pair<char,int>('H',2));
    this->materials.insert(std::pair<char,int>('C', 2));
    this->points_of_benefit = 3;
}

Armero::~Armero(){}
