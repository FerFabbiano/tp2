#include "carpintero.h"
#include <utility>

Carpintero::Carpintero(Inventory &inventory, ResultProtected &puntos) 
    : inventory(inventory), puntos(puntos){
    this->materials.insert(std::pair<char,int>('H',1));
    this->materials.insert(std::pair<char,int>('M', 3));
}

Carpintero::~Carpintero(){}

void Carpintero::run(){
    bool convertir_a_puntos = true;
    while (convertir_a_puntos){
        convertir_a_puntos = 
        inventory.consult_stock_and_get_materials_if_there_is(materials);
        if (convertir_a_puntos){
            usleep(60000);
            puntos.inc(2);
        }
    }
}
