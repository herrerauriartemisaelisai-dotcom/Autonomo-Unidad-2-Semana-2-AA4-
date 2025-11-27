#include <iostream>
using namespace std;

// Esta funcion es la que calcula un numero de Fibonacci,
// aqui uso la definicion normal, los dos primeros son 0 y 1
// y los demas salen sumando los dos anteriores

int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

     // Aqui hago la suma de los dos anteriores usando recursion

    return fib(n - 1) + fib(n - 2);
}

// Esta funcion sirve para ir contando cuantos numeros de Fibonacci
// caen dentro del rango 1000 a 2000
int contar(int n)
{
    int f = fib(n);

    if (f > 2000)   
    {
        return 0;
    }
    
    // Si el numero de Fibonacci esta dentro del rango,
    // sumo 1 y sigo buscando el siguiente
    if (f >= 1000 && f <= 2000)  
    {
        return 1 + contar(n + 1);
    }

    // Si todavia no llega al rango, simplemente paso al siguiente numero

    return contar(n + 1);  
}

int main()
{
    int total = contar(0);

    cout << "Cantidad de numeros de Fibonacci entre 1000 y 2000: "<< total << endl;

    return 0;
}
