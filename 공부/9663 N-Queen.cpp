#include <cstdio>

int N;
int cnt;
bool chess_row[15];		
bool chess_dig1[30];	
bool chess_dig2[30];	

// calc(x): x 열에 퀸을 어디 놓을지 결정하는 함수
void calc(int x) {
	if (x == N) {
		cnt++;
		return;
	}
	for (int y = 0; y < N; y++) {
		if (!chess_row[y] && !chess_dig1[x + y] && !chess_dig2[y - x + N - 1]) {
			chess_row[y] = true;
			chess_dig1[x + y] = true;
			chess_dig2[y - x + N - 1] = true;
			
			calc(x + 1);

			chess_row[y] = false;
			chess_dig1[x + y] = false;
			chess_dig2[y - x + N - 1] = false;
		}
	}
}

int main() {
	scanf("%d", &N);
	calc(0);
	printf("%d", cnt);
}

/*
#include <cstdio>

int N;
int cnt;
bool chess[15][15];	// 퀸을 놓으면 true로

bool check(int y, int x) {
	for (int i = 0; i < x; i++)
		if (chess[y][i]) return false;
	for (int i = 1; y - i >= 0 && x - i >= 0; i++)
		if (chess[y - i][x - i]) return false;
	for (int i = 1; y + i < N && x - i >= 0; i++)
		if (chess[y + i][x - i]) return false;

	return true;
}

// calc(x): x 열에 퀸을 어디 놓을지 결정하는 함수
void calc(int x) {
	if (x == N) {
		cnt++;
		return;
	}
	for (int y = 0; y < N; y++) {
		chess[y][x] = true;
		if (check(y, x)) calc(x + 1);
		chess[y][x] = false;
	}
}

int main() {
	scanf("%d", &N);
	calc(0);
	printf("%d", cnt);
}
*/



/*

#include <cstdio>

int N;
int cnt;
bool chess[15][15];	// 퀸을 놓을 수 있는 상태의 칸은 false

void func(int idx) {

	if (idx == N) {
		cnt++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!chess[i][idx]) {

			bool chess_copy[15][15];
			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
					chess_copy[j][k] = chess[j][k];

			// 가로칸은 더 이상 퀸을 놓을 수 없다
			for (int j = idx; j < N; j++) chess[i][j] = true;
			
			// 대각선칸은 더 이상 퀸을 놓을 수 없다
			for (int j = 1; i + j < N && idx + j < N; j++) chess[i + j][idx + j] = true;
			for (int j = 1; i - j >= 0 && idx + j < N; j++) chess[i - j][idx + j] = true;

			func(idx + 1);

			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
					chess[j][k] = chess_copy[j][k];

		}
	}
}

int main() {
	scanf("%d", &N);
	func(0);
	printf("%d", cnt);
}
*/