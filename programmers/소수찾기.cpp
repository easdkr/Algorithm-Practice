#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
const int MAX = 10000000;
//isPrime[i] : i가 소수인지 저장
bool isPrime[MAX+1];
vector<bool> visited;
vector<int> v;
int n;
vector<int> picked;
vector<int> ret;

//8자리 자연수까지 소수를 판별한다. 
void setPrime();
//벡터를 정수로 변환한다. 
void ArrayToNum();
//toPick 개의 순열을 만든다. 
void pick(int toPick);
//길이 i~m 까지 순열을 만든뒤 
//중복을 제거하여 중복이 없는 수들의 조합을 만든다.
void getPermutation();
//전체 문제를 해결한다. 
int solution(string numbers);
int main(void) {
	setPrime();
	string numbers = "17";
	cout << solution(numbers);
	return 0;
}

void setPrime() {
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= int(sqrt(MAX)); ++i) {
		//아직 지워지지 않은 수이면 
		//이 수의 배수들을 다 지운다. 
		if (isPrime[i]) {
			for (int j = i * i; j <= MAX; j += i)
				isPrime[j] = false;
		}
	}
}

void ArrayToNum() {
	string num;
	for (int i = 0; i < picked.size(); ++i)
		num += to_string(v[picked[i]]);
	ret.push_back(atoi(num.c_str()));
}

void pick(int toPick) {
	if (toPick == 0) {
		ArrayToNum();
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			visited[i] = true;
			picked.push_back(i);
			pick(toPick - 1);
			picked.pop_back();
			visited[i] = false;
		}
	}
}

void getPermutation() {
	//ret[i]: 길이가 i인 수 
	ret = vector<int>(n + 1);
	visited = vector<bool>(n + 1);
	//길이가 i 인 순열을 ret 배열에 저장한다. 
	for (int i = 1; i <= n; ++i)
		pick(i);

	//중복을 제거한다. 
	for (int i = 0; i < ret.size(); ++i) {
		sort(ret.begin(), ret.end());
		ret.erase(unique(ret.begin(), ret.end()), ret.end());
	}

}

int solution(string numbers) {
	int answer = 0;
	//string 타입의 수를 벡터로 변환 
	for (int i = 0; i < numbers.size(); ++i)
		v.push_back(numbers[i] - '0');
	//벡터의 길이 
	n = v.size();
	//중복이 없는 수들의 조합 저장 
	getPermutation();
	//소수 갯수 체크
	for (int i = 0; i < ret.size(); ++i)
		if (isPrime[ret[i]])
			answer++;
	return answer;
}