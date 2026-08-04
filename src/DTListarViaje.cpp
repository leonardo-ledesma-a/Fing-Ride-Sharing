#include "../include/DTListarViaje.h"

DTListarViaje::DTListarViaje(int codigo, DTFecha fecha, std::string origen, std::string destino, std::string conductor) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->conductor = conductor;
}

int DTListarViaje::getCodigo() { return codigo; }
DTFecha DTListarViaje::getFecha() { return fecha; }
std::string DTListarViaje::getOrigen() { return origen; }
std::string DTListarViaje::getDestino() { return destino; }
std::string DTListarViaje::getConductor() { return conductor; }

std::ostream& operator<<(std::ostream& os, DTListarViaje dtvi){
    os << "> Codigo: " << dtvi.getCodigo() << ", " 
    << "Fecha: " << dtvi.getFecha() << ", " 
    << "Origen: " << dtvi.getOrigen() << ", "
    << "Destino: " << dtvi.getDestino() << ", " 
    << "Conductor: " << dtvi.getConductor();
    return os;
}
