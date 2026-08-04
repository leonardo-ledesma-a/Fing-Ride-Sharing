#include "../include/DTUsuario.h"

DTUsuario::DTUsuario(std::string nickname, std::string nombre)
    {
    this->nickname = nickname;
    this->nombre = nombre;
}

std::string DTUsuario::getNickname() { return nickname; }
std::string DTUsuario::getNombre() { return nombre; }


std::ostream& operator<<(std::ostream& os, DTUsuario dtu){
    os << "> Nickname: " << dtu.getNickname() << ", " << "Nombre: " << dtu.getNombre();
    return os;
}
