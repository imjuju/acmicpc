// 목표 = 빨간 구슬을 구멍을 통해서 빼내는 것
// 파란 구슬이 구멍에 들어가면 안 된다

// 빨간 구슬과 파란 구슬은 동시에 같은 칸에 있을 수 없다

// # 장애물
// O 구멍
// . 빈 칸

#include <cstdio>
#include <queue>
using namespace std;

struct state {
	int by, bx, ry, rx, dist;
};

int N, M;
queue<state> q;

char map[10][10];
bool visit[10][10][10][10];

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void move(int& y, int& x, int& cnt, int dir) {
	while (true) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (map[ny][nx] == '#') return;
		y = ny;
		x = nx;
		cnt++;
		if (map[y][x] == 'O') return;
	}
}

void bfs() {
	while (!q.empty()) {
		int by = q.front().by, bx = q.front().bx;
		int ry = q.front().ry, rx = q.front().rx;
		int dist = q.front().dist;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nby = by, nbx = bx, bcnt = 0;
			int nry = ry, nrx = rx, rcnt = 0;
			int ndist = dist + 1;

			move(nby, nbx, bcnt, i);
			move(nry, nrx, rcnt, i);

			if (map[nby][nbx] == 'O') continue;
			if (map[nry][nrx] == 'O') {
				printf("%d", ndist);
				return;
			}

			if (nby == nry && nbx == nrx) {
				if (rcnt > bcnt) nry -= dy[i], nrx -= dx[i];
				else nby -= dy[i], nbx -= dx[i];
			}
			if (!visit[nby][nbx][nry][nrx]) {
				visit[nby][nbx][nry][nrx] = true;
				q.push({ nby,nbx,nry,nrx,ndist });
			}

		}
	}
	printf("-1");
}


int main() {
	int by, bx, ry, rx;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &map[i][j]);

			if (map[i][j] == 'B') {
				by = i, bx = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'R') {
				ry = i, rx = j;
				map[i][j] = '.';
			}
		}
	}

	q.push({ by,bx,ry,rx,0 });
	visit[by][bx][ry][rx] = true;
	bfs();
}