#include "Functions.h"

bool confirmacion_de_impacto(float *proyectil, float *destino){

    float x_0, y_0, x_f, y_f, v_0, v_x, v_y, a, r_impacto, x, y, t, g = -9.81, pi = 3.14159265;

    x_f = destino[0];
    y_f = destino[1];

    x_0 = proyectil[0];
    y_0 = proyectil[1];
    v_0 = proyectil[2];
    a = proyectil[3];
    r_impacto = proyectil[4];

    v_x = v_0*cos(a*pi / 180);
    v_y = v_0*sin(a *pi / 180);

    t = -1*(((v_y)+sqrt((pow(v_y,2)+(-2*g*(y_0-y_f)))))/(g));

    x = x_0 + v_x*t;
    y = y_0 + ((v_y)*t) + ((-4.905)*pow(t,2));

    if(sqrt( (pow((x_f-x),2))+(pow((y_f)-y,2)) ) <= r_impacto){
        proyectil[5] = abs(t);
        return true;
    }

    return false;
}

void imprimir_proyectil(float *proyectil, float *destino){

    cout<<"Velocidad inicial: "<<proyectil[2]<<" m/s"<<endl;
    cout<<"Angulo del proyectil: "<<proyectil[3]<<" grados"<<endl;
    cout<<"Tiempo de impacto: "<<proyectil[5]<<" s"<<endl;
    cout<<"distancia  recorrida en X: "<<abs(destino[0] - proyectil[0])<<" m"<<endl;
    cout<<"distancia  recorrida en Y: "<<abs(destino[1] - proyectil[1])<<" m"<<endl;
    cout<<endl;

}

void generar_disparos_ofensivos(float *inicio, float *destino, float r_impacto){

    float x_0, y_0, v_o = 1, a = 0, t_0 = 0;
    int count = 0;
    bool confirmation, loop1 = true, loop2 = true, sum = true;

    if(inicio[1] < destino[1]) a = asin((destino[1]-inicio[1])/(sqrt(pow(destino[1]-inicio[1],2)+pow((abs(destino[0]-inicio[0])),2))));
    else if( inicio[1] > destino[1])  a = -1*(asin((inicio[1]-destino[1])/(sqrt(pow(inicio[1]-destino[1],2)+pow((abs(destino[0]-inicio[0])),2)))));

    x_0 = inicio[0];
    y_0 = inicio[1];

    float *proyectil = new float[6]{x_0, y_0, v_o, a, r_impacto, t_0};

    if(inicio[0]>destino[0]){
      a = 360 - a;
      sum = false;
    }

    while (loop1){

        loop2 = true;

        while(loop2){

            confirmation = confirmacion_de_impacto(proyectil, destino);

            if(confirmation == true){
                count++;
                cout<<"Proyectil numero "<<count<<": "<<endl;
                imprimir_proyectil(proyectil, destino);

                loop2 = false;
            }

            proyectil[2]++; //velocidad
            if(proyectil[2]>1500) break;
        }

        proyectil[2] = 1;

        if (sum) proyectil[3]++; //angulo
        else proyectil[3]++;

        if(count == 3) loop1 = false;

    }

    delete[] proyectil;
}

void intersepcion_proyectil(float *proyectil_o, float *destino){

    if(confirmacion_de_impacto(proyectil_o, destino)){
        float v_0d = 1, r_impacto_d = 0.025*destino[0];
        float proyectil_d[7] = {destino[0], destino[1], v_0d, 45, r_impacto_d, 2.5, 0};
        float destino_d[2];

        float x_o, y_o, x_d, y_d, t = 2.5, g = 9.81;

        //proyectil_o[7] = {x_0o, y_0o, v_0o, a_o, r_impacto_o, t_0o, t_fo}

        for(int i = 0; i<3; ){

            x_o = proyectil_o[0] + (cos(proyectil_o[3])*proyectil_o[2])*t;
            y_o = proyectil_o[1] + (((sin(proyectil_o[3])*proyectil_o[2]) - g*t)*t) + (1/2)*g*(t*t);

            x_d = proyectil_d[0] + (cos(proyectil_d[3])*proyectil_d[2])*t;
            y_d = proyectil_d[1] + (((sin(proyectil_d[3])*proyectil_d[2]) - g*t)*t) + (1/2)*g*(t*t);

            if( sqrt((pow(x_o-x_d,2))+(pow(y_o-y_d,2))) <= r_impacto_d){
                destino_d[0] = x_o;
                destino_d[1] = y_o;
                imprimir_proyectil(proyectil_d, destino_d);
                i++;
            }
            else proyectil_d[2]+= 0.1;

        }
    }
    else cout<<"El proyectil enemigo no tiene posibilidad de impacto"<<endl;
}





















