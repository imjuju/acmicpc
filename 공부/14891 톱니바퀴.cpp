// Åé´Ï´Â N±Ø ¶Ç´Â S±Ø

// Åé´Ï¹ÙÄû¸¦ ÃÑ K¹ø È¸Àü½ÃÅ°°íÀÚÇÔ
// ¼­·Î ¸Â´êÀº ±Ø¿¡ µû¶ó ¿·¿¡ ÀÖ´Â Åé´Ï ¹ÙÄû¸¦ È¸Àü½ÃÅ³ ¼öµµ ÀÖÀ½

// ¿· Åé´Ï¹ÙÄû¿Í ¸Â´êÀº Åé´ÏÀÇ ±ØÀÌ ´Ù¸£¸é
// ¿· Åé´Ï¹ÙÄû´Â ¹İ´ë ¹æÇâÀ¸·Î È¸Àü

// N±Ø = 0
// S±Ø = 1

#include <cstdio>

int K, num, order;
int a[5][8];

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

	for (int i = 1; i <= 4; i++)
		for (int j = 0; j < 8; j++)
			scanf("%1d", &a[i][j]);

	scanf("%d", &K);

	while (K--) {
		scanf("%d %d", &num, &order);

		if (num == 1) {
			if (a[1][2] != a[2][6]) {
				if (a[2][2] != a[3][6]) {
					if (a[3][2] != a[4][6]) {
						clockwise(4, order * -1);
					}
					clockwise(3, order);
				}
				clockwise(2, order * -1);
			}
			clockwise(1, order);
		}
		if (num == 2) {
			if (a[2][6] != a[1][2]) clockwise(1, order * -1);
			if (a[2][2] != a[3][6]) {
				if (a[3][2] != a[4][6]) {
					clockwise(4, order);
				}
				clockwise(3, order * -1);
			}
			clockwise(2, order);
		}
		if (num == 3) {
			if (a[3][2] != a[4][6]) clockwise(4, order * -1);
			if (a[3][6] != a[2][2]) {
				if (a[2][6] != a[1][2]) {
					clockwise(1, order);
				}
				clockwise(2, order * -1);
			}
			clockwise(3, order);
		}
		if (num == 4) {
			if (a[4][6] != a[3][2]) {
				if (a[3][6] != a[2][2]) {
					if (a[2][6] != a[1][2]) {
						clockwise(1, order * -1);
					}
					clockwise(2, order);
				}
				clockwise(3, order * -1);
			}
			clockwise(4, order);
		}
	}

	printf("%d", a[1][0] + a[2][0] * 2 + a[3][0] * 4 + a[4][0] * 8);
}