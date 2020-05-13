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
    inventario.print_stock_restante();
    puntos.print_points();
    return 0;
}
