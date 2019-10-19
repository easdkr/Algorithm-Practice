#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int red);
//세로, 가로 크기가 주어질 때, 
//갈색 격자의 수를 반환한다. 
int getBrown(int height, int width);
int main(void) {
	int brown = 24, red = 24;
	cout << solution(brown, red)[0] << solution(brown, red)[1];
	return 0;
}
int getBrown(int height, int width) {
	return (width + height - 2) * 2;
}
vector<int> solution(int brown, int red) {
	vector<int> answer;
	//전체 면적
	int area = brown + red;
	//모든 세로 크기에 대해 완전 탐색을 진행한다.
	//세로의 최소 : 3 , 최대 : 전체면적의 제곱근
	for (int h = 3; h <= int(sqrt(area)); ++h) {
		//전체 면적으로 나누어 떨어지면 일단 카펫 가능
		if (area % h == 0) {
			//가로 크기 
			int w = area / h;
			//현재 가로, 세로 크기에서 구할 수 있는 brown의 개수 
			int _brown = getBrown(h, w);
			//만약 _brown == brown이면 정담
			if (_brown == brown) {
				answer = vector<int>({ w, h });
				break;
			}
		}
	}
	return answer;
}