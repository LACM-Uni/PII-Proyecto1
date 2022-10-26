#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "matriz.hpp"

int main()
{
    int select;
    int a = 0;
    int b = 0;
    float c = 0.0;

    cout<<"Calculadora de Operaciones con Matrices cuadradas."<<endl<<endl;

    cout<<"Elija una de las siguientes operaciones: "<<endl<<endl;
    
    cout<<"1- Sumar dos matrices cuadradas"<<endl;
    cout<<"2- Multiplicar dos matrices cuadradas"<<endl;
    cout<<"3- Mutiplicar un escalar a una matriz cuadrada"<<endl;
    cout<<"4- Resolver matriz aumentada por eliminacion Gauss-Jordan"<<endl<<endl;

    cout<<"Escriba el numero de la operacion que desea realizar: \n";
    cin>>select;

    if(select==1)
    {
        cout<<"\nInserte las dimensiones de las matrices cuadradas"<<endl;
        cout<<"Primera matriz: ";
        cin>>a;
        cout<<"\nSegunda matriz: ";
        cin>>b;
       
        while(a!=b)
        {
            cout<<"\n\nLas matrices no son de igual dimension.";
            cout<<"\nPor favor, reingrese los datos de dimension"<<endl;
            cout<<"\nInserte las dimensiones de las matrices cuadradas"<<endl;
            cout<<"Primera matriz: ";
            cin>>a;
            cout<<"\nSegunda matriz: ";
            cin>>b;
        }

        cout<<"\nIngrese los datos de la primera matriz"<<endl;
        Matriz mat1(a,a);
        mat1.llenar_matriz();
        mat1.mostrar_matriz();

        cout<<"\nIngrese los datos de la segunda matriz"<<endl;
        Matriz mat2(b,b);
        mat2.llenar_matriz();
        mat2.mostrar_matriz();

        mat1.sumar_matriz(mat2);

        cout<<"\n\nEl resultado de la suma de ambas matrices es: "<<endl;
        mat1.mostrar_matriz();

        mat1.~Matriz();
        mat2.~Matriz();

        system ("pause");
        return 0;
    }
    
    else if(select==2)
    {
        cout<<"\nIntroduzca las dimensiones de las matrices a multiplicar: ";
        cin>>a;
        cout<<"\nIntroduzca los datos de la primera matriz."<<endl;
        Matriz m1(a,a);
        m1.llenar_matriz();

        cout<<"\nIntroduzca los datos de la segunda matriz."<<endl;
        Matriz m2(a,a);
        m2.llenar_matriz();

        Matriz m3(a,a);

        m1.producto_matriz(m2, m3);
        m3.mostrar_matriz();

        m1.~Matriz();
        m2.~Matriz();
        m3.~Matriz();

        system ("pause");
        return 0;
    }

    else if(select==3)
    {
        cout<<"\nIngrese las dimension de la matriz cuadrada: ";
        cin>>a;
        Matriz matEsc(a,a);
        cout<<"\nIngrese los datos de la matriz: ";
        matEsc.llenar_matriz();
        matEsc.mostrar_matriz();
        cout<<"Ingrese el escalar que desea multiplicar a la matriz: ";
        cin>>c;
        cout<<"\n\nEl resultado es:"<<endl;
        matEsc.escalar_por_matriz(c);

        matEsc.~Matriz();

        system ("pause");
        return 0;
    }

    else if(select==4)
    {
        cout<<"Ingrese el numero de ecuaciones: "<<endl;
        cin>>a;
        b = a+1;
        cout<<"Introduzca los valores constantes en la ecuacion de la forma a11 + a12... = b1: \n";
        Matriz matgauss(a,b);
        matgauss.llenar_matriz();
        matgauss.mostrar_matriz();

        matgauss.gauss_jordan(a);
        matgauss.~Matriz();
            

            system("pause");
            return 0;
        

    }
    
    else
    {
        cout<<"\n\nLa seleccion realizada no esta entre las opciones disponibles"<<endl;
        return main();
    }
}