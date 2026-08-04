#include "../include/Menu.h"
#include "../include/Fabrica.h"
#include "../include/CargaDatos.h"
#include "../include/DTFecha.h"
#include <iostream>
#include <limits>
#include <string>


void Menu::altaUsuario() {
    Fabrica* fabrica = Fabrica::getInstance();
    IControladorAltaUsuario* controlador = fabrica->getIControladorAltaUsuario();

    int tipoUsuario;
    std::cout << "1. Alta Pasajero\n";
    std::cout << "2. Alta Conductor\n";
    std::cout << "Seleccione: ";
    std::cin >> tipoUsuario;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (tipoUsuario != 1 && tipoUsuario != 2) {
        std::cout << "Opcion invalida.\n";
        return;
    }

    std::string nickname, nombre, contrasena, email;
    std::cout << "Ingrese nickname: "; std::getline(std::cin, nickname);
    std::cout << "Ingrese nombre: "; std::getline(std::cin, nombre);
    std::cout << "Ingrese contrasena: "; std::getline(std::cin, contrasena);
    if (contrasena.length() < 8){
        std::cout << "La contrasena debe tener por lo menos 8 caracteres.\n";
        return;
    }
    std::cout << "Ingrese email: "; std::getline(std::cin, email);


    bool usuarioOk = false;

    if (tipoUsuario == 1) {
        std::string ci;
        std::cout << "Ingrese CI: "; std::getline(std::cin, ci);
        usuarioOk = controlador->altaPasajero(nickname, nombre, contrasena, email, ci);
    } else if (tipoUsuario == 2) {
        bool tieneMotoProfesional = false;
        bool tieneMotoAmateur = false;
        bool tieneAutoProfesional = false;
        bool tieneAutoAmateur = false;

        int cantLibretas = 0;
        int agregarLibreta = 1;

        while (agregarLibreta == 1 && cantLibretas < 4) {
            int tipoLibreta;
            std::cout << "\n=== Registrar Libreta ===\n";
            std::cout << "0. Moto (Profesional)\n";
            std::cout << "1. Moto (Amateur)\n";
            std::cout << "2. Auto (Profesional)\n";
            std::cout << "3. Auto (Amateur)\n";
            std::cout << "Seleccione el tipo de libreta: ";
            std::cin >> tipoLibreta;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            bool yaExiste = false;
            if (tipoLibreta == 0) {
                if (tieneMotoProfesional) {
                    yaExiste = true;
                } else {
                    tieneMotoProfesional = true;
                    cantLibretas++;
                }
            } else if (tipoLibreta == 1) {
                if (tieneMotoAmateur) {
                    yaExiste = true;
                } else {
                    tieneMotoAmateur = true;
                    cantLibretas++;
                }
            } else if (tipoLibreta == 2) {
                if (tieneAutoProfesional) {
                    yaExiste = true;
                } else {
                    tieneAutoProfesional = true;
                    cantLibretas++;
                }
            } else if (tipoLibreta == 3) {
                if (tieneAutoAmateur) {
                    yaExiste = true;
                } else {
                    tieneAutoAmateur = true;
                    cantLibretas++;
                }
            } else {
                std::cout << "Opcion invalida.\n";
                continue;
            }

            if (yaExiste) {
                std::cout << "Esa libreta ya fue ingresada.\n";
            } else {
                std::cout << "Libreta agregada.\n";
            }

            if (cantLibretas < 4) {
                std::cout << "¿Desea agregar otra libreta? (1: Si, 0: No): ";
                std::cin >> agregarLibreta;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                std::cout << "Se ha alcanzado el limite maximo de libretas.\n";
            }
        }

        if (cantLibretas == 0) {
            std::cout << "Debe ingresar al menos una libreta para registrar un conductor.\n";
            return;
        }

        std::vector<TipoLibreta> libretas;
        if (tieneMotoProfesional) {
            libretas.push_back(TipoLibreta::MotoProfesional);
        }
        if (tieneMotoAmateur) {
            libretas.push_back(TipoLibreta::MotoAmateur);
        }
        if (tieneAutoProfesional) {
            libretas.push_back(TipoLibreta::AutoProfesional);
        }
        if (tieneAutoAmateur) {
            libretas.push_back(TipoLibreta::AutoAmateur);
        }
        usuarioOk = controlador->altaConductor(nickname, nombre, contrasena, email, libretas);
        
        int agregarVehiculo = 1;
        while (usuarioOk == true && agregarVehiculo == 1) {
            std::string matricula, marca, modelo;
            int capacidad, tipo;
            std::cout << "\n=== Registrar Vehiculo ===\n";
            std::cout << "Ingrese matricula: "; std::getline(std::cin, matricula);
            std::cout << "Ingrese capacidad: "; std::cin >> capacidad;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ingrese marca: "; std::getline(std::cin, marca);
            std::cout << "Ingrese modelo: "; std::getline(std::cin, modelo);
            std::cout << "Ingrese tipo (0: Auto, 1: Moto): "; std::cin >> tipo;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            TipoVehiculo tipoVehiculo;
            if (tipo == 0){
                tipoVehiculo = Auto;
            }else if (tipo == 1){
                tipoVehiculo = Moto;
            }

            int resultadoRegistrarVehiculo = -3;
            resultadoRegistrarVehiculo = controlador->registrarVehiculo(nickname, matricula, capacidad, marca, modelo, tipoVehiculo);
            if (resultadoRegistrarVehiculo == -1) {
                std::cout << "Ya existe un vehiculo con esa matricula.\n";
            } else if (resultadoRegistrarVehiculo == -2) {
                std::cout << "El conductor no tiene la libreta necesaria para registrar ese vehiculo.\n";
            } else if (resultadoRegistrarVehiculo == 0) {
                std::cout << "Vehiculo registrado exitosamente.\n";
            }
            std::cout << "¿Desea agregar otro vehiculo? (1: Si, 0: No): ";
            std::cin >> agregarVehiculo;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    if (usuarioOk == 0) {std::cout << "\nERROR: Ese nickname ya existe.\n";}
    
}

void Menu::altaViaje() {
    Fabrica* fabrica = Fabrica::getInstance();
    IControladorAltaViaje* controladorAltaViaje = fabrica->getIControladorAltaViaje();

    std::string nickname, matricula, origen, destino;
    int dia, mes, anio, asientos;
    float precio;

    std::cout << "Ingrese nickname del conductor: "; std::getline(std::cin, nickname);
    //TODO: Coleccion de DTVehiculosConductor = controlador->listarVehiculosConductor(nickname)
    std::vector<DTVehiculosConductor> dtvc = controladorAltaViaje->listarVehiculosConductor(nickname);
    //TODO: Recorrer la coleccion y mostrar "> Matricula: xx, Capacidad: yy, Marca: zzz, Modelo: www, Tipo: ttt"
    for ( auto it: dtvc){
        std::cout << it; 
    }
    std::cout << "Ingrese matricula del vehiculo a utilizar: "; std::getline(std::cin, matricula);
    bool matriculaValida = false;
    //TODO: Validar matricula en listado
    matriculaValida = std::any_of(dtvc.begin(), dtvc.end(), [&](DTVehiculosConductor dt) {return dt.getDTMatricula() == matricula;});
    if (!matriculaValida) {
        std::cout << "Matricula invalida.\n";
        return;
    }

    std::cout << "Ingrese fecha del viaje (dia mes anio): "; std::cin >> dia >> mes >> anio;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ingrese origen: "; std::getline(std::cin, origen);
    std::cout << "Ingrese destino: "; std::getline(std::cin, destino);
    std::cout << "Ingrese cantidad de asientos: "; std::cin >> asientos;
    std::cout << "Ingrese precio por asiento: "; std::cin >> precio;
    if (precio <= 0){
        std::cout << "El precio por asiento debe ser un numero positivo.\n";
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool viajeOk = false;
    //TODO: viajeOk = controlador->
    viajeOk = controladorAltaViaje->altaViaje(matricula, DTFecha(dia, mes, anio), origen, destino, asientos, precio);
    if (viajeOk) {
        std::cout << "Viaje registrado exitosamente.\n";
    } else {
        std::cout << "Error al registrar el viaje.\n";
    }
}

void Menu::generarReserva() {
    //DONE: Colecion de String = controlador->listarPasajeros() (X)
    //DONE: Recorrer la colección y mostrar "> xx" (X)
    Fabrica* fabrica = Fabrica::getInstance();
    IControladorGenerarReserva* controlador = fabrica->getIControladorGenerarReserva();
    std::vector<std::string> nicknames = controlador->listarPasajeros();
    for (std::string n : nicknames){
        std::cout << "> " << n << "\n";
    }

    std::string nickname;
    std::cout << "Ingrese nickname del pasajero: "; std::getline(std::cin, nickname);

    //DONE: Validar nickname en listado (X)
    bool nicknameValido = std::any_of(nicknames.begin(), nicknames.end(), [&](std::string n) {return n.compare(nickname) == 0;});
    if (!nicknameValido) {
        std::cout << "Nickname invalido.\n";
        return;
    }

    int dia, mes, anio, asientos;
    std::string origen, destino;
    std::cout << "Ingrese fecha del viaje a consultar (dia mes anio): "; std::cin >> dia >> mes >> anio;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ingrese origen: "; std::getline(std::cin, origen);
    std::cout << "Ingrese destino: "; std::getline(std::cin, destino);
    std::cout << "Ingrese cantidad de asientos a reservar: "; std::cin >> asientos;
    if (asientos < 1){
        std::cout << "La cantidad de asientos a reservar tiene que ser mayor o igual a uno.\n";
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //DONE: Coleccion de DTConsultaViaje = controlador->consultarViajes(DTFecha(dia, mes, anio), origen, destino, asientos) (X)
    std::vector<DTConsultaViaje> ColeccionDTCV = controlador->consultarViajes(DTFecha(dia, mes, anio), origen, destino, asientos);
    //DONE: Recorrer la coleccion y mostrar: "> Codigo: xx, Marca: yy, Modelo: zzz, Conductor: aaa, CalificacionPromedio: qqq, PrecioTotal: eee" (X)
    for (auto dtcv : ColeccionDTCV){
        std::cout << ">" << dtcv << "\n";
    }

    if (ColeccionDTCV.size() == 0) {
        std::cout << "No hay viajes disponibles.\n";
        return;
    }

    int codigo;
    std::cout << "Ingrese codigo del viaje a reservar: "; std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //DONE: Validar codigo en listado
    if (!std::any_of(ColeccionDTCV.begin(), ColeccionDTCV.end(), [&](DTConsultaViaje dtcv) {return dtcv.getCodigo() == codigo;})){
        std::cout << "Codigo invalido.\n";
        return;
    }

    bool reservaOk = controlador->generarReserva(nickname, codigo, asientos);
    //DONE: reservaOk = controlador->generarReserva(nickname, codigo, asientos)
    if (reservaOk) {
        std::cout << "Reserva realizada exitosamente.\n";
    } else {
        std::cout << "Error al realizar la reserva.\n";
    }
}

void Menu::calificarUsuario() {
    Fabrica* fabrica = Fabrica::getInstance();
    IControladorCalificarUsuario* controlador = fabrica->getIControladorCalificarUsuario();
    //TODO: Coleccion de DTUsuario = controlador->listarUsuarios() hecho
    std::vector<DTUsuario> listaU = controlador->listarUsuarios();
    //TODO: Recorrer la coleccion y mostrar "> Nickname: xx, Nombre: yyy" hecho
    for (DTUsuario it : listaU){
        std::cout << it << "\n";
    }
    std::string nickname;
    std::cout << "Ingrese su nickname: "; std::getline(std::cin, nickname);
    //TODO: Validar nickname en listado hecho
    bool nicknameValido = std::any_of(listaU.begin(), listaU.end(), [nickname](DTUsuario n){
        return n.getNickname() == nickname;
    });
    if (!nicknameValido) {
        std::cout << "Nickname invalido.\n";
        return;
    }
    //TODO: Coleccion de DTListarViaje = controlador->listarViajes(nickname) hecho
    std::vector<DTListarViaje> listaVi = controlador->listarViajes(nickname);
    //TODO: Recorrer la coleccion y mostrar "> Codigo: xx, Fecha: dd/mm/aaaa, Origen: zzz, Destino: www, Conductor: aaa" hecho
    for (DTListarViaje it : listaVi){
        std::cout << it << "\n";
    }
    int codigo;
    std::cout << "Ingrese codigo del viaje: "; std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //TODO: Validar codigo en listado
    bool codigoValido = std::any_of(listaVi.begin(), listaVi.end(), [&](DTListarViaje n){
        return n.getCodigo() == codigo;
    });
    if (!codigoValido) {
        std::cout << "Codigo invalido.\n";
        return;
    }
    //TODO: Coleccion de DTUsuarioViaje = Controlador->listarUsuariosViaje(codigo) hecho
    std::vector<DTUsuarioViaje> listaUVi = controlador->listarUSuariosViaje(codigo);
    //TODO: Recorrer la coleccion y mostrar "> Nickname: xx, Tipo: yyy" hecho
    for (DTUsuarioViaje it : listaUVi){
        std::cout << it << "\n";
    }
    std::string nicknameCalificado;
    int calificacion;
    std::cout << "Ingrese nickname del usuario a calificar: "; std::getline(std::cin, nicknameCalificado);
    std::cout << "Ingrese calificacion (1-5): "; std::cin >> calificacion;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //TODO: Validar nickname en listado hecho
    bool nicknameCalificadoValido = std::any_of(listaUVi.begin(), listaUVi.end(), [nicknameCalificado](DTUsuarioViaje n){
        return n.getNickname() == nicknameCalificado;
    });
    if (!nicknameCalificadoValido) {
        std::cout << "Nickname invalido.\n";
        return;
    }
    //TODO: calificacionOk = Controlador->calificarUsuario(nicknameCalificado, calificacion) hecho
    bool calificacionOk = controlador->calificarUsuario(nicknameCalificado,calificacion);
    if (calificacionOk) {
        std::cout << "Calificacion exitosa.\n";
    } else {
        std::cout << "Error al calificar.\n";
    }
    ;
}

void Menu::eliminarViaje() {
    Fabrica* fabrica = Fabrica::getInstance();
    IControladorEliminarViaje* controlador = fabrica->getIControladorEliminarViaje();
    std::vector<DTListarViaje> DTLV = controlador->listarViajes(); 
    //TODO: Coleccion de DTListarViaje = controlador->listarViajes()
    //TODO: Recorrer la coleccion y mostrar "> Codigo: xx, Fecha: dd/mm/aaaa, Origen: zzz, Destino: www, Conductor: aaa"
    for (auto it: DTLV){
        std::cout << it << "\n";
    }
    int codigo;
    std::cout << "Ingrese codigo del viaje a eliminar: "; std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool codigoValido = std::any_of(DTLV.begin(), DTLV.end(), [codigo](DTListarViaje n){
        return n.getCodigo() ==  codigo;
    });
    //TODO: Validar codigo en listado
    if (!codigoValido) {
        std::cout << "Codigo invalido.\n";
        return;
    }

    //TODO: DTDetalleViaje = controlador->detalleViaje(codigo)
    DTDetalleViaje DTVi = controlador->detalleViaje(codigo);
    //TODO: Mostrar detalle del viaje siguiendo el formato
    //>> Viaje <<
    //--- codigo aa, Fecha: dd/mm/aaaa, Origen: zzz, Destino: www, Capacidad: bbb, Precio por asiento: qqq
    //>> Vehiculo <<
    //--- Matricula: mm, Capacidad: aa, Marca: bbb, Modelo: ccc, Tipo: ddd
    //>> Reservas <<
    //--- AsientosReservados: xx, Fecha: dd/mm/aaaa, Pasajero: aaa
    std::cout << DTVi;
    int confirmar;
    std::cout << "¿Confirmar eliminacion? (1: Si, 0: No): "; std::cin >> confirmar;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (confirmar == 1) {
        //TODO: controlador->eliminarViaje()
        controlador->eliminarViaje();
        std::cout << "Viaje eliminado exitosamente.\n";
    } else {
        //TODO: controlador->cancelarEliminarViaje()
        controlador->cancelarEliminarViaje();
        std::cout << "Eliminacion cancelada.\n";
    }
}

void Menu::administrarFechaActual() {
    int opFecha;
    std::cout << "1. Ver fecha actual\n";
    std::cout << "2. Modificar fecha actual\n";
    std::cout << "Seleccione: ";
    std::cin >> opFecha;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Fabrica* fabrica = Fabrica::getInstance();
    IControladorFechaActual* controladorFecha = fabrica->getIControladorFechaActual();

    if (opFecha == 1) {
        DTFecha fecha = controladorFecha->getFecha();
        std::cout << "Fecha actual: " << fecha << "\n";
    } else if (opFecha == 2) {
        int dia, mes, anio;
        std::cout << "Ingrese dia: "; std::cin >> dia;
        std::cout << "Ingrese mes: "; std::cin >> mes;
        std::cout << "Ingrese anio: "; std::cin >> anio;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        controladorFecha->setFecha(DTFecha(dia, mes, anio));
        std::cout << "Fecha modificada exitosamente a " << controladorFecha->getFecha() << "\n";
    } else {
        std::cout << "Opcion invalida.\n";
    }
}

void Menu::cargarDatos() {
    CargaDatos::getInstance()->cargarDatos();
}

void Menu::mostrarMenu() {
    int opcion = -1;
    while (opcion != 8) {
        std::cout << "\n=== MENU PRINCIPAL ===\n";
        std::cout << "1. Alta de Usuario\n";
        std::cout << "2. Alta de Viaje\n";
        std::cout << "3. Generar Reserva\n";
        std::cout << "4. Calificar Usuario\n";
        std::cout << "5. Eliminar Viaje\n";
        std::cout << "6. Administrar Fecha Actual\n";
        std::cout << "7. Cargar Datos\n";
        std::cout << "8. Salir\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                altaUsuario();
                break;
            case 2:
                altaViaje();
                break;
            case 3:
                generarReserva();
                break;
            case 4:
                calificarUsuario();
                break;
            case 5:
                eliminarViaje();
                break;
            case 6:
                administrarFechaActual();
                break;
            case 7:
                cargarDatos();
                break;
            case 8:{
                Fabrica::destroyInstance();
                CargaDatos::destroyInstance();
                std::cout << "Saliendo del sistema...\n";
            }
                break;
            default:
                std::cout << "Opcion invalida.\n";
        }
    }
}
