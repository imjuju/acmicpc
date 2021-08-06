#include <cstdio>
#include <algorithm>
using namespace std;

int N, S;
int A[100000];
int ans = 999999;

int main() {
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	int left = -1;	// 제거할 숫자의 idx
	int right = -1;	// 추가할 숫자의 idx
	int len = 0;
	int sum = 0;

	while (left < N && right < N) {
		if (sum == S) {
			ans = min(ans, len);
			right++;
			if (right < N) {
				sum += A[right];
				len++;
			}
		}
		else if (sum < S) {
			right++;
			if (right < N) {
				sum += A[right];
				len++;
			}
		}
		else {
			ans = min(ans, len);
			left++;
			if (left < N) {
				sum -= A[left];
				len--;
			}
		}
	}

	if (ans == 999999) printf("0");
	else printf("%d", ans);

}