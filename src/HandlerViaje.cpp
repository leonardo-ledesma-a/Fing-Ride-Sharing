#include "../include/HandlerViaje.h"
    
    HandlerViaje* HandlerViaje::Instancia = nullptr;
    
    HandlerViaje::HandlerViaje(){

    }

void HandlerViaje::destroyInstance(){
        std::map<int, Viaje*>::iterator it;
        for (it = Viajes.begin(); it != Viajes.end(); it++){
            delete it->second;
            it->second = NULL;
        }
        Viajes.clear();
        delete Instancia;
        Instancia = nullptr;
    }

    HandlerViaje* HandlerViaje::getInstance(){
         if (Instancia == NULL) { 
            Instancia = new HandlerViaje();
         }
    return Instancia;
    };
    
    std::map<int, Viaje*> HandlerViaje::getViajes(){
        return this->Viajes;
    };

    void HandlerViaje::agregarViaje(Viaje* v){
        this->Viajes.insert(std::make_pair(v->getCodigo(), v)); 
    }; 

    Viaje* HandlerViaje::getViaje(int codigo){
        auto it = this->Viajes.find(codigo);
        return (it->second); 
    };

    void HandlerViaje::eliminarViaje(int codigo){
        auto it = Viajes.find(codigo);
        Viaje* vi = it->second;
        Viajes.erase(it);
        delete vi;
        vi = nullptr;
    }

    Viaje* HandlerViaje::crearViaje(Vehiculo* v, DTFecha f, std::string origen, std::string destino, int asientos, float precio){
        Viaje* vi = new Viaje();
        vi->setFecha(f);
        vi->setOrigen(origen);
        vi->setDestino(destino);
        vi->setAsientos(asientos);
        vi->setPrecio(precio);
        vi->setVehiculo(v);
        v->asociarViaje(vi);
        this->Viajes.insert({vi->getCodigo(), vi});
        return vi; 
    };
    