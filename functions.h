#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <vector>
#include <functional>

#include "config.h"

vec_t runge_kutta_method4(val_t x0, vec_t y0, func_t f, val_t h, int num_steps = 1);
vec_t runge_kutta_method3(val_t x0, vec_t y0, func_t f, val_t h, int num_steps = 1);


namespace sample
{

constexpr val_t A = -1;
constexpr val_t B = -3;
constexpr val_t C = 3;
constexpr val_t c2 = val_t(3)/10;

const val_t x0 = 0;
const vec_t y0 = {val_t(1), val_t(1), A, val_t(1)};

vec_t f(val_t x, vec_t y);
vec_t exact_solution(val_t x);
vec_t custom_runge_kutta_method(val_t x0, vec_t y0, func_t f, val_t h, int num_steps = 1);

}





#endif