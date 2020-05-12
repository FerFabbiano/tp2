#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <condition_variable>
#include <mutex>
#include <cstring>
#include <iostream>
#include <map>

#include "lock.h"

class Inventory{
public:
    /* Inicializo el mapa con sus keys en 0 */
    Inventory (); 

    void add_material(char material);
    
    void remove_materials(const char material, const int cantidad);
    
    bool consult_stock(const char material, const int cantidad);
    
    /* Devuelve falso si no hay stock, devuelvo verdadero y quito los materiales del 
    inventario en caso de disponer del stock requerido */
    bool consult_stock_and_remove_if_there_is(const char material1, const int cantidad1, 
        const char material2, const int cantidad2);
    
    void close();

    /* Destructor */
    ~Inventory();

private:
    std::map<char, int> inventory;
    /* Si las colas están cerradas, cierro el inventario */
    bool isClosed;
    std::mutex m;
    std::condition_variable cv;
    std::map<char,int>::iterator it;
};







#endif
