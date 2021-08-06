// 0행 0열에는 말이 놓여있음
// 말은 상하좌우로 이동할 수 있음
// 같은 알파벳이 적힌 칸을 두 번 지날 수 없음

// 말이 최대한 몇 칸을 지날 수 있는지 구해라

#include <cstdio>
#include <algorithm>
using namespace std;

int R, C;	// 세로 가로
int ans;
char map[20][20];
bool alpha[26];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void search(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;

		int na = map[ny][nx];	// next alpha
		
		// 지나온 적 없는 알파벳이면
		if (!alpha[na - 'A']) {
			alpha[na - 'A'] = true;
			search(ny, nx);
			alpha[na - 'A'] = false;
		}
	}

	int cnt = 0;
	for (int i = 0; i < 26; i++)
		if (alpha[i]) cnt++;
	ans = max(ans, cnt);
}
int main() {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) 
		for (int j = 0; j < C; j++) 
			scanf(" %c", &map[i][j]);
	

	alpha[map[0][0] - 'A'] = true;
	search(0, 0);

	printf("%d", ans);
}