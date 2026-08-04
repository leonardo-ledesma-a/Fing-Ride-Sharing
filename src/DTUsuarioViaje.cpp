#include "../include/DTUsuarioViaje.h"

DTUsuarioViaje::DTUsuarioViaje(std::string nickname, TipoUsuario tipo)
    {
    this->nickname = nickname;
    this->tipo = tipo;
}

std::string DTUsuarioViaje::getNickname() { return nickname; }
TipoUsuario DTUsuarioViaje::getTipo() { return tipo; }

std::ostream& operator<<(std::ostream& os, DTUsuarioViaje dtuvi){
    os << "> Nickname: " << dtuvi.getNickname() << ", " << "Tipo: " << toString(dtuvi.getTipo());
    return os;
}
