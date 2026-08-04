#include "../include/Usuario.h"

Usuario::Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email) {
    this->nickname = nickname;
    this->nombre = nombre;
    this->contrasena = contrasena;
    this->email = email;
    this->calificacionPromedio = 0;
}

Usuario::~Usuario() {
    std::vector<Calificacion*>::iterator it;
    for(it = this->calificacionesRealizadas.begin();it != this->calificacionesRealizadas.end();++it){
        if ((*it) != nullptr)
        delete (*it);
    }

    this->calificacionesRealizadas.clear();
    this->calificacionesRecibidas.clear();
}

std::string Usuario::getNickname(){
    return this->nickname;
}
std::string Usuario::getNombre(){
    return this->nombre;
}
std::string Usuario::getContrasena(){
    return this->contrasena;
}
std::string Usuario::getEmail(){
    return this->email;
}

float Usuario::getCalificacionPromedio(){
    return this->calificacionPromedio;
}


void Usuario::calificar(int calif, Usuario* usuarioCalificado, int cod){
    ControladorFechaActual* cf = ControladorFechaActual::getInstance();
    DTFecha fechaActual = cf->getFecha();

    Calificacion* nc = new Calificacion(fechaActual,calif);
    usuarioCalificado->recibirCalificacion(nc);
    nc->setCalificado(usuarioCalificado);
    nc->setCalificador(this);
    Reserva* r = this->obtenerReservaCalificar(cod,usuarioCalificado); 
    nc->asociarR(r);
    r->agregarCalificacion(nc);

    this->calificacionesRealizadas.push_back(nc);

    this->calificacionesRecibidas.push_back(nc);
}


void Usuario::recibirCalificacion(Calificacion* c){
    int califNueva = c->getPuntaje();
    int total = this->calificacionesRecibidas.size();
    this->calificacionPromedio = (this->calificacionPromedio*total + califNueva)/(total + 1);
    this->calificacionesRecibidas.push_back(c);
}


void Usuario::desasociarCalificacionRecibida(Calificacion* c){
    int califElim = c->getPuntaje();
    int total = this->calificacionesRecibidas.size();
    int nuevaCalifPromedio = this->calificacionPromedio*(total) - califElim;
    if (total > 1)
    this->calificacionPromedio = nuevaCalifPromedio/(total - 1);
    else this->calificacionPromedio = 0;

    auto itCalif = std::find(this->calificacionesRecibidas.begin(),this->calificacionesRecibidas.end(),c);
    if (itCalif != this->calificacionesRecibidas.end() ){
        this->calificacionesRecibidas.erase(itCalif);
    }
}

void Usuario::desasociarCalificacionRealizada(Calificacion* c){

    auto itCalif = std::find(this->calificacionesRealizadas.begin(),this->calificacionesRealizadas.end(),c);
    if (itCalif != this->calificacionesRealizadas.end()){
        this->calificacionesRealizadas.erase(itCalif);
    }
}


bool Usuario::existeCalificacion(std::string nicknameCalificado, int codigo){
    std::vector<Calificacion*>::iterator it;
    bool existe = false;
    for (it = this->calificacionesRealizadas.begin(); it != this->calificacionesRealizadas.end() && !existe; it++ ){
        existe = (*it)->estaCalificadoEnViaje(nicknameCalificado, codigo);
    }
  return existe;
}

