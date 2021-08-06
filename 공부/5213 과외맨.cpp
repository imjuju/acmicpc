// 홀수 줄 = N개 타일
// 짝수 줄 = N - 1개 타일

// 넘어갈 수 있는 조건
// 1) 두 타일이 인접
// 2) 같은 변을 공유하는 조각에 쓰여있는 숫자가 같아야

// 과외맨
// from 첫 줄의 첫 타일
// to 마지막 줄의 마지막 타일
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

int N;
int num[500][500];	// 타일 번호
int map[500][500][2];
int dist[500][500];
bool visit[500][500];
pair<int, int> from[500][500];
int dy0[6] = { -1,-1,0,0,1,1 };
int dx0[6] = { -1,0,-1,1,-1,0 };
int dy1[6] = { -1,-1,0,0,1,1 };
int dx1[6] = { 0,1,-1,1,0,1 };


bool range(int y, int x) {
	if (y < 0 || y >= N) return false;
	if (y % 2 == 0) {
		if (x < 0 || x >= N) return false;
	}
	else {
		if (x < 0 || x >= N - 1) return false;
	}
	return true;
}

bool go(int y, int x, int ny, int nx, int dir) {
	if (dir == 0 || dir == 2 || dir == 4) {
		if (map[y][x][0] == map[ny][nx][1]) return true;
		else return false;
	}
	else {
		if (map[y][x][1] == map[ny][nx][0]) return true;
		else return false;
	}
}

void BFS() {
	queue<pair<int, int> > q;
	visit[0][0] = true;
	dist[0][0] = 1;
	from[0][0] = { -1,-1 };
	q.push({ 0,0 });

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int ny, nx;
			if (y % 2 == 0) {
				ny = y + dy0[i];
				nx = x + dx0[i];
			} 
			else {
				ny = y + dy1[i];
				nx = x + dx1[i];
			}

			if (!range(ny, nx)) continue;
			if (!go(y, x, ny, nx, i)) continue;
			if (visit[ny][nx]) continue;
			visit[ny][nx] = true;
			dist[ny][nx] = dist[y][x] + 1;
			from[ny][nx] = { y,x };
			q.push({ ny,nx });
		}
	}

}

int main() {
	int cnt = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < N; j++) {
				scanf("%d %d", &map[i][j][0], &map[i][j][1]);
				cnt++;
				num[i][j] = cnt;
			}
		}
		else {
			for (int j = 0; j < N - 1; j++) {
				scanf("%d %d", &map[i][j][0], &map[i][j][1]);
				cnt++;
				num[i][j] = cnt;
			}
		}
	}

	BFS();

	for (int i = N - 1; i >= 0; i--) {
		int temp;
		if (i % 2 == 0) temp = N - 1;
		else temp = N - 2;

		for (int j = temp; j >= 0; j--) {
			if (visit[i][j]) {
				printf("%d\n", dist[i][j]);

				int y = i;
				int x = j;
				stack<pair<int, int> > route;
				while (true) {
					if (y == -1 && x == -1) break;
					route.push({ y,x });
					int ty = y, tx = x;
					y = from[ty][tx].first;
					x = from[ty][tx].second;
				}

				while (!route.empty()) {
					printf("%d ", num[route.top().first][route.top().second]);
					route.pop();
				}
				return 0;
			
			}
		}
	}

}

/*
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

int N;
int cnt;
int map[501][1010];
int num[501][1010];	// 타일 번호
bool visit[501][1010];
pair<int, int> from[501][1010];	// 경로

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void BFS() {
	queue<pair<int, int> > q;
	q.push({ 1,1 });
	visit[1][1] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (num[y][x] == cnt)
			return;

		// 홀수행 일 때
		if (y % 2 == 1) {
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny<1 || ny>N || nx<1 || nx>N * 2) continue;
				if (visit[ny][nx]) continue;

				// 이동하려는 칸이 같은 타일일 때
				if ((x % 2 == 0 && i == 2) || (x % 2 == 1 && i == 3)) {
					visit[ny][nx] = true;
					from[ny][nx] = { y,x };
					q.push({ ny,nx });
				}
				// 이동하려는 칸이 다른 타일일 때
				else {
					if (map[y][x] == map[ny][nx]) {
						visit[ny][nx] = true;
						from[ny][nx] = { y,x };
						q.push({ ny,nx });
					}
				}


			}
		}

		// 짝수행 일 때
		else {
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny<1 || ny>N || nx<2 || nx>N * 2 - 1) continue;
				if (visit[ny][nx]) continue;

				// 이동하려는 칸이 같은 타일일 때
				if ((x % 2 == 0 && i == 3) || (x % 2 == 1 && i == 2)) {
					visit[ny][nx] = true;
					from[ny][nx] = { y,x };
					q.push({ ny,nx });
				}
				// 이동하려는 칸이 다른 타일일 때
				else {
					if (map[y][x] == map[ny][nx]) {
						visit[ny][nx] = true;
						from[ny][nx] = { y,x };
						q.push({ ny,nx });
					}
				}


			}
		}
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= N * 2; j++) {
				if (j % 2 == 1) cnt++;
				scanf("%d", &map[i][j]);
				num[i][j] = cnt;
			}
		}
		else {
			for (int j = 2; j <= N * 2 - 1; j++) {
				if (j % 2 == 0) cnt++;
				scanf("%d", &map[i][j]);
				num[i][j] = cnt;
			}
			map[i][1] = map[i][N * 2] = -1;
		}

	}

	BFS();

	for (int i = N; i >= 1; i--) {
		for (int j = N * 2; j >= 1; j--) {
			if (from[i][j].first != 0 && from[i][j].second != 0) {
				// 경로 출력
				stack<int> route;
				int y = i, x = j;
				int from_y = from[i][j].first, from_x = from[i][j].second;
				while (true) {
					if (num[from_y][from_x] != num[y][x]) route.push(num[y][x]);
					y = from_y;
					x = from_x;
					from_y = from[y][x].first;
					from_x = from[y][x].second;

					if (y == 0 && x == 0) break;

				}

				printf("%d\n", route.size());
				while (!route.empty()) {
					printf("%d ", route.top());
					route.pop();
				}
				return 0;
			}
		}
	}

}

*/