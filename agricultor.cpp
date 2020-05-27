#include "agricultor.h"

Agricultor::Agricultor(BlockingQueue &queue_agricultores, Inventory 
&inventory) : queue_agricultores(queue_agricultores), inventory(inventory){}

Agricultor::~Agricultor(){}

void Agricultor::run(){
    char material = ' ';
    while (material != '1'){
        material = queue_agricultores.pop();
        if (material != '1'){
            usleep(50000);
            inventory.add_material(material);
        }
        if (material == '1'){ 
            inventory.close();
        }
    }
}
