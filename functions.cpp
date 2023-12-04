#include <cmath>
#include "functions.h"



vec_t runge_kutta_method4(val_t x0, vec_t y0, func_t f, val_t h, int num_steps)
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


namespace sample
{

using namespace std;

vec_t exact_solution(val_t x)
{
    return 
    {
        exp(sin(x*x)),
        exp(B*sin(x*x)),
        C*sin(x*x) + A,
        cos(x*x)
    };
}


vec_t f(val_t x, vec_t y)
{
    return 
    {
        2*x*pow(y[1], 1/B)*y[3],
        2*B*x*exp(B/C*(y[2]-A))*y[3],
        2*C*x*y[3],
        -2*x*log(y[0])
    };
}


vec_t custom_runge_kutta_method(val_t x0, vec_t y0, func_t f, val_t h, int num_steps)
{
    val_t a21 = c2, b2 = 1/2/c2, b1 = 1-b2;
    vec_t K1, K2;
    
    for (int i = 0; i < num_steps; i++)
    {
        K1 = f(x0, y0);
        K2 = f(x0 + c2*h, y0 + h*a21*K1);

        x0 += h;
        y0 += h*(b1*K1 + b2*K2);
    }

    return y0;
}

}// namespace bracket