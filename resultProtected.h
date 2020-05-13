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
    /* Constructor */
    explicit ResultProtected(unsigned int v);
    /* Incremento el valor del atributo resultado */
    void inc(unsigned int s);
    /* Imprimo el valor del atributo resultado por pantalla */
    void print_points() const;
    /* Destructor */
    ~ResultProtected();
};

#endif
