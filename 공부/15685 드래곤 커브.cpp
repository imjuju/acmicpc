#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

bool map[101][101];
int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };

vector<int> dir;

void func(int d, int g) {
	dir.clear();
	dir.push_back(d);
	for (int i = 1; i <= g; i++) {
		vector<int> temp = dir;
		reverse(temp.begin(), temp.end());
		for (int j = 0; j < temp.size(); j++) {
			dir.push_back((temp[j] + 1) % 4);
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		scanf("%d %d %d %d", &x, &y, &d, &g);
		func(d, g);
		map[y][x] = true;
		for (int i = 0; i < dir.size(); i++) {
			y += dy[dir[i]];
			x += dx[dir[i]];
			map[y][x] = true;
		}
	}

	int ans = 0;
	for (int i = 0; i <= 99; i++)
		for (int j = 0; j <= 99; j++)
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) ans++;

	printf("%d", ans);
}