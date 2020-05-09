#include "blocking_queue.h"
#include "agricultores.h"

#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>
 
int main(){

    BlockingQueue cola;

    std::vector<Agricultores*> agricultores;

    std::thread producer([&]() {
        for (int i = 0; i < 5; ++i) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "producing " << 'T' << '\n';
            cola.push('T');
        }
        cola.close();
    });

    for (int i = 0; i < 3; i++){
        agricultores.push_back(new Agricultores(cola));
    }

    for (int i = 0; i < 3; i++){
        agricultores[i]->start();    
    }

    producer.join();
    for (int i = 0; i < 3; i++){
        agricultores[i]->join();    
        delete(agricultores[i]);
    }

    return 0;
}

/*
int main(){

    BlockingQueue cola;
    int num = 0;

    std::thread producer([&]() {
        for (int i = 0; i < 5; ++i) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "producing " << i << '\n';
            cola.push(i);
        }   
        cola.close();
    }); 

    std::thread consumer([&]() {
        while (num != -1){
            num = cola.pop();
            if (num == -1){
                std::cout << "No hay mas elementos por consumir " << '\n';
                break;
            }
            std::cout << "consuming " << num << '\n';
        }
    }); 

    producer.join();
    consumer.join();

    return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include "Thread.h"
#include "CounterThread.h"
#include "ResultProtected.h"

int main(int argc, const char* argv[]) {

    ResultProtected resultado(0);

    std::vector<Thread*> threads;

    for (int i = 0; i < 2; ++i) {
        threads.push_back(new CharCounter(argv[i+1], 'C', resultado));
    }

    for (int i = 2; i < 4; ++i) {
        threads.push_back(new CharCounter(argv[i+1], 'M', resultado));
    }

    for (int i = 0; i < 4; ++i) {
        threads[i]->start();
    }

    for (int i = 0; i < 4; ++i) {
        threads[i]->join();
        delete threads[i];
    }

    std::cout << "Resultado " << resultado.get_val() << std::endl;

    return 0;

}
*/