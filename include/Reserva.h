#ifndef RESERVA_H
#define RESERVA_H

#include "DTFecha.h"
#include "DTListarViaje.h"
#include "Viaje.h"
#include "DTUsuarioViaje.h"
#include "DTDetalleReserva.h"

class Calificacion;

class Pasajero;

class Reserva {
private:
    int asientosReservados;
    DTFecha fecha;
    Viaje* vi;
    Pasajero* p;
    std::vector<Calificacion*> c;


public:
    //CONSTRUCTOR
    Reserva(int asientosReservados, DTFecha fecha, Pasajero* p);

    //GETTERS
    int getAsientos();
    DTFecha getFecha();

    //SETTERS
    void setAsientos(int asientosReservados);
    void setFecha(DTFecha fecha);
    void setViaje(Viaje* vi);
    //DESTRUCTOR
    ~Reserva();

    //OPERACIONES

    //Caso de uso: Calificar Usuario
    //Operacion: listarViajes()
    //Controlador: ControladorCalificarUsuario
    DTListarViaje viajeRegistrado();



    void agregarCalificacion( Calificacion* calif);

    //Caso de uso: Calificar Usuario
    //Operacion: listarUsuariosViaje()
    //Controlador: ControladorCalificarUsuario
    DTUsuarioViaje getDTUsuarioViaje();

    //Caso de uso: Eliminar Viaje
    //Operacion: eliminarViaje()
    //Controlador: ControladorEliminarViaje
    DTDetalleReserva getDTDetalleReserva();

    //Caso de uso: Calificar Usuario
    //Operacion: calificarUsuario()
    //Controlador: ControladorCalificarUsuario
    //Pre: Existe el viaje con vi.codigo = codigo asociado a la reserva
    bool esViaje(int codigo);

    //Caso de uso: Eliminar Viaje
    //Operacion: eliminarViaje()
    //Controlador: ControladorEliminarViaje
	void eliminarReserva();
    
    //Caso de uso: Eliminar Viaje
    //Operacion: eliminarViaje()
    //Controlador: ControladorEliminarViaje
    void eliminarCalificaciones();

    
    /*La necesito para la operacion de infoReservado de Viaje, 
    devuelve el nick del pasajero que hizo la reserva*/
    std::string getNicknamePasajero();
};

#include "Pasajero.h"
#include "Calificacion.h"

#endif

