#include "agricultor.h"

Agricultor::Agricultor(BlockingQueue &queue_agricultores, Inventory 
&inventory) : queue_agricultores(queue_agricultores), inventory(inventory){}

Agricultor::~Agricultor(){}

void Agricultor::run(){
    char material = ' ';
    while (material != NO_MORE_MATERIALS){
        material = queue_agricultores.pop();
        if (material != NO_MORE_MATERIALS){
            usleep(50000);
            inventory.add_material(material);
        }
        if (material == NO_MORE_MATERIALS){ 
            inventory.close();
        }
    }
}
