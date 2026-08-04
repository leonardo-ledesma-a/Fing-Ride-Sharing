#ifndef DT_USUARIO_VIAJE_H
#define DT_USUARIO_VIAJE_H

#include "TipoUsuario.h"
#include <string>
#include <iostream>

class DTUsuarioViaje {
private:
    std::string nickname;
    TipoUsuario tipo;

public:
    DTUsuarioViaje(std::string nickname, TipoUsuario tipo);

    std::string getNickname();
    TipoUsuario getTipo();
};

std::ostream& operator<<(std::ostream& os, DTUsuarioViaje dtuvi);

#endif
