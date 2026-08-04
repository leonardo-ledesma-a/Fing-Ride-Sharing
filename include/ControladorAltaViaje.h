#ifndef CONTROLADOR_ALTA_VIAJE_H
#define CONTROLADOR_ALTA_VIAJE_H

#include "IControladorAltaViaje.h"
#include <string>
#include <vector>

class ControladorAltaViaje : public IControladorAltaViaje {

private:
    
    static ControladorAltaViaje* instancia;
    ControladorAltaViaje();

public: 
    ControladorAltaViaje(const ControladorAltaViaje& obj) = delete;
    static ControladorAltaViaje* getInstance();
    static void destroyInstance(); 
    std::vector<DTVehiculosConductor> listarVehiculosConductor(std::string nickname);
    bool altaViaje(std::string matricula, DTFecha fecha,std::string origen,  std::string destino, int asientos, float precio);
};

#endif