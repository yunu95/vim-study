// 1. Pause 단어를 검색해 찾아가시오. 
// 4. Component라는 단어를 검색해가면서, 5번 지문을 찾으시오.
#include <iostream>
#include <chrono>
#include <stack>
#include "YunutyCycle.h"
#include "Time.h"
#include "GameObject.h"
#include "Component.h"
#include "GlobalComponent.h"
#include "Scene.h"
#include "Camera.h"
#include <cassert>

using namespace YunutyEngine;

YunutyEngine::YunutyCycle* YunutyEngine::YunutyCycle::_instance = nullptr;
YunutyEngine::YunutyCycle::YunutyCycle()
{
    assert(!_instance);
    _instance = this;
}
YunutyEngine::YunutyCycle& YunutyEngine::YunutyCycle::GetInstance()
{
    if (!_instance)
        _instance = new YunutyCycle();
    return *_instance;
}
void YunutyEngine::YunutyCycle::Initialize()
{
}

void YunutyEngine::YunutyCycle::Play()
{
    updateThread = thread(&YunutyCycle::ThreadFunction, this);
    ActiveComponentsDo(StartComponent);
}

void YunutyEngine::YunutyCycle::Stop()
{
}

// 2. 본문의 코드는 파스칼 케이스와 카멜 케이스로 쓰여져 있어, 대문자 탐색을 통해 코드의 주요 위치를 간편하게 탐색할 수 있습니다.
// 아래의 코드들에서 대문자 P,Y,C,E,S,M과 같은 문자들을 f, 혹은 t 단축키로 탐색해보시오.
// 3. 문서의 처음 위치로 돌아가시오.
void YunutyEngine::YunutyCycle::Pause()
{
}

void YunutyEngine::YunutyCycle::SetMaxFrameRate()
{
}

bool YunutyEngine::YunutyCycle::IsGameRunning()
{
    return isGameRunning;
}

void YunutyEngine::YunutyCycle::ThreadFunction()
{
    while (true)
    {
        ThreadUpdate();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
// Update components and render camera
void YunutyEngine::YunutyCycle::ThreadUpdate()
{
    Time::Update();

    for (auto i = GlobalComponent::globalComponents.begin(); i != GlobalComponent::globalComponents.end(); i++)
        i->second->Update();

    ActiveComponentsDo(UpdateComponent);
    if (Camera::mainCamera)
        Camera::mainCamera->Render();
}

void YunutyEngine::YunutyCycle::UpdateComponent(Component* component)
{
    if (!component->StartCalled)
    {
        component->StartCalled = true;
        component->Start();
    }
    component->Update();
}
void YunutyEngine::YunutyCycle::StartComponent(Component* component)
{
    component->StartCalled = true;
    component->Start();
}


// 5. 잘 찾았습니다. 끝.
void YunutyEngine::YunutyCycle::ActiveComponentsDo(function<void(Component*)> todo)
{
    YunutyEngine::IGameObjectParent* gameObjectParent = Scene::getCurrentScene();
    if (Scene::getCurrentScene())
    {
        stack<GameObject*> objectsStack;
        auto firstChildren = Scene::getCurrentScene()->GetChildren();
        for (auto each = firstChildren.rbegin(); each != firstChildren.rend(); each++)
            objectsStack.push(*each);

        while (!objectsStack.empty())
        {
            auto gameObject = objectsStack.top();
            objectsStack.pop();
            if (!gameObject->GetSelfActive())
                continue;


            for (auto each = gameObject->components.begin(); each != gameObject->components.end(); each++)
                todo(each->first);

            for (auto each = gameObject->children.begin(); each != gameObject->children.end(); each++)
                objectsStack.push(each->first);
        }
    }
}
