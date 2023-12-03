#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

#include <functional>
#include "vec.h"

using val_t = long double;
using vec_t = Vec<val_t, 4>;
using func_t = std::function<vec_t(val_t, vec_t)>;

#endif