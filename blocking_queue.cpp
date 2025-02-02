#include "blocking_queue.h"

BlockingQueue::BlockingQueue() : isClosed(false){}

void BlockingQueue::push(const char material){
    std::unique_lock<std::mutex> lk(this->m);
    queue.push(material);
    cv.notify_all();
}

/*
Pueden suceder dos casos.
1- la queue esta vacía, pero no cerrada. En cuyo caso debo esperar hasta que 
se le agregue un elemento a la queue. 
2- la queue esta vacía y cerrada, es decir, no se van a recibir mas elementos 
en la queue. 
*/
char BlockingQueue::pop(){
    std::unique_lock<std::mutex> lk(this->m);
    while (queue.empty()){
        if (isClosed){
            return '1';
        }
        cv.wait(lk); // función bloqueante, evito Busy Wait
    }
    int out = queue.front(); // devuelve una referencia al próximo elemento
    queue.pop(); // quito el próximo elemento de la queue
    return out;
}

void BlockingQueue::close(){
    std::unique_lock<std::mutex> lk(this->m);
    /*
    Cuando no haya mas nada por sacar, el consumidor debe saberlo, por eso
    lo despierto y le aviso.
    */
    isClosed = true;
    cv.notify_all();
}

BlockingQueue::~BlockingQueue(){}
