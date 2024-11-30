//
// Created by gonza on 29/11/2024.
//
#include "../Actores/funcion_actor.h"
#include <iostream>
#include <iomanip>
#include "../launcher.h"
#include "../Tarea/Tarea.h"

Actor::Actor(const std::string& id, const std::string& descripcion)
    : id(id), descripcion(descripcion) {}

std::string Actor::getId() const {
    return id;
}

std::string Actor::getDescripcion() const {
    return descripcion;
}

int Actor::addTarea(const Tarea& tarea) {
    tareas.push_back(tarea);
    return tareas.size();
}

int Actor::getDuracionTotal() const {
    int duracionTotal = 0;
    for (const auto& tarea : tareas) {
        duracionTotal += tarea.getDuracion();
    }
    return duracionTotal;
}

std::string Actor::tostring() const {
    std::string resul;
    for (size_t i = 0; i < tareas.size(); i++) {
        resul += "  Tarea " + std::to_string(i + 1) + ": " + tareas[i].toString() + "\n";
    }

    return resul;
}
std::vector<Tarea> Actor::getTareas() const {
    return tareas;
}