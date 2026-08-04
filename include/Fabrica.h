#ifndef FABRICA_H
#define FABRICA_H

#include "IControladorFechaActual.h"
#include "IControladorCalificarUsuario.h"
#include "IControladorAltaUsuario.h"
#include "IControladorAltaViaje.h"
#include "IControladorGenerarReserva.h"
#include "IControladorEliminarViaje.h"

class Fabrica {
private:
    static Fabrica* instancia;
    Fabrica();

public:
    static Fabrica* getInstance();
    static void destroyInstance();
    IControladorFechaActual* getIControladorFechaActual();
    IControladorCalificarUsuario* getIControladorCalificarUsuario();
    IControladorAltaUsuario* getIControladorAltaUsuario();
    IControladorAltaViaje* getIControladorAltaViaje();
    IControladorGenerarReserva* getIControladorGenerarReserva();
    IControladorEliminarViaje* getIControladorEliminarViaje();

};

#endif
