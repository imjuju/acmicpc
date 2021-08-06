#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int h, w;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int document;

char map[102][102] = {};
bool visit[102][102] = {};
bool key[26] = {};

void BFS(int y, int x) {
	queue<pair<int, int> > q;
	q.push({ y,x });
	visit[y][x] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (ny < 0 || ny > h + 1 || nx < 0 || nx > w + 1) continue;
			if (map[ny][nx] == '*') continue;
			if ('A' <= map[ny][nx] && map[ny][nx] <= 'Z') continue;		// ��� ��
			if (visit[ny][nx]) continue;
			
			if (map[ny][nx] == '$') {
				document++;
				visit[ny][nx] = true;
				map[ny][nx] = '.';	// for �ߺ� Ž�� ����
				q.push({ ny,nx });
			}
			if ('a' <= map[ny][nx] && map[ny][nx] <= 'z' && !key[map[ny][nx] - 'a']) {
				key[map[ny][nx] - 'a'] = true;
				
				// ������ �ִ� ���迡 ���� ó��
				for (int j = 1; j <= h; j++) {
					for (int k = 1; k <= w; k++) {
						if ('A' <= map[j][k] && map[j][k] <= 'Z' && key[map[j][k] - 'A']) {
							map[j][k] = '.';	// ���� ����
						}
						if ('a' <= map[j][k] && map[j][k] <= 'z' && key[map[j][k] - 'a']) {
							map[j][k] = '.';	// ���踦 �ݴ´�
						}
					}
				}

				// ���� ��κ��� ��� ��θ� ��Ž��
				memset(visit, false, sizeof(visit));
				while (!q.empty()) q.pop();
				q.push({ ny,nx });
				
			}
			if (map[ny][nx] == '.') {
				visit[ny][nx] = true;
				q.push({ ny,nx });
			}
		}

	}
}

int main() {
	int T;
	cin >> T;
	
	while (T--) {
		// �ʱ�ȭ
		document = 0;
		memset(visit, false, sizeof(visit));
		memset(key, false, sizeof(key));

		cin >> h >> w;

		// ���� �Է�
		for (int i = 0; i <= w + 1; i++) map[0][i] = map[h + 1][i] = '.';
		for (int i = 0; i <= h + 1; i++) map[i][0] = map[i][w + 1] = '.';
		for (int i = 1; i <= h; i++) for (int j = 1; j <= w; j++) cin >> map[i][j];
		
		// ���� ���� �Է�
		string str;
		cin >> str;
		if (str != "0") 
			for (int i = 0; i < str.length(); i++) key[str[i] - 'a'] = true;
		
		// ������ �ִ� ���迡 ���� ó��
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if ('A' <= map[i][j] && map[i][j] <= 'Z' && key[map[i][j] - 'A']) {
					map[i][j] = '.';	// ���� ����
				}
				if ('a' <= map[i][j] && map[i][j] <= 'z' && key[map[i][j] - 'a']) {
					map[i][j] = '.';	// ���踦 �ݴ´�
				}
			}
		}

		BFS(0, 0);

		cout << document << '\n';
	}
}