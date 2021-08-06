// �� ���� �õ�����
// �� �������� �� �� �ִ� ĭ���� ��� �̵��Ѵ�
// ���� �������� �̵��� ������
// ���� mirror ���� �����Ѵ�

// ���� �õ�����
// �ٸ� �������� ���� ���� mirror + 1���� �����Ѵ�

#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int w, h;
char map[100][100];
int mirror[100][100];
bool visit[100][100];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0, -1,1 };

void BFS(int sy, int sx) {
	queue<pair<int, int> > q;

	q.push({ sy,sx });
	visit[sy][sx] = true;
	mirror[sy][sx] = 0;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (map[y][x] == 'C' && (y != sy || x != sx)) {
			printf("%d", mirror[y][x] - 1);
			return;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y;
			int nx = x;

			while (true) {
				ny += dy[i];
				nx += dx[i];

				if (ny < 0 || ny >= h || nx < 0 || nx >= w) break;
				if (map[ny][nx] == '*') break;
				if (!visit[ny][nx]) {
					visit[ny][nx] = true;
					mirror[ny][nx] = mirror[y][x] + 1;
					q.push({ ny,nx });
				}
			}

		}
	}
}

int main() {
	scanf("%d %d", &w, &h);
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			scanf(" %c", &map[i][j]);


	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			if (map[i][j] == 'C') {
				BFS(i, j);
				return 0;
			}

}