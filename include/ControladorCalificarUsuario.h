#ifndef CONTROLADOR_CALIFICAR_USUARIO_H
#define CONTROLADOR_CALIFICAR_USUARIO_H

#include "IControladorCalificarUsuario.h"
#include "Reserva.h"
#include "Usuario.h"
#include "DTUsuario.h"
#include "DTListarViaje.h"
#include "DTUsuarioViaje.h"
#include "HandlerUsuario.h"
#include "HandlerViaje.h"
#include <vector>
#include <string>

class ControladorCalificarUsuario : public IControladorCalificarUsuario {
private:

    static ControladorCalificarUsuario* instancia;
    ControladorCalificarUsuario();

    std::string nickname;
    int codigo;

public:
    ControladorCalificarUsuario(const ControladorCalificarUsuario& obj) = delete; 
    static ControladorCalificarUsuario* getInstance();
    static void destroyInstance(); 
    std::vector<DTUsuario> listarUsuarios();
    std::vector<DTListarViaje> listarViajes(std::string nickname);
    std::vector<DTUsuarioViaje> listarUSuariosViaje(int codigo);
    bool calificarUsuario(std::string nicknameCalificado, int calificacion);
};


#endif