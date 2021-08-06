// 1) 화면에 A를 출력
// 2) 화면을 전체 선택
// 3) 버퍼에 복사
// 4) 붙여넣기

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N;
	long long dp[101] = {};

	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		for (int j = 1; j <= i - 3; j++) {
			dp[i] = max(dp[i], dp[j] * (i - j - 1));
		}
	}

	printf("%lld", dp[N]);
}