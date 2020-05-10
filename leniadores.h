#ifndef LENIADORES_H
#define LENIADORES_H

#include "thread.h"
#include "blocking_queue.h"
#include <iostream>

class Leniadores : public Thread {
public:
    Leniadores(BlockingQueue &queue_leniadores);
    ~Leniadores();
    void run();
private:
    BlockingQueue &queue_leniadores;
};


#endif
