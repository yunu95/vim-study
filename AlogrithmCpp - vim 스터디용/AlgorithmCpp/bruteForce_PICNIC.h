// 문제
// 안드로메다 유치원 익스프레스반에서는 다음 주에 율동공원으로 소풍을 갑니다.원석 선생님은 소풍 때 학생들을 두 명씩 짝을 지어 행동하게 하려고 합니다.그런데 서로 친구가 아닌 학생들끼리 짝을 지어 주면 서로 싸우거나 같이 돌아다니지 않기 때문에, 항상 서로 친구인 학생들끼리만 짝을 지어 줘야 합니다.
// 
// 각 학생들의 쌍에 대해 이들이 서로 친구인지 여부가 주어질 때, 학생들을 짝지어줄 수 있는 방법의 수를 계산하는 프로그램을 작성하세요.짝이 되는 학생들이 일부만 다르더라도 다른 방법이라고 봅니다.예를 들어 다음 두 가지 방법은 서로 다른 방법입니다.
// 
// (태연, 제시카) (써니, 티파니) (효연, 유리)
// (태연, 제시카) (써니, 유리) (효연, 티파니)
// 입력
// 입력의 첫 줄에는 테스트 케이스의 수 C(C <= 50) 가 주어집니다.각 테스트 케이스의 첫 줄에는 학생의 수 n(2 <= n <= 10) 과 친구 쌍의 수 m(0 <= m <= n * (n - 1) / 2) 이 주어집니다.그 다음 줄에 m 개의 정수 쌍으로 서로 친구인 두 학생의 번호가 주어집니다.
// 번호는 모두 0 부터 n - 1 사이의 정수이고, 같은 쌍은 입력에 두 번 주어지지 않습니다.학생들의 수는 짝수입니다.
// 
// 출력
// 각 테스트 케이스마다 한 줄에 모든 학생을 친구끼리만 짝지어줄 수 있는 방법의 수를 출력합니다.
// 
// 예제 입력
// 3
// 2 1
// 0 1
// 4 6
// 0 1 1 2 2 3 3 0 0 2 1 3
// 6 10
// 0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5
// 예제 출력
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
