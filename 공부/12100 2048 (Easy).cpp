#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
pair<int, bool> map[20][20];

int ans = 0;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void func(int cnt) {
	if (cnt >= 5) return;

	for (int dir = 0; dir < 4; dir++) {
		pair<int, bool> copy[20][20];

		// ���� ���� ����
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				copy[i][j] = map[i][j];

		while (true) {
			bool move = false;

			// ��
			if (dir == 0) {
				for (int y = 1; y < N; y++) {
					for (int x = 0; x < N; x++) {
						int ny = y + dy[dir], nx = x + dx[dir];

						// ���� ĭ�� �� ĭ - ����
						if (map[y][x].first == 0) continue;

						// ���� ĭ�� �� ĭ - �׳� �̵�
						if (map[ny][nx].first == 0) {
							map[ny][nx].first = map[y][x].first;
							map[ny][nx].second = map[y][x].second;
							map[y][x].first = 0;
							map[y][x].second = false;
							move = true;
						}

						// ���� ��ϰ� ���� ����� ���� ���� ��
						if (map[y][x].first == map[ny][nx].first) {
							// �� �� ������ �� ���� ����̸� - ��ģ��
							if (!map[y][x].second && !map[ny][nx].second) {
								map[ny][nx].first *= 2;
								map[ny][nx].second = true;
								map[y][x].first = 0;
								map[y][x].second = false;
								move = true;
							}
						}
					}
				}
			}

			// ��
			if (dir == 1) {
				for (int y = N - 2; y >= 0; y--) {
					for (int x = 0; x < N; x++) {
						int ny = y + dy[dir], nx = x + dx[dir];

						// ���� ĭ�� �� ĭ - ����
						if (map[y][x].first == 0) continue;

						// ���� ĭ�� �� ĭ - �׳� �̵�
						if (map[ny][nx].first == 0) {
							map[ny][nx].first = map[y][x].first;
							map[ny][nx].second = map[y][x].second;
							map[y][x].first = 0;
							map[y][x].second = false;
							move = true;
						}

						// ���� ��ϰ� ���� ����� ���� ���� ��
						if (map[y][x].first == map[ny][nx].first) {
							// �� �� ������ �� ���� ����̸� - ��ģ��
							if (!map[y][x].second && !map[ny][nx].second) {
								map[ny][nx].first *= 2;
								map[ny][nx].second = true;
								map[y][x].first = 0;
								map[y][x].second = false;
								move = true;
							}
						}
					}
				}
			}

			// ��
			if (dir == 2) {
				for (int y = 0; y < N; y++) {
					for (int x = 1; x < N; x++) {
						int ny = y + dy[dir], nx = x + dx[dir];

						// ���� ĭ�� �� ĭ - ����
						if (map[y][x].first == 0) continue;

						// ���� ĭ�� �� ĭ - �׳� �̵�
						if (map[ny][nx].first == 0) {
							map[ny][nx].first = map[y][x].first;
							map[ny][nx].second = map[y][x].second;
							map[y][x].first = 0;
							map[y][x].second = false;
							move = true;
						}

						// ���� ��ϰ� ���� ����� ���� ���� ��
						if (map[y][x].first == map[ny][nx].first) {
							// �� �� ������ �� ���� ����̸� - ��ģ��
							if (!map[y][x].second && !map[ny][nx].second) {
								map[ny][nx].first *= 2;
								map[ny][nx].second = true;
								map[y][x].first = 0;
								map[y][x].second = false;
								move = true;
							}
						}
					}
				}
			}

			// ��
			if (dir == 3) {
				for (int y = 0; y < N; y++) {
					for (int x = N - 2; x >= 0; x--) {
						int ny = y + dy[dir], nx = x + dx[dir];

						// ���� ĭ�� �� ĭ - ����
						if (map[y][x].first == 0) continue;

						// ���� ĭ�� �� ĭ - �׳� �̵�
						if (map[ny][nx].first == 0) {
							map[ny][nx].first = map[y][x].first;
							map[ny][nx].second = map[y][x].second;
							map[y][x].first = 0;
							map[y][x].second = false;
							move = true;
						}

						// ���� ��ϰ� ���� ����� ���� ���� ��
						if (map[y][x].first == map[ny][nx].first) {
							// �� �� ������ �� ���� ����̸� - ��ģ��
							if (!map[y][x].second && !map[ny][nx].second) {
								map[ny][nx].first *= 2;
								map[ny][nx].second = true;
								map[y][x].first = 0;
								map[y][x].second = false;
								move = true;
							}
						}
					}
				}
			}

			if (!move) break;
		}

		// �� ����
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ans = max(ans, map[i][j].first);
				map[i][j].second = false;
			}
		}		
		
		func(cnt + 1);

		// ���� ����
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++) {
				map[i][j].first = copy[i][j].first;
				map[i][j].second = false;
			}
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j].first);

	func(0);

	printf("%d", ans);
}
