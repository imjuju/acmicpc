// '.' 빈 필드
// '#' 울타리
// 'o' 양
// 'v' 늑대

// 양의 수 > 늑대의 수
// 아니면 늑대가 모든 양을 먹는다

#include <cstdio>
#include <queue>
using namespace std;

int R, C;
int sheep, wolf;
char map[250][250];
bool visit[250][250];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void BFS(int y, int x) {
	int temp_sheep = 0;
	int temp_wolf = 0;
	queue<pair<int, int> > q;
	visit[y][x] = true;
	q.push({ y,x });

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (map[y][x] == 'o') temp_sheep++;
		if (map[y][x] == 'v') temp_wolf++;
		
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
			if (map[ny][nx] == '#') continue;
			if (visit[ny][nx]) continue;

			visit[ny][nx] = true;
			q.push({ ny,nx });
		}
	}
	
	if (temp_sheep > temp_wolf) wolf -= temp_wolf;
	else sheep -= temp_sheep;
}

int main() {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'o') sheep++;
			if (map[i][j] == 'v') wolf++;
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] != '#' && !visit[i][j]) BFS(i, j);
		}
	}

	printf("%d %d", sheep, wolf);	
}