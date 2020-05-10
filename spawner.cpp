#include "spawner.h"

Spawner::Spawner(const char* filename, BlockingQueue &cola, 
std::vector<Agricultores*> &agricultores) : filename(filename), cola(cola),
agricultores(agricultores) {}

Spawner::~Spawner(){}

void Spawner::read_file(){
    FILE* fp = fopen(this->filename.c_str(), "r+b");
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
    if (strcmp(trabajador, "Agricultores") == 0){
        for (int i = 0; i < 2; i++){
            this->agricultores.push_back(new Agricultores(cola));
        }
    }else if(strcmp(trabajador, "Mineros") == 0){
        std::cout << trabajador << std::endl;
    }else if(strcmp(trabajador, "Leniadores") == 0){
        std::cout << trabajador << std::endl;
    }else if(strcmp(trabajador, "Cocineros") == 0){
        std::cout << trabajador << std::endl;
    }else if(strcmp(trabajador, "Carpinteros") == 0){
        std::cout << trabajador << std::endl;
    }else if(strcmp(trabajador, "Armeros") == 0){
        std::cout << trabajador << std::endl;
    }
}
