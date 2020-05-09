#include "resultProtected.h"

ResultProtected::ResultProtected(unsigned int v) : result(v) {}
    
void ResultProtected::inc(unsigned int s) {
        Lock l(m);
        result += s;
}

unsigned int ResultProtected::get_val() {
        Lock l(m);
        return result;
}
