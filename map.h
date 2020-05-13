#ifndef MAP_H
#define MAP_H

#include <queue>
#include <iostream>
#include <string>

#include "blocking_queue.h"

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
