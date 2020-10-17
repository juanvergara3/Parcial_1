#include <iostream>
#include "Functions.h"
using namespace std;

int main()
{
    float d, h_o, h_d; //parametros fijos
    float x_0d, y_0d, v_0d, t_0d, t_fd; //parametros del proyectil defensico

    while(true){
        cout<<"Ingrese la distancia entre los cañones: "; cin>>d;
        if(d>0) break;
        else cout<<"Ingrese una distancia positiva"<<endl;
    }

    cout<<"Ingrese la altura del cañon ofensivo: "; cin>>h_o;
    cout<<"Ingrese la altura del cañon defensivo: "; cin>>h_d;







    return 0;
}
