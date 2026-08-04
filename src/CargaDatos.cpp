#include "../include/CargaDatos.h"
#include "../include/Fabrica.h"
#include <iostream>

CargaDatos* CargaDatos::instancia = nullptr;

CargaDatos::CargaDatos() {
    datosCargados = false;
}

CargaDatos::~CargaDatos(){}

CargaDatos* CargaDatos::getInstance() {
    if (instancia == nullptr) {
        instancia = new CargaDatos();
    }
    return instancia;
}

void CargaDatos::cargarDatos() {
    if (datosCargados) {
        std::cout << "Error: Los datos ya han sido cargados anteriormente.\n";
        return;
    }
    Fabrica* fabrica = Fabrica::getInstance();

    IControladorAltaUsuario* controladorUsuario =
        fabrica->getIControladorAltaUsuario();

    IControladorAltaViaje* controladorViaje =
        fabrica->getIControladorAltaViaje();

    IControladorGenerarReserva* controladorReserva =
        fabrica->getIControladorGenerarReserva();

    IControladorFechaActual* controladorFecha =
        fabrica->getIControladorFechaActual();

    IControladorCalificarUsuario* controladorCalificacion =
        fabrica->getIControladorCalificarUsuario();

        

    std::cout << "Cargando datos harcodeados del sistema...\n";
 


    // PASAJEROS

    controladorUsuario->altaPasajero("santi_90","Santiago Acosta","Santi123","santiago.acosta@gmail.com","1.492.304-2");
    controladorUsuario->altaPasajero("mari_b","Maria Noel Barreto","Mari123","mari.barreto@outlook.com","4.103.859-1");
    controladorUsuario->altaPasajero("nacho_f","Ignacio Figueroa","Nacho123","ignacio.figueroa@fing.edu.uy","3.847.112-5");
    controladorUsuario->altaPasajero("valen_uy","Valentina Mendez","Valen123","valen.mendez@fing.edu.uy","2.956.403-0");
    controladorUsuario->altaPasajero("joaco_r","Joaquin Rivero","Joaco123","joaquin_rivero@hotmail.com","5.021.784-3");

  
    // CONDUCTORES
  
    std::vector<TipoLibreta> libretas = {AutoAmateur};

    controladorUsuario->altaConductor("matil92","Matias Lopez","m4t14s92","matias.lopez.92@gmail.com",libretas);
    libretas = {AutoProfesional};
    controladorUsuario->altaConductor("ana_silva","Ana Silva","asilva2026","anasilva.m@outlook.com",libretas);
    libretas = {MotoAmateur};
    controladorUsuario->altaConductor("greg_m","Diego Rodriguez","drodriguez88","diegorodriguez@fing.edu.uy",libretas);
    libretas = {MotoProfesional};
    controladorUsuario->altaConductor("lau_vaz","Laura Vazquez","lvazquezQ7","laura.vazquez@fing.edu.uy",libretas);
    libretas = {AutoProfesional,MotoAmateur};
    controladorUsuario->altaConductor("carlos_r","Carlos Rossi","crossi99x","carlos.rossi.uy@gmail.com",libretas);

    // VEHICULOS

    controladorUsuario->registrarVehiculo("matil92","ABJ4586",4,"Chevrolet","Onix",Auto);
    controladorUsuario->registrarVehiculo("matil92","ACM4455",6,"Toyota","Rush",Auto);
    controladorUsuario->registrarVehiculo("ana_silva","BAS7895",4,"Fiat","Argo",Auto);
    controladorUsuario->registrarVehiculo("ana_silva","BCS4105",9,"Hyundai","H1",Auto);
    controladorUsuario->registrarVehiculo("greg_m","LDA4875",1,"Honda","CB Twist",Moto);
    controladorUsuario->registrarVehiculo("lau_vaz","PDB1205",1,"Yumbo","Max 110",Moto);
    controladorUsuario->registrarVehiculo("carlos_r","SBJ4874",4,"Volkswagen","Gol",Auto);
    controladorUsuario->registrarVehiculo("carlos_r","SCF2469",1,"Yamaha","FZ S",Moto);
    
    // VIAJES

    controladorViaje->altaViaje("ABJ4586",DTFecha(21,10,2026),"montevideo","mercedes",4,200);
    controladorViaje->altaViaje("ACM4455",DTFecha(20,10,2026),"young","montevideo",5,250);
    controladorViaje->altaViaje("BAS7895",DTFecha(20,10,2026),"young","montevideo",4,200);
    controladorViaje->altaViaje("BCS4105",DTFecha(21,10,2026),"montevideo","mercedes",9,200);
    controladorViaje->altaViaje("LDA4875",DTFecha(21,10,2026),"montevideo","mercedes",1,300);
    controladorViaje->altaViaje("PDB1205",DTFecha(21, 10, 2026),"montevideo","mercedes",1,350);
    controladorViaje->altaViaje("SBJ4874",DTFecha(21, 10, 2026),"montevideo","mercedes",4,260);
    controladorViaje->altaViaje("SCF2469",DTFecha(20, 10, 2026),"montevideo","cerro chato",1,150);
    controladorViaje->altaViaje("ABJ4586",DTFecha(15, 3, 2026),"montevideo","colonia",4,140);
    controladorViaje->altaViaje("BCS4105",DTFecha(15, 3, 2026),"montevideo","colonia",9,180);
    controladorViaje->altaViaje("SBJ4874",DTFecha(15, 3, 2026),"montevideo","colonia",1,100);
    controladorViaje->altaViaje("SBJ4874",DTFecha(14, 3, 2026),"montevideo","colonia",4,600);
    controladorViaje->altaViaje("LDA4875",DTFecha(20, 10, 2026),"young","montevideo",1,250);


// RESERVAS

    controladorFecha->setFecha(DTFecha(14,3,2026));
    controladorReserva->generarReserva("santi_90",9,2);
    controladorReserva->generarReserva("mari_b",9,1);
    controladorReserva->generarReserva("nacho_f",10,5);
    controladorReserva->generarReserva("valen_uy",10,3);
    controladorReserva->generarReserva("joaco_r",10,1);
    controladorFecha->setFecha(DTFecha(13,3,2026));
    controladorReserva->generarReserva("mari_b",12,1);
    controladorReserva->generarReserva("nacho_f",12,1);
    controladorReserva->generarReserva("nacho_f",9,1);
    controladorFecha->setFecha(DTFecha(1, 6, 2026));
    controladorReserva->generarReserva("mari_b",1,2);


   
    // CALIFICACIONES
   

    controladorCalificacion->listarViajes("santi_90");
    controladorCalificacion->listarUSuariosViaje(9);
    controladorCalificacion->calificarUsuario("matil92", 4);
    controladorCalificacion->listarViajes("mari_b");
    controladorCalificacion->listarUSuariosViaje(9);
    controladorCalificacion->calificarUsuario("matil92", 4);
    controladorCalificacion->listarViajes("matil92");
    controladorCalificacion->listarUSuariosViaje(9);
    controladorCalificacion->calificarUsuario("mari_b", 3);
    controladorCalificacion->listarViajes("ana_silva");
    controladorCalificacion->listarUSuariosViaje(10);
    controladorCalificacion->calificarUsuario("valen_uy", 5);
    controladorCalificacion->listarViajes("ana_silva");
    controladorCalificacion->listarUSuariosViaje(10);
    controladorCalificacion->calificarUsuario("joaco_r", 5);
    controladorCalificacion->listarViajes("mari_b");
    controladorCalificacion->listarUSuariosViaje(12);
    controladorCalificacion->calificarUsuario("carlos_r", 5);
    controladorCalificacion->listarViajes("carlos_r");
    controladorCalificacion->listarUSuariosViaje(12);
    controladorCalificacion->calificarUsuario("nacho_f", 5);


    datosCargados = true;
    std::cout << "Datos cargados exitosamente.\n";
}

void CargaDatos::destroyInstance(){
delete instancia;
instancia = nullptr;
}