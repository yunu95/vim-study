//보글(Boggle) 게임은 그림(a)와 같은 5x5 크기의 알파벳 격자인
//게임판의 한 글자에서 시작해서 펜을 움직이면서 만나는 글자를 그 순서대로 나열하여 만들어지는 영어 단어를 찾아내는 게임입니다.
//펜은 상하좌우, 혹은 대각선으로 인접한 칸으로 이동할 수 있으며 글자를 건너뛸 수는 없습니다.
//지나간 글자를 다시 지나가는 것은 가능하지만, 펜을 이동하지않고 같은 글자를 여러번 쓸 수는 없습니다.
//
//입력
//입력의 첫 줄에는 테스트 케이스의 수 C(C <= 50)가 주어집니다.각 테스트 케이스의 첫 줄에는 각 5줄에 5글자로 보글 게임판이 주어집니다.게임판의 모든 칸은 알파벳 대문자입니다.
//그 다음 줄에는 우리가 알고 있는 단어의 수 N(1 <= N <= 10)이 주어집니다.그 후 N줄에는 한 줄에 하나씩 우리가 알고 있는 단어들이 주어집니다.각 단어는 알파벳 대문자 1글자 이상 10글자 이하로 구성됩니다.
//
//출력
//각 테스트 케이스마다 N줄을 출력합니다.각 줄에는 알고 있는 단어를 입력에 주어진 순서대로 출력하고, 해당 단어를 찾을 수 있을 경우 YES, 아닐 경우 NO를 출력합니다.
//https://www.algospot.com/judge/problem/read/BOGGLE
#pragma once
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

char board[5][5];
bool isProspective[5][5][100] = { true };
vector<string> words;
const int deltaRow[] = { 1,1,0,-1,-1,-1,0,1 };
const int deltaCol[] = { 0,1,1,1,0,-1,-1,-1 };
const auto testInput = "1\nURLPM\nXPRET\nGIAET\nXTNZY\nXOQRS\n6\nPRETTY\nGIRL\nREPEAT\nKARA\nPANDORA\nGIAZAPX";

bool BackTracking(int row, int col, string word) {
    if (row < 0 || row>5 || col < 0 || col >5)
        return false;
    if (word.length() == 1 && word[0] == board[row][col])
        return true;
    if (word[0] != board[row][col])
        return false;
    FOR(direction, 8)
        if (BackTracking(row + deltaRow[direction], col + deltaCol[direction], word.substr(1)))
            return true;
    return false;
}
void BOGGLE() {
#ifdef test
    stringstream cin(testInput);
#endif
    int C = 1;
    cin >> C;
    FOR(i, C) {
        int n;
        vector<bool> found;
        FOR(j, 25) {
            char letter;
            cin >> letter;
            board[j / 5][j % 5] = letter;
        }
        cin >> n;
        words = vector<string>(n);
        found = vector<bool>(n);
        FOR(j, n) {
            cin >> words[j];
        }
        FOR(j, 25) {
            auto row = j / 5;
            auto col = j % 5;
            // BackTracking
            FOR(k, n) {
                /*if (failedBefore[i][j][k])
                    continue;*/
                if (BackTracking(row, col, words[k]))
                    found[k] = true;
            }
        }
        FOR(j, n)
            cout << words[j] << ' ' << (found[j] ? "YES" : "NO") << '\n';
    }
}


#ifndef YunuComputer
int main() {
    BOGGLE();
}
#endif

