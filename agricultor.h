#ifndef AGRICULTORES_H
#define AGRICULTORES_H

#include "blocking_queue.h"
#include "inventory.h"
#include <unistd.h>

class Agricultor : public Thread {
public:
    Agricultor(BlockingQueue &queue_agricultores, Inventory &inventory);
    ~Agricultor();
    void run();
private:
    BlockingQueue &queue_agricultores;
    Inventory &inventory;
};


#endif
