#ifndef RESULT_PROTECTED_H
#define RESULT_PROTECTED_H

#include <vector>
#include <thread>
#include <mutex>
#include "lock.h"

class ResultProtected {
private:
    std::mutex m;        
    unsigned int result; 
public:
    ResultProtected(unsigned int v);
    void inc(unsigned int s);
    void print_points() const;
};

#endif
