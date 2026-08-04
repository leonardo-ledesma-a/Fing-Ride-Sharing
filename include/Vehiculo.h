#ifndef VEHICULO_H
#define VEHICULO_H

#include "TipoVehiculo.h"
#include "DTListarViaje.h"
#include "DTUsuarioViaje.h"
#include "DTVehiculosConductor.h"
#include <map>
#include <vector>
#include <string>
#include "DTDetalleVehiculo.h"

class Viaje;
class Conductor;

class Vehiculo {
private:
    std::string matricula;
    int capacidad;
    std::string marca;
    std::string modelo;
    TipoVehiculo tipo;
    Conductor* c;
    std::map <int, Viaje*> Viajes;


public:
    Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo, Conductor * condu);
    ~Vehiculo();
    std::string getMatricula();
    int getCapacidad();
    std::string getMarca();
    std::string getModelo();
    TipoVehiculo getTipo();
    Conductor* getConductor();


    //Caso de Uso: Calificar Usuario 
    // Controlador: ControladorCalificarUsuario 
    // Operacion: listarViajes()
    std::vector<DTListarViaje> listarViajes();

    //Caso de Uso: Calificar Usuario
    // Controlador: ControladorCalificarUsuario
    // Operacion: listarUsuariosViaje()
    DTUsuarioViaje getDTConductorViaje();

    //Caso de Uso: Calificar Usuario y Generar Reserva
    // Controlador: ControladorCalificarUsuario y ControladorGenerarReserva
    // Operacion: listarViajes() y consultarViajes()
    std::string getNicknameConductor();
    
    //Caso de Uso: Generar Reserva
    // Controlador: ControladorGenerarReserva
    // Operacion: consultarViajes()
    float getCalifConductor();

    //Caso de Uso: Alta de Viaje
    // Controlador: ControladorAltaViaje 
    // Operacion: listarVehiculos()
    DTVehiculosConductor getDTVehiculosConductor();

    DTDetalleVehiculo getDTDetalleVehiculo();

    //Caso de Uso: Alta de Viaje
    // Controlador: ControladorAltaViaje 
    // Operacion: altaViaje()
    bool hayViajeConductor(DTFecha f);

    //Caso de Uso: Alta de Viaje
    // Controlador: ControladorAltaViaje 
    // Operacion: altaViaje()
    void asociarViaje(Viaje* v);

    //Caso de Uso: Eliminar Viaje
    // Controlador: ControladorEliminarViaje
    // Operacion: eliminarViaje()
	void desasociarViaje(Viaje* v);
    

    //Caso de usi: Alta de Viaje
    //Controlador: ControladorAltaViaje
    // Operación: altaViaje()
    bool hayViajes(DTFecha fecha); 
};

#include "Viaje.h"
#include "Conductor.h"

#endif
