#include "../include/Conductor.h"

Conductor::Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::vector<TipoLibreta> libs)
    : Usuario(nickname, nombre, contrasena, email) {
    this->Libretas = libs;
}

Conductor::~Conductor(){
 this->Vehiculos.clear();
}

void Conductor::agregarVehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo Tipo){
    if (verificarLibreta(Tipo)){
    Vehiculo* v = new Vehiculo(matricula, capacidad, marca, modelo, Tipo, this);
    this->Vehiculos.push_back(v); 
    HandlerVehiculo* hv = HandlerVehiculo::getInstance();
    hv->agregarV(v);
    }
}

bool Conductor::verificarLibreta(TipoVehiculo t) {
    if (t == TipoVehiculo::Moto) {
        return (std::find(this->Libretas.begin(), this->Libretas.end(), TipoLibreta::MotoAmateur) != this->Libretas.end()) ||
               (std::find(this->Libretas.begin(), this->Libretas.end(), TipoLibreta::MotoProfesional) != this->Libretas.end());
    } 
    else if (t == TipoVehiculo::Auto) {
        return (std::find(this->Libretas.begin(), this->Libretas.end(), TipoLibreta::AutoAmateur) != this->Libretas.end()) ||
               (std::find(this->Libretas.begin(), this->Libretas.end(), TipoLibreta::AutoProfesional) != this->Libretas.end());
    }
    return false;
}

std::vector<DTListarViaje> Conductor::listarViajes(){
    std::vector<DTListarViaje> DTL;
    std::vector<Vehiculo*>::iterator it;
    for (it = this->Vehiculos.begin(); it != this->Vehiculos.end();it++){
         std::vector<DTListarViaje> DTLve  = (*it)->listarViajes();
         DTL.reserve(DTL.size() + DTLve.size());
         DTL.insert(DTL.end(), DTLve.begin(), DTLve.end());
    }
    return DTL;
}

std::vector<DTVehiculosConductor> Conductor::listarVehiculos(){
     std::vector<DTVehiculosConductor> listaVehiculos;
     std::vector<Vehiculo*>::iterator it;
    for ( it = this->Vehiculos.begin(); it != this->Vehiculos.end(); it++){ 
         DTVehiculosConductor dtvc = (*it)->getDTVehiculosConductor();
         listaVehiculos.push_back(dtvc);
    }

    return listaVehiculos;
}


bool Conductor::hayViajesFechaConductor(DTFecha fecha) {
    for (std::vector<Vehiculo*>::iterator it = this->Vehiculos.begin(); it != this->Vehiculos.end(); ++it) {
        if ((*it)->hayViajes(fecha)) {
            return true;
        }
    }
    return false;
}

std::vector<TipoLibreta> Conductor::getLibretas(){
    return this->Libretas;  
}

Reserva* Conductor::getReserva(int codigo){
     return nullptr;
}

Reserva* Conductor::obtenerReservaCalificar(int codigo, Usuario* usuarioCalificado){
    return usuarioCalificado->getReserva(codigo);
}

