#pragma once
#include "Object.h"
#include "Vector2.h"
namespace YunutyEngine
{
    class Rect :
        public Object
    {
    public:
        double width;
        double height;
        Vector2d pivot= Vector2d(0.5,0.5);
    };
}
