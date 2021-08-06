// 이동하려는 칸이 벽이면 이동하지 않는다
// 이동하려는 방향에 칸이 없으면 밖으로 떨어진다

// 그 외의 경우 한 칸 이동한다
// 이동하려는 칸에 동전이 있는 경우에도 한 칸 이동한다

#include <cstdio>
#include <queue>
using namespace std;


struct coin {
	int y1, x1, y2, x2, cnt;
};

int N, M;
char map[20][20] = {};
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

queue<coin> q;

void BFS() {
	while (!q.empty()) {
		int y1 = q.front().y1;
		int x1 = q.front().x1;
		int y2 = q.front().y2;
		int x2 = q.front().x2;
		int cnt = q.front().cnt;
		q.pop();
		
		if (cnt == 10) {
			printf("-1");
			return;
		}

		for (int i = 0; i < 4; i++) {
			int ny1 = y1 + dy[i];
			int nx1 = x1 + dx[i];
			int ny2 = y2 + dy[i];
			int nx2 = x2 + dx[i];
			
			// 벽이면 이동하지 않는다
			if (0 <= ny1 && ny1 < N && 0 <= nx1 && nx1 < M) {
				if (map[ny1][nx1] == '#') {
					ny1 = y1;
					nx1 = x1;
				}
			}

			// 벽이면 이동하지 않는다
			if (0 <= ny2 && ny2 < N && 0 <= nx2 && nx2 < M) {
				if (map[ny2][nx2] == '#') {
					ny2 = y2;
					nx2 = x2;
				}
			}

			bool isout1 = false;
			bool isout2 = false;

			if (ny1 < 0 || ny1 >= N || nx1 < 0 || nx1 >= M) isout1 = true;
			if (ny2 < 0 || ny2 >= N || nx2 < 0 || nx2 >= M) isout2 = true;

			// 두 동전이 다 떨어졌을 때
			if (isout1 && isout2) continue;
			
			// 한 동전만 떨어졌을 때
			if (isout1 || isout2) {
				printf("%d", cnt + 1);
				return;
			}

			
			q.push({ ny1,nx1,ny2,nx2,cnt + 1 });
		}

	}
}

int main() {
	int y1 = -1, x1 = -1, y2 = -1, x2 = -1;


	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &map[i][j]);

			if (map[i][j] == 'o') {
				map[i][j] = '.';
				if (y1 == -1) {
					y1 = i;
					x1 = j;
				}
				else {
					y2 = i;
					x2 = j;
				}
			}
		}
	}

	q.push({ y1,x1,y2,x2,0 });
	
	BFS();
}