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

