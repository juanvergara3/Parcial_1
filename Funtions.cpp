#include "Functions.h"

bool confirmacion_de_impacto(float *proyectil, float *destino){

    float x_0, y_0, x_f, y_f, v_0, v_x, v_y, a, r_impacto, y, t, g = -9.81;

    x_f = destino[0];
    y_f = destino[1];

    x_0 = proyectil[0];
    y_0 = proyectil[1];
    v_0 = proyectil[2];
    a = proyectil[3];
    r_impacto = proyectil[4];
    t = proyectil[5];

    v_x = v_0*cos(a);
    v_y = v_0*sin(a);

    x_f -= r_impacto;

    for(float increment = 0.01 ;increment<r_impacto*2; increment+= 0.01){

        t = (x_f - x_0)/(v_x);

        y = y_0 + ((v_y - (g*t))*t) + (0.5*g*(t*t));

        if(abs(y - y_f) <= r_impacto){
          return true;
          proyectil[6] = t;
        }
    }
    return false;
}

void imprimir_proyectil(float *proyectil, float *destino){

    cout<<"Velocidad inicial:"<<proyectil[2]<<endl;
    cout<<"Angulo del proyectil: "<<proyectil[3]<<endl;
    cout<<"Tiempo de impacto: "<<proyectil[5]<<endl;
    cout<<"distancia  recorrida en X: "<<destino[0] - proyectil[0]<<endl;
    cout<<"distancia  recorrida en Y: "<<destino[1] - proyectil[1]<<endl;
    cout<<endl;

}

void generar_disparos_ofensivos(float *inicio, float *destino, float r_impacto){

    float x_0, y_0, v_o = 1, a = 0, t_0 = 0;
    int count = 0;
    bool confirmation;

    if(inicio[1]<destino[1]) a = asin((destino[1]-inicio[1])/(sqrt(pow(destino[1]-inicio[1],2)+pow((abs(destino[0]-inicio[0])),2))));
    else if( inicio[1] > destino[1])  a = -1*(asin((inicio[1]-destino[1])/(sqrt(pow(inicio[1]-destino[1],2)+pow((abs(destino[0]-inicio[0])),2)))));

    x_0 = inicio[0];
    y_0 = inicio[1];

    float *proyectil = new float[6]{x_0, y_0, v_o, a, r_impacto, t_0};

    while (count<3){

        while(true){
            confirmation = confirmacion_de_impacto(proyectil, destino);

            if(confirmation == true){
                count++;

                cout<<"Proyectil numero "<<count<<": "<<endl;
                imprimir_proyectil(proyectil, destino);

                break;
            }
            proyectil[2]++; //velocidad
        }
        proyectil[2] = 1;


        proyectil[3]++; //angulo

    }

    delete[] proyectil;
}

