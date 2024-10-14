#pragma once
//6
//1  2
//3  7  4
//9  4  1  7
//2  7  5  9  4
//위 형태와 같이 삼각형 모양으로 배치된 자연수들이 있습니다.
//맨 위의 숫자에서 시작해, 한 번에 한 칸씩 아래로 내려가 맨 아래 줄로 내려가는 경로를 만들려고 합니다.
//경로는 아래 줄로 내려갈 때마다 바로 아래 숫자, 혹은 오른쪽 아래 숫자로 내려갈 수 있습니다.
//이 때 모든 경로 중 포함된 숫자의 최대 합을 찾는 프로그램을 작성하세요.
//
//
//입력
//입력의 첫 줄에는 테스트 케이스의 수 C(C <= 50)가 주어집니다.
//각 테스트 케이스의 첫 줄에는 삼각형의 크기 n(2 <= n <= 100)이 주어지고, 그 후 n줄에는 각 1개~n개의 숫자로 삼각형 각 가로줄에 있는 숫자가 왼쪽부터 주어집니다.
//각 숫자는 1 이상 100000 이하의 자연수입니다.
//
//
//출력
//각 테스트 케이스마다 한 줄에 최대 경로의 숫자 합을 출력합니다.
//
//https://www.algospot.com/judge/problem/read/TRIANGLEPATH
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

namespace TRIANGLEPATH {
    int costMatrix[100][100];
    int sumMatrix[100][100];
    void TRIANGLEPATH();
    void TRIANGLEPATH() {
#ifdef test
        stringstream cin(string("2\n5\n6\n1  2\n3  7  4\n9  4  1  7\n2  7  5  9  4\n5\n1 \n2 4\n8 16 8\n32 64 32 64\n128 256 128 256 128"));
#endif
        int C;
        cin >> C;
        FOR(i, C) {
            int n;
            cin >> n;
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
            int max = -987654321;
            for (int j = 0; j < n; j++)
                if (max < sumMatrix[n-1][j])
                    max = sumMatrix[n-1][j];
            cout << max<<endl;
        }
    }
}
#ifndef YunuComputer
int main() {
    TRIANGLEPATH::TRIANGLEPATH();
}
#endif

