#ifndef DT_DETALLE_RESERVA_H
#define DT_DETALLE_RESERVA_H

#include "DTFecha.h"
#include <string>
#include <iostream>

class DTDetalleReserva {
private:
    int asientosReservados;
    DTFecha fecha;
    std::string pasajero;

public:
    DTDetalleReserva(int asientosReservados, DTFecha fecha, std::string pasajero);

    int getAsientosReservados();
    DTFecha getFecha();
    std::string getPasajero();
};

std::ostream& operator<<(std::ostream& os, DTDetalleReserva dtdr);

#endif
