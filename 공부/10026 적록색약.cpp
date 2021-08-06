#include <cstdio>
#include <queue>
using namespace std;

int N;
int cnt1, cnt2;
char map[100][100];
bool visit1[100][100];
bool visit2[100][100];	// 적록색약

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void BFS1(int sy, int sx) {
	cnt1++;

	queue<pair<int, int> > q;
	q.push({ sy,sx });
	visit1[sy][sx] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (visit1[ny][nx]) continue;
			if (map[ny][nx] == map[sy][sx]) {
				visit1[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
	}
}

void BFS2(int sy, int sx) {
	cnt2++;

	queue<pair<int, int> > q;
	q.push({ sy,sx });
	visit2[sy][sx] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (visit2[ny][nx]) continue;
			if (map[sy][sx] == 'B') {
				if (map[ny][nx] == map[sy][sx]) {
					visit2[ny][nx] = true;
					q.push({ ny,nx });
				}
			}
			else {
				if (map[ny][nx] != 'B') {
					visit2[ny][nx] = true;
					q.push({ ny,nx });
				}
			}
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %c", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit1[i][j]) BFS1(i, j);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit2[i][j]) BFS2(i, j);
		}
	}

	printf("%d %d", cnt1, cnt2);
}