#include "minero.h"

Minero::Minero(BlockingQueue &queue_mineros, Inventory &inventory) 
: Recolectores(queue_mineros, inventory) {}

Minero::~Minero(){}
