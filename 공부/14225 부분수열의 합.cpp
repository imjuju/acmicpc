#include <cstdio>

int N;
int S[20];
bool check[20];
bool sum[20 * 100000 + 10];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &S[i]);

	for (int i = 0; i < (1 << N); i++) {
		int temp = 0;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) temp += S[j];
		}
		sum[temp] = true;
	}

	for (int i = 1;; i++) {
		if (!sum[i]) {
			printf("%d", i);
			return 0;
		}
	}
}

/*
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int N;
int S[20];
bool check[20];
map<int, bool> sum;

void search(int idx) {
	if (idx == N) {
		int temp = 0;
		for (int i = 0; i < N; i++) {
			if (check[i]) temp += S[i];
		}
		sum[temp] = true;
		return;
	}

	check[idx] = true;
	search(idx + 1);

	check[idx] = false;
	search(idx + 1);

}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &S[i]);

	search(0);

	for (int i = 1;; i++) {
		if (sum.count(i) == 0) {
			printf("%d", i);
			return 0;
		}
	}

}
*/