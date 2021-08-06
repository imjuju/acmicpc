#include <cstdio>
#include <deque>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int T;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0, -1,1 };

int h, w;
vector<pair<int, int> > start;
char map[102][102];
bool visit[3][102][102];
int door[3][102][102];

void BFS(int idx) {
	int sy = start[idx].first;
	int sx = start[idx].second;
	
	deque<pair<int, int> > dq;
	
	dq.push_back({ sy,sx });
	visit[idx][sy][sx] = true;
	door[idx][sy][sx] = 0;

	while (!dq.empty()) {
		int y = dq.front().first;
		int x = dq.front().second;
		dq.pop_front();
		
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			// 범위 밖이거나, 벽이거나, 방문한 적 있는 칸이면 continue
			if (ny<0 || ny>h + 1 || nx<0 || nx>w + 1) continue;
			if (map[ny][nx] == '*') continue;
			if (visit[idx][ny][nx]) continue;

			visit[idx][ny][nx] = true;	// 방문 체크

			// 문이면
			if (map[ny][nx] == '#') {
				door[idx][ny][nx] = door[idx][y][x] + 1;
				dq.push_back({ ny,nx });
			}
			// 빈 공간이면
			else {
				door[idx][ny][nx] = door[idx][y][x];
				dq.push_front({ ny,nx });
			}
		}
	}

}

int main() {
	scanf("%d", &T);

	while (T--) {

		// 초기화
		start.clear();
		memset(visit, false, sizeof(visit));
		memset(door, 0, sizeof(door));

		scanf("%d %d", &h, &w);
		
		// map 입력
		for (int i = 0; i <= w + 1; i++) map[0][i] = map[h + 1][i] = '.';
		for (int i = 0; i <= h + 1; i++) map[i][0] = map[i][w + 1] = '.';
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				scanf(" %c", &map[i][j]);
				if (map[i][j] == '$') start.push_back({ i,j });
			}
		}

		start.push_back({ 0,0 });

		BFS(0);
		BFS(1);
		BFS(2);

		
		int ans = 99999;
		for (int i = 0; i <= h + 1; i++) {
			for (int j = 0; j <= w + 1; j++) {
				door[0][i][j] += door[1][i][j] + door[2][i][j];

				if (map[i][j] == '#') door[0][i][j] -= 2;
				if (map[i][j] != '*') {
					ans = min(ans, door[0][i][j]);
				}
			}
		}

		printf("%d\n", ans);
	}
}