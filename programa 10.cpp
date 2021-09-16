/******************************************************************************
Objetivo: Practicar modulos, ciclos,decisiones multiples y reutilizacion de codigo
Desarrollado online
Autor: Todos
Fecha: Julio 31/2021
*******************************************************************************/
#include <iostream>

using namespace std;

//=======Prototipos
bool esPrimo(int numero);
void primosGemelos(void);
void primoFeliz(void);
void divisibilidad_11(void);
short menu(void);
int moduloDigitos(int numero);


int main()
{   int opc;
    do{
        
    
    opc = menu();
    switch(opc)
    {
        case 1: cout<<" ===PRIMOS GEMELOS\n ";
                primosGemelos();
                cout << endl;
                system("Pause");
                break;
        case 2: cout<<" ===PRIMOS FELIZ\n";
                primoFeliz();
                cout << endl;
                system("Pause");
                break;
        case 3: cout << " === DIVISIBILIDAD POR 11\n ";
                divisibilidad_11();
                cout << endl;
                system("Pause");
                break;
        case 0: cout << " === FINNNN\n";
                cout << endl;
                
                break;
                
    }
    }while(opc != 0);
    return 0;
}

short menu()
{
    short opcion;
    system("cls");
    cout<<"\t\tMENU DE POCIONES\n\n";
    cout<<"1. Primos Gemelos"<<endl;
    cout<<"2. Primos Felices"<<endl;
    cout<<"3. Divisibilidad por 11"<<endl;
    cout<<"0. TERMINAR"<<endl;
    cout<<"Ingrese opcion ===> ";
    cin>>opcion;
    while(opcion < 0 or opcion > 3)
    {
        cout<< "Ingrese opcion valido ===> ";
        cin>> opcion;
    }
    
    return opcion;
}

// ======================
bool esPrimo(int numero)
{
	int i;
	
	if(numero==0 or numero==1)
	{
		return false;
	}
	else
	{
		for(i=2;i<numero;i++)
		{
			if(numero%i==0)
			{
				return false;
			}
		
		}
	}
    return true;	
}
//=============

void primosGemelos()
{
	int i,n;
	
	cout<<"\n Ingrese numero:";
	cin>>n;
	
	while(n<2 or n>35000)
	{
		cout<<"Ingrese numero valido (2,35000):";
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
// =====================

void primoFeliz(void)
{
	int numero,i=0,suma;
	cout<<"\nIngrese numero:";
	cin>>numero;
	
	while(numero<=9 or numero>=10000)
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
		 cout<<"\nsuma:"<<suma;
		 i++;	
		}while(suma>=10 and i<100);
		
		if(suma==1)
		{
			cout<<numero<<" \nEs un numero feliz";
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
//===================
int moduloDigitos(int numero)
{
	int d1=0,d2=0,d3=0,d4=0,sumaCuadrados,i;
	int cociente;
	
	d1=numero%10;
	cociente=numero/10;
	d2=cociente%10;
	cociente=cociente/10;
	d3=cociente%10;
	cociente=cociente/10;
	d4=cociente%10;
	
	sumaCuadrados=d1*d1 + d2*d2 + d3*d3 + d4*d4;
	
	return sumaCuadrados;	
}
//================
int divisibilidad_11(void)
    	
{  long long int numero;
   long long int resultado;
   long long int cociente, residuo;
   
   do {
   	cout << endl << "Ingrese numero para averigua si es divisible por 11:   ";
   	cin >> numero;
   }  while(numero <= 0 );
   resultado = numero;
   cout << resultado ;
   
   while(resultado > 0 or resultado > 10)
   {
   	cociente = resultado / 10;
   	residuo = resultado % 10;
   	resultado = cociente - residuo;
    cout << endl << resultado;
   }
   cout << endl << endl;
   if( resultado == 0 or resultado %  11 == 0)
   {system("Color 0A");  
   cout << endl << endl <<"\a\a\t\t  ES DIVISIBLE POR 11  ";
   }
}




