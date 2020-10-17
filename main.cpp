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

    float x_0o = 0, y_0o = h_o, v_0o = 0, t_0o = 0, t_fo = 0, a_o = 0, r_impacto = ; //parametros del proyectil defensivo
    float x_0d = d, y_0d = h_d, v_0d = 0, t_0d = t_0o+2, t_fd = 0, a_d; //parametros del proyectil defensico

    float proyectil_o[2] = {v_0o, a_o};
    float proyectil_d[2] = {v_0d, a_d};



    return 0;
}
