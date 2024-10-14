#pragma once
//문제
//N개의 도시가 P개의 단방향 길로 연결되어 있다. 이석원은 1번 도시와 2번 도시 사이를 가며 워해머를 한다. 성실한 이석원은 1번에서 2번으로 가는 서로 다른 경로를 최대한 많이 찾으려고 하는데, 이때 한 경로에 포함된 길이 다른 경로에 포함되면 안된다. 입력에는 1번 도시와 2번 도시를 연결하는 길은 없다. 도시의 번호는 1번부터 N번까지이다.
//
//입력
//첫째 줄에 두 정수 N(3 ≤ N ≤ 400), P(1 ≤ P ≤ 10,000)이 주어진다. 다음 P개의 줄에는 각 길이 연결하는 출발 도시와 도착 도시의 번호가 주어지며, 두 번호는 다르다.
//
//출력
//1번에서 2번으로 가는 서로 다른 경로의 최대 개수를 출력한다.
//https://www.algospot.com/judge/problem/read/roundTrip
#define FOR(i,n) for(int i=0;i<n;i++)

#include <iostream>
#include <sstream>
#include <algorithm>
//#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

bool biPath[401][401] = { false };
namespace RoundTrip {
    void RoundTrip();

    void RoundTrip() {
#ifdef test
        stringstream cin(string("5 5\n1 3\n3 2\n1 5\n5 4\n4 2"));
#endif 
        int n, p;
        cin >> n;
        cin >> p;
        FOR(i, p)
        {
            int a,b;
            cin >> a;
            cin >> b;
            biPath[a][b] = true;
        }
    }
}
#ifndef YunuComputer
int main() {
    RoundTrip::RoundTrip();
}
#endif
