#include <cstdio>

int main() {
	int E, S, M;
	int ans = 1;
	scanf("%d %d %d", &E, &S, &M);

	if (E == 15) E = 0;
	if (S == 28) S = 0;
	if (M == 19) M = 0;

	while (true) {
		if (ans % 15 == E && ans % 28 == S && ans % 19 == M) {
			printf("%d", ans);
			return 0;
		}
		
		ans++;
	}
}