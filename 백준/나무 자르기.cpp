#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//N: 나무의 수, M: 나무의 길이 
long long N, M;
vector<long long> tree;
long long ret;
//cutLen을 기준으로 잘랐을때 얻을 수 있는 나무의 길이 
long long getTreeLen(long long cutLen) {
	long long len = 0;
	for (int i = 0; i < tree.size(); ++i)
		if (tree[i] > cutLen)
			len += (tree[i] - cutLen);
	return len;
}
//이분 탐색을 진행한다. 
//mid를 기준으로 잘라 얻은 나무의 길이가 
//M보다 크면 더 많이 잘라내도 되니 더 큰쪽에서 탐색을 계속한다.
//M보다 작으면 더 적게 잘라내야하니 더 작은쪽으로 탐색을 계속한다. 
void binarySearch(long long left, long long right) {
	if (left > right) return;
	long long mid = (left + right) / 2;
	if (getTreeLen(mid) >= M) {
		ret = max(ret, mid);
		binarySearch(mid + 1, right);
	}
	/*else 
		binarySearch(left, mid - 1);*/
}
int main(void){
	cin >> N >> M;
	tree = vector<long long>(N);
	ret = -987654321;
	for (int i = 0; i < N; ++i)
		cin >> tree[i];
	sort(tree.begin(), tree.end());
	binarySearch(0, tree.back());
	cout << ret;
	return 0;
}