#include "map.h"
#include <fstream>

Map::Map(const char* filename, BlockingQueue &cola_a, BlockingQueue &cola_l,
    BlockingQueue &cola_m) : filename(filename), cola_a(cola_a), 
    cola_l(cola_l), cola_m(cola_m){}

Map::~Map(){}

int Map::repartir_recursos() {
    std::ifstream fs;
    fs.open(this->filename);
    if (!fs.is_open())
        return ERROR;
    while (!fs.eof()){
        char material;
        material = fs.get();
        if (material == '\n'){
        }else if (material == 'T'){
            this->cola_a.push(material);
        }else if (material == 'M'){
            this->cola_l.push(material);
        }else if (material == 'C' || material == 'H'){
            this->cola_m.push(material);
        }
    }
    fs.close();
    this->cola_a.close();
    this->cola_l.close();
    this->cola_m.close();
    return 0;
}
