#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <limits>
using namespace std;

int ans = -1;
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int BFS(vector<vector<vector<int>>>& a) {
	if (a[0][0][0] == 0) return -1;

	queue<pair<int, pair<int, int> > > q;
	int dist[5][5][5];
	memset(dist, -1, sizeof(dist));

	dist[0][0][0] = 0;
	q.push({ 0,{0,0} });
	

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second.first;
		int z = q.front().second.second;
		q.pop();

		if (x == 4 && y == 4 && z == 4) break;

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			
			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5) continue;
			if (a[nx][ny][nz] == 0 || dist[nx][ny][nz] != -1) continue;

			dist[nx][ny][nz] = dist[x][y][z] + 1;
			q.push({ nx,{ny,nz} });
		}
	}


	return dist[4][4][4];
}

// 90µµ È¸Àü
vector<vector<int>> clockwise(vector<vector<int>>& a) {
	vector<vector<int>> b(5, vector<int>(5));
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			b[i][j] = a[5 - j - 1][i];
		}
	}
	
	return b;
}

void simulate(vector<vector<vector<int>>>& a, int idx) {
	if (idx == 5) return;

	for (int i = 0; i < 4; i++) {
		int temp = BFS(a);
		if (temp != -1) {
			if (ans == -1 || ans > temp) ans = temp;
		}

		simulate(a, idx + 1);
		a[idx] = clockwise(a[idx]);
	}
}

int main() {
	vector<vector<vector<int>>> a(5);

	for (int i = 0; i < 5; i++) {
		a[i].resize(5, vector<int>(5));
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				scanf("%d", &a[i][j][k]);
			}
		}
	}

	vector<int> order;
	for (int i = 0; i < 5; i++) order.push_back(i);

	do {
		vector<vector<vector<int>>> b(5);
		for (int i = 0; i < 5; i++) b[order[i]] = a[i];

		simulate(b, 0);

	
	} while (next_permutation(order.begin(), order.end()));

	printf("%d", ans);
}