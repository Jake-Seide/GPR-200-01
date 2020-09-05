#ifndef COLOR_H
#define COLOR_H

#include "gpro/gpro-math/gproVector.h"
#include <iostream>

//incharge of shortening the old for loop of our screen
void write_color(std::ostream& out, vec3 pixel_color) {
	//translates [0, 255] value for each of the colors
	out << static_cast<int>(255.999 * pixel_color.x) << ' '
		<< static_cast<int>(255.999 * pixel_color.y) << ' '
		<< static_cast<int>(255.999 * pixel_color.z) << '\n';
}


#endif // !
