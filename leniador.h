#ifndef LENIADOR_H
#define LENIADOR_H

#include "blocking_queue.h"
#include "inventory.h"
#include <iostream>
#include <unistd.h>

class Leniador : public Thread {
public:
    Leniador(BlockingQueue &queue_leniadores, Inventory &inventario);
    ~Leniador();
    void run();
private:
    BlockingQueue &queue_leniadores;
    Inventory &inventario;
};


#endif
