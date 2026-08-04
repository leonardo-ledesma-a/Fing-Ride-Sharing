#include "../include/DTReserva.h"

//CONSTRUCTOR
DTReserva::DTReserva(bool res,int aD){
    this->reservado = res;
    this->asientosDisponibles = aD;

}

//METODOS OPERACIONES
bool DTReserva::getInfoReservado(){
    return reservado;
}

int DTReserva::getAsientosDisponibles(){
    return asientosDisponibles;
}

//DESTRUCTOR
DTReserva::~DTReserva(){}