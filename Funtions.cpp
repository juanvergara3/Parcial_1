#include "Functions.h"

bool confirmacion_de_impacto(float *proyectil, float *destino){

    float x_0, y_0, x_f, y_f, v_0, v_x, v_y, a, r_impacto, x, y, t, t_f, g = -9.81, distancia;

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

    while(true){

       t = (x_f - x_0)/(v_x);

       y = y_0 + ((v_y - (g*t))*t) + (0.5*g*(t*t));

       distancia = sqrt(pow((x-x_f) ,2)+pow((y-y_f) ,2));

       if(distancia <= r_impacto) break;
       else t++;

    }

}


