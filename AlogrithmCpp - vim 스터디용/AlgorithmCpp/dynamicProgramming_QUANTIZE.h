#pragma once
//Quantization(양자화) 과정은, 더 넓은 범위를 갖는 값들을 작은 범위를 갖는 값들로 근사해 표현함으로써 자료를 손실 압축하는 과정을 말한다.
//예를 들어 16비트 JPG 파일을 4컬러 GIF 파일로 변환하는 것은 RGB 색 공간의 색들을 4컬러 중의 하나로 양자화하는 것이고, 키가 161, 164, 170, 178 인 학생 넷을 '160대 둘, 170대 둘' 이라고 축약해 표현하는 것 또한 양자화라고 할 수 있다.
//
//
//1000 이하의 자연수들로 구성된 수열을 최대 S종류 의 값만을 사용하도록 양자화하고 싶다.
//이 때 양자화된 숫자는 원래 수열에 없는 숫자일 수도 있다.
//양자화를 하는 방법은 여러 가지가 있다.
//수열 1 2 3 4 5 6 7 8 9 10 을 2개의 숫자만을 써서 표현하려면, 3 3 3 3 3 7 7 7 7 7 과 같이 할 수도 있고, 1 1 1 1 1 10 10 10 10 10 으로 할 수도 있다.
//우리는 이 중, 각 숫자별 오차 제곱의 합을 최소화하는 양자화 결과를 알고 싶다.
//
//
//예를 들어, 수열 1 2 3 4 5 를 1 1 3 3 3 으로 양자화하면 오차 제곱의 합은 0 + 1 + 0 + 1 + 4 = 6 이 되고, 2 2 2 4 4 로 양자화하면 오차 제곱의 합은 1 + 0 + 1 + 0 + 1 = 3 이 된다.
//
//
//수열과 S 가 주어질 때, 가능한 오차 제곱의 합의 최소값을 구하는 프로그램을 작성하시오.
//
//
//입력
//입력의 첫 줄에는 테스트 케이스의 수 C(1 <= C <= 50) 가 주어진다.
//각 테스트 케이스의 첫 줄에는 수열의 길이 N(1 <= N <= 100), 사용할 숫자의 수 S(1 <= S <= 10) 이 주어진다.
//그 다음 줄에 N개의 정수로 수열의 숫자들이 주어진다.
//수열의 모든 수는 1000 이하의 자연수이다.
//
//
//출력
//각 테스트 케이스마다, 주어진 수열을 최대 S 개의 수로 양자화할 때 오차 제곱의 합의 최소값을 출력한다.
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
