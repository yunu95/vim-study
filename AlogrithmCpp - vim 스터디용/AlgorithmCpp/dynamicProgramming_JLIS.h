#pragma once
//� �������� 0�� �̻��� ���ڸ� ���� ����� �� ������ �κ� �����̶�� �θ��ϴ�.
//���� ��� '4 7 6'�� '4 3 7 6 9'�� �κ� �����Դϴ�.
//�ߺ��� ���ڰ� ���� ���� �������� ���ĵǾ� �ִ� �κ� �������� ������ ���� �κ� �����̶�� �θ�����.
//���� ��� '3 6 9'�� ���� ������ ���� �κ� �����Դϴ�.
//
//�� ���� ���� ���� A �� B ���� ���� ���� �κ� ������ ���� �� �̵��� ũ�� ������� ��ģ ���� ��ģ ���� �κ� �����̶�� �θ���� �սô�.
//�� �� ���� �� ������ ��ģ JLIS(JLIS, Joined Longest Increasing Subsequence)�̶�� �θ��ô�.
//���� ��� '1 3 4 7 9' �� '1 9 4' �� '3 4 7' �� JLIS�Դϴ�.
//'1 9' �� '3 4 7' �� ���� '1 3 4 7 9'�� ���� �� �ֱ� ����������.
//
//A �� B �� �־��� ��, JLIS�� ���̸� ����ϴ� ���α׷��� �ۼ��ϼ���.
//
//�Է�
//�Է��� ù �ٿ��� �׽�Ʈ ���̽��� �� c ( 1 <= c <= 50 ) �� �־����ϴ�.
//�� �׽�Ʈ ���̽��� ù �ٿ��� A �� B �� ���� n �� m �� �־����ϴ� (1 <= n,m <= 100).
//���� �ٿ��� n ���� ������ A �� ���ҵ���, �� ���� �ٿ��� m ���� ������ B �� ���ҵ��� �־����ϴ�.
//��� ���ҵ��� 32��Ʈ ��ȣ �ִ� ������ ������ �� �ֽ��ϴ�.
//
//���
//�� �׽�Ʈ ���̽����� �� �ٿ�, JLIS �� ���̸� ����մϴ�.
//https://algospot.com/judge/problem/read/JLIS


#define test
#define FOR(i,n) for(int i=0;i<n;i++)

#include <deque>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <string>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <memory>

using namespace std;

namespace JLIS {
    int n;
    vector<int> LIS(const vector<int>& sequence, vector<vector<int>>& results, const int& start = 0)
    {
        if (start == n - 1)
            return results[start] = vector<int>(1, n - 1);

        vector<int> result = vector<int>(start);
        //int current = sequence[start];
        for (int i = start; i < n; i++)
        {
            if (sequence[i] <= sequence[start])
                continue;

            if (result.size() < (results[i].size() == 0 ? LIS(sequence, results, i).size() : results[i].size()) + 1)
                result = results[i] + 1;
        }
        return results[start] = result;
    }
    void JLIS();
    void JLIS()
    {
#ifdef test
        stringstream cin(string("3\n4\n1 2 3 4\n8\n5 4 3 2 1 6 7 8 \n8\n5 6 7 8 1 2 3 4\n"));
#endif
        int C;
        cin >> C;
        FOR(i, C)
        {
            // n<500
            vector<int> sequence;
            vector<int> results;

            cin >> n;
            sequence = vector<int>(n);
            results = vector<int>(n, -1);
        }
    }
}
#ifndef YunuComputer
int main()
{
    JLIS::JLIS();
}
#endif

