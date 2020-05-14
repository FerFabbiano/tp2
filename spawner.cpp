#include "spawner.h"
#include <vector>
#include <fstream>

Spawner::Spawner(const char* filename, BlockingQueue &cola_a, BlockingQueue 
    &cola_l, BlockingQueue &cola_m, std::vector<Thread*> &threads, Inventory
    &inventario, ResultProtected &puntos) : filename(filename), cola_a(cola_a),
    cola_l(cola_l), cola_m(cola_m), threads(threads), inventario(inventario),
    puntos(puntos) {
        this->cantidad_recolectores = 0;
    }

Spawner::~Spawner(){}

void Spawner::read_file(){
    std::ifstream fs;
    fs.open(this->filename);
    char trabajador[14], cantidad;
    memset(trabajador, 0, sizeof(trabajador));
    int n = 0;
    while (!fs.eof()){
        while (strchr(trabajador, '=') == NULL){
            fs.read(&trabajador[n], 1);
            n++;
        }
        trabajador[n-1] = '\0';
        fs.read(&cantidad, 1);
        create(trabajador, &cantidad);
        memset(trabajador, 0, sizeof(trabajador));
        fs.read(&cantidad, 1); // avanzo uno el tintero del archivo
        n = 0;
        fs.read(&trabajador[n], 1);
        n++;
    }
    fs.close();
}

void Spawner::create(const char *trabajador, const char *cantidad){
    int cant = strtol(cantidad, NULL, 10);
    if (strcmp(trabajador, "Agricultores") == 0){
        for (int i = 0; i < cant; i++){
            cantidad_recolectores ++;
            this->threads.push_back(new Agricultor(cola_a, inventario));
        }
    }else if (strcmp(trabajador, "Mineros") == 0){
        for (int i = 0; i < cant; i++){
            cantidad_recolectores ++;
            this->threads.push_back(new Minero(cola_m, inventario));
        }
    }else if (strcmp(trabajador, "Leniadores") == 0){
        for (int i = 0; i < cant; i++){
            cantidad_recolectores ++;
            this->threads.push_back(new Leniador(cola_l, inventario));
        }
    }else if (strcmp(trabajador, "Cocineros") == 0){
        for (int i = 0; i < cant; i++)
            this->threads.push_back(new Cocinero(inventario, puntos));
    }else if (strcmp(trabajador, "Carpinteros") == 0){
        for (int i = 0; i < cant; i++)
            this->threads.push_back(new Carpintero(inventario, puntos));
    }else if (strcmp(trabajador, "Armeros") == 0){
        for (int i = 0; i < cant; i++)
            this->threads.push_back(new Armero(inventario, puntos));
    }
}
