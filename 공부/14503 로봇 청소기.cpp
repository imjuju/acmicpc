// ���� ��ġ�� û��

// ���� ���⿡ ���� û������ ���� ������ ������
// �� �������� ȸ���� �� �� ĭ ����

// ����

// d = 0 ��, 1 �� , 2 ��, 3 ��

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

		// �� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���̰�
		if (map[r - 1][c] != 0 && map[r + 1][c] != 0 && map[r][c - 1] != 0 && map[r][c + 1] != 0) {
			// ���� ������ ���̶� ������ �� ������ �۵��� �����
			if (map[r - dy[d]][c - dx[d]] == 1) break;
			// �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �Ѵ�
			else {
				r -= dy[d];
				c -= dx[d];
			}
		}

		else {
			d = (d - 1 + 4) % 4;
			// ���� ���⿡ ���� û������ ���� ������ �����ϸ� ����
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
