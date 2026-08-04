#include "../include/ControladorAltaViaje.h"

ControladorAltaViaje* ControladorAltaViaje::instancia = nullptr;

ControladorAltaViaje::ControladorAltaViaje(){
}

ControladorAltaViaje* ControladorAltaViaje::getInstance(){
     if (instancia == nullptr){
    instancia = new ControladorAltaViaje();
    }
    return instancia;
}

void ControladorAltaViaje::destroyInstance(){
    if (instancia != nullptr) {
        delete instancia;
        instancia = nullptr;
    }
    HandlerVehiculo* hvehi = HandlerVehiculo::getInstance();
    hvehi->destroyInstance();

    HandlerViaje* hv = HandlerViaje::getInstance();
    hv->destroyInstance();
}


std::vector<DTVehiculosConductor> ControladorAltaViaje::listarVehiculosConductor(std::string nickname){
    std::vector<DTVehiculosConductor> listaVehiculos;
    HandlerUsuario* hu = HandlerUsuario::getInstance();
    Conductor* c = hu->getConductor(nickname);
    listaVehiculos = c->listarVehiculos();
    return listaVehiculos;
}


bool ControladorAltaViaje::altaViaje(std::string matricula, DTFecha fecha,std::string origen,  std::string destino, int asientos, float precio){
    HandlerVehiculo* hv = HandlerVehiculo::getInstance();
    Vehiculo* v = hv->getVehiculo(matricula);
    int capacidad = v->getCapacidad();
    if (capacidad >= asientos){
        bool hayViajesFecha = v->hayViajeConductor(fecha);
        if (!hayViajesFecha){
             HandlerViaje* hv = HandlerViaje::getInstance();
             Viaje* vi = hv->crearViaje(v, fecha, origen, destino, asientos, precio);
             v->asociarViaje(vi);
       } return (!hayViajesFecha);
    } else return false;
}