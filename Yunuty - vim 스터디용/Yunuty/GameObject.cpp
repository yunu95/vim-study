#include "GameObject.h"
#include "Component.h"
#include "Transform.h"
#include <stack>

using namespace YunutyEngine;
using namespace std;
YunutyEngine::GameObject::GameObject(IGameObjectParent* parent)
{
    transform = AddComponent<Transform>();
    SetParent(parent);
}
void YunutyEngine::GameObject::DoThingsOnParents(function<void(GameObject*)> todo)
{
    auto node = this->parentGameObject;
    while (node)
    {
        todo(node);
        node = node->parentGameObject;
    }
}
void YunutyEngine::GameObject::DeleteComponent(Component* component)
{
    components.erase(component);
}
bool YunutyEngine::GameObject::GetActive()
{
    if (!selfActive)
        return false;
    if (parentGameObject)
        return parentGameObject->GetActive();
    else
        return true;
}
bool YunutyEngine::GameObject::GetSelfActive()
{
    return selfActive;
}
void YunutyEngine::GameObject::SetSelfActive(bool selfActive)
{
    bool activeBefore = GetActive();
    bool activeAfter;

    this->selfActive = selfActive;

    activeAfter = GetActive();
    if (activeBefore != activeAfter)
    {
        if (activeAfter)
        {
            stack<GameObject*> activeStack;
            activeStack.push(this);
            while (!activeStack.empty())
            {
                auto child = activeStack.top();
                activeStack.pop();
                for (auto each : child->childrenIndexed)
                    if (each->selfActive)
                        activeStack.push(each);

                for (auto eachComp = child->components.begin(); eachComp != child->components.end(); eachComp++)
                    if (activeAfter)
                        eachComp->first->OnEnable();
                    else
                        eachComp->first->OnDisable();
            }
        }
    }

}
GameObject* YunutyEngine::GameObject::GetParentGameObject()
{
    return parentGameObject;
}
Scene* YunutyEngine::GameObject::GetScene()
{
    return scene;
}
void YunutyEngine::GameObject::SetParent(IGameObjectParent* parent)
{
    DoThingsOnParents([](GameObject* parent) {parent->childrenNum--; });
    if (this->parent)
        parent->ReceiveChild(this->parent->MoveChild(this));
    else
        parent->ReceiveChild(move(unique_ptr<GameObject>(this)));
    this->parent = parent;
    this->parentGameObject = dynamic_cast<GameObject*>(parent);
    DoThingsOnParents([](GameObject* parent) {parent->childrenNum++; });
}
// �̰� ���⵵ n��.
unique_ptr<YunutyEngine::GameObject> YunutyEngine::GameObject::MoveChild(GameObject* child)
{
    auto ret = move(children[child]);
    auto index = GetChildIndex(child);
    children.erase(child);
    childIndexMap.erase(child);
    childrenIndexed.erase(childrenIndexed.begin() + index);
    for (int i = index; i < childrenIndexed.size(); i++)
        childIndexMap[childrenIndexed[i]] = i;

    return ret;
}

const vector<GameObject*>& YunutyEngine::GameObject::GetChildren()const
{
    return childrenIndexed;
}
void YunutyEngine::GameObject::ReceiveChild(remove_reference<unique_ptr<GameObject>>::type&& child)
{
    auto ptr = child.get();
    children.insert(make_pair(ptr, unique_ptr<GameObject>()));
    children[ptr] = move(child);
    childIndexMap.insert(make_pair(ptr, childrenIndexed.size()));
    childrenIndexed.push_back(ptr);
}
int YunutyEngine::GameObject::GetChildIndex(GameObject* child)
{
    return childIndexMap[child];
}
YunutyEngine::GameObject::~GameObject()
{

}
Transform* YunutyEngine::GameObject::GetTransform()
{
    return transform;
}
int YunutyEngine::GameObject::GetChildIndex()
{
    return parent->GetChildIndex(this);
}
int YunutyEngine::GameObject::GetSceneIndex()
{
    int ret = 1;
    int childIndex = parent->GetChildIndex(this);
    if (childIndex == 0)
    {
        ret += parentGameObject ? parentGameObject->GetSceneIndex() : 0;
    }
    else
    {
        auto brother = parent->GetChildren()[childIndex - 1];
        ret += brother->GetSceneIndex() + brother->childrenNum;
    }

    return ret;
}
string YunutyEngine::GameObject::getName()const
{
    return name;
}
void YunutyEngine::GameObject::setName(const string& name)
{
    this->name = name;
}
