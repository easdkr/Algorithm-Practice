/*
* 알고리즘이 복잡하진 않았는데 문제 이해가 어려웠고 구현이 생각보다 힘든 문제였다.
* 문제의 설명대로 구현하면 되는데 왼쪽으로 한번씩 (최대 4번) 회전하면서 
* 청소할 공간을 찾으면 해당 좌표를 청소(탐색)하고, 
* 4회전 후에도 청소할 곳이 없으면 후진을하고, 
* 모든케이스가 불가능한 경우 탐색을 종료한다. 
* 회전방향에 대해 주의해야한다. 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class Robot {
public:
    Robot(int _y, int _x, int _dir) :
        y(_y), x(_x), dir(_dir) {};
    int y;
    int x;
    int dir;
};
//                  북 동 남 서
const int my[4] = { -1, 0, 1, 0 };
const int mx[4] = { 0, 1, 0, -1 };
int N, M;
int r, c, d;
vector<vector<int>> board;

void solve();
int bfs(Robot robot);
void input();
void init();
bool outOfRange(int y, int x);
int getLeftDir(int dir);
int getBackDir(int dir);
int main(void) {
    init();
    input();
    solve();
    return 0;
}
void solve() {
    cout << bfs(Robot(r, c, d));
}
int bfs(Robot startRobot) {
    int cnt = 0;
    queue<Robot> q;
    vector<vector<bool>> cleared = vector<vector<bool>>(N, vector<bool>(M, false));
    q.push(startRobot);
    cleared[startRobot.y][startRobot.x] = true;
    //첫 위치는 항상 청소해야하므로 +1
    cnt += 1;
    while (!q.empty()) {
        Robot curr = q.front();
        q.pop();
        
        int hy = curr.y, hx = curr.x;
        int hd = curr.dir;

        int ny = 0, nx = 0, nd = hd;
        bool isCleanedAround = true;
        //왼쪽으로 한번씩 돌면서 청소하지 않은 영역 탐색
        for (int i = 0; i < 4; ++i) {
            nd = getLeftDir(nd);
            ny = hy + my[nd], nx = hx + mx[nd];
            if (!outOfRange(ny, nx) && board[ny][nx] == 0 && !cleared[ny][nx]) {
                cleared[ny][nx] = true;
                ++cnt;
                q.push(Robot(ny, nx, nd));
                isCleanedAround = false;
                break;
            }
        }

        //후진
        if (isCleanedAround) {
            nd = getBackDir(hd);
            ny = my[nd] + hy, nx = mx[nd] + hx;
            if (!outOfRange(ny, nx)) {
                if (board[ny][nx] == 0)
                    q.push(Robot(ny, nx, hd));
            }
        }
    }
    return cnt;
}
void input() {
    cin >> N >> M;
    cin >> r >> c >> d;
    board = vector<vector<int>>(N, vector<int>(M));
    for (int y = 0; y < N; ++y)
        for (int x = 0; x < M; ++x)
            cin >> board[y][x];
}
void init() {
    std::iostream::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool outOfRange(int y, int x) {
    if (y >= N || y < 0 || x >= M || x < 0) return true;
    return false;
}

//왼쪽 좌표
int getLeftDir(int dir) {
    //북 동 남 서 (0, 1, 2, 3)
    //서 동 북 남 (3, 0, 1, 2)
    if (dir == 0) return 3;
    else if (dir == 1) return 0;
    else if (dir == 2) return 1;
    else return 2;
}
//뒤쪽 좌표
int getBackDir(int dir) {
    //북 동 남 서 (0, 1, 2, 3)
    //남 서 북 동 (2, 3, 0, 1)
    if (dir == 0) return 2;
    else if (dir == 1) return 3;
    else if (dir == 2) return 0;
    else return 1;
}