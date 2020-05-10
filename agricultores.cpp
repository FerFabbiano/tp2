#include "agricultores.h"

Agricultores::Agricultores(BlockingQueue &queue_agricultores) : 
queue_agricultores(queue_agricultores){}

Agricultores::~Agricultores(){}

void Agricultores::run(){
    char material = ' ';
    while (material != '1'){
        material = queue_agricultores.pop();
        if (material == '1'){
            break;
        }
    }
}
