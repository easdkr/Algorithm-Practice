/*
무조건 cache를 쓰려고 해서 더 헷갈린 문제 
그냥 알파벳 방문유무만 체크하면되는 백트래킹 문제이다. 
따로 base case가 없어서 헷갈린거같다 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int my[4] = { 1, -1, 0, 0 };
const int mx[4] = { 0, 0, 1, -1 };

void solve();
void input();
void init();
bool outOfRange(int y, int x);
void dfs(int y, int x, int cnt, int& answer);
int R, C;
vector<string> board;
vector<bool> visited;
int main(void) {
    init();
    input();
    solve();
    return 0;
}
void solve() {
    int answer = -1;
    //첫번째 위치는 항상 먼저 방문 
    visited[board[0][0] - 'A'] = true;
    dfs(0, 0, 1, answer);
    cout << answer;
}
void dfs(int y, int x, int cnt, int& answer) {
    answer = max(answer, cnt);
    for (int i = 0; i < 4; ++i) {
        int ny = y + my[i], nx = x + mx[i];
        if (!outOfRange(ny, nx)) {
            int color = board[ny][nx] - 'A';
            if (visited[color] == false) {
                visited[color] = true;
                dfs(ny, nx, cnt + 1, answer);
                visited[color] = false;
            }
        }
    }
}
void input() {
    cin >> R >> C;
    board.resize(R);
    for (int i = 0; i < R; ++i)
        cin >> board[i];
}
void init() {
    std::iostream::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    visited.resize(26, false);
}

bool outOfRange(int y, int x) {
    if (y < 0 || y >= R || x < 0 || x >= C) return true;
    return false;
}