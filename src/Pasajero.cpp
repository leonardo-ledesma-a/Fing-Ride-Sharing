#include "../include/Pasajero.h"


Pasajero::Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string documento)
    : Usuario(nickname, nombre, contrasena, email) {
    this->ci = documento;
}

Reserva* Pasajero::crearReserva(DTFecha fechaActual , int asientos){
    Pasajero* p = this;
    Reserva* r = new Reserva(asientos, fechaActual,p);
    this->reservas.push_back(r);
    return (r);
}

std::vector<DTListarViaje> Pasajero::listarViajes(){
    std::vector<Reserva*>::iterator it;
    std::vector<DTListarViaje> DTL;
    for ( it = this->reservas.begin(); it != this->reservas.end(); it++){
        DTListarViaje dtvi = (*it)->viajeRegistrado();
        DTL.push_back(dtvi);
    }

    return DTL;
}

Reserva* Pasajero::getReserva(int codigo){
    std::vector<Reserva*>::iterator it;
    for ( it = this->reservas.begin(); it != this->reservas.end() && !(*it)->esViaje(codigo); it++);
    return (*it);
}

void Pasajero::desasociarReserva(int codigo){
    std::vector<Reserva*>::iterator it;
   for ( it = this->reservas.begin(); it != this->reservas.end() && !(*it)->esViaje(codigo); it++);
   if ((it) != this->reservas.end())
   this->reservas.erase(it);
}

Reserva* Pasajero::obtenerReservaCalificar(int codigo,Usuario* usuarioCalificado){
    return getReserva(codigo);
}

Pasajero::~Pasajero() {
    std::vector<Reserva*>::iterator it;
    for(it = this->reservas.begin();it != this->reservas.end(); ++it)
      delete (*it);
    this->reservas.clear();
}
