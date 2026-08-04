#include "../include/DTDetalleVehiculo.h"

DTDetalleVehiculo::DTDetalleVehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo)
    {
    this->matricula = matricula;
    this->capacidad = capacidad;
    this->marca = marca;
    this->modelo = modelo;
    this->tipo = tipo;
}
DTDetalleVehiculo::DTDetalleVehiculo(){
    TipoVehiculo t {};
    this->matricula = "";
    this->capacidad = 0;
    this->marca = "";
    this->modelo = "";
    this->tipo = t;
}

std::string DTDetalleVehiculo::getMatricula() { return matricula; }
int DTDetalleVehiculo::getCapacidad() { return capacidad; }
std::string DTDetalleVehiculo::getMarca() { return marca; }
std::string DTDetalleVehiculo::getModelo() { return modelo; }
TipoVehiculo DTDetalleVehiculo::getTipo() { return tipo; }

std::ostream& operator<<(std::ostream& os, DTDetalleVehiculo dtv)
{
    os << ">> Vehiculo <<\n" << "--- Matricula: " << dtv.getMatricula() << ", Capacidad: " << dtv.getCapacidad() << ", Marca: " << dtv.getMarca() << 
    ", Modelo: " << dtv.getModelo() 
    << ", Tipo:" << dtv.getTipo() << "\n"; 
    return os;
}