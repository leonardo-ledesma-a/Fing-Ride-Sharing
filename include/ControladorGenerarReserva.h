#ifndef CONTROLADOR_GENERAR_RESERVA_H
#define CONTROLADOR_GENERAR_RESERVA_H

#include "IControladorGenerarReserva.h"
#include <string>
#include <vector>
#include "DTFecha.h"
#include "DTConsultaViaje.h"

class ControladorGenerarReserva : public IControladorGenerarReserva {
	
private: 

    static ControladorGenerarReserva* instancia;
    ControladorGenerarReserva();

public:
    ControladorGenerarReserva(const ControladorGenerarReserva& obj) = delete; 
    static ControladorGenerarReserva* getInstance();
    static void destroyInstance();
	std::vector<std::string> listarPasajeros();
	std::vector<DTConsultaViaje> consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos);
	bool generarReserva(std::string nickname, int codigo, int asientos);
};

#endif
