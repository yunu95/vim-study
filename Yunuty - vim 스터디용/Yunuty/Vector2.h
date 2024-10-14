#pragma once
// 1. 25번째 줄로 이동하시오.
#include "Vector.h"
namespace YunutyEngine
{
    template<typename real>
    class Vector2 : public Vector<real>
    {
    private:
        // 7. 이 지문 위에 새로 줄바꿈하고 "이윤우"를, 이 지문 아래에 새로 줄바꿈하고 "만세!"를 타이핑해보시오.
        // 8. 끝
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
        //2. 70번째 줄로 이동하시오.
        //4. 잘라내기한 글을 이 지문의 아래에 붙여넣으시오.
        //5. 83번째 줄로 이동하시오. 
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
    // 3. 현재 커서가 위치한 줄을 통째로 삭제하고, 단축키 ``를 눌러 점프하기 이전의 위치로 이동하시오.
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
    // 6. 73번 줄부터 84번줄까지 모두 삭제하고, private라는 키워드를 검색하여 문서 상단의 private : 키워드에 커서를 위치시키고, 복사한 줄들을 그 아래에 붙여넣으시오.
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
