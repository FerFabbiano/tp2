#include "cocinero.h"

Cocinero::Cocinero(Inventory &inventario, ResultProtected &puntos) 
    : inventario(inventario), puntos(puntos){
        material1 = 'T';
        material2 = 'C';
        cantidad1 = 2;
        cantidad2 = 1;
    }

Cocinero::~Cocinero(){}

void Cocinero::run(){
    bool convertir_a_puntos = true;
    while (convertir_a_puntos != false){
        convertir_a_puntos = 
        inventario.consult_stock_and_get_materials_if_there_is(material1,
        cantidad1, material2, cantidad2);
        if (convertir_a_puntos == true){
            usleep(60000);
            puntos.inc(5);
        }
    }
}
