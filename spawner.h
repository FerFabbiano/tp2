#ifndef SPAWNER_H
#define SPAWNER_H

#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <vector>
#include "thread.h"
#include "blocking_queue.h"
#include "agricultor.h"
#include "leniador.h"
#include "carpintero.h"
#include "minero.h"
#include "cocinero.h"
#include "armero.h"
#include "inventory.h"

/* Clase que lee el archivo de entrada, y crea los threads
según las cantidades indicadas en el archivo */
class Spawner {
public:
    Spawner(const char* filename, BlockingQueue &cola_a, 
        BlockingQueue &cola_l, BlockingQueue &cola_m, 
        std::vector<Thread*> &threads, Inventory &inventario, 
        ResultProtected &puntos);
    /* Lee el archivo de a una línea, y va llamando a la función create 
    cada vez que termina de leer una. */
    void read_file();
    /* Recibe por parámetro el tipo de trabajador, y la cantidad que tiene 
    que crear, para luego agregar al vector de threads. */
    void create(char *trabajador, char *cantidad);
    int get_cant_recolectores();
    ~Spawner();
private:
    std::string filename;
    BlockingQueue &cola_a;
    BlockingQueue &cola_l;
    BlockingQueue &cola_m;
    std::vector<Thread*> &threads;
    Inventory &inventario;
    ResultProtected &puntos;
    int cantidad_recolectores;
};

#endif
