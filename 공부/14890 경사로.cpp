#include <cstdio>
#include <vector>
using namespace std;

int N, L, ans;
int map[100][100];

vector<int> v;
vector<bool> c;

bool check() {
	for (int i = 1; i < N; i++) {
		if (v[i - 1] != v[i]) {
			// 하강 경사로 = v[i]가 낮은 칸
			if (v[i - 1] - v[i] == 1) {
				for (int j = 0; j < L; j++) {
					// 경사로를 놓다가 범위를 벗어나는 경우
					if (i + j >= N) return false;

					// 낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우
					if (v[i] != v[i + j]) return false;

					// 경사로를 놓은 곳에 또 경사로를 놓는 경우
					if (c[i + j]) return false;

					c[i + j] = true;
				}
			}

			// 상승 경사로 = v[i-1]가 낮은 칸
			else if (v[i - 1] - v[i] == -1) {
				for (int j = 0; j < L; j++) {
					// 경사로를 놓다가 범위를 벗어나는 경우
					if (i - 1 - j < 0) return false;

					// 낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우
					if (v[i - 1] != v[i - 1 - j]) return false;

					// 경사로를 놓은 곳에 또 경사로를 놓는 경우
					if (c[i - 1 - j]) return false;

					c[i - 1 - j] = true;
				}
			}

			// 낮은 칸과 높은 칸의 높이 차이가 1이 아닌 경우
			else return false;
		}
	}

	return true;
}
int main() {
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	// 열 검사
	for (int i = 0; i < N; i++) {
		v.clear();
		c.clear();
		for (int j = 0; j < N; j++) v.push_back(map[i][j]);
		for (int j = 0; j < N; j++) c.push_back(false);
		bool tf = check();
		if (tf) ans++;
	}

	// 행 검사
	for (int i = 0; i < N; i++) {
		v.clear();
		c.clear();
		for (int j = 0; j < N; j++) v.push_back(map[j][i]);
		for (int j = 0; j < N; j++) c.push_back(false);
		bool tf = check();
		if (tf) ans++;
	}

	printf("%d", ans);
}