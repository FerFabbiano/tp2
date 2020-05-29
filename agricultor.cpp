#include "agricultor.h"

Agricultor::Agricultor(BlockingQueue &queue_agricultores, Inventory 
&inventory) : Recolectores(queue_agricultores, inventory){}

Agricultor::~Agricultor(){}
