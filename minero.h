#ifndef MINERO_H
#define MINERO_H

#include "blocking_queue.h"
#include "inventory.h"
#include <unistd.h>

class Minero : public Thread {
public:
    Minero(BlockingQueue &queue_agricultores, Inventory &inventory);
    ~Minero();
    void run();
private:
    BlockingQueue &queue_mineros;
    Inventory &inventory;
};

#endif
