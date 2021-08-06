#include <cstdio>

int main() {
	int N, M;
	int A[10000];
	int cnt = 0;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	int left = 0, right = 0;	// 합의 구간
	int sum = A[0];
	while (right < N) {
		if (sum == M) {
			cnt++;
			right++;
			sum += A[right];
		}
		else if (sum < M) {
			right++;
			sum += A[right];
		}
		else {
			sum -= A[left];
			left++;
		}
	}

	printf("%d", cnt);
}

/*
#include <cstdio>

int main() {
	int N, M;
	int A[10000];
	int cnt = 0;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	int left = -1;	// 제거할 숫자의 idx
	int right = -1;	// 추가할 숫자의 idx
	int sum = 0;
	while (left < N && right < N) {
		if (sum == M) {
			cnt++;
			right++;
			if (right < N) sum += A[right];
		}
		else if (sum < M) {
			right++;
			if (right < N) sum += A[right];
		}
		else {
			left++;
			if (left < N) sum -= A[left];
		}
	}

	printf("%d", cnt);
}

*/

/*
#include <cstdio>

int main() {
	int N, M;
	int A[10000];
	int cnt = 0;
	
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = i; j < N; j++) {
			sum += A[j];
			if (sum == M) {
				cnt++;
				break;
			}
			if (sum > M) break;
		}
	}

	printf("%d", cnt);
}
*/