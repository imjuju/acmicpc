#include <cstdio>

int R, C, N;
char map[100][100];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void dfs(int y, int x) {
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (0 > ny || ny >= R || 0 > nx || nx >= C) continue;
		if()
		dfs(ny, nx);
	}
}


int main() {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) 
		for (int j = 0; j < C; j++) 
			scanf(" %c", &map[i][j]);


	// 막대 던지기
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int y;
		scanf("%d", &y);
		y = R - y;

		// 왼쪽에서 오른쪽으로
		if (i % 2 == 0) {
			for (int x = 0; x < C; x++) {
				if (map[y][x] == 'x') {
					map[y][x] = '.';
					break;
				}
			}

			
		}

		// 오른쪽에서 왼쪽으로
		else {
			for (int x = C - 1; x >= 0; x--) {
				if (map[y][x] == 'x') {
					map[y][x] = '.';
					break;
				}
			}
		}
	}
}