#ifndef PRODUCTORES_H
#define PRODUCTORES_H

#include "thread.h"
#include "inventory.h"
#include "resultProtected.h"
#include <map>

class Productores : public Thread{
public: 
    Productores(Inventory &inventory, ResultProtected &points);
    virtual ~Productores();
    virtual void run();
private:
    Inventory &inventory;
    ResultProtected &points;
protected: 
    std::map<char,int> materials;
    int points_of_benefit;
};

#endif
