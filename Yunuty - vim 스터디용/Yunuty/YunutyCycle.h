// 1. 18번째 줄부터 32번째줄까지 모두 복사하고, 문서의 마지막에 붙여넣기 하시오.
// 2. 
#pragma once
#include <thread>
#include "Object.h"
#include <functional>

using namespace std;

namespace YunutyEngine
{
    class Component;
    static class YunutyCycle : Object
    {
    private:
        thread updateThread;
        bool isGameRunning = false;
        static YunutyCycle* _instance;
        void ActiveComponentsDo(function<void(Component*)> todo);
        static void UpdateComponent(Component* component);
        static void StartComponent(Component* component);
        void ThreadFunction();
    protected:
        YunutyCycle();
        virtual void ThreadUpdate();
    public:
        static YunutyCycle& GetInstance();
        void Initialize();
        void Play();
        void Stop();
        void Pause();
        void SetMaxFrameRate();
        bool IsGameRunning();
    };
}
