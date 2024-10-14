#pragma once
//Quantization(����ȭ) ������, �� ���� ������ ���� ������ ���� ������ ���� ����� �ٻ��� ǥ�������ν� �ڷḦ �ս� �����ϴ� ������ ���Ѵ�.
//���� ��� 16��Ʈ JPG ������ 4�÷� GIF ���Ϸ� ��ȯ�ϴ� ���� RGB �� ������ ������ 4�÷� ���� �ϳ��� ����ȭ�ϴ� ���̰�, Ű�� 161, 164, 170, 178 �� �л� ���� '160�� ��, 170�� ��' �̶�� ����� ǥ���ϴ� �� ���� ����ȭ��� �� �� �ִ�.
//
//
//1000 ������ �ڿ������ ������ ������ �ִ� S���� �� ������ ����ϵ��� ����ȭ�ϰ� �ʹ�.
//�� �� ����ȭ�� ���ڴ� ���� ������ ���� ������ ���� �ִ�.
//����ȭ�� �ϴ� ����� ���� ������ �ִ�.
//���� 1 2 3 4 5 6 7 8 9 10 �� 2���� ���ڸ��� �Ἥ ǥ���Ϸ���, 3 3 3 3 3 7 7 7 7 7 �� ���� �� ���� �ְ�, 1 1 1 1 1 10 10 10 10 10 ���� �� ���� �ִ�.
//�츮�� �� ��, �� ���ں� ���� ������ ���� �ּ�ȭ�ϴ� ����ȭ ����� �˰� �ʹ�.
//
//
//���� ���, ���� 1 2 3 4 5 �� 1 1 3 3 3 ���� ����ȭ�ϸ� ���� ������ ���� 0 + 1 + 0 + 1 + 4 = 6 �� �ǰ�, 2 2 2 4 4 �� ����ȭ�ϸ� ���� ������ ���� 1 + 0 + 1 + 0 + 1 = 3 �� �ȴ�.
//
//
//������ S �� �־��� ��, ������ ���� ������ ���� �ּҰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//
//�Է�
//�Է��� ù �ٿ��� �׽�Ʈ ���̽��� �� C(1 <= C <= 50) �� �־�����.
//�� �׽�Ʈ ���̽��� ù �ٿ��� ������ ���� N(1 <= N <= 100), ����� ������ �� S(1 <= S <= 10) �� �־�����.
//�� ���� �ٿ� N���� ������ ������ ���ڵ��� �־�����.
//������ ��� ���� 1000 ������ �ڿ����̴�.
//
//
//���
//�� �׽�Ʈ ���̽�����, �־��� ������ �ִ� S ���� ���� ����ȭ�� �� ���� ������ ���� �ּҰ��� ����Ѵ�.
// 
//https://www.algospot.com/judge/problem/read/TILING2

//#define test
#define JM
#define FOR(i,n) for(int i=0;i<n;i++)

#include <deque>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <memory>

using namespace std;

#ifndef JM
namespace QUANTIZE {
    const int INF = 987654321;
    vector<int> numbers;
    // begin, s
    typedef tuple<int, int> iiIndex;
    map<iiIndex, int> cache;
    int getError(const int& begin, const int& exlusiveEnd, const int& x)
    {
        int ret = 0;
        for (int i = begin; i < exlusiveEnd; i++)
            ret += (numbers[i] - x) * (numbers[i] - x);

        return ret;
    }
    int mean(const int& begin, const int& exlusiveEnd)
    {
        double ret = 0;
        double n = exlusiveEnd - begin;
        for (int i = begin; i < exlusiveEnd; i++)
            ret += numbers[i] / n;

        return round(ret);
    }
    int minError(const int& begin, const int& s)
    {
        if (s >= numbers.size() - begin)
            return 0;
        auto cacheIndex = make_pair(begin, s);
        if (begin >= numbers.size() && s < 0)
            return 0;

        if (cache.find(cacheIndex) != cache.end())
            return cache[cacheIndex];

        cache.insert(make_pair(cacheIndex, INF));
        int& res = cache[cacheIndex];

        if (s == 1)
            return res = getError(begin, numbers.size(), mean(begin, numbers.size()));

        for (int i = begin; i < numbers.size() - s; i++)
            res = min(res, getError(begin, i + 1, mean(begin, i + 1)) + minError(i + 1, s - 1));

        return res;
    }
    void QUANTIZE()
    {
#ifdef test
        stringstream cin;
        cin << "1\n9 3\n1 744 755 4 897 902 890 6 777";
#endif
        int C;
        cin >> C;

        FOR(i, C)
        {
            int N, S;
            cin >> N;
            cin >> S;
            numbers = vector<int>(N, 0);
            cache.clear();
            //numbers.resize(N);
            FOR(j, N)
                cin >> numbers[j];

            sort(numbers.begin(), numbers.end());
            cout << minError(0, S) << endl;
        }
    }
}
#else
namespace QUANTIZE
{
    const int INF = 987654321;
    int n;
    int A[101], pSum[101], pSqSum[101];

    void precalc() {
        sort(A, A + n);
        pSum[0] = A[0];
        pSqSum[0] = A[0] * A[0];
        for (int i = 1; i < n; ++i)
        {
            pSum[i] = pSum[i - 1] + A[i];
            pSqSum[i] = pSqSum[i - 1] + A[i] * A[i];
        }
    }
    int minError(int lo, int hi) {
        int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
        int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]);
        int m = int(0.5 + (double)sum/(hi-lo+1));
        int ret = sqSum - 2 * m * sum + m * m * (hi - lo + 1);
    }
    
    void QUANTIZE()
    {
#ifdef test
        stringstream cin;
        cin << "1\n9 3\n1 744 755 4 897 902 890 6 777";
#endif
        int C;
        cin >> C;

        FOR(i, C)
        {
            int N, S;
            cin >> N;
            cin >> S;
            numbers = vector<int>(N, 0);
            cache.clear();
            //numbers.resize(N);
            FOR(j, N)
                cin >> numbers[j];

            sort(numbers.begin(), numbers.end());
            cout << minError(0, S) << endl;
        }
}
}

#endif

#ifndef YunuComputer
int main()
{
    QUANTIZE::QUANTIZE();
}
#endif
