#include <iostream>
using namespace std;

// Esta funcion la uso para sacar la potencia (x^n).
// Lo hago con recursion, voy multiplicando x hasta que n llega a 0

double pot(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return x * pot(x, n - 1);// aqui voy bajando el exponente
    }
}

// Esta funcion saca el factorial de un numero pero de forma recursiva.
// n! = n * (n-1) * (n-2) y asi continua
double fact(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}

// Aqui ya empiezo con la formula del seno usando la serie de Taylor

double senoT(double rad, int k, int limite)
{
    if (k == limite)
    {
        return 0;
    }

    // Aqui saco un termino de la serie.

    double num = pot(-1, k) * pot(rad, 2 * k + 1);
    double den = fact(2 * k + 1);
    double term = num / den;

    return term + senoT(rad, k + 1, limite);// sigo con el siguiente termino
}

// Lo mismo que el seno pero ahora para el coseno.
// La unica diferencia es la formula 
double cosT(double rad, int k, int limite)
{
    if (k == limite)
    {
        return 0;
    }

    double num = pot(-1, k) * pot(rad, 2 * k);
    double den = fact(2 * k);
    double term = num / den;

    return term + cosT(rad, k + 1, limite);
}

int main()
{
    double grados;
    cout << "Ingrese el angulo en grados: ";
    cin >> grados;

    
    double pi = 3.1415926535;
    double rad = grados * (pi / 180);

    int cantidad = 10; 

    double s = senoT(rad, 0, cantidad);
    double c = cosT(rad, 0, cantidad);

    cout << "Seno de " << grados << " grados = " << s << endl;
    cout << "Coseno de " << grados << " grados = " << c << endl;

    return 0;
}
