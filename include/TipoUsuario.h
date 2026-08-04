#ifndef TIPO_USUARIO_H
#define TIPO_USUARIO_H
#include <string>

enum TipoUsuario {
    conductor,
    pasajero
};

inline std::string toString(TipoUsuario t){
    switch (t){
    case 0:
        return "Conductor";
    case 1:
        return "Pasajero";
    default:
        return "";
    }

}

#endif
