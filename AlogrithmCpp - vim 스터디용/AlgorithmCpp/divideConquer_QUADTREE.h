//대량의 좌표 데이터를 메모리 안에 압축해 저장하기 위해 사용하는 여러 기법 중 쿼드 트리(quad tree)란 것이 있습니다.
//주어진 공간을 항상 4개로 분할해 재귀적으로 표현하기 때문에 쿼드 트리라는 이름이 붙었는데, 이의 유명한 사용처 중 하나는 검은 색과 흰 색밖에 없는 흑백 그림을 압축해 표현하는 것입니다.
//쿼드 트리는 2N × 2N 크기의 흑백 그림을 다음과 같은 과정을 거쳐 문자열로 압축합니다.
//
//
//이 그림의 모든 픽셀이 검은 색일 경우 이 그림의 쿼드 트리 압축 결과는 그림의 크기에 관계없이 b가 됩니다.
//
//이 그림의 모든 픽셀이 흰 색일 경우 이 그림의 쿼드 트리 압축 결과는 그림의 크기에 관계없이 w가 됩니다.
//
//모든 픽셀이 같은 색이 아니라면, 쿼드 트리는 이 그림을 가로 세로로 각각 2등분해 4개의 조각으로 쪼갠 뒤 각각을 쿼드 트리 압축합니다.
//이때 전체 그림의 압축 결과는 x(왼쪽 위 부분의 압축 결과)(오른쪽 위 부분의 압축 결과)(왼쪽 아래 부분의 압축 결과)(오른쪽 아래 부분의 압축 결과)가 됩니다.
//예를 들어 그림(a)의 왼쪽 위 4분면은 xwwwb로 압축됩니다.
//
//그림(a)와 그림(b)는 16×16 크기의 예제 그림을 쿼드 트리가 어떻게 분할해 압축하는지를 보여줍니다.
//이때 전체 그림의 압축 결과는 xxwww bxwxw bbbww xxxww bbbww wwbb가 됩니다.
//
//
//쿼드 트리로 압축된 흑백 그림이 주어졌을 때, 이 그림을 상하로 뒤집은 그림 을 쿼드 트리 압축해서 출력하는 프로그램을 작성하세요.
//
//
//입력
//첫 줄에 테스트 케이스의 개수 C(C≤50)가 주어집니다.
//그 후 C줄에 하나씩 쿼드 트리로 압축한 그림이 주어집니다.
//모든 문자열의 길이는 1, 000 이하이며, 원본 그림의 크기는 220 × 220 을 넘지 않습니다.
//
//
//출력
//각 테스트 케이스당 한 줄에 주어진 그림을 상하로 뒤집은 결과를 쿼드 트리 압축해서 출력합니다.
//https://www.algospot.com/judge/problem/read/QUADTREE
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

namespace QUADTREE {
    void QUADTREE();
    //#ifndef MainFile
    struct Node{
        unique_ptr<struct Node> nodes[4];
        char colors[4] = { 0 };
    };
    template<typename T, typename... Args>
    std::unique_ptr<T> make_unique(Args&&... args) {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }
    typedef struct Node Node;
    void BuildTree(stringstream& input, Node* node) {
        FOR(i, 4) {
            input >> node->colors[i];
            if (node->colors[i] == 'x') {
                node->nodes[i] = make_unique<Node>();
                BuildTree(input, node->nodes[i].get());
            }
        }
    }
    void PrintTree(Node* const& node) {
        FOR(i, 4) {
            cout << node->colors[i];
            if (node->colors[i] == 'x') {
                PrintTree(node->nodes[i].get());
            }
        }
    }
    void InvertTree(Node* node) {
        auto tempChar = node->colors[0];
        node->nodes[0].swap(node->nodes[2]);
        node->colors[0] = node->colors[2];
        node->colors[2] = tempChar;

        tempChar = node->colors[1];
        node->nodes[1].swap(node->nodes[3]);
        node->colors[1] = node->colors[3];
        node->colors[3] = tempChar;

        FOR(i, 4)
            if (node->nodes[i].get() != nullptr)
                InvertTree(node->nodes[i].get());
    }

    void QUADTREE() {
#ifdef test
        stringstream cin(string("4\n w\nxbwwb\nxbwxwbbwb\nxxwwwbxwxwbbbwwxxxwwbbbwwwwbb\n"));
#endif
        int C;
        cin >> C;
        FOR(i, C) {
            //unique_ptr<Node> firstNode = make_unique<Node>();
            Node firstNode;
            char firstChar;
            cin >> firstChar;
            if (firstChar != 'x') {
                cout << firstChar << endl;
                continue;
            }
            string input;
            cin >> input;
            stringstream inputStream(input);
            //inputStream = stringstream(input);
            BuildTree(inputStream, &firstNode);
            InvertTree(&firstNode);
            cout << 'x';
            PrintTree(&firstNode);
            cout << endl;
        }
    }
    //#endif
}
#ifndef YunuComputer
    int main() {
        QUADTREE::QUADTREE();
    }
#endif
