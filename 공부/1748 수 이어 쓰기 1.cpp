#include <cstdio>

int main() {
	int N;
	int ans = 0;
	scanf("%d", &N);
	for (int start = 1, len = 1; start <= N; start *= 10, len++) {
		int end = start * 10 - 1;
		ans += (end > N ? (N - start + 1) * len : (end - start + 1) * len);
	}
	printf("%d", ans);
}

/*
#include <cstdio>


// 자릿수를 return하는 함수
int digit(int num) {
	int cnt = 0;
	while (num > 0) {
		num /= 10;
		cnt++;
	}
	return cnt;
}

int main() {
	int N;
	int ans = 0;

	scanf("%d", &N);

	int val = digit(N) - 1;
	int mid_interval = 9;
	int mid_digit = 1;

	while (val--) {
		ans += mid_interval * mid_digit;
		mid_interval *= 10;
		mid_digit++;
	}

	mid_interval /= 9;
	ans += (N - mid_interval + 1) * digit(N);

	printf("%d", ans);
}
*/