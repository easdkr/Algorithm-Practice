#define _CRT_SECURE_NO_WARNINGS 
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
//연산의 개수 
int N;
struct abs_compare {
	//false이면 j가 우선순위가 높다고 판단
	//true이면 i가 우선순위가 높다고 판단
	bool operator()(int i, int j) {
		if (abs(i) == abs(j)) {
			if (i < 0) return false;
			if (j < 0) return true;
		}
		return abs(i) > abs(j);
	}
}; 

typedef priority_queue<int, vector<int>, abs_compare> abs_heap;

int main(void) {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	abs_heap absHeap;

	cin >> N;

	for (int i = 0; i < N; ++i) {
		int x; 
		cin >> x;
		if (x == 0) {
			if (absHeap.empty())
				cout << "0\n";
			else {
				cout << absHeap.top() << "\n";
				absHeap.pop();
			}
		}
		else {
			absHeap.push(x);
		}

	}
	
	return 0;
}
