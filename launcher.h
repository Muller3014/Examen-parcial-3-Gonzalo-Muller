//
// Created by gonza on 29/11/2024.
//

#ifndef LAUNCHER_H
#define LAUNCHER_H

#include "Actores/funcion_actor.h"
#include "Tarea/tarea.h"
#include <vector>

class launcher {
public:
    launcher();
    void ejecutar();
    std::vector<Tarea> getListaDeTareas() const;
    void crearActoresConInput();
    void asignarTareasConInput();
    void imprimirTareas();

private:
    std::vector<Tarea> crearTareas();
    std::vector<Actor> actores;
    std::vector<Tarea> tareas;
};



#endif //LAUNCHER_H
