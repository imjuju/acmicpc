#include <cstdio>
#include <map>
using namespace std;

int a[5][5];
int ans;
map<int, bool> check;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void BFS(int y, int x, int cnt, int num) {
	if (cnt == 6) {
		if (check.count(num) == 0) {
			ans++;
			check[num] = true;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
		BFS(ny, nx, cnt + 1, num * 10 + a[ny][nx]);
	}
}
int main() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			scanf("%d", &a[i][j]);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			BFS(i, j, 1, a[i][j]);

	printf("%d", ans);
}