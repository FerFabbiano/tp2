#include "resultProtected.h"

ResultProtected::ResultProtected() : points(0) {}
    
void ResultProtected::inc(unsigned int s) {
    Lock l(m);
    points += s;
}

void ResultProtected::print_points() const{
    std::cout << "Puntos de Beneficio acumulados: " << points << '\n';
}

ResultProtected::~ResultProtected(){}
