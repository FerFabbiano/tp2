#include "carpintero.h"

Carpintero::Carpintero(Inventory &inventory, ResultProtected &puntos) 
    : inventory(inventory), puntos(puntos){
        material1 = 'M';
        material2 = 'H';
        cantidad1 = 3;
        cantidad2 = 1;
    }

Carpintero::~Carpintero(){}

void Carpintero::run(){
    bool convertir_a_puntos = true;
    while (convertir_a_puntos){
        convertir_a_puntos = 
        inventory.consult_stock_and_get_materials_if_there_is(material1,
        cantidad1, material2, cantidad2);
        if (convertir_a_puntos == true){
            usleep(60000);
            puntos.inc(2);
        }
    }
}
