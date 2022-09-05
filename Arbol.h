#pragma once

#include <iostream>

using namespace std;

#include "Nodo.h"

class Arbol {
private:

    Nodo* r; //ra�z

public:
    Arbol() {
        this->r = NULL;
    }

    int getbalanceFactor(Nodo* nodo) {
        if (nodo == NULL) {
            return -1;
        }
        else {
            return nodo->balanceFactor;
        }
    }

    Nodo* rotacionIzquierda(Nodo* nodo) {
        Nodo* aux = nodo->left;
        nodo->left = aux->right;

        aux->right = nodo;

        nodo->balanceFactor = max(this->getbalanceFactor(nodo->left), this->getbalanceFactor(nodo->right)) + 1;
        aux->balanceFactor = max(this->getbalanceFactor(aux->left), this->getbalanceFactor(aux->right)) + 1;

        return aux;
    }

    Nodo* rotacionDerecha(Nodo* nodo) {
        Nodo* aux = nodo->right;
        nodo->right = aux->left;

        aux->left = nodo;

        nodo->balanceFactor = max(this->getbalanceFactor(nodo->left), this->getbalanceFactor(nodo->right)) + 1;
        aux->balanceFactor = max(this->getbalanceFactor(aux->left), this->getbalanceFactor(aux->right)) + 1;

        return aux;
    }

    Nodo* rotacionDobleIzquierda(Nodo* nodo) {
        Nodo* aux;

        nodo->left = this->rotacionDerecha(nodo->left);
        aux = this->rotacionIzquierda(nodo);

        return aux;
    }

    Nodo* rotacionDobleDerecha(Nodo* nodo) {
        Nodo* aux;

        nodo->right = this->rotacionIzquierda(nodo->right);
        aux = this->rotacionDerecha(nodo);

        return aux;
    }

    Nodo* pushNode(Nodo* nuevo, Nodo* subArbol) {
        Nodo* nuevoPadre = subArbol;

        if (nuevo->value < subArbol->value) {
            if (subArbol->left == NULL) {
                subArbol->left = nuevo;
            }
            else {
                subArbol->left = this->pushNode(nuevo, subArbol->left);

                int balance = this->getbalanceFactor(subArbol->left) - this->getbalanceFactor(subArbol->right);

                if (balance == 2) {
                    if (nuevo->value < subArbol->left->value) {
                        nuevoPadre = this->rotacionIzquierda(subArbol);
                    }
                    else {
                        nuevoPadre = this->rotacionDobleIzquierda(subArbol);
                    }
                }

            }
        }
        else if (nuevo->value > subArbol->value) {
            if (subArbol->right == NULL) {
                subArbol->right = nuevo;
            }
            else {
                subArbol->right = this->pushNode(nuevo, subArbol->right);

                int balance = this->getbalanceFactor(subArbol->right) - this->getbalanceFactor(subArbol->left);

                if (balance == 2) {
                    if (nuevo->value > subArbol->right->value) {
                        nuevoPadre = this->rotacionDerecha(subArbol);
                    }
                    else {
                        nuevoPadre = this->rotacionDobleDerecha(subArbol);
                    }
                }
            }
        }
        else {
            cout << "El valor introducido es repetido" << endl;
        }

        // Actualizando factor de equilibrio
        if ((subArbol->left == NULL) && (subArbol->right != NULL)) {
            subArbol->balanceFactor = subArbol->right->balanceFactor + 1;
        }
        else if ((subArbol->right == NULL) && (subArbol->left != NULL)) {
            subArbol->balanceFactor = subArbol->left->balanceFactor + 1;
        }
        else {
            subArbol->balanceFactor = max(this->getbalanceFactor(subArbol->left), this->getbalanceFactor(subArbol->right)) + 1;
        }

        return nuevoPadre;
    }

    void push(int value) {
        Nodo* nuevo = new Nodo(value);

        if (this->r == NULL) {
            this->r = nuevo;
        }
        else {
            this->r = this->pushNode(nuevo, r);
        }
    }

    void inOrden(Nodo* nodo) {
        if (nodo != NULL) {
            this->inOrden(nodo->left);
            cout << nodo->value << ", ";
            this->inOrden(nodo->right);
        }
    }

    void preOrden(Nodo* nodo) {
        if (nodo != NULL) {
            cout << nodo->value << ", ";
            this->preOrden(nodo->left);
            this->preOrden(nodo->right);
        }
    }

    void postOrden(Nodo* nodo) {
        if (nodo != NULL) {
            this->postOrden(nodo->left);
            this->postOrden(nodo->right);
            cout << nodo->value << ", ";
        }
    }

    void mostrar(Nodo* nodo, int c) {


        if (nodo == NULL) {
            return;
        }
        else {
            mostrar(nodo->right, c + 1);
            for (int i = 0; i < c; i++) {
                cout << "   ";
            }
            cout << nodo->value << endl;
            mostrar(nodo->left, c + 1);
        }

    }

    Nodo* getRaiz() {
        return this->r;
    }

};