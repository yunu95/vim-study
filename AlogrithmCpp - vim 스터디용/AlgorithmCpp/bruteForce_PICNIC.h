// ����
// �ȵ�θ޴� ��ġ�� �ͽ��������ݿ����� ���� �ֿ� ������������ ��ǳ�� ���ϴ�.���� �������� ��ǳ �� �л����� �� �� ¦�� ���� �ൿ�ϰ� �Ϸ��� �մϴ�.�׷��� ���� ģ���� �ƴ� �л��鳢�� ¦�� ���� �ָ� ���� �ο�ų� ���� ���ƴٴ��� �ʱ� ������, �׻� ���� ģ���� �л��鳢���� ¦�� ���� ��� �մϴ�.
// 
// �� �л����� �ֿ� ���� �̵��� ���� ģ������ ���ΰ� �־��� ��, �л����� ¦������ �� �ִ� ����� ���� ����ϴ� ���α׷��� �ۼ��ϼ���.¦�� �Ǵ� �л����� �Ϻθ� �ٸ����� �ٸ� ����̶�� ���ϴ�.���� ��� ���� �� ���� ����� ���� �ٸ� ����Դϴ�.
// 
// (�¿�, ����ī) (���, Ƽ�Ĵ�) (ȿ��, ����)
// (�¿�, ����ī) (���, ����) (ȿ��, Ƽ�Ĵ�)
// �Է�
// �Է��� ù �ٿ��� �׽�Ʈ ���̽��� �� C(C <= 50) �� �־����ϴ�.�� �׽�Ʈ ���̽��� ù �ٿ��� �л��� �� n(2 <= n <= 10) �� ģ�� ���� �� m(0 <= m <= n * (n - 1) / 2) �� �־����ϴ�.�� ���� �ٿ� m ���� ���� ������ ���� ģ���� �� �л��� ��ȣ�� �־����ϴ�.
// ��ȣ�� ��� 0 ���� n - 1 ������ �����̰�, ���� ���� �Է¿� �� �� �־����� �ʽ��ϴ�.�л����� ���� ¦���Դϴ�.
// 
// ���
// �� �׽�Ʈ ���̽����� �� �ٿ� ��� �л��� ģ�������� ¦������ �� �ִ� ����� ���� ����մϴ�.
// 
// ���� �Է�
// 3
// 2 1
// 0 1
// 4 6
// 0 1 1 2 2 3 3 0 0 2 1 3
// 6 10
// 0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5
// ���� ���
// 1
// 3
// 4
// https://www.algospot.com/judge/problem/read/PICNIC
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

void PICNIC();

#ifndef MainFile
bool relation[10][10];
int compositionCount = 0;

void backTracking(unordered_set<int> remnants) {
    if (remnants.empty())
    {
        compositionCount++;
        return;
    }
    int current = *remnants.begin();
    remnants.erase(current);

    for (int i = 0; i < 10; i++)
        if (remnants.find(i) != remnants.end() && relation[current][i])
        {
            remnants.erase(i);
            backTracking(remnants);
            remnants.insert(i);
        }

}
void PICNIC() {
#ifdef test
    stringstream cin(string("3\n2 1\n0 1\n4 6\n0 1 1 2 2 3 3 0 0 2 1 3\n6 10\n0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5"));
#endif
    int C;
    cin >> C;
    FOR(i, C) {
        int n, m;
        cin >> n;
        cin >> m;
        compositionCount = 0;
        unordered_set<int> remnants;

        FOR(j, n) {
            FOR(k, n)
                relation[j][k] = false;
            remnants.insert(j);
        }
        FOR(j, m)
        {
            int friendA, friendB;
            cin >> friendA;
            cin >> friendB;
            relation[friendA][friendB] = true;
            relation[friendB][friendA] = true;
        }
        backTracking(remnants);

        cout << compositionCount << '\n';
    }
}
#endif

#ifndef YunuComputer
int main() {
    PICNIC();
}
#endif
