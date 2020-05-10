#include "mineros.h"

Mineros::Mineros(BlockingQueue &queue_mineros) : queue_mineros(queue_mineros){}

Mineros::~Mineros(){}

void Mineros::run(){
    char material = ' ';
    while (material != '1'){
        material = queue_mineros.pop();
        if (material == '1'){
            std::cout << "No hay mas elementos por consumir " << '\n';
            break;
        }
        std::cout << "consuming " << material << '\n';
    }
}