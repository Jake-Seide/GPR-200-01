#ifndef RAY_H
#define RAY_H

#include "gpro/gpro-math/gproVector.h"
//#include <cmath>

class ray {
public:
	ray() {}
	//getting the Origin and Direction then puting them as orig and dir
	ray(const vec3& origin, const vec3& direction)
		: orig(origin), dir(direction)
	{}

	//Getting the actual numbers
	vec3 origin() const { return orig; }
	vec3 direction() const { return dir; }

	vec3 at(float t) const {
		return orig + t*dir; //Equation P(t) = A + tb
	}

public:
	vec3 orig;
	vec3 dir;
};

#endif // !RAY_H