#ifndef AGRICULTORES_H
#define AGRICULTORES_H

#include "blocking_queue.h"
#include "inventory.h"
#include <unistd.h>
#include "recolectores.h"

class Agricultor : public Recolectores {
public:
    Agricultor(BlockingQueue &queue_agricultores, Inventory &inventory);
    ~Agricultor();
    
};


#endif
