#include "../include/Viaje.h"

//CONSTRUCTOR
Viaje::Viaje(DTFecha fecha, std::string origen, std::string destino, int asientosPublicados,Vehiculo* ve, float precio):codigo(++codigoActual) {
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->ve = ve;
    this->precio = precio;
}

int Viaje::codigoActual = 0;

Viaje::Viaje():codigo(++codigoActual){}

//GETTERS
int Viaje::getCodigo(){
    return this->codigo;
}

DTFecha Viaje::getFecha(){
    return this->fecha;
}

std::string Viaje::getOrigen(){
    return this->origen;
}

std::string Viaje::getDestino(){
    return this->destino;
}

int Viaje::getAsientosPublicados(){
    return this->asientosPublicados;
}

float Viaje::getPrecio(){
    return this->precio;
}

//SETTERS
void Viaje::setCodigo(int codigo){
    this->codigo = codigo;
}

void Viaje::setFecha(DTFecha  fecha){
    this->fecha = fecha;
}

void Viaje::setOrigen(std::string origen){
    this->origen = origen;
}

void Viaje::setDestino(std::string destino){
    this->destino = destino;
}

void Viaje::setAsientos(int asientosPublicados){
    this->asientosPublicados = asientosPublicados;
}

void Viaje::setPrecio(int precio){
    this->precio = precio;
}

void Viaje::setVehiculo(Vehiculo* ve){
    this->ve = ve;
}

//METODOS OPERACIONES
Vehiculo* Viaje::getVehiculoAsociado(){
    return this->ve;
}

std::vector<Reserva*> Viaje::getReservas(){
  return this->r;
}

std::string Viaje::getNicknameConductor(){
    return (this->ve->getNicknameConductor());
}

DTListarViaje Viaje::getDTListarViaje(){
    std::string nick = getNicknameConductor();
    DTListarViaje dtlv = DTListarViaje(this->codigo,this->fecha,this->origen,this->destino,nick);
    return dtlv;
}

float Viaje::getCalifConductor(){  
    return ve->getCalifConductor();  
}

int Viaje::getAsientosDisponibles(){
    std::vector<Reserva*>::iterator it;
    int asientos = this->asientosPublicados;
    for (it = (this->r).begin(); it != (this->r).end(); it++){
        asientos = asientos - (*it)->getAsientos();
    }
    return asientos;
}

DTConsultaViaje Viaje::getDTCV(int asientos){
    int precio = asientos*getPrecio();
    DTConsultaViaje dtcv = DTConsultaViaje(this->codigo,ve->getMarca(),ve->getModelo(),ve->getNicknameConductor(),ve->getCalifConductor(),precio);
    return dtcv;
}

int Viaje::obtenerCodigo(){
    return getCodigo();
}

DTReserva Viaje::infoReservado(std::string nickname){
    std::vector<Reserva*>::iterator it;
    bool noReservado = true;
    int asientos = getAsientosPublicados();
    for (it = (this->r).begin(); noReservado && it != (this->r).end(); it++){
        noReservado =  (nickname != (*it)->getNicknamePasajero());
        asientos -= (*it)->getAsientos();
    }
    DTReserva dtr = DTReserva(noReservado,asientos);
    return dtr;
}

void Viaje::anadirReserva(Reserva* r){
    this->r.push_back(r);
    r->setViaje(this);
}
/*
int Viaje::getAsientosDisponibles(){
    return 0;
}
*/
DTDetalleViaje Viaje::getDTDetalleViaje(){
    std::vector<DTDetalleReserva> dtre;
    std::vector<Reserva*>::iterator it;
    for (it = r.begin(); it != r.end(); it++){
        dtre.push_back((*it)->getDTDetalleReserva());
    }
    DTDetalleVehiculo dtve = DTDetalleVehiculo(ve->getMatricula(),ve->getCapacidad(),ve->getMarca(),ve->getModelo(),ve->getTipo());
    DTDetalleViaje dtvi = DTDetalleViaje(codigo,fecha,origen,destino,asientosPublicados,precio,dtve,dtre);
    return dtvi;
}

void Viaje::eliminarViaje(){
    std::vector<Reserva*> copia = r;
    std::vector<Reserva*>::iterator it;
    for (it = copia.begin(); it != copia.end(); it++) {
        if ((*it)!= nullptr) {
            (*it)->eliminarCalificaciones();
            (*it)->eliminarReserva(); 
            delete (*it);
        }
    }

    this->r.clear();
    
    if (ve != nullptr) {
        ve->desasociarViaje(this);
    }
}


void Viaje::desasociarReserva(std::string nickname){
    std::vector<Reserva*>::iterator it;
    it = r.begin();
    while(it != r.end() && (*it)->getNicknamePasajero() != nickname  ){
        it++;
    }
    r.erase(it);
}

Viaje::~Viaje() {}
