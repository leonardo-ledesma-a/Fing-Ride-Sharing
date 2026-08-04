#include "../include/Fabrica.h"
#include "../include/ControladorFechaActual.h"
#include "../include/ControladorCalificarUsuario.h"
#include "../include/ControladorAltaUsuario.h"
#include "../include/ControladorAltaViaje.h"
#include "../include/ControladorGenerarReserva.h"
#include "../include/ControladorEliminarViaje.h"

Fabrica* Fabrica::instancia = nullptr;

Fabrica::Fabrica() {}

Fabrica* Fabrica::getInstance() {
    if (instancia == nullptr) {
        instancia = new Fabrica();
    }
    return instancia;
}

IControladorFechaActual* Fabrica::getIControladorFechaActual() {
    return ControladorFechaActual::getInstance();
}

IControladorCalificarUsuario* Fabrica::getIControladorCalificarUsuario(){
    return ControladorCalificarUsuario::getInstance(); 
}

IControladorAltaUsuario* Fabrica::getIControladorAltaUsuario(){
    return ControladorAltaUsuario::getInstance();
}

IControladorAltaViaje* Fabrica::getIControladorAltaViaje(){
    return ControladorAltaViaje::getInstance();
}

IControladorGenerarReserva* Fabrica::getIControladorGenerarReserva(){
    return ControladorGenerarReserva::getInstance();
}

IControladorEliminarViaje* Fabrica::getIControladorEliminarViaje(){
    return ControladorEliminarViaje::getInstance();
}

void Fabrica::destroyInstance(){
 
    ControladorFechaActual::destroyInstance();
    ControladorCalificarUsuario::destroyInstance();
    ControladorAltaUsuario::destroyInstance();
    ControladorAltaViaje::destroyInstance();
    ControladorGenerarReserva::destroyInstance();
    ControladorEliminarViaje::destroyInstance();

    delete instancia;
    instancia = nullptr;
}