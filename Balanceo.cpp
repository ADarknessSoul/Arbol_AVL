#include "Arbol.h"
#include <stdlib.h>

int ingresarOpcion();
void mostrarArbol(Arbol*, int);

int main() {

    int c;
    int dato;
    int detener = 0;

    Arbol* a = new Arbol();

        int opcion = ingresarOpcion();

        switch (opcion) {

        case 1: 

            do {

                c = 0;

                cout << "Ingresa el dato: ";
                cin >> dato;

                a->push(dato);

                mostrarArbol(a, c);

                cout << "Ingresa: \n1: Parar\nCualquier otro numero: Seguir\n";

                cin >> detener;

               system("cls");

            } while (detener != 1);


            break;

        case 2:

            c = 0;

            a->push(5);
            a->push(4);
            a->push(8);
            a->push(6);
            a->push(7);

            mostrarArbol(a, c);

            break;

        default:

            cout << "Ingresa una opcion valida" << endl;
    
            break;

        }

    return 0;
}

int ingresarOpcion() {

    int opcion;

    cout << "Quiere introducir los datos, o mostrar los cargados? \n1:Introducir datos\n2: Mostrar cargados" << endl << endl;
    cin >> opcion;

    return opcion;

}

void mostrarArbol(Arbol* a, int c) {

    cout << "Preorden del arbol (R, sI, sD): " << endl;

    a->preOrden(a->getRaiz());

    cout << endl << endl;

    cout << "PostOrden del arbol (sI, sD, R): " << endl;

    a->postOrden(a->getRaiz());

    cout << endl << endl;

    cout << "InOrden del arbol (sI, R, sD): " << endl;

    a->inOrden(a->getRaiz());

    cout << endl << endl;

    cout << "Forma del arbol balanceado: " << endl;
    a->mostrar(a->getRaiz(), c);

}