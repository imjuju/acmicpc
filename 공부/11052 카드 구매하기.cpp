// 카드팩의 종류 카드 1개 ~ N개
// 민규: 가격이 비싸면 높은 등급의 카드가 많이 들어있을 것이다

// 돈을 최대한 많이 지불해서 카드 N개를 구매하려고 함

// N개보다 많은 개수의 카드를 산 다음 버려서 N개를 만드는 것을 불가능


#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int P[1001] = {};
	int dp[1001] = {};	// dp[i] = i장을 구매하기 위한 금액의 최댓값

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &P[i]);

	for (int i = 1; i <= N; i++) {
		dp[i] = P[i];
		for (int j = 1; j <= i / 2; j++) dp[i] = max(dp[i], dp[i - j] + dp[j]);
	}

	printf("%d", dp[N]);
}