#ifndef COLLISIONDETECTION_RUN_H
#define COLLISIONDETECTION_RUN_H

#include "../Assets/Asset.hpp"
#include "../Collision/Collision.h"
#include <iostream>

namespace col
{

    struct square {
        sf::ConvexShape p;
        sf::Vector2f center;

        square(int count ) {
            p.setPointCount(count);
        }

        void pointsToScreenCords();
        static void collision(sf::ConvexShape& p1, sf::ConvexShape& p2);
        void regularPolygon(float r, int n);
        sf::Vector2f rotate(sf::Vector2f pt, float angle);
    };

    class Run
    {
    private:
        int num = 0;
        void decide();
        void create(col::C_TYPE type);
        void getInfo();
    public:
        Run();
    };
};

#endif
