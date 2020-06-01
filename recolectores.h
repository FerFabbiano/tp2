#ifndef RECOLECTORES_H
#define RECOLECTORES_H

#include "thread.h"
#include "inventory.h"
#include "blocking_queue.h"

class Recolectores : public Thread{
public:
    Recolectores(BlockingQueue &queue, Inventory &inventory);
    virtual ~Recolectores();
    virtual void run();
private:
    BlockingQueue &queue;
    Inventory &inventory;
};

#endif
