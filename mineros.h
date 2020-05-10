#ifndef MINEROS_H
#define MINEROS_H

#include "thread.h"
#include "blocking_queue.h"
#include <iostream>

class Mineros : public Thread {
public:
    Mineros(BlockingQueue &queue_agricultores);
    ~Mineros();
    void run();
private:
    BlockingQueue &queue_mineros;
};


#endif
