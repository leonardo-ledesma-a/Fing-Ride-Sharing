#include "../include/DTConsultaViaje.h"

DTConsultaViaje::DTConsultaViaje(int codigo, std::string marca, std::string modelo, std::string conductor, float calificacionProm, float precioTotal) {
    this->codigo = codigo;
    this->marca = marca;
    this->modelo = modelo;
    this->conductor = conductor;
    this->calificacionProm = calificacionProm;
    this->precioTotal = precioTotal;
}

int DTConsultaViaje::getCodigo() { return codigo; }
std::string DTConsultaViaje::getMarca() { return marca; }
std::string DTConsultaViaje::getModelo() { return modelo; }
std::string DTConsultaViaje::getConductor() { return conductor; }
float DTConsultaViaje::getCalificacionProm() { return calificacionProm; }
float DTConsultaViaje::getPrecioTotal() { return precioTotal; }

std::ostream& operator<<(std::ostream& os, DTConsultaViaje c){
    os << "> Codigo: " << std::to_string(c.getCodigo()) << ", Marca: " << c.getMarca() << ", Modelo: " << c.getModelo() << ", Conductor: " << c.getConductor() 
    << ", CalificacionPromedio:" << std::to_string(c.getCalificacionProm()) << ", PrecioTotal:" << std::to_string(c.getPrecioTotal());
    return os;
}