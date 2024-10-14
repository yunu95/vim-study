//�׸��� ���� 4 x 4 ���� ���� ���·� ��ġ�� 16���� �ð谡 �ִ�.
//  �� �ð���� ��� 12��, 3��, 6��, Ȥ�� 9�ø� ����Ű�� �ִ�.
//  �� �ð���� ��� 12�ø� ����Ű���� �ٲٰ� �ʹ�.
//
//�ð��� �ð��� �����ϴ� ������ ����� ��� 10�� �ִ� ����ġ���� �����ϴ� ������, �� ����ġ���� ��� ���Դ� 3������ ���Դ� 5���� �ð迡 ����Ǿ� �ִ�/\.
// �� ����ġ�� ���� ������, �ش� ����ġ�� ����� �ð���� �ð��� 3�ð��� ������ �����δ�/\.
// ����ġ��� �׵��� ����� �ð���� ����� ������ ����/\.
//
//
//0	0, 1, 2
//1	3, 7, 9, 11
//2	4, 10, 14, 15
//3	0, 4, 5, 6, 7
//4	6, 7, 8, 10, 12
//5	0, 2, 14, 15
//6	3, 14, 15
//7	4, 5, 7, 14, 15
//8	1, 2, 3, 4, 5
//9	3, 4, 5, 9, 13
//�ð���� �� ���ٺ���, ���ʿ��� ���������� ������� ��ȣ�� �Ű����ٰ� ��������/\.
// �ð���� ���� ����Ű�� �ð����� �־����� ��, ��� �ð踦 12�÷� ������ ���� �ּ��� ������ �� ����ġ�� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�/\.
//
//
//�Է�
//ù �ٿ� �׽�Ʈ ���̽��� ���� C (<= 30) �� �־�����/\.
//
//�� �׽�Ʈ ���̽��� �� �ٿ� 16���� ������ �־�����, �� ������ 0������ 15������ �� �ð谡 ����Ű�� �ִ� �ð��� 12, 3, 6, 9 �� �ϳ��� ǥ���Ѵ�/\.
//
//
//���
//�� �׽�Ʈ ���̽��� �� ���� ����Ѵ�. �ð���� ��� 12�÷� �������� ���� ������ �� ����ġ�� �ּ� ���� ����Ѵ�. ���� �̰��� �Ұ����� ��� -1 �� ����Ѵ�.
// https://www.algospot.com/judge/problem/read/CLOCKSYNC
//#define test
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

using namespace std;

namespace CLOCKSYNC {
    void CLOCKSYNC();

#ifndef MainFile
    int clocks[16];
    int minClicks;
    const vector<int> switches[10] =
    {
        vector<int>({0,1,2}),
        vector<int>({3,7,9,11}),
        vector<int>({4,10,14,15}),
        vector<int>({0,4,5,6,7}),
        vector<int>({6,7,8,10,12}),
        vector<int>({0,2,14,15}),
        vector<int>({3,14,15}),
        vector<int>({4,5,7,14,15}),
        vector<int>({1,2,3,4,5}),
        vector<int>({3,4,5,9,13})
    };
    bool isSynced() {
        FOR(i, 16)
            if (clocks[i] != 0)
                return false;
        return true;
    }
    void backTracking(const int& currentSwitch = 0, const int& clicksSoFar = 0)
    {
        for (int clicks = 0; clicks < 4; clicks++)
        {
            if (clicks > 0)
                for (auto each : switches[currentSwitch])
                    clocks[each] = (clocks[each] + 1) % 4;
            if (isSynced()) {
                if (clicksSoFar + clicks < minClicks)
                    minClicks = clicksSoFar + clicks;
                return;
            }
            else if (currentSwitch < 9)
                backTracking(currentSwitch + 1, clicksSoFar + clicks);
        }
        for (auto each : switches[currentSwitch])
            clocks[each] = (clocks[each] + 1) % 4;
    }
    void CLOCKSYNC() {
#ifdef test
        stringstream cin(string("2\n12 6 6 6 6 6 12 12 12 12 12 12 12 12 12 12 \n12 9 3 12 6 6 9 3 12 9 12 9 12 12 6 6\n"));
#endif
        int C;
        cin >> C;
        FOR(i, C) {
            minClicks = 987654321;
            FOR(j, 16) {
                cin >> clocks[j];
                clocks[j] = (clocks[j] % 12) / 3;
            }
            backTracking();
            cout << (minClicks == 987654321 ? -1 : minClicks) << endl;
        }
    }
}
#endif

#ifndef YunuComputer
    int main() {
        CLOCKSYNC::CLOCKSYNC();
    }
#endif
