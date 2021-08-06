#include <cstdio>

int main() {
	int N, K;
	int angle[10] = {};
	bool check[360] = { true };
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) scanf("%d", &angle[i]);

	for (int i = 0; i < N; i++) {
		for (int k = 0; k < 360; k++) {
			for (int j = 0; j < 360; j++) {
				if (check[j]) {
					check[(j - angle[i] + 360) % 360] = true;
					check[(j + angle[i] + 360) % 360] = true;
				}
			}
		}
	}

	while (K--) {
		int input;
		scanf("%d", &input);
		if (check[input]) printf("YES\n");
		else printf("NO\n");
	}
}

/*
#include <cstdio>

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main() {
	int N, K;
	int angle[10] = {};
	bool check[360] = {};
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) scanf("%d", &angle[i]);
	
	for (int i = 0; i < N; i++) {
		int GCD = gcd(360, angle[i]);
		for (int j = 0; GCD * j < 360; j++) check[GCD * j] = true;
	}
	
	while (K--) {
		int input;
		scanf("%d", &input);
		if (check[input]) printf("YES\n");
		else printf("NO\n");
	}

}
*/