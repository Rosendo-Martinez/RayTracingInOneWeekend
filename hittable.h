#ifndef HITTABLE_H
#define HITTABLE_H

#include "rtweekend.h"

class hit_record
{
public:
    point3 p;
    vec3 normal;
    double t;
    bool front_face;

    /**
     * Figures out proper normal direction, and what side (front or back)
     * the object was hit.
     * 
     * @param r ray that hit hittable object
     * @param outward_normal OUTWARD normal of hit surface at hit point
     */
    void set_face_normal(const ray& r, const vec3& outward_normal)
    {
        // Sets the hit record normal vector.
        // NOTE: the parameter `outward_normal` is assumed to have unit length.

        // NOTE: choosen that normal should always go in oppsite direction as 
        // ray.

        // EXAMPLE with sphere:
        // Ray was inside sphere if outward_normal is going in same-ish
        // direction as it (the ray).
        // Else the ray was outside the sphere, and 
        // it (ray) is going in oppsite-ish direction as the outward-normal.

        // For sphere front face is its outside, and the back face is its inside.

        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable
{
public:
    virtual ~hittable() = default;

    virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
};

#endif