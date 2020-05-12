#include "spawner.h"

Spawner::Spawner(const char* filename, BlockingQueue &cola_a, BlockingQueue 
    &cola_l, BlockingQueue &cola_m, std::vector<Thread*> &threads, Inventory
    &inventario) : filename(filename), cola_a(cola_a), cola_l(cola_l),
    cola_m(cola_m), threads(threads), inventario(inventario) {}

Spawner::~Spawner(){}

void Spawner::read_file(){
    FILE* fp = fopen(this->filename.c_str(), "r");
    if (fp == NULL){
        // Lanzar excepción?
    }
    char trabajador[14], cantidad;
    memset(trabajador, 0, sizeof(trabajador));
    int n = 0;
    while(!feof(fp)){
        while (strchr(trabajador, '=') == NULL){
            n += fread(&trabajador[n], 1, 1, fp);
        }
        trabajador[n-1] = '\0';
        n += fread(&cantidad, 1, 1, fp);
        create(trabajador, &cantidad);
        memset(trabajador, 0, sizeof(trabajador));
        n += fread(&cantidad, 1, 1, fp); // avanzo uno el tintero del archivo
        n = 0;
        n += fread(&trabajador[n], 1, 1, fp);
    }
    fclose(fp);
}

void Spawner::create(char *trabajador, char *cantidad){
    int cant = strtol(cantidad, NULL, 10);
    if (strcmp(trabajador, "Agricultores") == 0){
        for (int i = 0; i < cant; i++){
            this->threads.push_back(new Agricultor(cola_a, inventario));
        }
    }else if(strcmp(trabajador, "Mineros") == 0){
        for (int i = 0; i < cant; i++){
            this->threads.push_back(new Minero(cola_m, inventario));
        }
    }else if(strcmp(trabajador, "Leniadores") == 0){
        for (int i = 0; i < cant; i++){
            this->threads.push_back(new Leniador(cola_l, inventario));
        }
    }else if(strcmp(trabajador, "Cocineros") == 0){
        //std::cout << trabajador << std::endl;
    }else if(strcmp(trabajador, "Carpinteros") == 0){
        //std::cout << trabajador << std::endl;
    }else if(strcmp(trabajador, "Armeros") == 0){
        //std::cout << trabajador << std::endl;
    }
}
