#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//입력값이 int의 범위를 넘어서 모든 처리를 string으로 해야했다
//입력값에 주의하자.
string N;
string solution() {
	//3의 배수인지 검사 
	int total = 0;
	for (int i = 0; i < N.size(); ++i)
		total += N[i];
	if (total % 3 != 0) return "-1";
	//10의 배수인지 검사
	bool tenFlag = false;
	for (int i = 0; i < N.size(); ++i) {
		if (N[i] == '0') {
			//cout << "0";
			tenFlag = true;
			break;
		}
	}
	if (tenFlag == false) return "-1";
	//30의 배수이면 내림차순 정렬하여 숫자를 만든뒤 리턴
	sort(N.begin(), N.end(), greater<int>());
	return N;
}
int main(void){
	cin >> N;
	cout << solution();
	return 0;
}