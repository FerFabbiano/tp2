#include "leniador.h"

Leniador::Leniador(BlockingQueue &queue_leniadores, Inventory &inventory) : 
queue_leniadores(queue_leniadores), inventory(inventory) {}

Leniador::~Leniador(){}

void Leniador::run(){
    char material = ' ';
    while (material != NO_MORE_MATERIALS){
        material = queue_leniadores.pop();
        if (material != NO_MORE_MATERIALS){
            usleep(50000);
            inventory.add_material(material);
        }
        if (material == NO_MORE_MATERIALS){
            inventory.close();
        }
    }
}
