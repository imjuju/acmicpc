// 몸길이를 늘려 머리를 다음 칸에 위치시킴
// 사과가 있으면 사과가 없어짐
// 사과가 없으면 꼬리가 위치한 칸을 비워준다

#include <cstdio>
#include <deque>
#include <queue>
using namespace std;

int main() {
	int N, K, L;
	int dir = 1;	// 뱀은 처음에 오른쪽을 향한다
	int dy[4] = { -1,0,1,0 };	// 북동남서
	int dx[4] = { 0,1,0,-1 };
	int time = 0;
	int map[110][110] = {};	// 1벽, 2사과, 3뱀
	
	queue<pair<int, char> > q;
	deque<pair<int, int> > snake; 

	scanf("%d", &N);	// 보드의 크기
	scanf("%d", &K);	// 사과의 개수
	
	map[1][1] = 3;	// 뱀은 맨위 맨좌측에 위치

	// 보드의 상하좌우 끝에 벽이 있다
	//for (int i = 0; i < N; i++) map[0][i] = map[i][0] = map[N - 1][i] = map[i][N - 1] = 1;


	while (K--) {
		int y, x;
		scanf("%d %d", &y, &x);
		map[y][x] = 2;
	}

	scanf("%d", &L);	// 뱀의 방향 변환 횟수
	while (L--) {
		int x;
		char c;
		scanf("%d %c", &x, &c);
		q.push({ x,c });
	}

	snake.push_back({ 1,1 });

	while (true) {
		time++;

		// 머리를 다음칸에 위치시킨다
		int hy = snake.front().first + dy[dir];
		int hx = snake.front().second + dx[dir];

		// 벽 또는 자기 자신과 몸을 부딪히면 게임이 끝난다
		if (hy < 1 || hy > N || hx < 1 || hx > N || map[hy][hx] == 3) break;

		if (map[hy][hx] == 0) {
			int ty = snake.back().first;
			int tx = snake.back().second;

			// 꼬리가 위치한 칸을 비워줌
			map[ty][tx] = 0;
			snake.pop_back();
		}
		
		map[hy][hx] = 3;
		snake.push_front({ hy,hx });

		
		if (!q.empty()) {
			if (q.front().first == time) {
				// 왼쪽으로 90도 방향 회전
				if (q.front().second == 'L') {
					dir = (dir + 3) % 4;
				}
				// 오른쪽으로 90도 방향 회전
				else {
					dir = (dir + 1) % 4;
				}
				q.pop();
			}
		}

	}

	printf("%d", time);

	
}