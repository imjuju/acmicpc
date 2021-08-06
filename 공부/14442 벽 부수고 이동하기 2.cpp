#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

int N, M, K;
int map[1000][1000];
int dist[1000][1000][11];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	
	memset(dist, -1, sizeof(dist));
	
	queue<pair<int, pair<int, int> > > q;
	q.push({ 0,{0,0} });
	dist[0][0][0] = 1;
	
	while (!q.empty()) {
		int cnt = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();

		if (y == N - 1 && x == M - 1) {
			printf("%d", dist[y][x][cnt]);
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			
			// 다음 칸이 벽일 때
			if (map[ny][nx] == 1) {
				// 지금까지 벽을 부순 적 없고, 다음 칸을 방문한 적 없으면
				if (cnt < K && dist[ny][nx][cnt + 1] == -1) {
					dist[ny][nx][cnt + 1] = dist[y][x][cnt] + 1;
					q.push({ cnt + 1,{ny,nx} });
				}
			}

			// 다음 칸이 빈 칸일 때
			else {
				// 다음 칸을 방문한 적 없을 때
				if (dist[ny][nx][cnt] == -1) {
					dist[ny][nx][cnt] = dist[y][x][cnt] + 1;
					q.push({ cnt,{ny,nx} });
				}
			}
		}
	}


	// 불가능할 때
	printf("-1");
}