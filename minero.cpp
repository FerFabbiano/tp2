#include "minero.h"

Minero::Minero(BlockingQueue &queue_mineros, Inventory &inventory) 
: queue_mineros(queue_mineros), inventory(inventory) {}

Minero::~Minero(){}

void Minero::run(){
    char material = ' ';
    while (material != NO_MORE_MATERIALS){
        material = queue_mineros.pop();
        if (material != NO_MORE_MATERIALS){
            usleep(50000);
            inventory.add_material(material);
        }
        if (material == NO_MORE_MATERIALS){
            inventory.close();
        }
    }
}
