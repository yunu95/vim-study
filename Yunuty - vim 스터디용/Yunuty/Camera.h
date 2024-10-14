#pragma once
#include "Object.h"
#include "Component.h"

// ī�޶�� ȭ�鿡 ���ӻ� �����ϴ� ��� �׷��� ��ҵ��� ����ϴ� ���� ���̴� ��ü�Դϴ�. 
// ī�޶��� ������ ������ ����ȯ��,Ȥ�� ī�޶��� Ư���� ���� �޶��� �� �ֱ� ������,
// ȭ���� �׷����� ���� ���̴� �Լ� Render�� �߻� �޼ҵ�� ���ǵ˴ϴ�.
namespace YunutyEngine
{
    class YunutyCycle;
    class Camera :
        public Component
    {
    private:
        static Camera* mainCamera;
    protected:
        Camera();
        virtual void Render() = 0;
    public:
        void SetCameraMain();
        static Camera* GetMainCamera();
        friend YunutyCycle;
    };
}
