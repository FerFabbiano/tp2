#include "resultProtected.h"

ResultProtected::ResultProtected(unsigned int v) : result(v) {}
    
void ResultProtected::inc(unsigned int s) {
    Lock l(m);
    result += s;
}

void ResultProtected::print_points() const{
    std::cout << "Puntos de Beneficio acumulados: " << result << '\n';
}


ResultProtected::~ResultProtected(){}
