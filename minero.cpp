#include "minero.h"

Minero::Minero(BlockingQueue &queue_mineros, Inventory &inventory) 
: queue_mineros(queue_mineros), inventory(inventory) {}

Minero::~Minero(){}

void Minero::run(){
    char material = ' ';
    while (material != '1'){
        material = queue_mineros.pop();
        if (material != '1'){
            usleep(50000);
            inventory.add_material(material);
        }
        if (material == '1'){
            inventory.close();
        }
    }
}
