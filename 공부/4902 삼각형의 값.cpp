/*
			 11
		  21 22 23
	   31 32 33 34 35
	41 42 43 44 45 46 47
*/

#include <cstdio>
#include <algorithm>
#include <limits.h>
using namespace std;

int h, ans;
int t;	// 테스트 케이스 번호
int map[401][801];
int sum[401][801];

void cal(int y, int x) {
	int left = x;
	int right = x;
	int temp = 0;

	// 삼각형
	if (x % 2 == 1) {
		while (true) {
			if (y < 1 || y > h || left < 1 || right > 2 * y - 1) break;
			temp = temp + sum[y][right] - sum[y][left - 1];
			ans = max(ans, temp);
			y++;
			right += 2;
		}
	}

	// 역삼각형
	else {
		while (true) {
			if (y < 1 || y > h || left < 1 || right > 2 * y - 1) break;
			temp = temp + sum[y][right] - sum[y][left - 1];
			ans = max(ans, temp);
			y--;
			left -= 2;
		}
	}

}
int main() {
	while (true) {
		t++;
		scanf("%d", &h);
		if (h == 0) return 0;

		// 초기화
		ans = INT_MIN;

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= i * 2 - 1; j++) {
				scanf("%d", &map[i][j]);
				sum[i][j] = sum[i][j - 1] + map[i][j];
			}
		}

		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= i * 2 - 1; j++)
				cal(i, j);


		printf("%d. %d\n", t, ans);

	}
}
