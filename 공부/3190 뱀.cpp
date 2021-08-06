// �����̸� �÷� �Ӹ��� ���� ĭ�� ��ġ��Ŵ
// ����� ������ ����� ������
// ����� ������ ������ ��ġ�� ĭ�� ����ش�

#include <cstdio>
#include <deque>
#include <queue>
using namespace std;

int main() {
	int N, K, L;
	int dir = 1;	// ���� ó���� �������� ���Ѵ�
	int dy[4] = { -1,0,1,0 };	// �ϵ�����
	int dx[4] = { 0,1,0,-1 };
	int time = 0;
	int map[110][110] = {};	// 1��, 2���, 3��
	
	queue<pair<int, char> > q;
	deque<pair<int, int> > snake; 

	scanf("%d", &N);	// ������ ũ��
	scanf("%d", &K);	// ����� ����
	
	map[1][1] = 3;	// ���� ���� �������� ��ġ

	// ������ �����¿� ���� ���� �ִ�
	//for (int i = 0; i < N; i++) map[0][i] = map[i][0] = map[N - 1][i] = map[i][N - 1] = 1;


	while (K--) {
		int y, x;
		scanf("%d %d", &y, &x);
		map[y][x] = 2;
	}

	scanf("%d", &L);	// ���� ���� ��ȯ Ƚ��
	while (L--) {
		int x;
		char c;
		scanf("%d %c", &x, &c);
		q.push({ x,c });
	}

	snake.push_back({ 1,1 });

	while (true) {
		time++;

		// �Ӹ��� ����ĭ�� ��ġ��Ų��
		int hy = snake.front().first + dy[dir];
		int hx = snake.front().second + dx[dir];

		// �� �Ǵ� �ڱ� �ڽŰ� ���� �ε����� ������ ������
		if (hy < 1 || hy > N || hx < 1 || hx > N || map[hy][hx] == 3) break;

		if (map[hy][hx] == 0) {
			int ty = snake.back().first;
			int tx = snake.back().second;

			// ������ ��ġ�� ĭ�� �����
			map[ty][tx] = 0;
			snake.pop_back();
		}
		
		map[hy][hx] = 3;
		snake.push_front({ hy,hx });

		
		if (!q.empty()) {
			if (q.front().first == time) {
				// �������� 90�� ���� ȸ��
				if (q.front().second == 'L') {
					dir = (dir + 3) % 4;
				}
				// ���������� 90�� ���� ȸ��
				else {
					dir = (dir + 1) % 4;
				}
				q.pop();
			}
		}

	}

	printf("%d", time);

	
}