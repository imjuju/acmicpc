// 현재 위치를 청소

// 왼쪽 방향에 아직 청소하지 않은 공간이 있으면
// 그 방향으로 회전한 후 한 칸 전진

// 왼쪽

// d = 0 북, 1 동 , 2 남, 3 서

#include <cstdio>

int dy[4] = { -1,0,1,0 };		// -1,0,1,0
int dx[4] = { 0,1,0,-1 };		// 0,1,0,-1

int main() {
	int N, M;
	int r, c, d;
	int map[50][50];
	
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &d);
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			scanf("%d", &map[i][j]);
	
	while (true) {
		map[r][c] = 2;

		// 네 방향 모두 청소가 이미 되어있거나 벽이고
		if (map[r - 1][c] != 0 && map[r + 1][c] != 0 && map[r][c - 1] != 0 && map[r][c + 1] != 0) {
			// 뒤쪽 방향이 벽이라 후진할 수 없으면 작동을 멈춘다
			if (map[r - dy[d]][c - dx[d]] == 1) break;
			// 바라보는 방향을 유지한 채로 한 칸 후진을 한다
			else {
				r -= dy[d];
				c -= dx[d];
			}
		}

		else {
			d = (d - 1 + 4) % 4;
			// 왼쪽 방향에 아직 청소하지 않은 공간이 존재하면 전진
			if (map[r + dy[d]][c + dx[d]] == 0) {
				r += dy[d];
				c += dx[d];
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == 2) ans++;
	printf("%d", ans);
}
