#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>
#include <map>
#include <unistd.h>


#include "blocking_queue.h"
#include "spawner.h"
#include "thread.h"
#include "map.h"
#include "inventory.h"
 
int main(int argc, const char* argv[]){

    Inventory inventario;
    ResultProtected puntos(0);
    BlockingQueue cola_a, cola_m, cola_l;
    std::vector<Thread*> threads;
    Spawner spawner(argv[1], cola_a, cola_m, cola_l, threads, inventario, puntos);
    spawner.read_file();
    int cant_threads = threads.size();
    int cant_recolectores = spawner.get_cant_recolectores();
    inventario.set_cant_recolectores(cant_recolectores);

    Map mapa(argv[2], cola_a, cola_l, cola_m);

    for (int i = 0; i < cant_threads; i++){
        threads[i]->start();    
    }

    mapa.repartir_recursos();

    for (int i = 0; i < cant_threads; i++){
        threads[i]->join();    
        delete(threads[i]);
    }

    std::cout << "Trigo: " << inventario.get_stock('T') << std::endl;
    std::cout << "Madera: " << inventario.get_stock('M') << std::endl;
    std::cout << "Carbon: " << inventario.get_stock('C') << std::endl;
    std::cout << "Hierro: " << inventario.get_stock('H') << std::endl;

    std::cout << "Puntos de beneficio acumulados: " << puntos.get_val() << std::endl;

    return 0;
}
