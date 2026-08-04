#ifndef CALIFICACION_H
#define CALIFICACION_H

#include "DTFecha.h"

class Reserva;


class Usuario;

class Calificacion {
private:
    DTFecha fecha;
    int puntaje;
    Usuario* calificador = nullptr;
    Usuario* calificado = nullptr;
    Reserva* reserva;

public:
    Calificacion(DTFecha fecha, int puntaje);
    ~Calificacion();
    DTFecha getFecha();
    int getPuntaje();
    Usuario* getCalificador();
    Usuario* getCalificado();
    Reserva* getReserva();
    void desasociarReserva();
    bool estaCalificadoEnViaje (std::string nickname, int codigo);
    void setCalificado (Usuario* uCalificado);
    void setCalificador(Usuario* uCalificador);
    void asociarR(Reserva* r);
    void desasociarUsuarios();
};

#include "Usuario.h"
#include "Reserva.h"

#endif
