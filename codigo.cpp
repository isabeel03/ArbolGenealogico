#include <iostream>
using namespace std;

struct Persona {
    int id;
    string nombre;
    string posicion;
    Persona* izquierda;
    Persona* derecha;
};

Persona* crearPersona(int id, string nombre, string psc) {
    Persona* nueva = new Persona();
    nueva->id = id;
    nueva->nombre = nombre;
    nueva->posicion = psc;
    nueva->izquierda = nueva->derecha = NULL;
    return nueva;
}

Persona* insertar(Persona* raiz, int id, string nombre, string psc) {
    if (raiz == NULL) {
        return crearPersona(id, nombre, psc);
    }
    if (id < raiz->id) {
        raiz->izquierda = insertar(raiz->izquierda, id, nombre, psc);
    } else {
        raiz->derecha = insertar(raiz->derecha, id, nombre, psc);
    }
    return raiz;
}

void inorden(Persona* raiz) {
    if (raiz != NULL) {
        inorden(raiz->izquierda);
        cout << "ID: " << raiz->id 
             << "  Nombre: " << raiz->nombre
             << "  Posicion: " << raiz->posicion << endl;
        inorden(raiz->derecha);
    }
}


int main() {
    Persona* raiz = NULL;
    int cantidad;

    cout << "Cuantos miembros desea ingresar: ";
    cin >> cantidad;

    for (int i = 0; i < cantidad; i++) {
        int id;
        string nombre, psc;
        cout << "\nMiembro #" << i + 1 << endl;
        cout << "ID: ";
        cin >> id;
        cout << "Nombre : ";
        cin >> nombre; 
        cout << "Posicion: ";
        cin >> psc;

        raiz = insertar(raiz, id, nombre, psc);
    }

    cout << "\nRecorrido en inorden del arbol \n";
    inorden(raiz);

    return 0;
}
