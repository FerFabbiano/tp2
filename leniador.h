#ifndef LENIADOR_H
#define LENIADOR_H

#include "blocking_queue.h"
#include "inventory.h"
#include <iostream>
#include <unistd.h>
#include "recolectores.h"

class Leniador : public Recolectores {
public:
    Leniador(BlockingQueue &queue_leniadores, Inventory &inventory);
    ~Leniador();
    //void run();
private:

};


#endif
