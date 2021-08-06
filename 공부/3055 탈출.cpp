// R행 C열
// . 비어있는 곳
// * 물이 차 있는 곳
// X 돌
// S 고슴도치의 위치
// D 비버의 굴

// 고슴도치는 상하좌우
// 물도 상하좌우
// 물, 고슴도치는 돌을 통과할 수 없음
// 물 비버의 소굴로 이동 X

#include <cstdio>
#include <queue>
using namespace std;

int main() {
	int R, C;	// 행, 열
	int by, bx;	// 비버의 굴이 있는 행, 열
	char map[50][50];
	int time[50][50] = {};

	int dy[4] = { -1,1,0,0 };
	int dx[4] = { 0,0,-1,1 };
	queue<pair<int, int> > q;

	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%1s", &map[i][j]);
			if (map[i][j] == '*') q.push({ i,j });
			if (map[i][j] == 'D') {
				by = i;
				bx = j;
			}
		}
	}

	for (int i = 0; i < R; i++) 
		for (int j = 0; j < C; j++) 
			if (map[i][j] == 'S') q.push({ i,j });
	
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (y == by && x == bx) {
			printf("%d", time[y][x]);
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
			
	
			// 고슴도치
			if (map[y][x] == 'S' && (map[ny][nx] == '.' || map[ny][nx] == 'D')) {
				//map[y][x] = '.';
				map[ny][nx] = 'S';
				time[ny][nx] = time[y][x] + 1;
				q.push({ ny,nx });
			}

			// 물
			if (map[y][x] == '*' && map[ny][nx] == '.') {
				map[ny][nx] = '*';
				time[ny][nx] = time[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}

	printf("KAKTUS");

}