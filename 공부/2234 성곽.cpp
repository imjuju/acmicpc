// ���� ����
// ���� ���� ���� ����
// �ϳ��� ���� �����Ͽ� ���� �� �ִ� ���� ���� ���� ũ��

#include <cstdio>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

int n, m;
int maxsize = -1;	// ���� ���� ���� ����
int map[50][50];	// �� ĭ�� �� ����
int visit[50][50];
int room[3000];	// room[i] = ��i�� ����

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
			if (map[y][x] & (1 << i)) continue;	// �̵��Ϸ��� ���⿡ ���� ������
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
	// �ʱ�ȭ
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

	int mergesize = -1;	// �ϳ��� ���� �����Ͽ� ���� �� �ִ� ���� ���� ���� ũ��
	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				
				if (ny < 0 || ny >= m || nx < 0 || ny >= n) continue;
				if (visit[y][x] == visit[ny][nx]) continue;	// �̹� (��ĥ �ʿ䰡 ����) ���� ���� ��
				mergesize = max(mergesize, room[visit[y][x]] + room[visit[ny][nx]]);
			}
		}
	}

	printf("%d\n", num);
	printf("%d\n", maxsize);
	printf("%d\n", mergesize);
}