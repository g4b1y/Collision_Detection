#ifndef _ASSET_H
#define _ASSET_H

namespace col
{
    typedef enum
    {
        Point_Point,
        Point_Circle,
        Circle_Circle,
        Point_Rectangle,
        Rectangle_Rectangle,
        Circle_Rectangle,
        Point_Polygon,
        Circle_Polygon,
        Rectangle_Polygon,
        Polygon_Polygon
    } C_TYPE, COLLISION_TYPE;

    typedef struct
    {
        float x;
        float y;
    } vec2;
};

#endif //_ASSET_H
