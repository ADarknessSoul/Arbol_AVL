#pragma once

#include <iostream>

using namespace std;

#include "Nodo.h"

class Arbol {
private:

    Nodo* r; 

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

    Nodo* LL(Nodo* nodo) {
        Nodo* aux = nodo->left;
        nodo->left = aux->right;

        aux->right = nodo;

        nodo->balanceFactor = max(this->getbalanceFactor(nodo->left), this->getbalanceFactor(nodo->right)) + 1;
        aux->balanceFactor = max(this->getbalanceFactor(aux->left), this->getbalanceFactor(aux->right)) + 1;

        return aux;
    }

    Nodo* RR(Nodo* nodo) {
        Nodo* aux = nodo->right;
        nodo->right = aux->left;

        aux->left = nodo;

        nodo->balanceFactor = max(this->getbalanceFactor(nodo->left), this->getbalanceFactor(nodo->right)) + 1;
        aux->balanceFactor = max(this->getbalanceFactor(aux->left), this->getbalanceFactor(aux->right)) + 1;

        return aux;
    }

    Nodo* LR(Nodo* nodo) {
        Nodo* aux;

        nodo->left = this->RR(nodo->left);
        aux = this->LL(nodo);

        return aux;
    }

    Nodo* RL(Nodo* nodo) {
        Nodo* aux;

        nodo->right = this->LL(nodo->right);
        aux = this->RR(nodo);

        return aux;
    }

    Nodo* pushNode(Nodo* nuevo, Nodo* subArbol) {
        Nodo* newR = subArbol;

        if (nuevo->value < subArbol->value) {
            if (subArbol->left == NULL) {
                subArbol->left = nuevo;
            }
            else {
                subArbol->left = this->pushNode(nuevo, subArbol->left);

                int balance = this->getbalanceFactor(subArbol->left) - this->getbalanceFactor(subArbol->right);

                if (balance == 2) {
                    if (nuevo->value < subArbol->left->value) {
                        newR = this->LL(subArbol);
                    }
                    else {
                        newR = this->LR(subArbol);
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
                        newR = this->RR(subArbol);
                    }
                    else {
                        newR = this->RL(subArbol);
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

        return newR;
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
            cout << nodo->value << "\n";
            this->inOrden(nodo->right);
        }
    }

    void preOrden(Nodo* nodo) {
        if (nodo != NULL) {
            cout << nodo->value << "\n";
            this->preOrden(nodo->left);
            this->preOrden(nodo->right);
        }
    }

    void postOrden(Nodo* nodo) {
        if (nodo != NULL) {
            this->postOrden(nodo->left);
            this->postOrden(nodo->right);
            cout << nodo->value << "\n";
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
