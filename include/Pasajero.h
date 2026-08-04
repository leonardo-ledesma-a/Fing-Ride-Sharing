#ifndef PASAJERO_H
#define PASAJERO_H

#include "Usuario.h"
#include "DTFecha.h"
#include <string>
#include <vector>

class Pasajero : public Usuario {
private:
    std::string ci;
    std::vector<Reserva *> reservas;
public:
    //Pasajero( Pasajero & p); puedo agregarlo o no, ya que puede sr útil a futuro.

    

    Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string documento);
    std::string getCi();
    std::vector<Reserva*> getReservas();

    //Caso de Uso: Generar Reserva
    // Controlador: ControladorGenerarReserva
    // Operacion: generarReserva()
    Reserva* crearReserva(DTFecha fechaActual , int asientos);

    //Caso de Uso: Calificar Usuario
    //Controlador: ControladorCalificarUsuario
    //Operacion: listarViajes()
    virtual std::vector<DTListarViaje> listarViajes();
   
    //Caso de Uso: Calificar Usuario 
    // Controlador: ControladorCalificarUsuario 
    // Operacion: calificarUsuario()
    Reserva* getReserva(int codigo);

    //La necesito para calificar obtener la reserva de calificar()
    virtual Reserva* obtenerReservaCalificar(int codigo, Usuario* usuarioCalificado);

    void desasociarReserva(int codigo);

    ~Pasajero();
};

#endif
