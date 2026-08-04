#ifndef ICONTROLADOR_CALIFICAR_USUARIO_H
#define ICONTROLADOR_CALIFICAR_USUARIO_H

#include "DTUsuario.h"
#include "DTListarViaje.h"
#include "DTUsuarioViaje.h"
#include <vector>


class IControladorCalificarUsuario{
public:
    virtual ~IControladorCalificarUsuario(){};
    virtual std::vector<DTUsuario> listarUsuarios() = 0;
    virtual std::vector<DTListarViaje> listarViajes(std::string nickname) = 0;
    virtual std::vector<DTUsuarioViaje> listarUSuariosViaje(int codigo) = 0;
    virtual bool calificarUsuario(std::string nicknameCalificado, int calificacion) = 0;
};


#endif