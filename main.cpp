#include <iostream>

int main() 
{
    int image_width = 256;
    int image_height = 256;

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    // rows
    for (int j = 0; j < image_height; j++)
    {
        // columns
        for (int i = 0; i < image_width; i++)
        {
            // redness increases from left to right (in row)
            double r = double(i) / (image_width-1);
            // greenness increases from top to bottom (in column)
            double g = double(j) / (image_height-1);
            // no blue
            double b = 0.0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
}