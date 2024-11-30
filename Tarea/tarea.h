//
// Created by gonza on 29/11/2024.
//

#ifndef FUNCIONES_TAREA_H
#define FUNCIONES_TAREA_H
#include <string>

class Tarea {
private:
    std::string id;
    std::string descripcion;
    int duracion;

public:
    Tarea(const std::string& id, const std::string& descripcion, int duracion);
    std::string getId() const;
    std::string getDescripcion() const;
    int getDuracion() const;
    std::string toString() const;
};
#endif //FUNCIONES_TAREA_H
