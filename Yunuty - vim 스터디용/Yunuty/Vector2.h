#pragma once
// 1. 25��° �ٷ� �̵��Ͻÿ�.
#include "Vector.h"
namespace YunutyEngine
{
    template<typename real>
    class Vector2 : public Vector<real>
    {
    private:
        // 7. �� ���� ���� ���� �ٹٲ��ϰ� "������"��, �� ���� �Ʒ��� ���� �ٹٲ��ϰ� "����!"�� Ÿ�����غ��ÿ�.
        // 8. ��
        real xy[2] = { 0 };
    public:
        real& x = xy[0];
        real& y = xy[1];
        Vector2() :Vector2<real>(0, 0) {}
        Vector2(real x, real y) :Vector<real>(xy, 2)
        {
            this->x = xy[0];
            this->y = xy[1];
            this->x = x;
            this->y = y;
        }
        Vector2(const Vector2& rhs) :Vector2()
        {
            Vector<real>::operator=(rhs);
        }
        //2. 70��° �ٷ� �̵��Ͻÿ�.
        //4. �߶󳻱��� ���� �� ������ �Ʒ��� �ٿ������ÿ�.
        //5. 83��° �ٷ� �̵��Ͻÿ�. 
        static const Vector2 zero;
        static const Vector2 one;
        static const Vector2 right;
        static const Vector2 left;
        static const Vector2 up;
        static const Vector2 down;

        Vector2& operator=(const Vector2& rhs)
        {
            return operator=((const Vector<real>&)rhs);
        }
        Vector2& operator=(const Vector<real>& rhs)
        {
            return (Vector2&)Vector<real>::operator=(rhs);
        }
        Vector2 operator+(const Vector<real>& rhs)
        {
            Vector2 ret(*this);
            ret += rhs;
            return ret;
        }
        Vector2 operator-(const Vector<real>& rhs)
        {
            Vector2 ret(*this);
            ret -= rhs;
            return ret;
        }
        Vector2 operator*(const double& scalar)
        {
            Vector2 ret(*this);
            ret *= scalar;
            return ret;
        }
        Vector2 operator/(const double& scalar)
        {
            Vector2 ret(*this);
            ret /= scalar;
            return ret;
        }
    };
    typedef Vector2<float> Vector2f;
    // 3. ���� Ŀ���� ��ġ�� ���� ��°�� �����ϰ�, ����Ű ``�� ���� �����ϱ� ������ ��ġ�� �̵��Ͻÿ�.
    typedef Vector2<double> Vector2d;

    template<typename real>
    const Vector2<real> Vector2<real>::one = Vector2<real>(1, 1);
    template<typename real>
    const Vector2<real> Vector2<real>::zero = Vector2<real>(0, 0);
    template<typename real>
    const Vector2<real> Vector2<real>::right = Vector2<real>(1, 0);
    template<typename real>
    const Vector2<real> Vector2<real>::left = Vector2<real>(-1, 0);
    template<typename real>
    const Vector2<real> Vector2<real>::up = Vector2<real>(0, 1);
    template<typename real>
    const Vector2<real> Vector2<real>::down = Vector2<real>(0, -1);
    // 6. 73�� �ٺ��� 84���ٱ��� ��� �����ϰ�, private��� Ű���带 �˻��Ͽ� ���� ����� private : Ű���忡 Ŀ���� ��ġ��Ű��, ������ �ٵ��� �� �Ʒ��� �ٿ������ÿ�.
};
//
//template<typename real>
//YunutyEngine::Vector2<real>::Vector2<real>(real x, real y) :Vector<real>(xy,2), x(x), y(y)
//{
//};
//template<typename real>
//YunutyEngine::Vector2<real>::Vector2<real>() : Vector2<real>(0, 0)
//{
//};
