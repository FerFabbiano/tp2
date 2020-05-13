#include "map.h"

Map::Map(const char* filename, BlockingQueue &cola_a, BlockingQueue &cola_l,
    BlockingQueue &cola_m) : filename(filename), cola_a(cola_a), 
    cola_l(cola_l), cola_m(cola_m){}

Map::~Map(){}

void Map::repartir_recursos() {
    FILE *fp = fopen(this->filename.c_str(), "r");
    if (fp == NULL){
        // Lanzar excepción?
    }
    while (!feof(fp)){
        char material;
        material = fgetc(fp);
        if (material == '\n'){
        }else if (material == 'T'){
            //std::cout << material;
            this->cola_a.push(material);
        }else if (material == 'M'){
            //std::cout << material;
            this->cola_l.push(material);
        }else if (material == 'C' || material == 'H'){
            //std::cout << material;
            this->cola_m.push(material);
        }
    }
    fclose(fp);
    this->cola_a.close();
    this->cola_l.close();
    this->cola_m.close();
}
