#pragma once
// 1. Arrow라는 단어를 모두 Direction으로 치환해 보시오.
// 2. ENUM 원소들의 이름들에 접두어와 접미어를 달아 보시오. 예) UpArrow => Prefix_UpArrow_Suffix (어려움)
// 3. 이 문서의 모든 문자를 y로 치환하고, 되돌려 보시오.
// 4. 끝.

namespace YunutyEngine
{
    enum class KeyCode
    {
        NoKey,
        LeftArrow,
        RightArrow,
        UpArrow,
        DownArrow,
        Space,
        Return,
        a,
        b,
        A,
        B
    };
}
