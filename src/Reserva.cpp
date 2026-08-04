#include "../include/Reserva.h"

//CONSTRUCTOR
Reserva::Reserva(int asientosReservados, DTFecha fecha, Pasajero* p) {
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
    this->p = p;
    this->vi = nullptr;
}

//GETTERS
int Reserva::getAsientos(){
    return this->asientosReservados;
}

DTFecha Reserva::getFecha(){
    return this->fecha;
}

//SETTERS
void Reserva::setAsientos(int a){
    this->asientosReservados = a;
}

void Reserva::setFecha(DTFecha f){
    this->fecha = f;
}

void Reserva::setViaje(Viaje* vi){
    this->vi = vi;
}

//METODOS OPERACIONES
bool Reserva::esViaje(int codigo){
    if (this->vi->getCodigo() == codigo){
        return true;
    } else {
        return false;
    }
}

void Reserva::agregarCalificacion( Calificacion* calif){
    c.push_back(calif);
}

DTUsuarioViaje Reserva::getDTUsuarioViaje(){
    DTUsuarioViaje dtuv = DTUsuarioViaje(this->p->getNickname(),pasajero);
    return dtuv;
}

DTListarViaje Reserva::viajeRegistrado(){
    DTListarViaje dtlv = DTListarViaje(this->vi->getCodigo(),this->vi->getFecha(),this->vi->getOrigen(),this->vi->getDestino(),this->vi->getNicknameConductor());
    return dtlv;
}

DTDetalleReserva Reserva::getDTDetalleReserva(){
    DTDetalleReserva dtdr = DTDetalleReserva(this->asientosReservados,this->fecha,this->p->getNickname());
    return dtdr;
}

void Reserva::eliminarReserva(){
    this->vi->desasociarReserva(this->p->getNickname());
    this->p->desasociarReserva(this->vi->getCodigo());
    this->p = nullptr;
    this->vi = nullptr;
}

void Reserva::eliminarCalificaciones(){ //No estoy seguro que este bien esta
    std::vector<Calificacion*>::iterator it;
    if (this->c.size() > 0){
    for (it = (this->c).begin(); it != (this->c).end(); it++){
        (*it)->desasociarUsuarios();
        delete (*it);
    }
}
    this->c.clear();
}


std::string Reserva::getNicknamePasajero(){
    return p->getNickname();
}

Reserva::~Reserva() {}
