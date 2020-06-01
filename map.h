#ifndef MAP_H
#define MAP_H

#include <queue>
#include <iostream>
#include <string>
#include "blocking_queue.h"

#define ERROR 1

/* Clase que parsea el mapa de recursos */
class Map{
public:
    /* Constructor */
    Map(const char* filename, BlockingQueue &queue_a, 
        BlockingQueue &queue_l, BlockingQueue &queue_m);
    /* Distribuye los recursos a sus recpectivas queues */
    int repartir_recursos();
    /* Destructor */
    ~Map();

private:
    std::string filename;
    BlockingQueue &queue_a;
    BlockingQueue &queue_l;
    BlockingQueue &queue_m;
};

#endif
