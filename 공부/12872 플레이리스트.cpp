// 모든 노래를 플레이리스트에 추가해야
// 같은 노래를 추가하려면,
// 플레이리스트에서 두 노래 사이 적어도 M개의 곡이 있어야함

#include <cstdio>
#include <string.h>	// memset
using namespace std;

const long long MOD = 1000000007;
int N, M, P;
long long dp[101][101][101];	// dp[플레이리스트 길이][이미 추가한 노래][추가한 적 없는 노래]

// p = 만든 플레이리스트의 길이, x = 이미 추가한 노래, y = 추가한 적 없는 노래
long long func(int idx, int x, int y) {
	// 플레이리스트를 완성했을 때
	if (idx == P) {
		// 모든 노래를 플레이리스트에 추가했으면 - 가능 1 반환
		if (y == 0) return 1;
		// 플레이리스트에 추가하지 않은 노래가 있으면 - 불가능 0 반환
		else return 0;
	}

	if (dp[idx][x][y] != -1) return dp[idx][x][y];
	

	long long temp = 0;

	
	// 이미 추가한 노래를 또 추가하는 경우
	if (x - M > 0) {
		temp = (temp + func(idx + 1, x, y) * (x - M)) % MOD;
	}

	// 추가한 적 없는 노래를 추가하는 경우
	if (y > 0) {
		temp = (temp + func(idx + 1, x + 1, y - 1) * y) % MOD;
	}

	dp[idx][x][y] = temp;

	return dp[idx][x][y];
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d %d", &N, &M, &P);

	printf("%lld", func(0, 0, N));
}