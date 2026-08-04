#ifndef ICONTROLADOR_ELIMINAR_VIAJE
#define ICONTROLADOR_ELIMINAR_VIAJE

#include "DTListarViaje.h"
#include "DTDetalleViaje.h"
#include "HandlerViaje.h"
#include <vector>

class IControladorEliminarViaje{

public:
    virtual ~IControladorEliminarViaje() {};
    virtual std::vector<DTListarViaje> listarViajes() = 0;
    virtual DTDetalleViaje detalleViaje(int codigo) = 0;
    virtual void eliminarViaje() = 0;
    virtual void cancelarEliminarViaje() = 0;

};

#endif