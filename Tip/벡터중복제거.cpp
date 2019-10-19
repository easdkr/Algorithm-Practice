#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
	vector<int> ret = {1,2,3, 1, 2, 3, 4, 5, 6};
    //unique를 하기 위해서는 정렬을 먼저한다.  
	sort(ret.begin(), ret.end());
    //unique는 버려진 원소의 첫번째 인덱스를 반환
	ret.erase(unique(ret.begin(), ret.end()), ret.end());
	
	for (auto i : ret)
		cout << i << " ";
	cout << "\n";
	return 0;
}