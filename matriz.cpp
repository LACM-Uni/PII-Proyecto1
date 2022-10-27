#include"matriz.hpp"

#include<iostream>
using std::cin;
using std::cout;
using std::endl;


Matriz::Matriz(int filas, int columnas)
    {
     this-> filas = filas;
     this-> columnas = columnas;

     matriz = new float *[filas];

     for(int i=0;i<filas;i++)
     {
            matriz[i] = new float [columnas];
        
     }
    }

void Matriz::llenar_matriz()
    {
        for(int i=0;i<filas;i++)
        {
            for(int j=0;j<columnas;j++)
            {
                cout<<"Asigne un valor para ["<<i+1<<"]["<<j+1<<"]: ";
                cin>>matriz[i][j];
                cout<<endl;
            }
        }
    }

void Matriz::mostrar_matriz()
    {
        cout<<endl;
        for(int i=0;i<filas;i++)
        {
            cout<<"| ";
            for(int j=0;j<columnas;j++)
            {
                if(j == filas)
                {
                    cout<<"| "<<matriz[i][j]<<" ";
                }
                else
                {
                    cout<<matriz[i][j]<<" ";
                }
            }
            cout<<"|"<<endl;
        }
        cout<<endl;
    }




void Matriz::producto_matriz(const Matriz mp, Matriz res)
    {

        for(int i=0; i<filas; i++)
        {
            for(int j=0; j<columnas; j++)
            {
                res.matriz[i][j] = 0;
                for(int k=0; k<columnas; k++)
                {
                    res.matriz[i][j] = res.matriz[i][j] + matriz[i][k] * mp.matriz[k][j];
                }
            }
        }
    }


void Matriz::sumar_matriz(const Matriz sum)
    {
        for(int i=0; i<filas; i++)
        {
            for(int j = 0; j<columnas; j++)
            {
                matriz[i][j] = matriz[i][j] + sum.matriz[i][j];
            }
        }

    }


void Matriz::escalar_por_matriz(float escalar)
    {
        for(int i=0;i<filas;i++)
        {
            cout<<"| ";
            for(int j=0;j<columnas;j++)
            {
                matriz[i][j] = matriz[i][j] * escalar;
                cout<<matriz[i][j]<<" ";
            }
            cout<<"|"<<endl;
        }

    }



void Matriz::gauss_jordan(const int n)
    {
        float x[n];
        float temp;
        for(int i=0; i < n ;i++)
        {                
            for(int j=0; j<n ;j++)
            {
                if (j!=i)
                {
                    temp = matriz[j][i] / matriz[i][i];
                    for(int k=0; k<n+1 ;k++)
                    {
                        matriz[j][k] = matriz[j][k] - temp * matriz[i][k];
                    }
                }
            }

            if(i==n-1)
            {
                for (int r=0; r<n; r++)
                {
                    x[r]= matriz[r][n] / matriz[r][r];
                    cout<<"\nx"<<r+1<<"= "<<x[r];
                }
                cout<<endl<<endl;
            }
        }
    }


Matriz::~Matriz()
    {
        for(int i=0; i<filas; i++)
            {
                delete[] matriz[i];
            }
            delete[] matriz;
    }
