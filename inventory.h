#ifndef inventory_H
#define inventory_H

#include <condition_variable>
#include <mutex>
#include <cstring>
#include <iostream>
#include <map>

#include "thread.h"
#include "lock.h"

class Inventory{
public:
    /* Inicializo el mapa con sus keys en 0 */
    Inventory(); 
    void add_material(const char material);
    /* Devuelve falso si no hay stock y ya no se van a agregar mas materiales a mi
    inventory. Devuelvo verdadero y quito los materiales del 
    inventory en caso de disponer del stock requerido */
    bool consult_stock_and_get_materials_if_there_is(const char material1, 
        const int cantidad1, const char material2, const int cantidad2);
    void close();
    void print_stock_restante() const;
    void set_cant_recolectores(const int cantidad);
    /* Destructor */
    ~Inventory();

private:
    /* Quito la cantidad indicada del material indicado, de mi inventory */
    void remove_materials(const char material, const int cantidad);
    /* Devuelvo verdadero en caso de tener ese stock en mi inventory,
    devuelvo falso en caso de no disponerlo */
    bool consult_stock(const char material, const int cantidad) const;
    std::map<char, int> inventory;
    int isClosed;
    std::mutex m;
    std::condition_variable cv;
    int cant_recolectores;
};

#endif
