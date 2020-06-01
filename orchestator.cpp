#include "orchestator.h"

Orchestator::Orchestator(const char* workers, const char* map_of_materials) : 
spawner(workers, cola_a, cola_l, cola_m, threads, inventory, points), 
map(map_of_materials, cola_a, cola_l, cola_m){}

void Orchestator::init(){
    spawner.read_file();
    inventory.set_cant_recolectores(spawner.cantidad_recolectores);
}

void Orchestator::launch_threads(){
    for (int i = 0; i < (int)threads.size(); i++){
        threads[i]->start();    
    }
}

int Orchestator::distribute_materials(){
    if (map.repartir_recursos() == 1){
        for (int i = 0; i < (int)threads.size(); i++){
            threads[i]->join();    
            delete(threads[i]);
        }
        return 1;
    }
    return 0;
}

void Orchestator::join_threads(){
    for (int i = 0; i < (int)threads.size(); i++){
            threads[i]->join();    
            delete(threads[i]);
    }  
}

void Orchestator::print_results() const{
    inventory.print_stock_restante();
    points.print_points();
}

Orchestator::~Orchestator(){}
