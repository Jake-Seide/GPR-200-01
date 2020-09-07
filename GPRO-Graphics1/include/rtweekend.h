#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>

#include "ray.h"
#include "gpro/gpro-math/gproVector.h"

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

//Constrants
const float infinity = std::numeric_limits<float>::infinity();
const float pi = 3.1415926535897932385f;

//Utility Functions
inline float degrees_to_radians(float degrees) {
	return degrees * pi / 180.0f;
}

#endif

