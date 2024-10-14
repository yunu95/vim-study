#pragma once
#include "Object.h"
#include "EKeycode.h"
#include "GlobalComponent.h"

// À¯¿ëÇÔ
// GetAsyncKeyState
namespace YunutyEngine
{
    class Input :
        public GlobalComponent
    {
    private:
        static unique_ptr<Input> instance;
    protected:
        Input();
        virtual bool m_isKeyDown(KeyCode keyCode) = 0;
        virtual bool m_isKeyPushed(KeyCode keyCode) = 0;
    public:
        static bool isKeyDown(KeyCode keyCode);
        static bool isKeyPushed(KeyCode keyCode);
    };
}
