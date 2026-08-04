#include "../include/ControladorAltaUsuario.h"
#include "../include/HandlerUsuario.h"
#include "../include/HandlerVehiculo.h"

ControladorAltaUsuario* ControladorAltaUsuario::instancia = nullptr;

ControladorAltaUsuario::ControladorAltaUsuario(){
}

ControladorAltaUsuario* ControladorAltaUsuario::getInstance(){
if (instancia == nullptr)
    instancia = new ControladorAltaUsuario();
return instancia;
}

void ControladorAltaUsuario::destroyInstance() {
    if (instancia != nullptr) {
        delete instancia;
        instancia = nullptr;
    }
    HandlerUsuario* h = HandlerUsuario::getInstance();
    h->destroyInstance();
}


bool ControladorAltaUsuario::altaPasajero(std::string nickname, std::string nombre , std::string contrasena, std::string email, std::string ci){
HandlerUsuario* h = HandlerUsuario::getInstance();
if (h->existeNickname(nickname)){
    return false;
}
Pasajero* p = new Pasajero(nickname, nombre, contrasena, email, ci);
h->agregarP(p);
return true;
}


bool ControladorAltaUsuario::altaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::vector<TipoLibreta> libretas){
HandlerUsuario* h = HandlerUsuario::getInstance();
if (h->existeNickname(nickname)){
    return false;
}
Conductor* c = new Conductor(nickname, nombre, contrasena, email, libretas);
h->agregarC(c);
return true;
}

int ControladorAltaUsuario::registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo){
HandlerVehiculo* hv = HandlerVehiculo::getInstance();
if (hv->existeMatricula(matricula)){                            //vehiculo ya registrado
    return -1;
}
HandlerUsuario* hu = HandlerUsuario::getInstance();
Conductor* c = hu->getConductor(nickname);
if (!c->verificarLibreta(tipo)){                                //conductor no tiene libreta adecuada
    return -2;
}
c->agregarVehiculo(matricula, capacidad, marca, modelo, tipo);
return 0;
}
