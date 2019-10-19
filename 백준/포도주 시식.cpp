#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
vector<vector<int>> cache;
//포도잔의 개수 n
int n;
//각 잔의 양
vector<int> wine;
int solve(int select, int succ);
int main(void){
	cin >> n;
	wine = vector<int>(n);
	cache = vector<vector<int>>(10001, vector<int>(3,-1));
	for (int i = 0; i < n; ++i) cin >> wine[i];
	cout << solve(0, 0);
	return 0;
}

int solve(int select, int succ) {
	if (select >= n) return 0;
	if (succ == 2) return solve(select + 1, 0);
	int& ret = cache[select][succ];
	if (ret != -1) return ret;
    //계속 안풀렸던 이유 : 
    //선택 안 할때 solve(select+1, 0)으로 해야하는데 (초기화 되니까 0)
    //0 대신 succ를 써서 일부 테스트케이스에 대해 해결이 안됐다. 
	ret = max(solve(select + 1, succ+1) + wine[select], solve(select + 1, 0));
	return ret;
}

