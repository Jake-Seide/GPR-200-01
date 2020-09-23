#ifndef COLOR_H
#define COLOR_H

#include "gpro/gpro-math/gproVector.h"
#include <iostream>

//incharge of shortening the old for loop of our screen
void write_color(std::ostream& out, vec3 pixel_color) {
	//translates [0, 255] value for each of the colors
	out << static_cast<int>(255.999 * pixel_color.x) << ' ' //The .999 is for good code practice
		<< static_cast<int>(255.999 * pixel_color.y) << ' ' //^ Does not effect color to a great degree
		<< static_cast<int>(255.999 * pixel_color.z) << '\n'; 
}


#endif // !
