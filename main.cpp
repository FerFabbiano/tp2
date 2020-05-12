#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>
#include <map>

#include "blocking_queue.h"
#include "spawner.h"
#include "thread.h"
#include "map.h"
 
int main(int argc, const char* argv[]){

/*
    std::map<char,int> mymap;

    // first insert function version (single parameter):
    mymap.insert ( std::pair<char,int>('a',100) );
    mymap.insert ( std::pair<char,int>('z',200) );
    mymap.insert ( std::pair<char,int>('d',200) );
    mymap.insert ( std::pair<char,int>('f',200) );

    std::map<char,int>::iterator it = mymap.begin();
  
    it ++++;
    it->second = 600;

    // showing contents:
    std::cout << "mymap contains:\n";
    for (it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
*/
    
    BlockingQueue cola_a, cola_m, cola_l;
    std::vector<Thread*> threads;
    Spawner spawner(argv[1], cola_a, cola_m, cola_l, threads);
    spawner.read_file();
    int cant_threads = threads.size();

    Map mapa(argv[2], cola_a, cola_l, cola_m);

    for (int i = 0; i < cant_threads; i++){
        threads[i]->start();    
    }

    mapa.repartir_recursos();
    int a = cola_a.tamanio(cola_a);
    int m = cola_m.tamanio(cola_m);
    int l = cola_l.tamanio(cola_l);

    std::cout << cant_threads << '\n' << a << '\n' << l << '\n' << m << '\n';

    for (int i = 0; i < cant_threads; i++){
        threads[i]->join();    
        delete(threads[i]);
    }

    return 0;
}

/*
  std::thread producer([&]() {
        for (int i = 0; i < 5; ++i) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "producing " << 'T' << '\n';
            std::cout << "producing " << 'C' << '\n';
            std::cout << "producing " << 'M' << '\n';
            cola_a.push('T');
            cola_m.push('C');
            cola_l.push('M');
        }
        cola_a.close();
        cola_m.close();
        cola_l.close();
    });

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