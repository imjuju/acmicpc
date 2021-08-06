// dp[2] = ()
// dp[4] = (()) / ()()
// dp[6] = ((())) / (())() / ()(()) / ()()()
// dp[8] = (((()))) / (())()() / ()(())() / ()()(()) / (())(())
//		   ((()))() / ()((())) / ()()()()
#include <cstdio>

int T, L;
long long dp[5001];	// dp[i] = 길이가 i인 괄호 문자열의 개수

int main() {
	scanf("%d", &T);


	while (T--) {
		scanf("%d", &L);
		if (L % 2 == 1) printf("0\n");
		else printf("%lld\n", dp[L]);
	}
}