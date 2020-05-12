#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>
#include <map>

#include "blocking_queue.h"
#include "spawner.h"
#include "thread.h"
#include "map.h"
#include "inventory.h"
 
int main(int argc, const char* argv[]){

/*
    Inventory inventario;
    inventario.add_material('T');
    inventario.add_material('T');
    inventario.add_material('T');
    inventario.add_material('T');
    inventario.add_material('T');
    inventario.add_material('C');
    inventario.add_material('C');

    inventario.close();

    bool m = inventario.consult_stock_and_get_materials_if_there_is('T', 2, 'C', 1);
    m = inventario.consult_stock_and_get_materials_if_there_is('T', 2, 'C', 1);

    std::cout << m << std::endl;
*/
    /*
    bool stock1 = inventario.consult_stock('T', 2);
    bool stock2 = inventario.consult_stock('C', 1);
    std::cout << stock1 << std::endl;
    std::cout << stock2 << std::endl;

    inventario.remove_materials('T', 2);
    inventario.remove_materials('C', 1);

    bool stock3 = inventario.consult_stock('T', 4);
    std::cout << stock3 << std::endl;
    bool stock4 = inventario.consult_stock('C', 1);
    std::cout << stock4 << std::endl;
    */

    Inventory inventario;
    BlockingQueue cola_a, cola_m, cola_l;
    std::vector<Thread*> threads;
    Spawner spawner(argv[1], cola_a, cola_m, cola_l, threads, inventario);
    spawner.read_file();
    int cant_threads = threads.size();
  
    Map mapa(argv[2], cola_a, cola_l, cola_m);

    for (int i = 0; i < cant_threads; i++){
        threads[i]->start();    
    }

    mapa.repartir_recursos();
    inventario.close();

    for (int i = 0; i < cant_threads; i++){
        threads[i]->join();    
        delete(threads[i]);
    }

    bool m = inventario.consult_stock_and_get_materials_if_there_is('T', 5, 'M', 7);

    std::cout << m << std::endl;

    return 0;
}

/*
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include "Thread.h"
#include "CounterThread.h"
#include "ResultProtected.h"

int main(int argc, const char* argv[]) {

    ResultProtected resultado(0);

    std::vector<Thread*> threads;

    for (int i = 0; i < 2; ++i) {
        threads.push_back(new CharCounter(argv[i+1], 'C', resultado));
    }

    for (int i = 2; i < 4; ++i) {
        threads.push_back(new CharCounter(argv[i+1], 'M', resultado));
    }

    for (int i = 0; i < 4; ++i) {
        threads[i]->start();
    }

    for (int i = 0; i < 4; ++i) {
        threads[i]->join();
        delete threads[i];
    }

    std::cout << "Resultado " << resultado.get_val() << std::endl;

    return 0;

}
*/