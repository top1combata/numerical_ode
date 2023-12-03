#include "functions.h"


vec_t runge_kutta_method(val_t x0, vec_t y0, func_t f, val_t h, int num_steps)
{
    vec_t K1, K2, K3, K4;

    for (int i = 0; i < num_steps; i++)
    {
        K1 = f(x0, y0);
        K2 = f(x0 + h/3, y0 + h/3*K1);
        K3 = f(x0 + 2*h/3, y0 - h/3*K1 + h*K2);
        K4 = f(x0 + h, y0 + h*K1 - h*K2 + h*K3);

        x0 += h;
        y0 += h/8*(K1 + 3*K2 + 3*K3 + K4);
    }

    return y0;
}