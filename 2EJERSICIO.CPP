#include <iostream>
using namespace std;

// Esta funcion la uso para ver si un numero es primo.
// Lo hago probando si tiene algun divisor. Si llego a 1 sin encontrar
// divisores, significa que si es primo

bool esprimo(int num, int divisor)
{
    if(divisor == 1)
    {
        return true;
    }

     // Si aqui encuentro que divide exacto, ya sé que no es primo

    if (num % divisor == 0)
    {
        return false; 
    }
    
    // Si no se decidió todavía, sigo probando con un divisor más pequeño
    return esprimo(num, divisor - 1);
   
}

// Esta funcion sirve para buscar el numero primo que está justo
// antes del que ingresas. Voy bajando uno por uno hasta
// que encuentre un primo y ahi lo devuelvo

int buscarPrimo(int k)
{
    // Si ya estoy muy abajo, el primer primo que existe es el 2 entonces le envío ese
    if (k <= 2)
    {
        return 2;
    }
    
    // Aquí reviso si k es primo. Si lo es, ya encontré el que buscaba

    if (esprimo(k, k - 1))
    {
        return k;
    }

    // Si no es primo, sigo bajando al siguiente numero

    return buscarPrimo(k - 1);
}



int main()
{
    int x;

    cout<<"Ingrese un número entero positivor"<<endl;
    cin>>x;

    while(x<=0)
    {
        cout<<"Escriba un número correcto porfavor: "<<endl;
        cin>>x;
    }

    if(esprimo(x, x - 1))
    {
        cout << x << " ES un numero primo." << endl;
    }
    else
    {
        cout << x << " NO es un numero primo." << endl;
    }

    // Aqui ya busco el primo que está por debajo del numero que la persona puso

    int resultado = buscarPrimo(x - 1);

    cout << "El numero primo mas grande menor que " << x << " es: "<< resultado << endl;
    return 0;
}