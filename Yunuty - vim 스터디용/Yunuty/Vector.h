#// 1. hjkl(좌하상우) 키를 눌러 미로를 통과하시오.
/*
   ██████████████████████████████████████████████████████████
                  █  █  █  █     █  █     █  █              █
█  █  ████  ███████  █  █  █  ████  ████  █  █  ████  ████  █
█  █     █           █           █  █     █     █     █     █
████  █  █  ████  ████  ██████████  █  ████  █  ██████████  █
█  █  █  █  █     █              █        █  █     █     █  █
█  ████  ████  █  ████  ███████  █  █  ████  █  ███████  ████
█           █  █        █  █     █  █  █  █  █  █     █  █  █
████████████████  ████  █  ████  █  █  █  █  ███████  █  █  █ 점멸 커맨드 : 2h,2j,2k,2l
█  █     █           █  █        █  █     █     █           █
█  █  ███████████████████  █████████████  █  ████  █  ████  █
█     █        █              █     █              █     █  █
█  ███████  █  █  █  ████  █  █  ███████  █████████████  ████
█        █  █  █  █  █     █        █     █     █  █  █  █  █
█  ████  █  ███████  ████  █████████████  ████  █  █  ████  █
█  █     █     █        █     █  █  █  █     █  █        █  █
███████  █  ████  ███████  ████  █  █  ████  █  █  ████  █  █
█                       █              █  █     █     █     █
███████  ████  █  █  █  █  █████████████  █  █  █  ███████  █
█        █     █  █  █  █                    █        █     █
███████████████████████████████████████████████████████     █ 앗! 미로를 건너는 도중에 강을 만났습니다. 19칸을 아래로 뛰어넘어 강을 건너 보시오.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  강은 무사히 건넜지만, 미로의 구조를 모두 파악하기 힘들게 되었습니다.
███████████████████████████████████████████████████████     █  단축키 zt, 혹은 zz를 눌러 포커싱을 재조정해보시오. 
█           █                    █        █        █        █ 
█        █  █              █           █     █     █        █
█  ████  █  █  █  █  █  █  █  ███████  █  █  █  ████  ████  █
█  █           █  █  █  █  █     █     █  █  █  █        █  █
█  ██████████  ████  ███████  ██████████  ████  █  █  ████  █
█        █     █  █                             █  █  █     █
█  ███████  ████  ███████  ████  ████  █  █  █  ████  ███████
█        █        █           █     █  █  █  █        █     █
███████  ████  ███████  ████  █  ████  ███████  █  ███████  █
█        █           █  █     █     █     █     █           █
█     ███████████████████████████████████████████████████████
""
2. 쌍따옴표 안을 편집 모드로 들어가서, 야호!라는 글을 써 보시오.
3. 다시 비주얼 모드로 들어가 문서의 끝으로 가시오.
*/


#pragma once
#include <iostream>
#include "Object.h"
namespace YunutyEngine
{
    template<typename real>
    class Vector abstract: Object
    {
    protected:
        real* vectorArray;
        unsigned int vectorSize;
        Vector(real* vectorArray, unsigned int vectorSize) : vectorArray(vectorArray), vectorSize(vectorSize) {}
        Vector(const Vector& rhs) = delete;
        void Normalize()
        {
            //for(int i=0;)
//vectorArray
        }
    public:
        static real Dot(const Vector& lhs, const Vector& rhs)
        {
            return 0;
        }

        static Vector Project(const Vector& vector, const Vector& onNormal)
        {
            return *this;
        }

        static Vector Lerp(const Vector& a, const Vector& b, float t)
        {
            return *this;
        }

        real Magnitude()const
        {
            return 0;
        }

        real MagnitudeSqr()const
        {
            return 0;
        }

        Vector& operator=(const Vector& rhs)
        {
            for (unsigned int i = 0; i < vectorSize; i++)
                vectorArray[i] = i < rhs.vectorSize ? rhs.vectorArray[i] : 0;
            return *this;
        }
        Vector& operator+=(const Vector& rhs)
        {
            for (unsigned int i = 0; i < vectorSize; i++)
                vectorArray[i] += i < rhs.vectorSize ? rhs.vectorArray[i] : 0;
            return *this;
        }
        Vector& operator-=(const Vector& rhs)
        {
            for (unsigned int i = 0; i < vectorSize; i++)
                vectorArray[i] -= i < rhs.vectorSize ? rhs.vectorArray[i] : 0;
            return *this;
        }
        Vector& operator*=(const double& scalar)
        {
            for (unsigned int i = 0; i < vectorSize; i++)
                vectorArray[i] *= scalar;
            return *this;
        }
        Vector& operator/=(const double& scalar)
        {
            for (unsigned int i = 0; i < vectorSize; i++)
                vectorArray[i] /= scalar;
            return *this;
        }
        /*template<typename SubVector>
        operator SubVector()const
        {
            static_assert(std::is_base_of<Vector, SubVector>::value, "only derived classes from vector are allowed");
            SubVector ret;
            (Vector)ret = *this;
            return ret;
        }
        template<class SubVector>
        operator const SubVector& ()const
        {
            return (SubVector&)*this;
        }*/
    };
}
//4. 끝
