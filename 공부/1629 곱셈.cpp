#include <cstdio>

int A, B, C;

long long calc(int a, int b) {
	if (b == 0) return 1 % C;
	else if (b == 1) return a % C;
	else if (b % 2 == 0) {
		long long temp = calc(a, b / 2) % C;
		return (temp * temp) % C;
	}
	else return a * calc(a, b - 1) % C;
}

int main() {
	scanf("%d %d %d", &A, &B, &C);
	printf("%lld", calc(A, B));
}