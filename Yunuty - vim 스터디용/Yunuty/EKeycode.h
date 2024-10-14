#pragma once
// 1. Arrow��� �ܾ ��� Direction���� ġȯ�� ���ÿ�.
// 2. ENUM ���ҵ��� �̸��鿡 ���ξ�� ���̾ �޾� ���ÿ�. ��) UpArrow => Prefix_UpArrow_Suffix (�����)
// 3. �� ������ ��� ���ڸ� y�� ġȯ�ϰ�, �ǵ��� ���ÿ�.
// 4. ��.

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
