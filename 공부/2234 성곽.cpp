// 방의 개수
// 가장 넓은 방의 넓이
// 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기

#include <cstdio>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

int n, m;
int maxsize = -1;	// 가장 넓은 방의 넓이
int map[50][50];	// 각 칸의 벽 정보
int visit[50][50];
int room[3000];	// room[i] = 방i의 넓이

int dy[4] = { 0,-1,0,1 };
int dx[4] = { -1,0,1,0 };

void BFS(int y, int x, int num) {
	int cnt = 0;
	queue<pair<int, int> > q;
	visit[y][x] = num;
	cnt++;
	q.push({ y,x });
	
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= m || nx < 0 || ny >= n) continue;
			if (map[y][x] & (1 << i)) continue;	// 이동하려는 방향에 벽이 있으면
			if (visit[ny][nx] != -1) continue;
			visit[ny][nx] = num;
			cnt++;
			q.push({ ny,nx });
		}
	}

	room[num] = cnt;
	maxsize = max(maxsize, cnt);
}


int main() {
	// 초기화
	memset(visit, -1, sizeof(visit));

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) 
		for (int j = 0; j < n; j++) 
			scanf("%d", &map[i][j]);
	

	int num = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == -1) {
				BFS(i, j, num);
				num++;
			}
		}
	}

	int mergesize = -1;	// 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				
				if (ny < 0 || ny >= m || nx < 0 || ny >= n) continue;
				if (visit[y][x] == visit[ny][nx]) continue;	// 이미 (합칠 필요가 없는) 같은 방일 때
				mergesize = max(mergesize, room[visit[y][x]] + room[visit[ny][nx]]);
			}
		}
	}

	printf("%d\n", num);
	printf("%d\n", maxsize);
	printf("%d\n", mergesize);
}