#include <iostream>
#include <string>
using namespace std;


void permutar(string &cadena, int inicio, int fin)
{
    if (inicio == fin)
    {
        cout<<cadena<<endl;
        return;
    }

    // En este for voy probando a cambiar la letra que está en "inicio"
    // con las demás.

    for (int i = inicio; i <= fin; i++)
    {
        swap (cadena[inicio], cadena[i]); // Pruebo mover una letra
        permutar(cadena, inicio + 1, fin); // Llamo recursivamente avanzando una posición
        swap (cadena[inicio], cadena[i]); // Regreso la cadena para seguir probando
    }
}


int main()
{
    string texto;

    cout<<"Ingrese el texto que desea permutar"<<endl;
    cin>>texto;

    cout<<"Su permutacion es: "<<endl;

    // Llamo la función mandando la cadena completa.
    // 0 es la primera posición y length()-1 es la última.

    permutar(texto, 0, texto.length() - 1);

    return 0;
}