// <x:y>의 다음 해 <x':y'>

// x < M이면 x' = x + 1
// 아니면 x' = 1

// y < N이면 y' = y + 1
// 아니면 y' = 1

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

		int lcm = M * N / gcd(M, N);	// 최소공배수 = 마지막 년도
		int ans = -1;
		
		// 마지막 년도
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
