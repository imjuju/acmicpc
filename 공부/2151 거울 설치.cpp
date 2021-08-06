#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int N;
int from = -1;
int to = -1;

char map[50][50];
int num[50][50];
bool edge[2500][2500];

bool visit[2500];
int dist[2500];

vector <pair<int, int> > v;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void make_edge() {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < 4; j++) {
			int y = v[i].first;
			int x = v[i].second;

			while (true) {
				y += dy[j];
				x += dx[j];
				if (y < 0 || y >= N || x < 0 || x >= N) break;
				if (map[y][x] == '*') break;
				if (map[y][x] == '#' || map[y][x] == '!') edge[i][num[y][x]] = edge[num[y][x]][i] = true;
			}
		}
	}
}

void BFS() {
	queue<int> q;
	visit[from] = true;
	dist[from] = 0;
	q.push(from);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == to) {
			printf("%d", dist[to] - 1);
			return;
		}

		for (int i = 0; i < v.size(); i++) {
			if (!edge[now][i]) continue;
			if (visit[i]) continue;
			visit[i] = true;
			dist[i] = dist[now] + 1;
			q.push(i);
		}
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == '#') {
				if (from == -1) from = v.size();
				else to = v.size();
			}
			if (map[i][j] == '#' || map[i][j] == '!') {
				num[i][j] = v.size();
				v.push_back({ i,j });
			}
		}
	}
	
	make_edge();
	
	BFS();
}