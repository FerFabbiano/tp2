#ifndef ORCHESTATOR_H
#define ORCHESTATOR_H

#include "blocking_queue.h"
#include "spawner.h"
#include "thread.h"
#include "map.h"
#include <vector>

class Orchestator{
public:
    Orchestator(const char* workers, const char* map_of_materials);
    void init();
    void launch_threads();
    void join_threads();
    void print_results() const;
    int distribute_materials();
    ~Orchestator();
private:
    Inventory inventory;
    ResultProtected points;
    BlockingQueue cola_a, cola_m, cola_l;
    std::vector<Thread*> threads;
    Spawner spawner;
    Map map;
};

#endif
