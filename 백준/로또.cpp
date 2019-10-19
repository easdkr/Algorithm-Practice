#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string A, B;
vector<bool> visited;
vector<int> picked;
int k;
vector<int> nums;
void pick(int toPick, int prior) {
	if (toPick == 0) {
		for (auto i : picked)
			cout << nums[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < k; ++i) {
		if (!visited[i] && prior < i) {
			visited[i] = true;
			picked.push_back(i);
			pick(toPick - 1, i);
			picked.pop_back();
			visited[i] = false;
		}
	}
}
int main(void){
	while (true) {
		cin >> k;
		if (k == 0) break;
		nums = vector<int>(k);
		visited = vector<bool>(k);
		for (int i = 0; i < k; ++i) 
			cin >> nums[i];
		
		pick(6, -1);
		nums.clear();
		visited.clear();
		cout << "\n";
	}
	return 0;
}