#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int solution(vector<int> citations) {
	int answer = 0;
	//내림차순 정렬
	sort(citations.begin(), citations.end(), greater<int>());
	int index = 0;
	//인덱스가 인용수보다 크거나 같은 시점이 올때까지 증가 
	while (index < citations.size() && citations[index] > index)
		index++;
	answer = index;
	return answer;
}
int main(void) {
	vector<int> citations = { 1545, 2, 999, 790, 540, 10, 22 };
	//vector<int> citations = { 3, 0, 6, 1, 5 };
	//vector<int> citations = { 0 };
	cout << solution(citations);
	return 0;
}