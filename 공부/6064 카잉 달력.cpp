// <x:y>�� ���� �� <x':y'>

// x < M�̸� x' = x + 1
// �ƴϸ� x' = 1

// y < N�̸� y' = y + 1
// �ƴϸ� y' = 1

#include <cstdio>

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int M, N, x, y;
		scanf("%d %d %d %d", &M, &N, &x, &y);

		int lcm = M * N / gcd(M, N);	// �ּҰ���� = ������ �⵵
		int ans = -1;
		
		// ������ �⵵
		if (M == x && N == y) {
			printf("%d\n", lcm);
			continue;
		}

		if (x == M) x = 0;
		if (y == N) y = 0;
		
		for (int i = 0; i < lcm / M; i++) {
			int year = M * i + x;
			if (year % N == y) {
				ans = year;
				break;
			}
		}
		
		printf("%d\n", ans);
	}
}
