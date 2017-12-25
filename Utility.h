#ifndef _Utility_
#define _Utility_

#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ColorPoint.h"

namespace Utility
{
    int distance(ColorPoint p1, ColorPoint p2);

    int crossProduct(ColorPoint p1, ColorPoint p2, ColorPoint p3);

    void writeConvexePointsToFIle(std::vector<ColorPoint> points);

    void writePointsFormatedForGeogebra(std::vector<ColorPoint> points);
};

#endif