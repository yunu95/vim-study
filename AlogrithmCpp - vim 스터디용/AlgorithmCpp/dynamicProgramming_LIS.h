#pragma once
//어떤 정수 수열에서 0개 이상의 숫자를 지우면 이 수열의 부분 수열(subsequence) 를 얻을 수 있다.
//예를 들어 10 7 4 9 의 부분 수열에는 7 4 9, 10 4, 10 9 등이 있다.
//단, 10 4 7 은 원래 수열의 순서와 다르므로 10 7 4 9 의 부분 수열이 아니다.
//
//
//어떤 부분 수열이 순증가할 때 이 부분 수열을 증가 부분 수열(increasing subsequence) 라고 한다.
//주어진 수열의 증가 부분 수열 중 가장 긴 것의 길이를 계산하는 프로그램을 작성하라.
//
//
//어떤 수열의 각 수가 이전의 수보다 클 때, 이 수열을 순증가 한다고 한다.
//
//
//입력
//입력의 첫 줄에는 테스트 케이스의 수 C(<= 50) 가 주어진다.
//각 테스트 케이스의 첫 줄에는 수열에 포함된 원소의 수 N(<= 500) 이 주어진다.
//그 다음 줄에 수열이 N개의 정수가 주어진다.
//각 정수는 1 이상 100, 000 이하의 자연수이다.
//
//
//출력
//각 테스트케이스마다 한 줄씩, 주어진 수열의 가장 긴 증가 부분 수열의 길이를 출력한다.
//
//
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
#include <memory>

using namespace std;

namespace LIS {
    int n;
    vector<int> sequence;
    vector<int> results;
    int Count(const int& start = 0) {
        if (start == n - 1)
            return results[start] = 1;

        int result = 1;
        //int current = sequence[start];
        for (int i = start; i < n; i++)
        {
            if (sequence[i] <= sequence[start])
                continue;
            if (result < (results[i] < 0 ? Count(i) : results[i]) + 1)
                result = results[i] + 1;
        }
        return results[start] = result;
    }
    void LIS();
    void LIS() {
#ifdef test
        stringstream cin(string("3\n4\n1 2 3 4\n8\n5 4 3 2 1 6 7 8 \n8\n5 6 7 8 1 2 3 4\n"));
#endif
        int C;
        cin >> C;
        FOR(i, C) {
            // n<500

            cin >> n;
            sequence = vector<int>(n);
            results = vector<int>(n, -1);

            FOR(j, n)
                cin >> sequence[j];

            FOR(j, n)
                Count(j);

            int max = -987654321;
            for (auto each : results)
                if (max < each)
                    max = each;

            cout << max << endl;

        }
    }
}
#ifndef YunuComputer
int main() {
    LIS::LIS();
}
#endif

