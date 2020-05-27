#include "resultProtected.h"
#include <iostream>

ResultProtected::ResultProtected() : points(0) {}
    
void ResultProtected::inc(unsigned int s) {
    std::unique_lock<std::mutex> lk(this->m);
    points += s;
}

void ResultProtected::print_points() const{
    std::cout << "Puntos de Beneficio acumulados: " << points << '\n';
}

ResultProtected::~ResultProtected(){}
