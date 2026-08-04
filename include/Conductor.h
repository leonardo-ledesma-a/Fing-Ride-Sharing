#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include "Usuario.h"
#include "TipoLibreta.h"
#include "TipoVehiculo.h"
#include "DTVehiculosConductor.h"
#include "Vehiculo.h"
#include "HandlerVehiculo.h"
#include <algorithm>
#include <vector>

class Conductor : public Usuario {
private:
    std::vector<TipoLibreta> Libretas;
	std::vector<Vehiculo*> Vehiculos;

public:
	//Constructor y destructor
    Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::vector<TipoLibreta> libs);
    ~Conductor();
	
	//Getters
	std::vector<TipoLibreta> getLibretas();
	
	//Operaciones
	void agregarVehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo Tipo);
	bool verificarLibreta(TipoVehiculo t);
	std::vector<DTListarViaje> listarViajes();
	std::vector<DTVehiculosConductor> listarVehiculos();
	bool hayViajesFechaConductor(DTFecha fecha);
	Reserva* getReserva(int codigo);
	virtual Reserva* obtenerReservaCalificar(int codigo, Usuario* usuarioCalificado);
};

#endif
