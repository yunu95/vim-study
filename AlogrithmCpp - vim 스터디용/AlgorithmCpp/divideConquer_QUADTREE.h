//�뷮�� ��ǥ �����͸� �޸� �ȿ� ������ �����ϱ� ���� ����ϴ� ���� ��� �� ���� Ʈ��(quad tree)�� ���� �ֽ��ϴ�.
//�־��� ������ �׻� 4���� ������ ��������� ǥ���ϱ� ������ ���� Ʈ����� �̸��� �پ��µ�, ���� ������ ���ó �� �ϳ��� ���� ���� �� ���ۿ� ���� ��� �׸��� ������ ǥ���ϴ� ���Դϴ�.
//���� Ʈ���� 2N �� 2N ũ���� ��� �׸��� ������ ���� ������ ���� ���ڿ��� �����մϴ�.
//
//
//�� �׸��� ��� �ȼ��� ���� ���� ��� �� �׸��� ���� Ʈ�� ���� ����� �׸��� ũ�⿡ ������� b�� �˴ϴ�.
//
//�� �׸��� ��� �ȼ��� �� ���� ��� �� �׸��� ���� Ʈ�� ���� ����� �׸��� ũ�⿡ ������� w�� �˴ϴ�.
//
//��� �ȼ��� ���� ���� �ƴ϶��, ���� Ʈ���� �� �׸��� ���� ���η� ���� 2����� 4���� �������� �ɰ� �� ������ ���� Ʈ�� �����մϴ�.
//�̶� ��ü �׸��� ���� ����� x(���� �� �κ��� ���� ���)(������ �� �κ��� ���� ���)(���� �Ʒ� �κ��� ���� ���)(������ �Ʒ� �κ��� ���� ���)�� �˴ϴ�.
//���� ��� �׸�(a)�� ���� �� 4�и��� xwwwb�� ����˴ϴ�.
//
//�׸�(a)�� �׸�(b)�� 16��16 ũ���� ���� �׸��� ���� Ʈ���� ��� ������ �����ϴ����� �����ݴϴ�.
//�̶� ��ü �׸��� ���� ����� xxwww bxwxw bbbww xxxww bbbww wwbb�� �˴ϴ�.
//
//
//���� Ʈ���� ����� ��� �׸��� �־����� ��, �� �׸��� ���Ϸ� ������ �׸� �� ���� Ʈ�� �����ؼ� ����ϴ� ���α׷��� �ۼ��ϼ���.
//
//
//�Է�
//ù �ٿ� �׽�Ʈ ���̽��� ���� C(C��50)�� �־����ϴ�.
//�� �� C�ٿ� �ϳ��� ���� Ʈ���� ������ �׸��� �־����ϴ�.
//��� ���ڿ��� ���̴� 1, 000 �����̸�, ���� �׸��� ũ��� 220 �� 220 �� ���� �ʽ��ϴ�.
//
//
//���
//�� �׽�Ʈ ���̽��� �� �ٿ� �־��� �׸��� ���Ϸ� ������ ����� ���� Ʈ�� �����ؼ� ����մϴ�.
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
