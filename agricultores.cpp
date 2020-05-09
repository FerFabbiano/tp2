#include "agricultores.h"

Agricultores::Agricultores(BlockingQueue &queue_agricultores) : 
queue_agricultores(queue_agricultores){}

Agricultores::~Agricultores(){}

void Agricultores::run(){
    int num = 0;
    while (num != -1){
        num = queue_agricultores.pop();
        if (num == -1){
            std::cout << "No hay mas elementos por consumir " << '\n';
            break;
        }
        std::cout << "consuming " << num << '\n';
    }
}
