#include "../include/ControladorGenerarReserva.h"
#include "../include/ControladorFechaActual.h"
#include "../include/HandlerUsuario.h"
#include "../include/HandlerViaje.h"
#include <map>
#include <algorithm>
#include <vector>
#include <string>

ControladorGenerarReserva* ControladorGenerarReserva::instancia = nullptr;

ControladorGenerarReserva::ControladorGenerarReserva(){}

ControladorGenerarReserva* ControladorGenerarReserva::getInstance(){
    if (instancia == nullptr) {
        instancia = new ControladorGenerarReserva();
    }
    return instancia;
}

 void ControladorGenerarReserva::destroyInstance(){
     if (instancia != nullptr) {
        delete instancia;
        instancia = nullptr;
    }
  }

std::vector<std::string> ControladorGenerarReserva::listarPasajeros(){
    auto hu = HandlerUsuario::getInstance();
    auto lp = hu->getPasajeros();
    std::map<std::string, Pasajero*>::iterator it;
    std::vector<std::string> resultado;
    for (it = lp.begin(); it != lp.end(); it++){
        resultado.push_back((it->second)->getNickname());
    }
    return resultado;
}

std::vector<DTConsultaViaje> ControladorGenerarReserva::consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos){
    std::vector<DTConsultaViaje> resultado;
    HandlerViaje* hu = HandlerViaje::getInstance();
    auto vi = hu->getViajes();
    std::map<int, Viaje*>::iterator it;
    for (it = vi.begin(); it != vi.end(); it++){
        auto aD = it->second->getAsientosDisponibles();
        if (it->second->getFecha() == fecha && it->second->getOrigen() == origen && it->second->getDestino() == destino && asientos <= aD){
            auto dtcv = it->second->getDTCV(asientos);
            resultado.push_back(dtcv);
        }
    }
    std::sort(resultado.begin(), resultado.end(), [](DTConsultaViaje c1, DTConsultaViaje c2) 
        {return ((c1.getPrecioTotal() < c2.getPrecioTotal()) || ((c1.getPrecioTotal() == c2.getPrecioTotal()) && (c1.getCalificacionProm() > c2.getCalificacionProm())));});
    return resultado;
}

bool ControladorGenerarReserva::generarReserva(std::string nickname, int codigo, int asientos){
    auto fa = ControladorFechaActual::getInstance();
    auto fechaActual = fa->getFecha();
    auto hu = HandlerViaje::getInstance();
    auto v = hu->getViaje(codigo);
    auto dtr = v->infoReservado(nickname);
    if (dtr.getInfoReservado() == false) return false;
    else if (dtr.getAsientosDisponibles() >= asientos){
        auto hu = HandlerUsuario::getInstance();
        auto p = hu->getPasajero(nickname);
        auto nr = p->crearReserva(fechaActual, asientos);
        v->anadirReserva(nr);
    }
    return true;
}