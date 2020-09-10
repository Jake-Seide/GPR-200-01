/*
   Copyright 2020 Jake Seide & Joe Tecce

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

	   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

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
