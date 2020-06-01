#include "spawner.h"
#include <vector>
#include <fstream>
#include <string>

Spawner::Spawner(const char* filename, BlockingQueue &queue_a, BlockingQueue 
    &queue_l, BlockingQueue &queue_m, std::vector<Thread*> &threads, Inventory
    &inventory, ResultProtected &puntos) : filename(filename), queue_a(queue_a),
    queue_l(queue_l), queue_m(queue_m), threads(threads), inventory(inventory),
    puntos(puntos) {
        this->cantidad_recolectores = 0;
}

Spawner::~Spawner(){}

int Spawner::read_file(){
    std::ifstream fs;
    fs.open(this->filename);
    if (!fs.is_open())
        return ERROR;
    std::string linea, trabajador, cantidad;
    while (!fs.eof()){
        while (getline(fs, linea)){
            trabajador = linea.substr(0, linea.find("=", 0));
            cantidad = linea.substr(linea.find("=")+1, 1);
            create(trabajador, cantidad);
        }
    }
    fs.close();
    return 0;
}

void Spawner::create(std::string trabajador, std::string cantidad){
    int cant = stoi(cantidad);
    if (trabajador.compare("Agricultores") == 0){
        for (int i = 0; i < cant; i++){
            cantidad_recolectores ++;
            this->threads.push_back(new Agricultor(queue_a, inventory));
        }
    }else if (trabajador.compare("Mineros") == 0){
        for (int i = 0; i < cant; i++){
            cantidad_recolectores ++;
            this->threads.push_back(new Minero(queue_m, inventory));
        }
    }else if (trabajador.compare("Leniadores") == 0){
        for (int i = 0; i < cant; i++){
            cantidad_recolectores ++;
            this->threads.push_back(new Leniador(queue_l, inventory));
        }
    }else if (trabajador.compare("Cocineros") == 0){
        for (int i = 0; i < cant; i++)
            this->threads.push_back(new Cocinero(inventory, puntos));
    }else if (trabajador.compare("Carpinteros") == 0){
        for (int i = 0; i < cant; i++)
            this->threads.push_back(new Carpintero(inventory, puntos));
    }else if (trabajador.compare("Armeros") == 0){
        for (int i = 0; i < cant; i++)
            this->threads.push_back(new Armero(inventory, puntos));
    }
}
