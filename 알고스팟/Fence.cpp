#define _CRT_SECURE_NO_WARNINGS 
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <cstring>
using namespace std;
//판자의 수 
int n;
//테스트케이스의 수 
int c;
//판자별 높이 
vector<int> fence_heights;

//분할 정복으로 잘라낼 수 있는 울타리의 최대면적을 계산한다. 
//left~ right 까지 최대 울타리의 최대면적을 계산한다. 
//int getMaxArea(int left, int right) {
//	int ret = 0;
//	if (left == right) return fence_heights[left];
//	int mid = (left + right) / 2;
//	ret = max(getMaxArea(left, mid), getMaxArea(mid + 1, right));
//	//가운데 부분의 울타리 면적계산 
//	int lo = mid, hi = mid + 1;
//	int height = min(fence_heights[lo], fence_heights[hi]);
//	ret = max(ret, height * 2); 
//	//가운데 부분을 포함하는 면적을 계산한다. 
//	while (lo > left || hi < right) {
//		//항상 더 큰쪽을 선택해서 확장해간다. 
//		if ((hi < right) && ((lo == left) || (fence_heights[hi+1] > fence_heights[lo-1]))) {
//			++hi;
//			height = min(height, fence_heights[hi]);
//		}
//		else {
//			--lo;
//			height = min(height, fence_heights[lo]);
//		}
//		ret = max(ret, height * (hi - lo + 1));
//	}
//	return ret;
//}


//스택을 이용하여 잘라낼 수 있는 울타리의 최대면적을 계산한다. 
int getMaxArea() {
	int ret = 0;
	//왼쪽의 울타리들을 저장할 스택
	stack<int> left;
	//펜스에 가장 오른쪽에 높이 0의 나무판자가 있다고 가정한다. 
	fence_heights.push_back(0);
	//첫번째 울타리를 최대로 가정한다 .
	ret = fence_heights[0];
	//모든 울타리를 탐색한다. 
	for (int i = 0; i < fence_heights.size(); ++i) {
		//왼쪽에 남아있는 판자 중 오른쪽 끝 판자h[j]가 h[i]보다 높다면 
		//j의 최대 사각형은 i에서 끝난다. 
		while (!left.empty() &&
			fence_heights[left.top()] >= fence_heights[i]) {
			int j = left.top(); left.pop();
			int width = 0;
			//뽑았는데 왼쪽에 아무것도 없는 경우
			if (left.empty()) width = i; // i인 이유 : 울타리가 0번부터 시작이므로 i-1울타리까지 너비 = i이다. 
			//왼쪽에 울타리가 남아있다면 남아있는 울타리 바로 앞까지 너비 계산 
			else width = i - (left.top() + 1);

			ret = max(ret, width * fence_heights[j]);
		}
		left.push(i);
	}
	return ret;
}
int main(void) {
	cin >> c;
	for (int i = 0; i < c; ++i) {
		//판자 개수 입력
		cin >> n;
		//높이 입력 
		fence_heights = vector<int>(n + 1);
		for (int i = 0; i < n; ++i)
			cin >> fence_heights[i];

		cout << getMaxArea() << "\n";
	}
	return 0;
}
