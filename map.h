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
    Map(const char* filename, BlockingQueue &cola_a, 
        BlockingQueue &cola_l, BlockingQueue &cola_m);
    /* Distribuye los recursos a sus recpectivas colas */
    int repartir_recursos();
    /* Destructor */
    ~Map();

private:
    std::string filename;
    BlockingQueue &cola_a;
    BlockingQueue &cola_l;
    BlockingQueue &cola_m;
};

#endif
