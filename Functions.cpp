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
        proyectil[6] = abs(t);
        return true;
    }

    return false;
}

void imprimir_proyectil(float *proyectil, float *destino){

    cout<<"Velocidad inicial: "<<proyectil[2]<<" m/s"<<endl;
    cout<<"Angulo del proyectil: "<<proyectil[3]<<" grados"<<endl;
    cout<<"Tiempo de impacto: "<<proyectil[6]<<" s"<<endl;
    cout<<"distancia  recorrida en X: "<<abs(destino[0] - proyectil[0])<<" m"<<endl;
    cout<<"distancia  recorrida en Y: "<<abs(destino[1] - proyectil[1])<<" m"<<endl;
    cout<<endl;

}

void generar_disparos_ofensivos(float *inicio, float *destino, float r_impacto, float angulo_inicial){

    float x_0, y_0, v_o = 1, a = 0, t_0 = 0, t_f = 0;
    int count = 0;
    bool confirmation, loop1 = true, loop2 = true;

    if(angulo_inicial == 0){
        if(inicio[1] < destino[1]) a = asin((destino[1]-inicio[1])/(sqrt(pow(destino[1]-inicio[1],2)+pow((abs(destino[0]-inicio[0])),2))));
        else if( inicio[1] > destino[1])  a = -1*(asin((inicio[1]-destino[1])/(sqrt(pow(inicio[1]-destino[1],2)+pow((abs(destino[0]-inicio[0])),2)))));
    }

    else a = angulo_inicial;

    x_0 = inicio[0];
    y_0 = inicio[1];

    float *proyectil = new float[7]{x_0, y_0, v_o, a, r_impacto, t_0, t_f};

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

        proyectil[3]++; //angulo

        if(count == 3) loop1 = false;

    }

    delete[] proyectil;
}

void intersepcion_proyectil(float *proyectil_o, float *destino_o){

    if(confirmacion_de_impacto(proyectil_o, destino_o)){

        float  r_impacto_d = 0.025*destino_o[0];

        float x_o, y_o, t = 2.5;
        float x_0o, y_0o, v_0o, v_xo, v_yo, a_o, g = -9.81, pi = 3.14159265;

        x_0o = proyectil_o[0];
        y_0o = proyectil_o[1];

        v_0o = proyectil_o[2];
        a_o = proyectil_o[3];
        v_xo = v_0o*cos(a_o*pi / 180);
        v_yo = v_0o*sin(a_o *pi / 180);

        float destino_d[2];

        x_o = x_0o + (v_xo)*t;
        y_o = y_0o+ ((v_yo - g*t)*t) + (-4.095)*(pow(t,2));

        destino_d[0] = x_o;
        destino_d[1] = y_o;

        generar_disparos_ofensivos(destino_o, destino_d, r_impacto_d, 90);

    }
    else cout<<"El proyectil enemigo no tiene posibilidad de impacto"<<endl;
}



















