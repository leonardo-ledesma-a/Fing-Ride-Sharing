#ifndef ICONTROLADOR_ALTA_H
#define ICONTROLADOR_ALTA_H

#include "Viaje.h"
#include "HandlerViaje.h"
#include "HandlerUsuario.h"
#include <string>
#include <vector>

class IControladorAltaViaje {
public: 
    virtual ~IControladorAltaViaje() {};
    virtual std::vector<DTVehiculosConductor> listarVehiculosConductor(std::string nickname) = 0;
    virtual bool altaViaje(std::string matricula, DTFecha fecha,std::string origen, std::string destino, int asientos, float precio) = 0;
};

#endif