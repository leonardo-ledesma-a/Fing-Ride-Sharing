#ifndef CONTROLADOR_ELIMINAR_VIAJE
#define CONTROLADOR_ELIMINAR_VIAJE

#include "IControladorEliminarViaje.h"
#include "DTListarViaje.h"
#include "DTDetalleViaje.h"
#include <vector>

class ControladorEliminarViaje : public IControladorEliminarViaje {
private:

    static ControladorEliminarViaje* instancia;
    ControladorEliminarViaje();
    int codigo;

public:
    ControladorEliminarViaje(const ControladorEliminarViaje& obj) = delete; 
    static ControladorEliminarViaje* getInstance();
    static void destroyInstance(); 
    std::vector<DTListarViaje> listarViajes();
    DTDetalleViaje detalleViaje(int codigo);
    void eliminarViaje();
    void cancelarEliminarViaje();
};

#endif