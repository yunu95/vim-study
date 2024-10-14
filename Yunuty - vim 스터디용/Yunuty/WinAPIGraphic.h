#pragma once
#include <Windows.h>
#include <vector>
#include <unordered_set>
#include "Graphic.h"
#include "Vector2.h"
#include "Rect.h"


using namespace std;
namespace YunutyEngine
{
    namespace WinAPI
    {
        class WinAPICamera2D;
        class WinAPIGraphic :
            public Graphic
        {
            friend WinAPICamera2D;
        private:
            static unordered_set<WinAPIGraphic*> winAPIGraphics;
        protected:
            // position�� Yunuty �������� ���ӿ�����Ʈ ��ġ�� �ƴ� winAPI���� �׷����� �������� ��ġ�� �ش��մϴ�.
            // Scale�� ���� �׸��� �׷����� ũ�Ⱑ �޶����� �մϴ�. Scale�� ũ�Ⱑ ������ ��� ����� �����˴ϴ�.
            // �� �Լ��� �Ű����� scale�� transform�� �����ϰ��� �����Դϴ�.
            // angle�� �׷��� ��Ұ� ���ϴ� ���� ������ �ǹ��մϴ�. 0���� ��������, 90���� ������ ���ϰ� �˴ϴ�.
            virtual void Render(HDC hdc,const Vector2d position, const Vector2d& scale = Vector2d::one, double angle = 0) = 0;
            Rect drawRect;
        public:
            WinAPIGraphic();
            virtual ~WinAPIGraphic();
            static const unordered_set<WinAPIGraphic*>& GetWinAPIGraphics();
        };
    }
}
