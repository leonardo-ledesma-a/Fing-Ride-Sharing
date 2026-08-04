#include "../include/Calificacion.h"

Calificacion::Calificacion(DTFecha fecha, int puntaje) {
    this->fecha = fecha;
    this->puntaje = puntaje;
}

Calificacion::~Calificacion() {}

DTFecha Calificacion::getFecha() {
return this->fecha;
}

int Calificacion::getPuntaje() {
return this->puntaje;
}

Usuario* Calificacion::getCalificador() {
return this->calificador;
}

Usuario* Calificacion::getCalificado() {
return this->calificado;
}

Reserva* Calificacion::getReserva() {
return this->reserva;
}

bool Calificacion::estaCalificadoEnViaje(std::string nickCalif, int codigo) {

if (nickCalif == this->calificado->getNickname())
    return this->reserva->esViaje(codigo);
else
    return false;
}

void Calificacion::setCalificado(Usuario* uCalificado){
this->calificado = uCalificado;
}

void Calificacion::setCalificador(Usuario* uCalificador){
    this->calificador = uCalificador;
}

void Calificacion::desasociarReserva(){
    this-> reserva = nullptr;
}



void Calificacion::asociarR(Reserva* r){

this->reserva = r;

}

void Calificacion::desasociarUsuarios(){

this->calificador->desasociarCalificacionRealizada(this);
this->calificado->desasociarCalificacionRecibida(this);

}