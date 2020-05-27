#include "inventory.h"
#include <utility>
#include <map>

Inventory::Inventory(){
    this->inventory.insert(std::pair<char,int>('T',0));
    this->inventory.insert(std::pair<char,int>('M',0));
    this->inventory.insert(std::pair<char,int>('H',0));
    this->inventory.insert(std::pair<char,int>('C', 0));
    this->isClosed = 0;
}

Inventory::~Inventory(){}

void Inventory::add_material(const char material){
    std::unique_lock<std::mutex> lk(this->m);
    this->inventory.at(material) ++;
    cv.notify_all();
}

bool Inventory::consult_stock(const char material, const int cantidad) const{
    return (this->inventory.at(material) >= cantidad);
}

void Inventory::remove_materials(const char material, const int cantidad){
    this->inventory[material] -= cantidad;
}

bool Inventory::consult_stock_and_get_materials_if_there_is(
    std::map<char, int> &materials){
    std::unique_lock<std::mutex> lk(this->m);
    bool stock = false;
    for (auto& x: materials){
        stock = consult_stock(x.first, x.second);
        if (!stock)
            break;
    }
    while (!stock){
        if (isClosed == cant_recolectores){
            return false;
        }
        this->cv.wait(lk);
        for (auto& x: materials){
            stock = consult_stock(x.first, x.second);
            if (!stock)
                break;
        }
    }
    for (auto& x: materials){
        remove_materials(x.first, x.second);
    }
    return true;
}

void Inventory::close(){
    std::unique_lock<std::mutex> lk(this->m);
    isClosed += 1;
    cv.notify_all();
}

void Inventory::print_stock_restante() const{
    std::cout << "Recursos restantes:\n";
    std::cout << "  - Trigo: " << this->inventory.at('T') << '\n';
    std::cout << "  - Madera: " << this->inventory.at('M') << '\n';
    std::cout << "  - Carbon: " << this->inventory.at('C') << '\n';
    std::cout << "  - Hierro: " << this->inventory.at('H') << '\n';
    std::cout << '\n';
}

void Inventory::set_cant_recolectores(int cantidad){
    this->cant_recolectores = cantidad;
}
