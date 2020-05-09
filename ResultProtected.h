#ifndef RESULT_PROTECTED_H
#define RESULT_PROTECTED_H

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include "Lock.h"

class ResultProtected {
private:
    std::mutex m;        
    unsigned int result; 
public:
    ResultProtected(unsigned int v);
    void inc(unsigned int s);
    unsigned int get_val();
};

#endif
