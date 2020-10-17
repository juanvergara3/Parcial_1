#include <iostream>
#include "Functions.h"
using namespace std;

int main()
{
    float d, h_o, h_d; //parametros fijos

    while(true){
        cout<<"Ingrese la distancia entre los cañones: "; cin>>d;
        if(d>0) break;
        else cout<<"Ingrese una distancia positiva"<<endl;
    }

    cout<<"Ingrese la altura del cañon ofensivo: "; cin>>h_o;
    cout<<"Ingrese la altura del cañon defensivo: "; cin>>h_d;

    float x_0o = 0, y_0o = h_o, v_0o = 0, t_0o = 0, t_fo = 0, a_o = 0, r_impacto_o = 0.05*d; //parametros del proyectil defensivo
    float x_0d = d, y_0d = h_d, v_0d = 0, t_0d = t_0o+2, t_fd = 0, a_d = 0, r_impacto_d = 0.025*d; //parametros del proyectil defensico

    float proyectil_o[7] = {x_0o, y_0o, v_0o, a_o, r_impacto_o, t_0o, t_fo}; //posicion inicial, velocidad inicial, angulo, radio de impacto, tiempo inicial y final
    float proyectil_d[7] = {x_0d, y_0d, v_0d, a_d, r_impacto_d, t_0d, t_fd};

    float c_o[2] = {0, h_o}, c_d[2] = {d, h_d};

    short selec;
    bool loop = true;

    while (loop){

        cout<<"1 = generar disparos del cañon ofensivo."<<endl;
        cout<<"2 = generar disparos del cañon defensivo."<<endl;
        cout<<"3 = generar disparos defensivos (sin importar si el cañon ofensivo es destruido o no)."<<endl;
        cout<<"4 = generar disparos defensivos (sin destruir el cañon ofensivo)"<<endl;
        cout<<"-1 = salir"<<endl;
        cout<<"Ingrese 1, 2, 3, 4 o -1: ";cin>>selec;

        switch (selec) {

        default:{
            cout<<"Opcion invalida"<<endl;
            break;
        }
        case -1:{
            loop = false;
            break;
        }

        case 1:{
            generar_disparos_ofensivos(c_o, c_d, r_impacto_o);
            break;
        }

        case 2:{
            generar_disparos_ofensivos(c_d, c_o, r_impacto_o);
            break;
        }

        }
    }


    return 0;
}
