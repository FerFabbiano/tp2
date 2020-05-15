#include "leniador.h"

Leniador::Leniador(BlockingQueue &queue_leniadores, Inventory &inventario) : 
queue_leniadores(queue_leniadores), inventario(inventario) {}

Leniador::~Leniador(){}

void Leniador::run(){
    char material = ' ';
    while (material != '1'){
        material = queue_leniadores.pop();
        if (material != '1'){
            usleep(50);
            inventario.add_material(material);
        }
        if (material == '1'){
            inventario.close();
        }
    }
}
