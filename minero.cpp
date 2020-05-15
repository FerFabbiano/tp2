#include "minero.h"

Minero::Minero(BlockingQueue &queue_mineros, Inventory &inventario) 
: queue_mineros(queue_mineros), inventario(inventario) {}

Minero::~Minero(){}

void Minero::run(){
    char material = ' ';
    while (material != '1'){
        material = queue_mineros.pop();
        if (material != '1'){
            usleep(50);
            inventario.add_material(material);
        }
        if (material == '1'){
            inventario.close();
        }
    }
}
