#include <cstdio>
#include <queue>
using namespace std;

int N;
int cnt;
int map[20][20];

struct state {
	int y, x, dir;
};

void BFS() {
	queue<state> q;
	q.push({ 0,1,0 });

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int dir = q.front().dir;
		q.pop();

		if (y == N - 1 && x == N - 1) {
			cnt++;
			continue;
		}

		int ny, nx, ndir;

		// 밀 방향이 가로
		if (dir == 0 || dir == 2) {
			ny = y;
			nx = x + 1;
			if (nx < N && map[ny][nx] == 0) {
				q.push({ ny,nx,0 });
			}
		}

		// 밀 방향이 세로
		if (dir == 1 || dir == 2) {
			ny = y + 1;
			nx = x;
			if (ny < N && map[ny][nx] == 0) {
				q.push({ ny,nx,1 });
			}
		}

		// 밀 방향이 대각선
		if (dir == 0 || dir == 1 || dir == 2) {
			ny = y + 1;
			nx = x + 1;
			if (ny < N && nx < N && map[ny][nx] == 0 && map[ny][x] == 0 && map[y][nx] == 0) {
				q.push({ ny,nx,2 });
			}
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);

	BFS();
	printf("%d", cnt);
}