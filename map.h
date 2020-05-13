#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <cstring>
#include <queue>
#include "thread.h"
#include "blocking_queue.h"
#include "agricultor.h"
#include "leniador.h"
#include "minero.h"
#include "inventory.h"

class Map{
public:
    Map(const char* filename, BlockingQueue &cola_a, 
        BlockingQueue &cola_l, BlockingQueue &cola_m);
    ~Map();
    void repartir_recursos();

private:
    std::string filename;
    BlockingQueue &cola_a;
    BlockingQueue &cola_l;
    BlockingQueue &cola_m;
};

#endif
