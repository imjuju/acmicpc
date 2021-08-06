// �̵��ϴ� ĭ�� ������ ���� 0�̸�
// �ֻ��� �ٴڸ鿡 ���� �ִ� ���� ĭ�� ����ȴ�

// 0�� �ƴϸ�
// ĭ�� ���� �ִ� ���� �ֻ��� �ٴڸ����� ����ǰ�
// ĭ�� ���� �ִ� ���� 0�� �ȴ�

// �ֻ����� �̵����� �� ���� ��ܿ� ���� �ִ� ���� ���϶�

#include <cstdio>

int N, M;	// ���� ����
int x, y;	// �ֻ��� ��ǥ
int K;	// ����� ����
int map[20][20];
int dice[7];

int dy[5] = { 0,0,0,-1,1 };	// �����ϳ�
int dx[5] = { 0,1,-1,0,0 };

int main() {
	scanf("%d %d %d %d %d", &N, &M, &y, &x, &K);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < K; i++) {
		int k;	// ���
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

