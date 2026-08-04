#ifndef HANDLER_VIAJE_H
#define HANDLER_VIAJE_H

#include <map> 
#include "DTFecha.h"
#include <string> 
#include "Vehiculo.h"

class Viaje;

class HandlerViaje{
 private: 
    static HandlerViaje* Instancia; 
    std::map<int, Viaje*> Viajes;  
    HandlerViaje();
 public: 
    HandlerViaje(const HandlerViaje& obj) = delete;
    static HandlerViaje* getInstance();
    void destroyInstance();
    std::map<int, Viaje*> getViajes();
    void agregarViaje(Viaje* v); 
    Viaje* getViaje(int codigo);
    Viaje* crearViaje(Vehiculo* v, DTFecha f, std::string origen, std::string destino, int asientos, float precio);
    void eliminarViaje(int codigo);
};

#include "Viaje.h"


#endif
