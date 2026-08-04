#include "../include/Vehiculo.h"

Vehiculo::Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo, Conductor * condu) {
    this->matricula = matricula;
    this->capacidad = capacidad;
    this->marca = marca;
    this->modelo = modelo;
    this->tipo = tipo;
    this->c = condu;
}

Vehiculo::~Vehiculo(){}

std::string Vehiculo::getMatricula(){
    return this->matricula;
}

int Vehiculo::getCapacidad(){
    return this->capacidad;
}

std::string Vehiculo::getMarca(){
    return this->marca;
}

std::string Vehiculo::getModelo(){
    return this->modelo;
}

TipoVehiculo  Vehiculo::getTipo(){
    return this->tipo;
}

Conductor* Vehiculo::getConductor(){
    return this->c;
}

std::vector<DTListarViaje> Vehiculo::listarViajes(){

std::string c = this->c->getNickname();
std::vector<DTListarViaje> dtvis;


 std::map<int, Viaje*>::iterator it;
 for(it= this->Viajes.begin(); it != this->Viajes.end(); it++){
    int codigo = it->second->getCodigo();
    DTFecha fecha =  it->second->getFecha();
    std::string origen = it->second->getOrigen();
    std::string destino = it->second->getDestino();
    
   DTListarViaje dtvi = DTListarViaje(codigo, fecha, origen, destino, c);
   dtvis.push_back(dtvi);
    }

 return dtvis;
} 

DTUsuarioViaje Vehiculo::getDTConductorViaje(){
    DTUsuarioViaje dtuv = DTUsuarioViaje(this->c->getNickname(), conductor);
    return dtuv;
}

 std::string Vehiculo::getNicknameConductor(){
    return this->c->getNickname();
 }

float Vehiculo::getCalifConductor(){
    return this->c->getCalificacionPromedio();
}

DTVehiculosConductor Vehiculo::getDTVehiculosConductor(){
    DTVehiculosConductor dtvc = DTVehiculosConductor(this->matricula, this->marca, this->capacidad);
    return dtvc;
}

bool Vehiculo::hayViajeConductor(DTFecha f){

    return this->c->hayViajesFechaConductor(f);
}

DTDetalleVehiculo Vehiculo::getDTDetalleVehiculo(){
    return DTDetalleVehiculo(this->matricula, this->capacidad, this->marca, this->modelo, this->tipo);
}


void Vehiculo::asociarViaje(Viaje* v){ 
   int cod = v->getCodigo();
   this->Viajes.insert({cod,v});
}


void Vehiculo::desasociarViaje(Viaje* v){
   int cod = v->getCodigo();
   this->Viajes.erase(cod);
}

bool Vehiculo::hayViajes(DTFecha fecha){
    for (std::map<int,Viaje*>::iterator it = this->Viajes.begin(); it != this->Viajes.end(); ++it){
        if (it->second->getFecha() == fecha){
            return true;
        }
    }
    return false;
}