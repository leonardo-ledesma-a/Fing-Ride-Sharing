#ifndef DT_USUARIO_H
#define DT_USUARIO_H

#include <iostream>
#include <string>

class DTUsuario {
private:
    std::string nickname;
    std::string nombre;

public:
    DTUsuario(std::string nickname, std::string nombre);

    std::string getNickname();
    std::string getNombre();
    
};

//Sobrecarga operador de flujo
std::ostream& operator<<(std::ostream& os, DTUsuario dtu); 

#endif
