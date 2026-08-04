#ifndef HANDLER_USUARIO_H
#define HANDLER_USUARIO_H

#include "Usuario.h"
#include "Pasajero.h"
#include "Conductor.h"
#include <string>
#include <map>



class HandlerUsuario {
private:
    static HandlerUsuario* instancia;
    HandlerUsuario();

    std::map<std::string, Usuario*> Usuarios;
    std::map<std::string, Pasajero*> Pasajeros;
    std::map<std::string, Conductor*> Conductores;

public:
    static HandlerUsuario* getInstance();
    HandlerUsuario(const HandlerUsuario& obj) = delete; 
    void destroyInstance();
    Usuario* getUsuario(std::string nickname);
    Pasajero* getPasajero(std::string nickname);
    Conductor* getConductor(std::string nickname);
    void agregarP(Pasajero* p);
    void agregarC(Conductor* c);
    std::map<std::string, Usuario*> getUsuarios();
    std::map<std::string, Pasajero*> getPasajeros();
    std::map<std::string, Conductor*> getConductores();
    bool existeNickname(std::string nickname);
};



#endif