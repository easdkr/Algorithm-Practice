#include <string>
#include <vector>

using namespace std;

int solution(vector<string> board) {
	int answer = 0;
	//3부터 사이즈를 2씩 늘려가며 X 모양을 탐색한다. 
	for (int size = 3; size <= board.size(); size += 2) {
		//모든 board를 탐색한다. 
		for (int y = 0; y <= board.size() - size; ++y) {
			for (int x = 0; x <= board.size() - size; ++x) {
				char base = board[y][x];
				bool Xflag = true;
				//오른쪽 아래로 가는 대각선 검사 
				for(int i = 0; i < size; ++i)
					if (board[y + i][x + i] != base) {
						Xflag = false;
						break;
					}
				//flag를 검사하여 X가 불가능하면 넘어간다. 
				if (!Xflag) continue;
				//왼쪽 아래로 가는 대각선 검사 
				for(int i = 0; i < size ; ++i)
					if (board[y + i][x + size - i - 1] != base) {
						Xflag = false;
						break;
					}
				if (!Xflag) continue;
				
				if (Xflag) {
					answer = size;
                    break;
				}
			}
		}
	}
	return answer;
}

int main(void){
	vector<string> board = {
		"ABCBA",
		"DABAG",
		"EBABH",
		"FAJAI",
		"AKLMA"
	};
	cout << solution(board);
	return 0;
}