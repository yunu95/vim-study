// 가장 멤버가 많은 아이돌 그룹으로 기네스 북에 올라 있는 혼성 팝 그룹 하이퍼시니어가 데뷔 10주년 기념 팬 미팅을 개최했습니다.
// 팬 미팅의 한 순서로, 멤버들과 참가한 팬들이 포옹을 하는 행사를 갖기로 했습니다.
// 하이퍼시니어의 멤버들은 우선 무대에 일렬로 섭니다.
// 팬 미팅에 참가한 M명의 팬들은 줄을 서서 맨 오른쪽 멤버에서부터 시작해 한 명씩 왼쪽으로 움직이며 멤버들과 하나씩 포옹을 합니다.
// 모든 팬들은 동시에 한 명씩 움직입니다.
// 아래 그림은 행사 과정의 일부를 보여줍니다.
// a~d는 네 명의 하이퍼시니어 멤버들이고, 0~5는 여섯 명의 팬들입니다.
//
// 하지만 하이퍼시니어의 남성 멤버들이 남성 팬과 포옹하기가 민망하다고 여겨서, 남성 팬과는 포옹 대신 악수를 하기로 했습니다.
// 줄을 선 멤버들과 팬들의 성별이 각각 주어질 때 팬 미팅이 진행되는 과정에서 하이퍼시니어의 모든 멤버가 동시에 포옹을 하는 일이 몇 번이나 있는지 계산하는 프로그램을 작성하세요.
//
// 입력
// 첫 줄에 테스트 케이스의 개수 C (C≤20)가 주어집니다.
// 각 테스트 케이스는 멤버들의 성별과 팬들의 성별을 각각 나타내는 두 줄의 문자열로 구성되어 있습니다.
// 각 문자열은 왼쪽부터 오른쪽 순서대로 각 사람들의 성별을 나타냅니다.
//
// M은 해당하는 사람이 남자, F는 해당하는 사람이 여자임을 나타냅니다.
// 멤버의 수와 팬의 수는 모두 1 이상 200,000 이하의 정수이며, 멤버의 수는 항상 팬의 수 이하입니다.
//
// 출력
// 각 테스트 케이스마다 한 줄에 모든 멤버들이 포옹을 하는 일이 몇 번이나 있는지 출력합니다.
//
// https:// www.algospot.com/judge/problem/read/FANMEETING
// 남 1, 여 0, 포옹 1, 악수 0
// 11 0
// 10 1
// 00 1
// 01 1
// !(m && f)

#define test
#define FOR(i,n) for(int i=0;i<n;i++)

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <memory>

using namespace std;

namespace FANMEETING {
    void FANMEETING();
    vector<int> Trim(const vector<int>& a) {
        vector<int> result(a);
        for (auto itr = result.rbegin(); itr != result.rend(); itr++)
            if (*itr != 0)
            {
                result.erase(itr.base(), result.end());
                break;
            }
        return result;
    }
    vector<int> ShiftLeft(const vector<int>& operand, const int& shiftNum)
    {
        vector<int> res(operand.size() + shiftNum);
        FOR(i, operand.size())
            res[i + shiftNum] = operand[i];
        return res;
    }
    vector<int> Multiply(const vector<int>& a, const vector<int>& b)
    {
        vector<int> result(a.size() + b.size() - 1);
        FOR(i, a.size())
            FOR(j, b.size())
            result[i + j] += a[i] * b[j];
        return Trim(result);
    }
    vector<int> Sum(const vector<int>& a, const vector<int>& b)
    {
        vector<int> result(max<int>(a.size(), b.size()) + 1);
        FOR(i, a.size())
            result[i] += a[i];
        FOR(j, b.size())
            result[j] += b[j];
        return Trim(result);
    }
    vector<int> Resize(const vector<int>& a, int n)
    {
        if (a.size() > n)
            return a;
        vector<int> ret(n);
        FOR(i, a.size())
            ret[i] = a[i];
        return ret;
    }
    vector<int> SubtractBfromA(const vector<int>& a, const vector<int>& b)
    {
        auto Alonger = a.size() > b.size();
        vector<int> result(Alonger ? a.size() : b.size());

        FOR(i, a.size())
            result[i] = a[i];
        FOR(i, b.size())
            result[i] -= b[i];

        return Trim(result);
    }
    vector<int> Karatsuba(const vector<int>& a, const vector<int>& b, const int& notation = -1) {
        if (a.size() == 0)
            return vector<int>();
        //a is always longer than b by this
        if (a.size() < b.size())
            Karatsuba(b, a);
        if (a.size() < 50)
            return Multiply(a, b);
        auto half = a.size() / 2;
        auto a0 = vector<int>(a.begin(), a.begin() + half);
        auto a1 = vector<int>(a.begin() + half, a.end());
        auto b0 = vector<int>(b.begin(), b.begin() + min<int>(b.size(), half));
        auto b1 = vector<int>(b.begin() + min<int>(b.size(), half), b.end());

        auto z0 = Karatsuba(a0, b0);
        auto z2 = Karatsuba(a1, b1);
        auto z1 = Karatsuba(Sum(a1, a0), Sum(b1, b0));
        z1 = SubtractBfromA(z1, z0);
        z1 = SubtractBfromA(z1, z2);

        vector<int> ret(4 * half + 1);
        ret = Sum(ret, ShiftLeft(z0, 0));
        ret = Sum(ret, ShiftLeft(z1, half));
        ret = Sum(ret, ShiftLeft(z2, half + half));
        if (notation > 0)
            FOR(i, ret.size() - 1)
        {
            ret[i + 1] += ret[i] / notation;
            ret[i] %= notation;
        }

        return Trim(ret);
    }
    //#ifndef MainFile
    void FANMEETING() {
#ifdef test
        stringstream cin(string("1\nFFMFMFMFMFMFMFMFMFFFFFFMFFFFMFFFFMFFMFMFMFFMFMFFFMFMFMFMFFMFMFMFFMFMFFMFMFMFFFFFFMFFMFFMFFMFMFMFMFMFMFMFMFMFFMFMFMFMFMFMFMFMFFFMFFMFMMMMFMFMFMFMFFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFFFFFMFMFFFFMFFFFMFFFMMMMFFMFMMMFMFMMMFFMFMF\n\
FFFFFFFFFMFFFMFFFMFFFFFFMFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFMFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFMFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFMFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFMFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFMFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFMFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFMFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF\n"));
#endif
        int C;
        char members[200000];
        char fans[200000];
        cin >> C;
        FOR(i, C) {
            int fanNum = 0;
            int memberNum = 0;
            int count = 0;
            string members;
            string fans;
            vector<int> fansOperand;
            vector<int> membersOperand;
            char input = 0;
            cin >> members;
            cin >> fans;
            for (auto each : members)
                membersOperand.push_back(each == 'M' ? 1 : 0);
            for (auto each : fans)
                fansOperand.push_back(each == 'M' ? 1 : 0);
            FOR(j, fanNum)
                fansOperand.push_back(fans[j]);
            FOR(j, memberNum)
                membersOperand.push_back(members[memberNum - j - 1]);
            reverse(membersOperand.begin(), membersOperand.end());
            auto res = Karatsuba(membersOperand, fansOperand);
            for (int j = membersOperand.size() - 1; j < fansOperand.size(); j++)
                if (res.size() > j) {
                    if (res[j] == 0)
                        count++;
                }
                else count++;
            cout << count << endl;
        }
    }
    //#endif
}
#ifndef YunuComputer
int main() {
    FANMEETING::FANMEETING();
}
#endif

