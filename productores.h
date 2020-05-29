#ifndef PRODUCTORES_H
#define PRODUCTORES_H

#include "thread.h"

class Productores : public Thread{
public: 
    Productores();
    virtual ~Productores() = 0;
    void run();
};

#endif