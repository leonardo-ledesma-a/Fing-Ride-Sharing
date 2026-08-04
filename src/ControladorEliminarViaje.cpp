#include "../include/ControladorEliminarViaje.h"

ControladorEliminarViaje* ControladorEliminarViaje::instancia = nullptr;

ControladorEliminarViaje::ControladorEliminarViaje(){}
  
ControladorEliminarViaje* ControladorEliminarViaje::getInstance(){
 if (instancia == nullptr){
  instancia = new ControladorEliminarViaje();
  }
  return instancia;
}
void ControladorEliminarViaje::destroyInstance(){
      if (instancia != nullptr) {
        delete instancia;
        instancia = nullptr;
    }
}

std::vector<DTListarViaje> ControladorEliminarViaje::listarViajes(){
  HandlerViaje* hv = HandlerViaje::getInstance();
  std::map<int, Viaje*> v = hv->getViajes();
  std::vector<DTListarViaje> dtvi;

  for (auto it = v.begin(); it != v.end(); it++) {
      dtvi.push_back(it->second->getDTListarViaje());
  }  
  return dtvi;
}

DTDetalleViaje ControladorEliminarViaje::detalleViaje(int codigo){
  this->codigo = codigo;
  HandlerViaje* hv = HandlerViaje::getInstance();
  Viaje* vi = (hv)->getViaje(codigo);
  return vi->getDTDetalleViaje();
}

void ControladorEliminarViaje::eliminarViaje(){
  HandlerViaje* hv = HandlerViaje::getInstance();
  Viaje* vi = hv->getViaje(this->codigo);
  vi->eliminarViaje();
  hv->eliminarViaje(this->codigo);
  delete instancia;
  instancia = nullptr;
};

void ControladorEliminarViaje::cancelarEliminarViaje(){
  delete instancia;
  instancia = nullptr;
}