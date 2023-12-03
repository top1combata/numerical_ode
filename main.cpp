#include <iostream>
#include "functions.h"


signed main()
{
    std::cout.precision(13);
    func_t f = [](val_t x, vec_t y) ->vec_t {return 2*y;};

    val_t h = 1e-3;
    vec_t y0 = {1,1,1,1};
    std::cout << runge_kutta_method(0,y0,f,h,1/h) << '\n';
    return 0;
}