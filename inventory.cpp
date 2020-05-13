#include "inventory.h"
#include <utility>
#include <map>

Inventory::Inventory(std::map<char, int> &inventario) : inventario(inventario){
    this->inventario.insert(std::pair<char,int>('T',0));
    this->inventario.insert(std::pair<char,int>('M',0));
    this->inventario.insert(std::pair<char,int>('H',0));
    this->inventario.insert(std::pair<char,int>('C', 0));
    this->isClosed = false;
}

Inventory::~Inventory(){}

void Inventory::add_material(char material){
    std::unique_lock<std::mutex> lk(this->m);
    this->inventario.at(material) ++;
    cv.notify_all();
}

bool Inventory::consult_stock(const char material, int cantidad) const{
    if (this->inventario[material] >= cantidad)
        return true;
    return false;
}

void Inventory::remove_materials(const char material, const int cantidad){
    this->inventario[material] -= cantidad;
}

bool Inventory::consult_stock_and_get_materials_if_there_is(const char 
    material1, const int cantidad1, const char material2, const int cantidad2){
    std::unique_lock<std::mutex> lk(this->m);
    bool stock1 = consult_stock(material1, cantidad1);
    bool stock2 = consult_stock(material2, cantidad2);
    while (!stock1 || !stock2){
        if (isClosed == cant_recolectores){
            return false;
        }
        this->cv.wait(lk);
        stock1 = consult_stock(material1, cantidad1);
        stock2 = consult_stock(material2, cantidad2);
    }
    remove_materials(material1, cantidad1);
    remove_materials(material2, cantidad2);
    return true;
}

void Inventory::close(){
    std::unique_lock<std::mutex> lk(this->m);
    isClosed += 1;
    cv.notify_all();
}

void Inventory::print_stock_restante() const{
    std::cout << "Recursos restantes:\n";
    std::cout << "  - Trigo: " << this->inventario['T'] << '\n';
    std::cout << "  - Madera: " << this->inventario['M'] << '\n';
    std::cout << "  - Carbon: " << this->inventario['C'] << '\n';
    std::cout << "  - Hierro: " << this->inventario['H'] << '\n';
    std::cout << '\n';
}

void Inventory::set_cant_recolectores(int cantidad){
    this->cant_recolectores = cantidad;
}
