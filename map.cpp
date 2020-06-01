#include "map.h"
#include <fstream>

Map::Map(const char* filename, BlockingQueue &queue_a, BlockingQueue &queue_l,
    BlockingQueue &queue_m) : filename(filename), queue_a(queue_a), 
    queue_l(queue_l), queue_m(queue_m){}

Map::~Map(){}

int Map::repartir_recursos() {
    std::ifstream fs;
    fs.open(this->filename);
    if (!fs.is_open())
        return ERROR;
    char material;
    material = fs.get();
    while (!fs.eof()){
        if (material == '\n'){
        }else if (material == 'T'){
            this->queue_a.push(material);
        }else if (material == 'M'){
            this->queue_l.push(material);
        }else if (material == 'C' || material == 'H'){
            this->queue_m.push(material);
        }else{ 
            return ERROR;    
        }
        material = fs.get();
    }
    fs.close();
    this->queue_a.close();
    this->queue_l.close();
    this->queue_m.close();
    return 0;
}
