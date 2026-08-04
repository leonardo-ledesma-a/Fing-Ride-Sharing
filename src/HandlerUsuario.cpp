#include "../include/HandlerUsuario.h"

HandlerUsuario* HandlerUsuario::instancia = nullptr;

HandlerUsuario::HandlerUsuario(){

}

HandlerUsuario* HandlerUsuario::getInstance(){
if (instancia == nullptr){
    instancia = new HandlerUsuario();
}
return instancia;
}

void HandlerUsuario::destroyInstance(){
    for (std::map<std::string,Usuario*>::iterator it = this->Usuarios.begin(); it != this->Usuarios.end();it++ ) {
    delete (it)->second; 
}
this->Usuarios.clear();
this->Pasajeros.clear();
this->Conductores.clear();
delete this->instancia;
this->instancia = nullptr;
}

Usuario* HandlerUsuario::getUsuario(std::string nickname){
std::map<std::string, Usuario*>::iterator it = this->Usuarios.find(nickname);       //it apunta al vector <clave, usuario> si lo encontro, y a Usuarios.end() si no

if (it != this->Usuarios.end()){                                                    
    return it->second;                                                              //it->second devuelve el segundo valor de vector, es decir Usuario*
}
return nullptr;
}

Pasajero* HandlerUsuario::getPasajero(std::string nickname){
std::map<std::string, Pasajero*>::iterator it = this->Pasajeros.find(nickname);       

if (it != this->Pasajeros.end()){                                                    
    return it->second;                                                              
}
return nullptr;
}

Conductor* HandlerUsuario::getConductor(std::string nickname){
std::map<std::string, Conductor*>::iterator it = this->Conductores.find(nickname);       

if (it != this->Conductores.end()){                                                    
    return it->second;                                                              
}
return nullptr;
}

void HandlerUsuario::agregarP(Pasajero* p){
std::string nickname = p->getNickname();
this->Usuarios.insert({nickname,p});
this->Pasajeros.insert({nickname,p});
}

void HandlerUsuario::agregarC(Conductor* c){
std::string nickname = c->getNickname();
this->Usuarios.insert({nickname,c});
this->Conductores.insert({nickname,c});
}

std::map<std::string, Usuario*> HandlerUsuario::getUsuarios(){
return this->Usuarios;    
}

std::map<std::string, Pasajero*> HandlerUsuario::getPasajeros(){
return this->Pasajeros;
}

std::map<std::string, Conductor*> HandlerUsuario::getConductores(){
return this->Conductores;
}

bool HandlerUsuario::existeNickname(std::string nickname){
return (this->Usuarios.find(nickname) != this->Usuarios.end());
}