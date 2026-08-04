#ifndef DT_CONSULTA_VIAJE_H
#define DT_CONSULTA_VIAJE_H

#include "DTFecha.h"
#include <string>
#include <iostream>

//este datatype debe estar  al hacerse un set

//este datatype debe estar  al hacerse un set qué?

class DTConsultaViaje {
private:
  int codigo;
  std::string marca;
  std::string modelo;
  std::string conductor;
  float calificacionProm;
  float precioTotal;

public:
  DTConsultaViaje(int codigo, std::string marca, std::string modelo, std::string conductor, float calificacionProm, float precioTotal);

  int getCodigo();
  std::string getMarca();
  std::string getModelo();
  std::string getConductor();
  float getCalificacionProm();
  float getPrecioTotal();
};

std::ostream& operator<<(std::ostream& os, DTConsultaViaje c);

#endif
