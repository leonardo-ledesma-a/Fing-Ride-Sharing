#ifndef CONTROLADOR_ALTA_USUARIO_H
#define CONTROLADOR_ALTA_USUARIO_H

#include "IControladorAltaUsuario.h"
#include "TipoVehiculo.h"
#include "TipoLibreta.h"
#include <vector>
#include <string>

class ControladorAltaUsuario : public IControladorAltaUsuario {

private:
    
    static ControladorAltaUsuario* instancia;
    ControladorAltaUsuario();

public:
    ControladorAltaUsuario(const ControladorAltaUsuario& obj) = delete; 
    static ControladorAltaUsuario* getInstance();
    static void destroyInstance();
    bool altaPasajero(std::string nickname, std::string nombre , std::string contrasena, std::string email, std::string ci);
    bool altaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::vector<TipoLibreta>);
    int  registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);
};

#endif