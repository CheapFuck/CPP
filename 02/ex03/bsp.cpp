#include "Point.hpp"
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    bool sign[3];
    
    // Convert Fixed to float (or int) for arithmetic calculations
    float ax = a.getX().toFloat();
    float ay = a.getY().toFloat();
    float bx = b.getX().toFloat();
    float by = b.getY().toFloat();
    float cx = c.getX().toFloat();
    float cy = c.getY().toFloat();
    float px = point.getX().toFloat();
    float py = point.getY().toFloat();
    
    // Calculate cross products for each edge
    float crossProduct0 = (ax - px) * (by - ay) - (bx - ax) * (ay - py);
    float crossProduct1 = (bx - px) * (cy - by) - (cx - bx) * (by - py);
    float crossProduct2 = (cx - px) * (ay - cy) - (ax - cx) * (cy - py);

    // Check if any of the cross products are zero (point on the edge)
    if (crossProduct0 == 0 || crossProduct1 == 0 || crossProduct2 == 0)
	{
        return false; // Point is on the edge
    }

    // Determine the signs of the cross products
    sign[0] = crossProduct0 > 0;
    sign[1] = crossProduct1 > 0;
    sign[2] = crossProduct2 > 0;

    // Return true if all signs are the same (same side of all edges)
    return (sign[0] == sign[1] && sign[1] == sign[2]);
}
