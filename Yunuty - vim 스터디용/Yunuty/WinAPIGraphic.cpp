#include "WinAPIGraphic.h"

using namespace YunutyEngine;
using namespace YunutyEngine::WinAPI;

unordered_set<WinAPIGraphic*> YunutyEngine::WinAPI::WinAPIGraphic::winAPIGraphics;


WinAPIGraphic::WinAPIGraphic()
{
    winAPIGraphics.insert(this);
}
WinAPIGraphic::~WinAPIGraphic()
{
    winAPIGraphics.erase(this);
}
const unordered_set<WinAPIGraphic*>& YunutyEngine::WinAPI::WinAPIGraphic::GetWinAPIGraphics()
{
    return winAPIGraphics;
}
