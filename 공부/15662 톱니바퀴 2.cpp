// Åé´Ï´Â N±Ø ¶Ç´Â S±Ø

// Åé´Ï¹ÙÄû¸¦ ÃÑ K¹ø È¸Àü½ÃÅ°°íÀÚÇÔ
// ¼­·Î ¸Â´êÀº ±Ø¿¡ µû¶ó ¿·¿¡ ÀÖ´Â Åé´Ï ¹ÙÄû¸¦ È¸Àü½ÃÅ³ ¼öµµ ÀÖÀ½

// ¿· Åé´Ï¹ÙÄû¿Í ¸Â´êÀº Åé´ÏÀÇ ±ØÀÌ ´Ù¸£¸é
// ¿· Åé´Ï¹ÙÄû´Â ¹İ´ë ¹æÇâÀ¸·Î È¸Àü

// N±Ø = 0
// S±Ø = 1

#include <cstdio>

int T, K, num, order;
int a[1001][8];
int b[1001][8];

void clockwise(int num, int order) {
	if (order == 1) {
		int temp = a[num][7];
		a[num][7] = a[num][6];
		a[num][6] = a[num][5];
		a[num][5] = a[num][4];
		a[num][4] = a[num][3];
		a[num][3] = a[num][2];
		a[num][2] = a[num][1];
		a[num][1] = a[num][0];
		a[num][0] = temp;
	}
	else {
		int temp = a[num][7];
		a[num][7] = a[num][0];
		a[num][0] = a[num][1];
		a[num][1] = a[num][2];
		a[num][2] = a[num][3];
		a[num][3] = a[num][4];
		a[num][4] = a[num][5];
		a[num][5] = a[num][6];
		a[num][6] = temp;
	}
}



int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
		for (int j = 0; j < 8; j++)
			scanf("%1d", &a[i][j]);

	scanf("%d", &K);

	while (K--) {
		for (int i = 1; i <= T; i++)
			for (int j = 0; j < 8; j++)
				b[i][j] = a[i][j];

		scanf("%d %d", &num, &order);

		int order2 = order;

		clockwise(num, order);

		for (int i = num - 1; i >= 1; i--) {
			if (b[i + 1][6] != b[i][2]) {
				order *= -1;
				clockwise(i, order);
			}
			else break;
		}

		for (int i = num + 1; i <= T; i++) {
			if (b[i - 1][2] != b[i][6]) {
				order2 *= -1;
				clockwise(i, order2);
			}
			else break;
		}


	}

	int ans = 0;
	for (int i = 1; i <= T; i++) ans += a[i][0];
	printf("%d", ans);
}