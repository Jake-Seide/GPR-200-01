#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

struct hit_record
{
	vec3 p; //this stands for "point" or "ray"
	vec3 normal; //normal map?
	float t{}; //ray parameters
	bool front_face = false;

	inline void set_face_normal(const ray& r, const vec3& outward_normal) {
		front_face = dot(r.direction(), outward_normal) < 0; //compares the dot product of the vectors on the insde and outside of the object
		normal = front_face ? outward_normal : -outward_normal; //positive dot product means the normal is front facing
	}
};

class hittable
{
public:
	virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const = 0;

};

#endif // !HITTABLE_H
