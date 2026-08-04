#ifndef DT_VEHICULOS_CONDUCTOR_H
#define DT_VEHICULOS_CONDUCTOR_H

#include <string>
#include <iostream>

class DTVehiculosConductor {
private:
  std::string matricula;
  std::string modelo;
  int capacidad;

public:
  DTVehiculosConductor(std::string matricula, std::string modelo, int capacidad);
  std::string getDTMatricula();
  std::string getDTModelo();
  int getDTCapacidad();
};

std::ostream& operator<<(std::ostream& os, DTVehiculosConductor dtvc);

#endif
