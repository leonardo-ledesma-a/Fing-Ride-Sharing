#include "../include/ControladorCalificarUsuario.h"

ControladorCalificarUsuario* ControladorCalificarUsuario::instancia = nullptr;

ControladorCalificarUsuario* ControladorCalificarUsuario::getInstance(){
    if (instancia == nullptr){
        instancia = new ControladorCalificarUsuario;
    }
    return instancia;
}

ControladorCalificarUsuario::ControladorCalificarUsuario(){
}



std::vector<DTUsuario> ControladorCalificarUsuario::listarUsuarios(){
    HandlerUsuario* h = HandlerUsuario::getInstance();
    std::map<std::string,Usuario*> lu = h->getUsuarios();
    std::map<std::string,Usuario*>::iterator it;
    std::vector<DTUsuario> vectorUsuarios;
    for(it = lu.begin(); it != lu.end(); it++){
        DTUsuario dtu = DTUsuario((*it).second->getNickname(),(*it).second->getNombre());
        vectorUsuarios.push_back(dtu);
    }
    return vectorUsuarios;
}

    void ControladorCalificarUsuario::destroyInstance(){
        if (instancia != nullptr) {
        delete instancia;
        instancia = nullptr;
    }
    } 

std::vector<DTListarViaje> ControladorCalificarUsuario::listarViajes(std::string nickname){
    this->nickname = nickname;
    HandlerUsuario* h = HandlerUsuario::getInstance();
    Usuario* u = h->getUsuario(nickname);
    Pasajero* p = dynamic_cast<Pasajero*>(u);
    Conductor* c = dynamic_cast<Conductor*>(u);
    std::vector<DTListarViaje> dtl;
    if (p != nullptr){
        dtl = p->listarViajes();
    } else {
        dtl = c->listarViajes();
    }
    return dtl;
}

std::vector<DTUsuarioViaje> ControladorCalificarUsuario::listarUSuariosViaje(int codigo){
    this->codigo = codigo;
    std::vector<DTUsuarioViaje> dtluv;
    HandlerViaje* h = HandlerViaje::getInstance();
    Viaje* vi = h->getViaje(codigo);
    std::vector<Reserva*> re = vi->getReservas();
    std::vector<Reserva*>::iterator it;
    for( it = re.begin(); it != re.end(); it++){
        if ((*it)->getNicknamePasajero() != nickname){
            dtluv.push_back((*it)->getDTUsuarioViaje());  
        } 
    }
    Vehiculo* ve = vi->getVehiculoAsociado();
    if (ve->getNicknameConductor() != nickname){
        dtluv.push_back(ve->getDTConductorViaje());
    }
    return dtluv;
}

bool ControladorCalificarUsuario::calificarUsuario(std::string nicknameCalificado, int calificacion){
    HandlerUsuario* h = HandlerUsuario::getInstance();
    Usuario* u = h->getUsuario(nickname);
    bool existe = u->existeCalificacion(nicknameCalificado,codigo);
    if (existe){
        return false;
    } else {
        Usuario* uc = h->getUsuario(nicknameCalificado);
        u->calificar(calificacion,uc,codigo);
        return true;
    }
}