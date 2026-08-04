#include "../include/DTVehiculosConductor.h"

DTVehiculosConductor::DTVehiculosConductor(std::string matricula, std::string modelo, int capacidad)
    {
    this->matricula = matricula;
    this->modelo=  modelo;
    this->capacidad = capacidad;
}

std::string DTVehiculosConductor::getDTMatricula(){ 
    return this->matricula;
}

  std::string DTVehiculosConductor::getDTModelo(){
    return this->modelo;
  }


  int DTVehiculosConductor::getDTCapacidad(){
    return this->capacidad;
  }

//Matricula: xx, Capacidad: yy, Modelo: zzz"
std::ostream& operator<<(std::ostream& os, DTVehiculosConductor dtvc){
    os << "> Matricula: " << dtvc.getDTMatricula() << ", Capacidad: " << dtvc.getDTCapacidad() << ", Modelo: " << dtvc.getDTModelo() << "\n";
    return os;
}
