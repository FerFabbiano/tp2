#include "leniador.h"

Leniador::Leniador(BlockingQueue &queue_leniadores, Inventory &inventory) : 
Recolectores(queue_leniadores, inventory){}

Leniador::~Leniador(){}
