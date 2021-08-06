// 이동하는 칸에 쓰여진 수가 0이면
// 주사위 바닥면에 쓰여 있는 수가 칸에 복사된다

// 0이 아니면
// 칸에 쓰여 있는 수가 주사위 바닥면으로 복사되고
// 칸에 쓰여 있는 수는 0이 된다

// 주사위가 이동했을 때 마다 상단에 쓰여 있는 값을 구하라

#include <cstdio>

int N, M;	// 세로 가로
int x, y;	// 주사위 좌표
int K;	// 명령의 개수
int map[20][20];
int dice[7];

int dy[5] = { 0,0,0,-1,1 };	// 동서북남
int dx[5] = { 0,1,-1,0,0 };

int main() {
	scanf("%d %d %d %d %d", &N, &M, &y, &x, &K);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < K; i++) {
		int k;	// 명령
		scanf("%d", &k);

		int ny = y + dy[k];
		int nx = x + dx[k];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
		
		if (k == 1) {
			int mid = dice[1];
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = mid;
		}
		else if (k == 2) {
			int mid = dice[1];
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[4];
			dice[4] = mid;
		}
		else if (k == 3) {
			int mid = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = mid;
		}
		else if (k == 4) {
			int mid = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = mid;
		}

		if (map[ny][nx] == 0) {
			map[ny][nx] = dice[6];
		}
		else {
			dice[6] = map[ny][nx];
			map[ny][nx] = 0;
		}
		printf("%d\n", dice[1]);

		y = ny;
		x = nx;
	}
}

