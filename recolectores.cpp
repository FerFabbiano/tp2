#include "recolectores.h"
#include <unistd.h>

Recolectores::Recolectores(BlockingQueue &queue, Inventory 
&inventory) : queue(queue), inventory(inventory){}

void Recolectores::run(){
    char material = ' ';
    while (material != NO_MORE_MATERIALS){
        material = queue.pop();
        if (material != NO_MORE_MATERIALS){
            usleep(50000);
            inventory.add_material(material);
        }
        if (material == NO_MORE_MATERIALS){ 
            inventory.close();
        }
    }
}

Recolectores::~Recolectores(){}
