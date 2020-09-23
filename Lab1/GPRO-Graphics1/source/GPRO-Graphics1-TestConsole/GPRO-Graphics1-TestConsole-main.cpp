/*
   Copyright 2020 Daniel S. Buckstein

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

/*
	GPRO-Graphics1-TestConsole-main.c/.cpp
	Main entry point source file for a Windows console application.

	Modified by: ____________
	Modified because: ____________
*/


#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

#include "rtweekend.h"

#include "color.h"
#include "hittable_list.h"
#include "sphere.h"

/*
#include "rtweekend.h"
#include "hittable_list.h"
#include "sphere.h"
//#include "gpro/gpro-math/gproVector.h"
//#include "ray.h" 
#include "color.h"
*/

void testVector()
{
	// test array vector initializers and functions
	float3 av, bv, cv, dv;
	vec3default(av);								// -> a = (0, 0, 0)
	vec3init(bv, 1.0f, 2.0f, 3.0f);					// -> b = (1, 2, 3)
	vec3copy(dv, vec3init(cv, 4.0f, 5.0f, 6.0f));	// -> d = c = (4, 5, 6)
	vec3copy(av, dv);								// a = d			-> a = (4, 5, 6)
	vec3add(dv, bv);								// d += b			-> d = (4 + 1, 5 + 2, 6 + 3) = (5, 7, 9)
	vec3sum(dv, bv, bv);							// d = b + b		-> d = (1 + 1, 2 + 2, 3 + 3) = (2, 4, 6)
	vec3add(vec3sum(dv, cv, bv), av);				// d = c + b + a	-> d = (4 + 1 + 4, 5 + 2 + 5, 6 + 3 + 6) = (9, 12, 15)

#ifdef __cplusplus
	// test all constructors and operators
	vec3 a, b(1.0f, 2.0f, 3.0f), c(cv), d(c);		// default; init; copy array; copy
	a = d;											// assign						-> a = (4, 5, 6)
	d += b;											// add assign					-> d = (5, 7, 9)
	d = b + b;										// sum, init, assign			-> d = (2, 4, 6)
	d = c + b + a;									// sum, init, sum, init, assign	-> d = (9, 12, 15)
#endif	// __cplusplus
}

//Creates a linear blend(lerp) of blue to white for the background
vec3 ray_color(const ray& r, const hittable& world) {
	hit_record rec;
	if (world.hit(r, 0, infinity, rec)) {
		return 0.5f * (rec.normal + vec3(1, 1, 1));
	}
	//float t = hit_sphere(vec3(0, 0, -1), 0.5f, r); //This is the return product of hit_sphere

	/*
	//If t is inside the sphere it will add the color corisponding with there x/y/z to r/g/b
	if (t > 0.0f) {
		vec3 N = unit_vector(r.at(t) - vec3(0, 0, -1));
		return 0.5f * vec3(N.x + 1, N.y + 1, N.z + 1); //+1 is to make positive for colors
	}
	*/

	//If not in sphere will create the Blue to White Gradiant
	vec3 unit_direction = unit_vector(r.direction());
	float t = 0.5f * (unit_direction.y + 1.0f);
	return (1.0f - t) * vec3(1.0f, 1.0f, 1.0f) + t * vec3(0.5f, 0.7f, 1.0f);
}

int main(int const argc, char const* const argv[])
{
	testVector();

	//Image bounds
	const float aspect_ratio = 16.0f / 9.0f;
	const int image_width = 400;
	const int image_height = static_cast<int>(image_width / aspect_ratio);

	//World
	hittable_list world;
	world.add(make_shared<sphere>(vec3(0, 0, -1), 0.5f));
	world.add(make_shared<sphere>(vec3(0, -100.5, -1), 100.0f));

	//Camera
	float viewport_height = 2.0f;
	float viewport_width = aspect_ratio * viewport_height;
	float focal_length = 1.0f;

	vec3 origin = vec3(0, 0, 0); //camera origin position
	vec3 horizontal = vec3(viewport_width, 0, 0); //screen width
	vec3 vertical = vec3(0, viewport_height, 0); //screen height
	vec3 lower_left_corner = origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length); //gets lower left corner of screen


	//Render
	std::ofstream fout;
	fout.open("ppmImage.ppm"); //opens a ppm file 

	//PPM file format
	fout << "P3\n" << image_width << ' ' << image_height << "\n255\n"; //Important...dont touch!!!

	//pixel rows are written from left to right
	//pixel cols are written from top to bottom
	for(int j = image_height - 1; j >= 0; j--)
	{
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush; //to check for looping correctly  
		for (int i = 0; i < image_width; i++)
		{
			//create gradient effect
			float u = float(i) / (image_width - 1);
			float v = float(j) / (image_height - 1);
			
			ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin); //creates ray
			vec3 pixel_color = ray_color(r, world); //adds color to ray
			write_color(fout, pixel_color); //Puts colored pixels in ppm file
		}
	}

	std::cerr << "\nDone. \n ";
	fout.close();

	printf("\n\n");
	system("pause");
}
