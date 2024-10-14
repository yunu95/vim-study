#pragma once
//����
//N���� ���ð� P���� �ܹ��� ��� ����Ǿ� �ִ�. �̼����� 1�� ���ÿ� 2�� ���� ���̸� ���� ���ظӸ� �Ѵ�. ������ �̼����� 1������ 2������ ���� ���� �ٸ� ��θ� �ִ��� ���� ã������ �ϴµ�, �̶� �� ��ο� ���Ե� ���� �ٸ� ��ο� ���ԵǸ� �ȵȴ�. �Է¿��� 1�� ���ÿ� 2�� ���ø� �����ϴ� ���� ����. ������ ��ȣ�� 1������ N�������̴�.
//
//�Է�
//ù° �ٿ� �� ���� N(3 �� N �� 400), P(1 �� P �� 10,000)�� �־�����. ���� P���� �ٿ��� �� ���� �����ϴ� ��� ���ÿ� ���� ������ ��ȣ�� �־�����, �� ��ȣ�� �ٸ���.
//
//���
//1������ 2������ ���� ���� �ٸ� ����� �ִ� ������ ����Ѵ�.
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
