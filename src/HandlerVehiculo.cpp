#include "../include/HandlerVehiculo.h"

HandlerVehiculo* HandlerVehiculo::Instancia = nullptr;

HandlerVehiculo::HandlerVehiculo(){
    
}

HandlerVehiculo* HandlerVehiculo::getInstance(){
            if (Instancia == nullptr){
               Instancia = new HandlerVehiculo();
            }
    return Instancia;
};

void HandlerVehiculo::destroyInstance(){
    std::map<std::string,Vehiculo*>::iterator it;
    for( it = this->Vehiculos.begin(); it != this->Vehiculos.end();++it){
        delete it->second;
    }
    this->Vehiculos.clear();
    delete this->Instancia;
    this->Instancia = nullptr;
}



bool HandlerVehiculo::existeMatricula(std::string matricula){
    auto it = this->Vehiculos.find(matricula);
    return it != this->Vehiculos.end();
};

Vehiculo* HandlerVehiculo::getVehiculo(std::string matricula){
        if (existeMatricula(matricula)){ // if (existeMatricula(matricula))
            auto ptr = this->Vehiculos.find(matricula); 
            return (ptr->second);
        }
    return nullptr;
};
        
void HandlerVehiculo::agregarV(Vehiculo* v){
    this->Vehiculos.insert({v->getMatricula(), v}); 
};

std::map<std::string, Vehiculo*> HandlerVehiculo::getVehiculos(){        
    return this->Vehiculos;
};
