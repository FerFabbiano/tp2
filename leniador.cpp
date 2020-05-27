#include "leniador.h"

Leniador::Leniador(BlockingQueue &queue_leniadores, Inventory &inventory) : 
queue_leniadores(queue_leniadores), inventory(inventory) {}

Leniador::~Leniador(){}

void Leniador::run(){
    char material = ' ';
    while (material != '1'){
        material = queue_leniadores.pop();
        if (material != '1'){
            usleep(50000);
            inventory.add_material(material);
        }
        if (material == '1'){
            inventory.close();
        }
    }
}
