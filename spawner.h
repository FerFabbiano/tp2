#include <iostream>
#include <cstring>
#include <queue>
#include "thread.h"
#include "blocking_queue.h"
#include "agricultores.h"

class Spawner {
public:
    Spawner(const char* filename, BlockingQueue &cola, 
    std::vector<Thread*> &threads);
    void read_file();
    void create(char *trabajador, char *cantidad);
    ~Spawner();
private:
    std::string filename;
    BlockingQueue &cola;
    std::vector<Thread*> &threads;
};
