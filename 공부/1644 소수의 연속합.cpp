#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int N, cnt = 0;
	scanf("%d", &N);

	vector<bool> check(N + 1);
	vector<int> prime;

	for (int i = 2; i <= N; i++) {
		if (!check[i]) {
			prime.push_back(i);
			for (int j = i * 2; j <= N; j += i) check[j] = true;
		}
	}

	int left = -1;
	int right = -1;
	int sum = 0;
	int size = prime.size();

	while (left < size && right < size) {
		if (sum == N) {
			cnt++;
			right++;
			if (right < size) sum += prime[right];
		}
		else if (sum < N) {
			right++;
			if (right < size) sum += prime[right];
		}
		else {
			left++;
			if (left < size) sum -= prime[left];
		}
	}

	printf("%d", cnt);
}