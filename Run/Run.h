#ifndef COLLISIONDETECTION_RUN_H
#define COLLISIONDETECTION_RUN_H

#include "../Assets/Asset.hpp"
#include "../Collision/Collision.h"
#include <iostream>

namespace col
{
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
