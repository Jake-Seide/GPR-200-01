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
