#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

using color = vec3;

void write_color(std::ostream& out, const color& pixel_color)
{
    // Color values in [0,1]
    double r = pixel_color.x();
    double g = pixel_color.y();
    double b = pixel_color.z();

    // Map: [0,1] --> [0,255]
    int rByte = int(255.999 * r);
    int gByte = int(255.999 * g);
    int bByte = int(255.999 * b);

    // Write out the pixel color
    out << rByte << ' ' << gByte << ' ' << bByte << '\n';
}

#endif