#include "armero.h"

Armero::Armero(Inventory &inventario, ResultProtected &puntos) 
    : inventario(inventario), puntos(puntos){
        material1 = 'C';
        material2 = 'H';
        cantidad1 = 2;
        cantidad2 = 2;
    }

Armero::~Armero(){}

void Armero::run(){
    bool convertir_a_puntos = true;
    while (convertir_a_puntos != false){
        convertir_a_puntos = 
        inventario.consult_stock_and_get_materials_if_there_is(material1,
        cantidad1, material2, cantidad2);
        if (convertir_a_puntos == true){
            usleep(60000);
            puntos.inc(3);
        }
    }
}
