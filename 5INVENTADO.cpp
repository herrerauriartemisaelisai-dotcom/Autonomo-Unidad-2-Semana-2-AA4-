/*“Este es un programa que yo diseñé para practicar varias cosas de C++. 
Básicamente hice una calculadora con un menú donde el usuario puede escoger entre sumar, restar, multiplicar, dividir y también calcular la potencia de un número.
La parte de la potencia la hice usando una función recursiva, porque era uno de los requisitos.
El menú se repite hasta que la persona elija la opción de salir, así se pueden hacer varias operaciones sin reiniciar el programa.”*/

#include <iostream>
using namespace std;


int potencia(int base, int exp)
{
    if (exp == 0)
    {
        return 1;
    }
    else
    {
        return base * potencia(base, exp - 1);
    }
}


int sumar(int a, int b)
{
    return a + b;
}

int restar(int a, int b)
{
    return a - b;
}

int multiplicar(int a, int b)
{
    return a * b;
}

double dividir(int a, int b)
{
    if (b == 0)
    {
        cout << "No se puede dividir para 0." << endl;
        return 0;
    }
    return (double)a / b;
}

int main()
{
    int opcion;
    int num1, num2;

    do
    {
        cout << "----CALCULADORA----" << endl;
        cout << "1. Sumar" << endl;
        cout << "2. Restar" << endl;
        cout << "3. Multiplicar" << endl;
        cout << "4. Dividir" << endl;
        cout << "5. Potencia (a^b) con recursion" << endl;
        cout << "6. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;

        if (opcion >= 1 && opcion <= 5)
        {
            cout << "Ingrese el primer numero: ";
            cin >> num1;

            cout << "Ingrese el segundo numero: ";
            cin >> num2;
        }

        switch (opcion)
        {
            case 1:
                cout << "Resultado: " << sumar(num1, num2) << endl;
                break;

            case 2:
                cout << "Resultado: " << restar(num1, num2) << endl;
                break;

            case 3:
                cout << "Resultado: " << multiplicar(num1, num2) << endl;
                break;

            case 4:
                cout << "Resultado: " << dividir(num1, num2) << endl;
                break;

            case 5:
                cout << "Resultado: " << potencia(num1, num2) << endl;
                break;

            case 6:
                cout << "Saliendo..." << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }

    } while (opcion != 6);

    return 0;
}
