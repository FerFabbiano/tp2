#ifndef MINERO_H
#define MINERO_H

#include "blocking_queue.h"
#include "inventory.h"
#include <unistd.h>
#include "recolectores.h"

class Minero : public Recolectores {
public:
    Minero(BlockingQueue &queue_agricultores, Inventory &inventory);
    ~Minero();
};

#endif
