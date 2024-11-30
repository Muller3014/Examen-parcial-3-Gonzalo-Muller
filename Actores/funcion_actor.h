//
// Created by gonza on 29/11/2024.
//

#ifndef FUNCION_ACTOR_H
#define FUNCION_ACTOR_H

#include <string>
#include <vector>
#include "../Tarea/Tarea.h"

class Actor {
private:
    std::string id;
    std::string descripcion;
    std::vector<Tarea> tareas;
public:
    Actor(const std::string& id, const std::string& descripcion);
    std::string getId() const;
    std::string getDescripcion() const;
    int addTarea(const Tarea& tarea);
    int getDuracionTotal() const;
    std::string tostring() const;
    std::vector<Tarea> getTareas() const;
};
#endif //FUNCION_ACTOR_H
