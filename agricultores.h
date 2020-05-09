#ifndef AGIRCULTORES_H
#define AGRICULTORES_H

#include "thread.h"
#include "blocking_queue.h"
#include <iostream>

class Agricultores : public Thread {
public:
    Agricultores(BlockingQueue &queue_agricultores);
    ~Agricultores();
    void run();
private:
    BlockingQueue &queue_agricultores;
};


#endif
