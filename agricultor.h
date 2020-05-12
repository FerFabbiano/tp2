#ifndef AGRICULTORES_H
#define AGRICULTORES_H

#include "thread.h"
#include "blocking_queue.h"
#include "inventory.h"
#include <iostream>

class Agricultor : public Thread {
public:
    Agricultor(BlockingQueue &queue_agricultores, Inventory &inventario);
    ~Agricultor();
    void run();
private:
    BlockingQueue &queue_agricultores;
    Inventory &inventario;
};


#endif
