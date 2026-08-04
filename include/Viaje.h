#ifndef VIAJE_H
#define VIAJE_H

#include "DTFecha.h"
#include "Vehiculo.h"
#include "DTConsultaViaje.h"
#include "DTReserva.h"
#include "DTListarViaje.h"
#include "DTDetalleViaje.h"
#include "HandlerViaje.h"
#include <string>
#include <vector>

class Reserva;

class Viaje {
private:
    int codigo;
    static int codigoActual;
    DTFecha fecha;
    std::string origen;
    std::string destino;
    int asientosPublicados;
    float precio;
    Vehiculo* ve;
    std::vector<Reserva*> r;

public:
    //CONSTRUCTOR
    Viaje(DTFecha fecha, std::string origen, std::string destino, int asientosPublicados,Vehiculo* ve, float precio);
    Viaje();
    //GETTERS
    int getCodigo();
    DTFecha getFecha();
    std::string getOrigen();
    std::string getDestino();
    int getAsientosPublicados();
    float getPrecio();

    //SETTERS
    void setCodigo(int codigo);
    void setFecha(DTFecha  fecha);
    void setOrigen(std::string origen);
    void setDestino(std::string destino);
    void setAsientos(int asientosPublicados);
    void setPrecio(int precio);
    void setVehiculo(Vehiculo* ve);

    //OPERACIONES

    //Caso de uso: Calificar usuario
    //Operacion: listarUsuariosViajes
    //Controlador: ControladorCalificarUsuario
    Vehiculo* getVehiculoAsociado(); 
    
    //Caso de uso: Calificar usuario
    //Operacion: listarViajes
    //Controlador: ControladorCalificarUsuario   
    std::string getNicknameConductor();


    float getCalifConductor();

    //Caso de uso: Generar Reserva
    //Operacion: generarReserva()
    //Controlador: ControladorGenerarReserva
    DTReserva infoReservado(std::string nickname);

    //Caso de uso: Calificar Usuario
    //Operacion: listarUsuariosViaje()
    //Controlador: ControladorCalificarUsuario
    std::vector<Reserva*> getReservas();

    //Caso de uso: Generar Reserva
    //Operacion: generarReserva()
    //Controlador: ControladorGenerarReserva
    void anadirReserva(Reserva* r);

    //Caso de uso: Generar Reserva
    //Operacion: consultarViajes
    //Controlador: ControladorGenerarReserva
    DTConsultaViaje getDTCV(int asientos);

    //Es el getter pero con otro nombre, lo usaron los profesores en el caso de uso de Alta de Viaje
	int obtenerCodigo();

    //Caso de uso: Eliminar Viaje
    //Operacion: eliminarViaje()
    //Controlador: ControladorEliminarViaje
	void eliminarViaje();

    //No se donde esta esta operacion
    //void desasociarReserva(std::string nick);

    //Caso de uso: Eliminar viaje
    //Operacion: listarViajes()
    //Controlador: ControladorEliminarViaje
    DTListarViaje getDTListarViaje();

    //Caso de uso: Eliminar Viaje
    //Operacion: detalleViaje()
    //Controlador: ControladorEliminarViaje
    DTDetalleViaje getDTDetalleViaje();

    //mia
    void desasociarReserva(std::string nickname);

    //Caso de uso: Generar Reserva
    //Operacion: consultarViajes()
    //Controlador: ControladorGenerarReserva
    int getAsientosDisponibles();
    
    //DESTRUCTOR
    ~Viaje();
};

#include "Reserva.h"

#endif
