#ifndef HANDLER_VEHICULO_H
#define HANDLER_VEHICULO_H

#include <vector>
#include <string>
#include <map>

class Vehiculo; 

class HandlerVehiculo{ 
    private: 
        static HandlerVehiculo* Instancia;
        HandlerVehiculo(); 
        std::map<std::string, Vehiculo*> Vehiculos; // Ahora el compilador acepta el puntero sin problemas
    public: 
        static HandlerVehiculo* getInstance();
        void destroyInstance();
        HandlerVehiculo(const HandlerVehiculo& obj) = delete; 
        bool existeMatricula(std::string matricula);
        Vehiculo* getVehiculo(std::string matricula);
        void agregarV(Vehiculo* v);
        std::map<std::string, Vehiculo*> getVehiculos();
};

#include "Vehiculo.h"

#endif