#pragma once

#include "Arbol.h"

class Nodo {
public:
    int value;
    int balanceFactor;  // factor de equilibrio
    Nodo* left;
    Nodo* right;

    Nodo(int value) {
        this->value = value;
        this->balanceFactor = 0;
        this->left = NULL;
        this->right = NULL;
    }
};