#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, H;
int map[50][50];

int check(int start) {
	int y = 1;
	int x = start;

	while (y <= H) {
		if (map[y][x] == 1) x++;
		else if (map[y][x] == 2) x--;
		y++;
	}

	return x;
}

bool simulate() {
	for (int i = 1; i <= N; i++) {
		int temp = check(i);
		if (temp != i) return false;
	}
	return true;
}

int main() {
	scanf("%d %d %d", &N, &M, &H);

	while (M--) {
		int a, b;
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
		map[a][b + 1] = 2;
	}
	
	if (simulate()) {
		printf("0");
		return 0;
	}

	vector<pair<int, int> > dot;	// Á¡¼±
	
	for (int i = 1; i <= H; i++)
		for (int j = 1; j < N; j++)
			if (map[i][j] == 0 && map[i][j + 1] == 0) dot.push_back({ i,j });
	

	int ans = -1;

	for (int a = 0; a < dot.size(); a++) {
		int y1 = dot[a].first, x1 = dot[a].second;
		if (map[y1][x1] != 0 || map[y1][x1 + 1] != 0) continue;

		map[y1][x1] = 1;
		map[y1][x1 + 1] = 2;
		
		if (simulate()) {
			if (ans == -1 || ans > 1) ans = 1;
		}

		for (int b = a + 1; b < dot.size(); b++) {
			int y2 = dot[b].first, x2 = dot[b].second;
			if (map[y2][x2] != 0 || map[y2][x2 + 1] != 0) continue;

			map[y2][x2] = 1;
			map[y2][x2 + 1] = 2;
			
			if (simulate()) {
				if (ans == -1 || ans > 2) ans = 2;
			}

			for (int c = b + 1; c < dot.size(); c++) {
				int y3 = dot[c].first, x3 = dot[c].second;
				if (map[y3][x3] != 0 || map[y3][x3 + 1] != 0) continue;

				map[y3][x3] = 1;
				map[y3][x3 + 1] = 2;

				if (simulate()) {
					if (ans == -1 || ans > 3) ans = 3;
				}
				map[y3][x3] = map[y3][x3 + 1] = 0;
			}
			map[y2][x2] = map[y2][x2 + 1] = 0;
		}
		map[y1][x1] = map[y1][x1 + 1] = 0;
	}

	printf("%d", ans);
}