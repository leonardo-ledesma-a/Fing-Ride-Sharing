#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "DTListarViaje.h"
#include <ControladorFechaActual.h>
#include <algorithm>

class Reserva;

class Calificacion;

class Usuario {
protected:
    std::string nickname;
    std::string nombre;
    std::string contrasena;
    std::string email;
	float calificacionPromedio;
	std::vector<Calificacion*> calificacionesRecibidas;
	std::vector<Calificacion*> calificacionesRealizadas;

public:
	//Contructor y destructor
    Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email);
    virtual ~Usuario();
	
	//Getters
	std::string getNickname();
	std::string getNombre();
    std::string getContrasena();
    std::string getEmail();	
	float getCalificacionPromedio();
	//void setCalificacionPromedio();

	//Caso de Uso: Calificar Usuario
	//Controlador: ControladorCalificarUsuario
	//Operación: listarViajes(). Esta es una operación abstracta, implementada por Conductor y Pasajero 
	virtual std::vector<DTListarViaje> listarViajes()=0;

	//Caso de Uso: Calificar Usuario
	//Controlador: ControladorCalificarUsuario
	//Operación: calificarUsuario
	bool existeCalificacion(std::string nicknameCalificado, int codigo);

	//Caso de Uso: Calificar Usuario
	//Controlador: ControladorCalificarUsuario
	//Operación: calificarUsuario	
	void calificar(int calif, Usuario* usuarioCalificado, int cod);

	//Caso de Uso: Calificar Usuario
	//Controlador: ControladorCalificarUsuario
	//Operación: calificarUsuario	
	void recibirCalificacion(Calificacion* c);

	//Caso de Uso: Eliminar Viaje
	//Controlador: ControladorEliminarViaje
	//Operación: eliminarViaje()		
	void desasociarCalificacionRecibida(Calificacion* c);

	//Caso de Uso: Eliminar Viaje
	//Controlador: ControladorEliminarViaje
	//Operación: eliminarViaje()	
	void desasociarCalificacionRealizada(Calificacion* c);

	//La necesito para calificar obtener la reserva de calificar()
	virtual Reserva* obtenerReservaCalificar(int codigo, Usuario* usuarioCalificado)=0;

	
	//La necesito para calificar obtener la reserva de calificar()
	virtual Reserva* getReserva(int codigo){return nullptr;}


};

#include "Calificacion.h"
#include "Reserva.h"
#endif
