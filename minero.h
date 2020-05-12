#ifndef MINERO_H
#define MINERO_H

#include "thread.h"
#include "blocking_queue.h"
#include <iostream>
#include "inventory.h"

class Minero : public Thread {
public:
    Minero(BlockingQueue &queue_agricultores, Inventory &inventario);
    ~Minero();
    void run();
private:
    BlockingQueue &queue_mineros;
    Inventory &inventario;
};


#endif
