#include "productores.h"
#include <unistd.h>

Productores::Productores(Inventory &inventory, ResultProtected &points) : 
inventory(inventory), points(points){}

void Productores::run(){
    bool convertir_a_puntos = true;
    while (convertir_a_puntos){
        convertir_a_puntos = 
        inventory.consult_stock_and_get_materials_if_there_is(materials);
        if (convertir_a_puntos){
            usleep(60000);
            points.inc(points_of_benefit);
        }
    }
}

Productores::~Productores(){}
