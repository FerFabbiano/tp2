#include "leniadores.h"

Leniadores::Leniadores(BlockingQueue &queue_leniadores) : 
queue_leniadores(queue_leniadores){}

Leniadores::~Leniadores(){}

void Leniadores::run(){
    char material = ' ';
    while (material != '1'){
        material = queue_leniadores.pop();
        if (material == '1'){
            break;
        }
    }
}
