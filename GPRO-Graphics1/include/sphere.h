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

#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "gpro/gpro-math/gproVector.h"

class sphere : public hittable {
public:
	vec3 center;
	float radius{};

public:
	sphere() {};
	sphere(vec3 cen, float r) : center(cen), radius(r) {};

	virtual bool hit(
		const ray& r, float tmin, float tmax, hit_record& rec) const override;
};


bool sphere::hit(const ray& r, float t_min, float t_max, hit_record& rec) const {
	
	//ask Dan the Man about how this math works cuz yo soy confusión
	//this block creates the the hittable sphere
	vec3 originCenter = r.origin() - center;
	float a = r.direction().length_squared(); //Same as Vector Dotted the same Vector "dot(r.direction(), r.direction());"
	float half_b = dot(originCenter, r.direction()); //Would be Muilitplied by 2 follow commented method;
	float c = originCenter.length_squared() - radius * radius; //dot(originCenter, originCenter) - radius * radius;
	float discriminant = half_b * half_b - a * c;

	//this section is the logic to determine whether the point/ray is within the sphere
	if (discriminant > 0) {
		float root = sqrt(discriminant);
		float temp = (-half_b - root) / a;

		if (temp < t_max && temp > t_min) {
			rec.t = temp;
			rec.p = r.at(rec.t);
			vec3 outward_normal = (rec.p - center) / radius; //storing outward normal
			rec.set_face_normal(r, outward_normal); //storing outward normal
			return true;
		}

		temp = (-half_b + root) / a;
		if (temp < t_max && temp > t_min) {
			rec.t = temp;
			rec.p = r.at(rec.t);
			vec3 outward_normal = (rec.p - center) / radius; //storing outward normal
			rec.set_face_normal(r, outward_normal); //storing outward normal
			return true;
		}
	}
	return false;
}

#endif 