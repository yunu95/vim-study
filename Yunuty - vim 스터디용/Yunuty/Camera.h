#pragma once
#include "Object.h"
#include "Component.h"

// 카메라는 화면에 게임상에 존재하는 모든 그래픽 요소들을 출력하는 데에 쓰이는 객체입니다. 
// 카메라의 구현은 엔진의 동작환경,혹은 카메라의 특성에 따라 달라질 수 있기 때문에,
// 화면을 그려내기 위해 쓰이는 함수 Render는 추상 메소드로 정의됩니다.
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
