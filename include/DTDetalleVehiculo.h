#ifndef DT_DETALLE_VEHICULO_H
#define DT_DETALLE_VEHICULO_H

#include "TipoVehiculo.h"
#include <string>
#include <iostream>

class DTDetalleVehiculo {
private:
    std::string matricula;
    int capacidad;
    std::string marca;
    std::string modelo;
    TipoVehiculo tipo;

public:
    DTDetalleVehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);
    DTDetalleVehiculo();
    
    std::string getMatricula();
    int getCapacidad();
    std::string getMarca();
    std::string getModelo();
    TipoVehiculo getTipo();
};

std::ostream& operator<<(std::ostream& os, DTDetalleVehiculo dtdve);

#endif
