#include "carpinteros.h"

Carpintero::Carpintero(Inventory &inventario, ResultProtected &puntos) 
    : inventario(inventario), puntos(puntos){
        material1 = 'M';
        material2 = 'H';
        cantidad1 = 3;
        cantidad2 = 1;
    }

Carpintero::~Carpintero(){}

void Carpintero::run(){
    bool convertir_a_puntos = NULL;
    while (convertir_a_puntos != false){
        convertir_a_puntos = 
        inventario.consult_stock_and_get_materials_if_there_is(material1,
        cantidad1, material2, cantidad2);
        if (convertir_a_puntos == true){
            puntos.inc(2);
        }
    }
}