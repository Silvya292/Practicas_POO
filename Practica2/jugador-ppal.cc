//jugador-ppal.cc
//Example to prove the class Jugador is working well

#include "jugador.h"
#include <iostream>

using namespace std;

int main(){
    cout << "Comprobación del funcionamiento de la clase Jugador\n\n";
    cout << "DATOS DEL JUGADOR:\n";

    string dni, codigo, nombre, apellidos, direccion, localidad, provincia, pais;
    int edad;

    cout << "Introduzca su DNI: ";
    cin >> dni;
    cout << "Introduzca ahora su código de jugador: ";
    cin >> codigo;
    cout << "Introduzca su nombre: ";
    cin >> nombre;
    cout << "Introduzca sus apellidos: ";
    cin >> apellidos;
    cout << "Introduzca su edad: ";
    cin >> edad;
    cout << "Introduzca su dirección: ";
    cin >> direccion;
    cout << "Introduzca su localidad: ";
    cin >> localidad;
    cout << "Introduzca su provincia: ";
    cin >> provincia;
    cout << "Introduzca su país: ";
    cin >> pais;
    system("clear");

    Jugador j(dni,codigo,nombre,apellidos,edad,direccion,localidad,provincia,pais); //Se define un elemento auxiliar de la clase jugador
    list <Apuesta> apuestas; //Se define una lista auxiliar de apuestas
    j.setApuestas(); //Se leen del fichero las apuestas del jugador
    apuestas=j.getApuestas(); //Se asocian las apuestas del jugador a la lista auxiliar

    list <Apuesta>::iterator i; //Se define un iterador para recorrer la lista
    int n=1;
    cout << "Jugador " << j.getCodigo() << ":\n\n";

    for(i=apuestas.begin();i!=apuestas.end();i++){ //Se imprime la lista de apuestas del jugador
        cout << "Apuesta número " << n << endl;
        cout << "   Tipo: " << i->tipo << endl;
        cout << "   Valor: " << i->valor << endl;
        cout << "   Cantidad: " << i->cantidad << endl << endl;
        n++;
    }

    return 0;
}