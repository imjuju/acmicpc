#include <cstdio>
#include <map>
#include <queue>
using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
map<int, int> dist;

void BFS(int state) {
	queue<int> q;
	q.push(state);
	dist[state] = 0;
	
	while (!q.empty()) {
		int state = q.front(), state_copy = q.front();
		int map[3][3];
		int y, x;

		q.pop();

		for (int i = 8; i >= 0; i--) {
			map[i / 3][i % 3] = state_copy % 10;
			if (map[i / 3][i % 3] == 9) {
				y = i / 3;
				x = i % 3;
			}
			state_copy /= 10;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (ny < 0 || ny >= 3 || nx < 0 || nx >= 3) continue;
			
			int nmap[3][3];
			int nstate = 0;

			for (int i = 0; i < 9; i++) nmap[i / 3][i % 3] = map[i / 3][i % 3];
			swap(nmap[y][x], nmap[ny][nx]);
			

			for (int i = 0; i < 3; i++) 
				for (int j = 0; j < 3; j++) 
					nstate = nstate * 10 + nmap[i][j];

			if (dist.count(nstate) == 0) {
				dist[nstate] = dist[state] + 1;
				q.push(nstate);
			}
			
		}
	}
}
int main() {
	int input = 0;
	for (int i = 0; i < 9; i++) {
		int temp;
		scanf("%d", &temp);

		// 시작점 0은 9로 바꾸어 넣어준다
		if (temp == 0) input = input * 10 + 9;
		else input = input * 10 + temp;
	}


	BFS(input);

	if (dist.count(123456789) == 0) printf("-1");
	else printf("%d", dist[123456789]);
}