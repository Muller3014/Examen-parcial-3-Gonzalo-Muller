//
// Created by gonza on 29/11/2024.
//

#include "launcher.h"
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <stdexcept>
# include "Tarea/tarea.h"

using namespace std;

vector<Tarea> launcher::crearTareas() {
    return {
        Tarea("A", "Reserva de vuelo", 20),
        Tarea("B", "Informar a casa para empacar", 5),
        Tarea("C", "Empacar maletas", 40),
        Tarea("D", "Preparacion del billete por la agencia", 10),
        Tarea("E", "Recoger el billete de la agencia", 5),
        Tarea("F", "Llevar el billete a la oficina", 10),
        Tarea("G", "Recoger las maletas de casa", 20),
        Tarea("H", "Llevar maletas a la oficina", 25),
        Tarea("I", "Conversacion sobre documentos requeridos", 35),
        Tarea("J", "Dictar instrucciones para ausencia", 25),
        Tarea("K", "Reunir documentos", 15),
        Tarea("L", "Organizar documentos", 5),
        Tarea("M", "Viajar al aeropuerto y facturar", 25)
    };
}

void launcher::crearActoresConInput() {
    int numActores;
    cout << "Ingrese el numero de actores: ";
    if (!(cin >> numActores)) {
        throw runtime_error("Error al leer el numero de actores.");
    }
    cin.ignore();

    for (int i = 0; i < numActores; ++i) {
        string id, descripcion;
        cout << "Ingrese el ID del actor " << i + 1 << ": ";
        if (!getline(cin, id)) {
            throw runtime_error("Error al leer el ID del actor.");
        }
        cout << "Ingrese la descripcion del actor " << i + 1 << ": ";
        if (!getline(cin, descripcion)) {
            throw runtime_error("Error al leer la descripcion del actor.");
        }
        actores.emplace_back(id, descripcion);
    }
}

void launcher::asignarTareasConInput() {
    for (auto& actor : actores) {
        while (true) {
            string respuesta;
            cout << "¿Quieres asignarle una nueva tarea al actor " << actor.getDescripcion() << "? (s/n): ";
            if (!getline(cin, respuesta)) {
                throw runtime_error("Error al leer la respuesta.");
            }

            if (respuesta != "s" && respuesta != "S") {
                break;
            }

            string tareaId;
            cout << "Ingrese el ID de la tarea para el actor " << actor.getDescripcion() << ": ";
            if (!getline(cin, tareaId)) {
                throw runtime_error("Error al leer el ID de la tarea.");
            }

            auto it = find_if(tareas.begin(), tareas.end(), [&tareaId](const Tarea& tarea) {
                return tarea.getId() == tareaId;
            });

            if (it != tareas.end()) {
                actor.addTarea(*it);
            } else {
                cout << "Tarea con ID " << tareaId << " no encontrada." << endl;
            }
        }
    }
}

void launcher::ejecutar() {
    try {
        tareas = crearTareas();
        crearActoresConInput();
        asignarTareasConInput();

        unordered_map<string, int> taskEndTimes;
        int tiempoTotal = 0;

        cout << "=== Resumen de tareas por actor ===" << endl;

        for (const auto& actor : actores) {
            cout << "Actor: " << actor.getDescripcion() << endl;
            cout << actor.tostring();
            int currentTime = 0;
            for (const auto& tarea : actor.getTareas()) {
                int startTime = currentTime;
                if (taskEndTimes.find(tarea.getId()) != taskEndTimes.end()) {
                    startTime = max(startTime, taskEndTimes[tarea.getId()]);
                }
                int endTime = startTime + tarea.getDuracion();
                taskEndTimes[tarea.getId()] = endTime;
                currentTime = endTime;
            }
            cout << "Tiempo total para " << actor.getDescripcion() << ": " << currentTime << " minutos" << endl;
            tiempoTotal = max(tiempoTotal, currentTime);
            cout << "----------------------------------" << endl;
        }

        cout << "=== Tiempo total para completar todas las tareas ===" << endl;
        cout << "Tiempo total: " << tiempoTotal << " minutos" << endl;

        cout << "\n=== Verificacion de tiempos ===" << endl;
        for (const auto& actor : actores) {
            if (actor.getDuracionTotal() > 100) {
                cout << "El actor " << actor.getDescripcion() << " NO puede completar sus tareas a tiempo." << endl;
            } else {
                cout << "El actor " << actor.getDescripcion() << " puede completar sus tareas a tiempo." << endl;
            }
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

void launcher::imprimirTareas() {
    cout << "=== Lista de tareas ===" << endl;
    for (const auto& tarea : tareas) {
        cout << tarea.toString() << endl;
    }
    cout << "=======================" << endl;
}

launcher::launcher() {
    try {
        tareas = crearTareas();
    } catch (const exception& e) {
        cerr << "Error al crear tareas: " << e.what() << endl;
    }
}