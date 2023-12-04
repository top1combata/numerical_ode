#include <iostream>
#include "functions.h"


signed main()
{
    std::cout.precision(13);
    //func_t f = [](val_t x, vec_t y) ->vec_t {return 2*y;};

    using namespace sample;

    val_t h = 1e-5;
    std::cout << custom_runge_kutta_method(x0, y0, f, h, 1/h) - exact_solution(x0+1) << '\n';
    return 0;
}