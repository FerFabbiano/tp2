#include "map.h"
#include <fstream>

Map::Map(const char* filename, BlockingQueue &cola_a, BlockingQueue &cola_l,
    BlockingQueue &cola_m) : filename(filename), cola_a(cola_a), 
    cola_l(cola_l), cola_m(cola_m){}

Map::~Map(){}

void Map::repartir_recursos() {
    std::ifstream fs;
    fs.open(this->filename);
    while (!fs.eof()){
        char material;
        material = fs.get();
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
    fs.close();
    this->cola_a.close();
    this->cola_l.close();
    this->cola_m.close();
}
