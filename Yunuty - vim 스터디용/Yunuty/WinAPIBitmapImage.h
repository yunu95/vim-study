#pragma once
#include <Windows.h>
#include "WinAPIGraphic.h"
#include <vector>
#include <unordered_set>
#include "Vector2.h"


using namespace std;
namespace YunutyEngine
{
    namespace WinAPI
    {
        class WinAPIBitmapImage :
            public WinAPIGraphic
        {
        private:
            HBITMAP hbitmap;
        protected:
        public:
            virtual void Render(HDC hdc, const Vector2d& position, const Vector2d& scale = Vector2d::one, double angle = 0);
        };
    }
}
