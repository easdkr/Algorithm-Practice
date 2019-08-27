#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//직사각형의 수 
int n; 
//각 직사각형의 높이
vector<int> h;
//left ~ right까지의 최대직사각형의 면적을 반환한다.
int maxSqaureArea(int left, int right) {
	int ret = 0;
	if (left == right) return h[left];
	int mid = (left + right) / 2;
	//반을 나눠서 최대면적을 재귀탐색한다.
	ret = max(maxSqaureArea(left, mid), maxSqaureArea(mid + 1, right));
	//가운데 부분을 포함하는 최대면적을 생각한다. 
	int lo = mid, hi = mid + 1;
	int height = min(h[lo], h[hi]);
	//가운데 부분의 면적 
	ret = max(ret, 2 * height);
	//가운데 부분을 포함하려면 가운데로 부터 확장되는 부분의 
	//높이가 항상 가운데의 높이보다 높아야한다.
	while (lo > left || hi < right) {
		//각 단계마다 왼쪽과 오른쪽 중 더 높은 쪽을 선택하며 확장한다. 
		if ((hi < right) && (lo == left || h[lo - 1] < h[hi + 1])) {
			++hi;
			height = min(height, h[hi]);
		}
		else {
			--lo;
			height = min(height, h[lo]);
		}
		ret = max(ret, (hi - lo + 1) * height);
	}
	return ret;
}
int main(void) {
	//cin >> n;
	h = vector<int>(100001, 0);
	for (int i = 0; i < 8; ++i)
		cin >> h[i];
	cout << maxSqaureArea(0, 8);
	return 0;
}
