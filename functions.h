#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <vector>
#include <functional>

#include "config.h"


vec_t runge_kutta_method(val_t x0, vec_t y0, func_t f, val_t h, int num_steps = 1);


#endif