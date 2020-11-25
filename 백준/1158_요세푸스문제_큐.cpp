#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
void solve();
void input();
void init();
int N, K;
int main(void) {
    init();
    input();
    solve();
    return 0;
}
void solve() {
    queue<int> q;
    for (int i = 1; i <= N; ++i)
        q.push(i);
    cout << "<";
    while (!q.empty()) {
        if (q.size() == 1) {
            cout << q.front() << ">";
            q.pop();
        }
        else {
            //Å¥ È¸Àü
            for (int i = 0; i < K - 1; ++i) {
                q.push(q.front());
                q.pop();
            }
            cout << q.front() << ", ";
            q.pop();
        }

    }
}
void input() {
    cin >> N >> K;
}
void init() {
    std::iostream::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}