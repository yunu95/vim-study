#pragma once
//위 형태와 같이 삼각형 모양으로 배치된 자연수들이 있습니다.맨 위의 숫자에서 시작해, 한 번에 한 칸씩 아래로 내려가 맨 아래 줄로 내려가는 경로를 만들려고 합니다.경로는 아래 줄로 내려갈 때마다 바로 아래 숫자, 혹은 오른쪽 아래 숫자로 내려갈 수 있습니다.
//
//이 때 숫자의 합이 가장 큰 경로는 하나가 아니라 여러 개일 수 있습니다.예를 들어 위 삼각형에서는{ 9, 7, 2, 6 }과{ 9, 7, 3, 5 }의 합이 모두 최대인 24이고, { 9, 7, 3, 5 }는 두 번 등장하거든요.
//
//삼각형이 주어질 때 최대 경로의 수를 세는 프로그램을 작성하세요.
//
//입력
//입력의 첫 줄에는 테스트 케이스의 수 C(C <= 50)가 주어집니다.각 테스트 케이스의 첫 줄에는 삼각형의 크기 n(2 <= n <= 100)이 주어지고, 그 후 n줄에는 각 1개~n개의 숫자로 삼각형 각 가로줄에 있는 숫자가 왼쪽부터 주어집니다.각 숫자는 1 이상 100000 이하의 자연수입니다.
//
//출력
//각 테스트 케이스마다 한 줄에 최대 경로의 수를 출력합니다.
//경로의 수는 230 이하라고 가정해도 좋습니다.
//
//https://www.algospot.com/judge/problem/read/TRIPATHCNT
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

namespace TRIPATHCNT {
    int costMatrix[100][100];
    int sumMatrix[100][100];
    int max;
    int n;
    vector<vector<int>> pathCache;

    int MaxPaths(int row = 0, int col = 0, int sum = 0)
    {
        int& ret = pathCache[row][col];
        if (ret != -1)
            return ret;

        if (row == n - 1)
        {
            ret = sum == max ? 1 : 0;
            return ret;
        }
        //ret = MatxPaths(row + 1,col,sum+) + pathCache[row + 1][col + 1];
        return ret;
    }
    void TRIPATHCNT();
    void TRIPATHCNT()
    {
#ifdef test
        stringstream cin(string("2 4 1 1 1  1 1 1  1 1 1 1  4 9 5 7 1 3 2 3 5 5 6"));
#endif
        int C;
        cin >> C;
        FOR(i, C) {
            cin >> n;
            pathCache = vector<vector<int>>(n, vector<int>());
            for (int j = 0; j < n; j++)
                pathCache[j] = vector<int>(j + 1, -1);

            for (int j = 0; j < n; j++)
                for (int k = 0; k <= j; k++)
                {
                    cin >> costMatrix[j][k];
                    sumMatrix[j][k] = costMatrix[j][k];
                }

            for (int j = 1; j < n; j++)
                for (int k = 0; k <= j; k++)
                {
                    if (k == 0)
                        sumMatrix[j][k] += sumMatrix[j - 1][k];
                    else if (k == j)
                        sumMatrix[j][k] += sumMatrix[j - 1][k - 1];
                    else
                        sumMatrix[j][k] += sumMatrix[j - 1][k] > sumMatrix[j - 1][k - 1] ? sumMatrix[j - 1][k] : sumMatrix[j - 1][k - 1];
                }
            max = -987654321;
            for (int j = 0; j < n; j++)
                if (max < sumMatrix[n - 1][j])
                    max = sumMatrix[n - 1][j];

            cout << max << endl;
        }
    }
}
#ifndef YunuComputer
int main()
{
    TRIPATHCNT::TRIPATHCNT();
}
#endif

