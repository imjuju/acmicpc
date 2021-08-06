#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int ans = 100;
int map[8][8];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

vector<pair<int, int> > cctv;

void check(int y, int x, int dir) {
	while (true) {
		y += dy[dir];
		x += dx[dir];
		
		if (y < 0 || y >= N || x < 0 || x >= M) break;
		if (map[y][x] == 6) break;
		if (map[y][x] == 0) map[y][x] = -1;
	}
}

void search(int idx) {
	if (idx == cctv.size()) {
		int temp = 0;
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < M; j++) 
				if (map[i][j] == 0) temp++;
		ans = min(ans, temp);
		return;
	}
	
	int nmap[8][8] = {};
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			nmap[i][j] = map[i][j];

	int y = cctv[idx].first;
	int x = cctv[idx].second;
	int type = map[y][x];

	if (type == 5) {
		check(y, x, 0);
		check(y, x, 1);
		check(y, x, 2);
		check(y, x, 3);
		search(idx + 1);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				map[i][j] = nmap[i][j];
	}

	if (type == 4) {
		check(y, x, 1);
		check(y, x, 2);
		check(y, x, 3);
		search(idx + 1);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				map[i][j] = nmap[i][j];

		check(y, x, 0);
		check(y, x, 2);
		check(y, x, 3);
		search(idx + 1);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				map[i][j] = nmap[i][j];

		check(y, x, 0);
		check(y, x, 1);
		check(y, x, 3);
		search(idx + 1);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				map[i][j] = nmap[i][j];

		check(y, x, 0);
		check(y, x, 1);
		check(y, x, 2);
		search(idx + 1);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				map[i][j] = nmap[i][j];
	}

	if (type == 3) {
		for (int d = 0; d <= 3; d++) {
			check(y, x, d);
			check(y, x, (d + 1) % 4);
			search(idx + 1);
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					map[i][j] = nmap[i][j];
		}
	}

	if (type == 2) {
		for (int d = 0; d <= 1; d++) {
			check(y, x, d);
			check(y, x, d + 2);
			search(idx + 1);
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					map[i][j] = nmap[i][j];
		}
	}

	if (type == 1) {
		for (int d = 0; d < 4; d++) {
			check(y, x, d);
			search(idx + 1);
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					map[i][j] = nmap[i][j];
		}
	}

}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (1 <= map[i][j] && map[i][j] <= 5) cctv.push_back({ i,j });
		}
	}

	search(0);

	printf("%d", ans);
}