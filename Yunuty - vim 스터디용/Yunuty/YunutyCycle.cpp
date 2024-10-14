// 1. Pause �ܾ �˻��� ã�ư��ÿ�. 
// 4. Component��� �ܾ �˻��ذ��鼭, 5�� ������ ã���ÿ�.
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

// 2. ������ �ڵ�� �Ľ�Į ���̽��� ī�� ���̽��� ������ �־�, �빮�� Ž���� ���� �ڵ��� �ֿ� ��ġ�� �����ϰ� Ž���� �� �ֽ��ϴ�.
// �Ʒ��� �ڵ�鿡�� �빮�� P,Y,C,E,S,M�� ���� ���ڵ��� f, Ȥ�� t ����Ű�� Ž���غ��ÿ�.
// 3. ������ ó�� ��ġ�� ���ư��ÿ�.
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


// 5. �� ã�ҽ��ϴ�. ��.
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
