#ifndef DT_RESERVA_H
#define DT_RESERVA_H

class DTReserva{
  private: 
    bool reservado;
    int asientosDisponibles; 
  public:
  //CONSTRUCTOR
  DTReserva( bool res, int aD);
  
  //GETTERS
  bool getInfoReservado();
  
  int getAsientosDisponibles();

  //DESTRUCTOR
  ~DTReserva();
};

#endif