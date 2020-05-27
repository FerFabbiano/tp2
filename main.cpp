#include "blocking_queue.h"
#include "spawner.h"
#include "thread.h"
#include "map.h"
#include "inventory.h"
#include <vector>
#include <map>

int main(int argc, const char* argv[]){
    Inventory inventory;
    ResultProtected points;
    BlockingQueue cola_a, cola_m, cola_l;
    std::vector<Thread*> threads;
    Spawner spawner(argv[1],cola_a,cola_l,cola_m,threads,inventory,points);
    spawner.read_file();
    inventory.set_cant_recolectores(spawner.cantidad_recolectores);
    Map mapa(argv[2], cola_a, cola_l, cola_m);
    for (int i = 0; i < (int)threads.size(); i++){
        threads[i]->start();    
    }
    if (mapa.repartir_recursos() == 1){
        for (int i = 0; i < (int)threads.size(); i++){
            threads[i]->join();    
            delete(threads[i]);
        }
        return 1;
    }
    for (int i = 0; i < (int)threads.size(); i++){
            threads[i]->join();    
            delete(threads[i]);
    }
    inventory.print_stock_restante();
    points.print_points();
    return 0;
}
