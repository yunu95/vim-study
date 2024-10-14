#pragma once
#include "Vector.h"
namespace YunutyEngine
{
    template<typename real>
    class Vector3 : public Vector<real>
    {
    private:
        real xyz[3] = { 0 };
    public:
        real& x;
        real& y;
        real& z;
        Vector3(real x, real y, real z) : Vector<real>(xyz, 3), x(xyz[0]), y(xyz[1]), z(xyz[2])
        {
            this->x = x;
            this->y = y;
            this->z = z;
        };
        Vector3() : Vector3<real>(0, 0, 0) {}
        Vector3(const Vector3& rhs) :Vector3()
        {
            Vector<real>::operator=(rhs);
        }
        static const Vector3 zero;
        static const Vector3 right;
        static const Vector3 left;
        static const Vector3 up;
        static const Vector3 down;

        Vector3& operator=(const Vector3& rhs)
        {
            return operator=((const Vector<real>&)rhs);
        }
        Vector3& operator=(const Vector<real>& rhs)
        {
            return (Vector3&)Vector<real>::operator=(rhs);
        }
        Vector3 operator+(const Vector<real>& rhs)
        {
            Vector3 ret(*this);
            ret += rhs;
            return ret;
        }
        Vector3 operator-(const Vector<real>& rhs)
        {
            Vector3 ret(*this);
            ret -= rhs;
            return ret;
        }
        Vector3 operator*(const double& scalar)
        {
            Vector3 ret(*this);
            ret *= scalar;
            return ret;
        }
        Vector3 operator/(const double& scalar)
        {
            Vector3 ret(*this);
            ret /= scalar;
            return ret;
        }
    };
    typedef Vector3<float> Vector3f;
    typedef Vector3<double> Vector3d;
};
//
//template<typename real>
//YunutyEngine::Vector3<real>::Vector3<real>(real x, real y, real z) : Vector<real>(xyz, 3), x(x), y(y), z(z)
//{
//};
//template<typename real>
//YunutyEngine::Vector3<real>::Vector3<real>() : Vector3<real>(0, 0)
//{
//};
