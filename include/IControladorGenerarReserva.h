#ifndef ICONTROLADOR_GENERAR_RESERVA_H
#define ICONTROLADOR_GENERAR_RESERVA_H

#include <string>
#include <vector>
#include "DTFecha.h"
#include "DTConsultaViaje.h"

class IControladorGenerarReserva{
	public:
		virtual ~IControladorGenerarReserva(){};
		virtual std::vector<std::string> listarPasajeros() = 0;
		virtual std::vector<DTConsultaViaje> consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos) = 0;
		virtual bool generarReserva(std::string nickname, int codigo, int asientos) = 0;
};


#endif
