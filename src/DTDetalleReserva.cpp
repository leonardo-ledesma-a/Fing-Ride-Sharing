#include "../include/DTDetalleReserva.h"

DTDetalleReserva::DTDetalleReserva(int asientosReservados, DTFecha fecha, std::string pasajero) {
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
    this->pasajero = pasajero;
}

int DTDetalleReserva::getAsientosReservados() { return asientosReservados; }
DTFecha DTDetalleReserva::getFecha() { return fecha; }
std::string DTDetalleReserva::getPasajero() { return pasajero; }
std::ostream& operator<<(std::ostream& os,DTDetalleReserva dtdr){
    os << "--- AsientosReservados: " << dtdr.getAsientosReservados() << ", Fecha: " <<  dtdr.getFecha() 
    << ", Pasajero: " << dtdr.getPasajero() << "\n";
    return os;
}
