#ifndef COLOR_H
#define COLOR_H

#include "rtweekend.h"
#include "interval.h"
#include "vec3.h"

using color = vec3;

void write_color(std::ostream& out, const color& pixel_color)
{
    // Color values in [0,1]
    double r = pixel_color.x();
    double g = pixel_color.y();
    double b = pixel_color.z();

    // Map: [0,1] -> [0,255]
    static const interval intensity(0.000, 0.999);
    int rByte = int(256 * intensity.clamp(r));
    int gByte = int(256 * intensity.clamp(g));
    int bByte = int(256 * intensity.clamp(b));

    // Write out the pixel color
    out << rByte << ' ' << gByte << ' ' << bByte << '\n';
}

#endif