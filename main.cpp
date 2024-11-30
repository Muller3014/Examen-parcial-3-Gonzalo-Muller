//
// Created by gonza on 29/11/2024.
//


#include "launcher.h"
#include <iostream>

int main() {
    try {
        launcher launcher;
        launcher.imprimirTareas();
        launcher.ejecutar();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}