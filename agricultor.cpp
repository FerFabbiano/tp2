#include "agricultor.h"

Agricultor::Agricultor(BlockingQueue &queue_agricultores, Inventory 
&inventario) : queue_agricultores(queue_agricultores), inventario(inventario){}

Agricultor::~Agricultor(){}

void Agricultor::run(){
    char material = ' ';
    while (material != '1'){
        material = queue_agricultores.pop();
        if (material != '1')
            inventario.add_material(material);
    }
}
