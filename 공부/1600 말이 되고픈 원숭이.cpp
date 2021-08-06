#include <cstdio>
#include <queue>
using namespace std;

int K, W, H;
int map[200][200];
bool visit[200][200][31];
int dist[200][200][31];

int dy[12] = { -1,1,0,0,-1,-2,-2,-1,1,2,2,1 };
int dx[12] = { 0,0,-1,1,-2,-1,1,2,-2,-1,1,2 };
int dcnt[12] = { 0,0,0,0,1,1,1,1,1,1,1,1 };

struct state {
	int y, x, cnt;
};

void BFS() {
	queue<state> q;
	q.push({ 0,0,0 });
	visit[0][0][0] = true;
	dist[0][0][0] = 0;

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		q.pop();
		
		if (y == H - 1 && x == W - 1) {
			printf("%d", dist[y][x][cnt]);
			return;
		}
		for (int i = 0; i < 12; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			int ncnt = cnt + dcnt[i];

			if (ncnt > K) continue;
			if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
			if (visit[ny][nx][ncnt]) continue;
			if (map[ny][nx] == 1) continue;
			visit[ny][nx][ncnt] = true;
			dist[ny][nx][ncnt] = dist[y][x][cnt] + 1;
			q.push({ ny,nx,ncnt });
		}
	}

	// 시작점에서 도착점까지 갈 수 없는 경우
	printf("-1");
}

int main() {
	scanf("%d", &K);
	scanf("%d %d", &W, &H);

	for (int i = 0; i < H; i++) 
		for (int j = 0; j < W; j++) 
			scanf("%d", &map[i][j]);

	BFS();
}

/*
#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

int K, W, H;
int map[200][200];
int dist[200][200][31];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int hy[8] = { -1,-2,-2,-1,1,2,2,1 };
int hx[8] = { -2,-1,1,2,-2,-1,1,2 };

int BFS() {
	queue<pair<int, pair<int, int> > > q;
	q.push({ 0,{0,0} });
	dist[0][0][0] = 0;

	while (!q.empty()) {
		int cnt = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();

		if (y == H - 1 && x == W - 1) {
			printf("%d", dist[y][x][cnt]);
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
			if (map[ny][nx] == 1 || dist[ny][nx][cnt] != -1) continue;
			dist[ny][nx][cnt] = dist[y][x][cnt] + 1;
			q.push({ cnt,{ny,nx} });
		}

		if (cnt + 1 > K) continue;

		for (int i = 0; i < 8; i++) {
			int ny = y + hy[i];
			int nx = x + hx[i];

			if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
			if (map[ny][nx] == 1 || dist[ny][nx][cnt + 1] != -1) continue;
			dist[ny][nx][cnt + 1] = dist[y][x][cnt] + 1;
			q.push({ cnt + 1,{ny,nx} });
		}
	}

	// 시작점에서 도착점까지 갈 수 없는 경우
	printf("-1");
}

int main() {
	scanf("%d", &K);
	scanf("%d %d", &W, &H);

	memset(dist, -1, sizeof(dist));

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	BFS();
}
*/