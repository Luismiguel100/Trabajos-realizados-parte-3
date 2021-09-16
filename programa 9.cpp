/******************************************************************************
Primos gemelos y primos felices
Desarrollado online
Autor: Todos
Fecha: Julio 24/2021
*******************************************************************************/
#include <stdio.h>

using namespace std;

bool esPrimo(int numero);
void primosGemelos();
int moduloDigitos();
void primoFeliz(void);

int main()
{
    primosGemelos();
    primoFeliz();

    return 0;
}
bool esPrimo(int numero)
{
    int i;
    if(numero==0 or numero==1)
    {
        return false;
    }
    else
    {
        for(i = 2,i<numero,i++)
        {
            if(numero%i==0)
            {
                return false;
            }
        }
    }
    return true;
}

void primosGemelos()
{
    int i,n;
    
    cout<<"\n Ingrese numero:";
    cin>>n;
    
    while(n<2 or 35000)
    {
        cout<<"Ingrese numero valido (2,35000)";
        cin>>n;
    }
    
    for(i=2;i<n;i++)
    {
        if(esPrimo(i)==true and esPrimo(i+2)==true)
        {
            cout<<"\n"<<i<<" "<<i+2<<" "<<"son gemelos"<<endl; 
        }
    }
}

int moduloDigitos(int numero)
{
    int d1=0,d2=0,d3=0,d4=0,sumaCuadrados,i;
    int cociente;
    
    d1=numero%10;
    cociente=numero/10;
    d2=cociente%10;
    d3=numero%10;
    cociente=numero/10;
    d4=cociente%10;
    
    sumaCuadrados=d1*d1 + d2*d2 + d3*d3 + d4*d4;
    
    return sumaCuadrados;
}

void primoFeliz(void)
{
    int numero,i,suma;
    cout<<"Ingrese numero:";
    cin>>numero;
    
    while(numero<=9 or numero>10000)
    {
        cout<<"Ingrese un numero valido (10, 9999):";
        cin>>numero;
    }
    suma=numero;
    
    if(esPrimo(numero)==true)
    {
        do
        {
        suma=moduloDigitos(suma);
        cout<<"suma:"<<suma;
        i++;
        }while(suma>=10 and i<100);
        
        if(suma==1)
        {
            cout<<numero<<"\n Es un numero feliz";
        }
        else
        {
            cout<<"No es un numero feliz";
        }
    }
    else
    {
        cout<<"No es un numero primo";
    }
}










