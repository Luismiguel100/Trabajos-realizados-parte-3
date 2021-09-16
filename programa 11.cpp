/******************************************************************************
Estudiantes y notas
Desarrollado online
Autor: Todos
Fecha: Septiembre 04/2021
*******************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

#define TAM_MAX 45
#define TAM_MIN 1

using namespace std;

//==========PROTOTIPOS============

int leer_notas(float notas[][5], string nombre[]);
void calculoDef(int n, float notas[][5]);
void calcularEstad(int n, float notas[][5], string nombre[]);
void mostrar(int n,float notas[][5],string nombre[]);
  
int main()
{
    string nombre[TAM_MAX];
    float notas[TAM_MAX][5];
    int n;
    n=leer_notas(notas,nombre);
    calculoDef( n, notas);
    mostrar(n, notas,nombre);
    calcularEstad(n, notas,nombre);
    
    return 0;
}

int leer_notas(float notas[][5], string nombre[])
{
    int n;
    int i,j;
    
    do{
        cout<<"Ingrese numero de estudiantes (1 – 45):  ";
        cin>>n;
    }while (n>TAM_MAX or n < TAM_MIN);
    
    for (i = 0;i<n;i++)
    {
        cout<<"Ingrese estudiante:  ", i+1;
        cin>> nombre[i];
        for( j = 0; j < 4;j++)
        {
            do
            {
            cout<<"Ingrese nota estudiante:  " <<j+1<<"Del estudiante "<< nombre[i]<<"   :";
            cin>>notas[i][j];
            } while(notas[i][j]< 0.0 or notas[i][j] > 5.0);
        }    
    }
return n;
}
//====================
void calculoDef(int n, float notas[][5])
{
    int i,j;
    float suma;
    
    for(i=0;i<n;i++)
    {
        suma=0;
        for(j=0;j<4;j++)
        {
            suma=suma+notas[i][j];
        }
        notas[i][4]=suma/4;
    }
    
}

void mostrar(int n,float notas[][5],string nombre[])
{
    int i,j;
    system("cls");
    cout<<"N Nombre Nota 1, Nota 2, Nota 3, Nota 4 Definitiva"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<endl;
        cout<<i+1<<nombre[i];
        
        for(j=0;j<5;j++)
        {
            cout<<notas[i][j]<<" "<<" ";
        }
    }
}
    
void calcularEstad(int n, float notas[][5],string nombre[])
{
    int ganaron,perdieron,sobreP,bajoP,i;
        float suma=0;
        float promedio;

        ganaron=0;
        perdieron=0;

        for(i=0;i<=n;i++)
        {
                if(notas[i][4]>=3.0)
                {
                        ganaron++;
                }
                else
                {
                        perdieron++;
                }
        }

        for(i=0;i<=n;i++)
        {
                suma=suma+notas[i][4];
        }
        promedio=suma/n;
        sobreP=0;
        bajoP=0;

        for(i=0;i<=n;i++)
        {
                if(promedio<notas[i][4])
                {
                        sobreP=sobreP+1;
                }
                else
                {
                        if(promedio>notas[i][4])
                        {
                                bajoP=bajoP+1;
                        }
                }
        }

        cout<<"\nLa nota promedio es: "<<promedio<<endl;
        cout<<"Estudiantes que ganaron: "<<ganaron<<endl;
        cout<<"Estudiantes que estan sobre el promedio:"<<sobreP<<endl;
        cout<<"Estudiantes por debajo del promedio:"<<bajoP;

}





