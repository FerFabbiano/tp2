#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <cstring>
#include <queue>
#include "thread.h"
#include "blocking_queue.h"
#include "agricultores.h"
#include "leniadores.h"
#include "mineros.h"

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
