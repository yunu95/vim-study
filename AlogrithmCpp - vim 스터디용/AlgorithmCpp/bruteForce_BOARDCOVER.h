//H* W 크기의 게임판이 있습니다.게임판은 검은 칸과 흰 칸으로 구성된 격자 모양을 하고 있는데 이 중 모든 흰 칸을 3칸짜리 L자 모양의 블록으로 덮고 싶습니다.
// 이 때 블록들은 자유롭게 회전해서 놓을 수 있지만, 서로 겹치거나, 검은 칸을 덮거나, 게임판 밖으로 나가서는 안 됩니다.
// 위 그림은 한 게임판과 이를 덮는 방법을 보여줍니다.
//
//게임판이 주어질 때 이를 덮는 방법의 수를 계산하는 프로그램을 작성하세요.
//
//입력
// 입력의 첫 줄에는 테스트 케이스의 수 C(C <= 30) 가 주어집니다.
// 각 테스트 케이스의 첫 줄에는 2개의 정수 H, W(1 <= H, W <= 20) 가 주어집니다.
// 다음 H 줄에 각 W 글자로 게임판의 모양이 주어집니다.
// # 은 검은 칸, . 는 흰 칸을 나타냅니다.
// 입력에 주어지는 게임판에 있는 흰 칸의 수는 50 을 넘지 않습니다.
//
//출력
//한 줄에 하나씩 흰 칸을 모두 덮는 방법의 수를 출력합니다.
// https://www.algospot.com/judge/problem/read/BOARDCOVER
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

using namespace std;

void BOARDCOVER();

#ifndef MainFile
char board[20][20] = { false };
// **  * * 
//  * ** ** 
int dy[12][3] = { {0,0,-1},{0,-1,-1},{0,0,+1} ,{0,+1,+1}, {0,0,+1},{0,-1,-1},{0,0,-1} ,{0,+1,+1} , {0,+1,0},{0,0,-1},{0,-1,0} ,{0,0,+1} };
int dx[12][3] = { {0,+1,+1},{0,0,-1},{0,-1,-1} ,{0,0,+1}, {0,+1,+1},{0,0,+1},{0,-1,-1} ,{0,0,-1} , {0,0,-1},{0,-1,0},{0,0,+1} ,{0,+1,0} };
int H, W;
int solutionCount;

bool Overlay(const int& y, const int& x, const int& layType)
{
    FOR(i, 3) {
        int currentY = y + dy[layType][i];
        int currentX = x + dx[layType][i];
        if (currentX < 0 || currentY < 0 || currentX >= W || currentY >= H)
            return false;
        else
            if (board[currentY][currentX] == '#')
                return false;
    }
    FOR(i, 3)
        board[y + dy[layType][i]][x + dx[layType][i]] = '#';
    return true;
}
void Detach(const int& y, const int& x, const int& layType)
{
    FOR(i, 3)
        board[y + dy[layType][i]][x + dx[layType][i]] = '.';
}
void backTracking(const int& y, const int& x)
{
    if (board[y][x] == '#')
        if (y == H - 1 && x == W - 1)
        {
            solutionCount++;
            return;
        }
        else
            backTracking(x + 1 == W ? y + 1 : y, x + 1 == W ? 0 : x + 1);
    FOR(i, 12)
        if (Overlay(y, x, i))
        {
            if (y == H - 1 && x == W - 1)
                solutionCount++;
            else
                backTracking(x + 1 == W ? y + 1 : y, x + 1 == W ? 0 : x + 1);
            Detach(y, x, i);
        }
}
void BOARDCOVER() {
#ifdef test
    stringstream cin(string("3\n3 7\n#.....# \n#.....# \n##...##\n3 7\n#.....# \n#.....# \n##..### \n8 10\n##########\n#........# \n#........# \n#........# \n#........# \n#........# \n#........# \n########## \n"));
#endif
    int C;
    cin >> C;
    FOR(i, C) {
        cin >> H;
        cin >> W;
        FOR(j, H)
            FOR(k, W)
            cin >> board[j][k];
        solutionCount = 0;
        backTracking(0, 0);
        cout << solutionCount << '\n';
    }
}
#endif

#ifndef YunuComputer
int main() {
    BOARDCOVER();
}
#endif
