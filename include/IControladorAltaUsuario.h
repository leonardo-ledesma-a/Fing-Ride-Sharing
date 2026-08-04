#ifndef ICONTROLADOR_ALTA_USUARIO_H
#define ICONTROLADOR_ALTA_USUARIO_H

#include "TipoVehiculo.h"
#include "TipoLibreta.h"
#include <vector>
#include <string>

class IControladorAltaUsuario{
public:
    virtual ~IControladorAltaUsuario(){};
    virtual bool altaPasajero(std::string nickname, std::string nombre , std::string contrasena, std::string email, std::string ci) = 0;
    virtual bool altaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::vector<TipoLibreta>) = 0;
    virtual int  registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) = 0 ;
};

#endif