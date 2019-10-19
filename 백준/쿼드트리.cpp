#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//영상의 크기 
int N; 
//영상
vector<string> img;
//쿼드트리압축을 저장할 문자열
string qudeTree;
//(xBegin,yBegin) ~ (xBegin+size, yBegin+size) 까지 압축이 가능한지를 반환한다. 
bool isCombinable(int xBegin, int yBegin, int size) {
	int baseColor = img[yBegin][xBegin];
	for (int y = yBegin; y < yBegin + size; ++y)
		for (int x = xBegin; x < xBegin + size; ++x)
			if (baseColor != img[y][x])
				return false;
	return true;
}
//(xBegin, yBegin) ~ (xBegin+size, yBegin+size)까지 압축한다. 
void compression(int xBegin, int yBegin, int size) {
	//압축가능하면 현재 색을 추가하고 함수를 끝낸다. 
	if (isCombinable(xBegin, yBegin, size)) {
		qudeTree.push_back(img[yBegin][xBegin]);
		return;
	}
	//압축이 불가능하면 영상을 1/4로 나눈다. 
	//나눌 때마다 괄호를 씌운다. 
	qudeTree.push_back('(');
	int half = size / 2;
	compression(xBegin, yBegin, half);
	compression(xBegin + half, yBegin, half);
	compression(xBegin, yBegin + half, half);
	compression(xBegin + half, yBegin + half, half);
	qudeTree.push_back(')');
}

int main(void) {
	cin >> N;
	img = vector<string>(N);
	for (int i = 0; i < N; ++i)
		cin >> img[i];

	compression(0, 0, N);
	cout << qudeTree << "\n";
	
	return 0;
}
