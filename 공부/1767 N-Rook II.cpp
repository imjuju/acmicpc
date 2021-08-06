// Rook = 같은 열 or 같은 행에 다른 말이 있을 경우 공격할 수 있음

// N * M 크기의 체스판에 K개의 Rook을 놓을 때
// 각 룩이 최대 1개의 Rook에만 공격받는 경우의 수
// (어떤 Rook은 공격받지 않을 수도 있다)

#include <cstdio>

int N, M, K;
int DP[101][101][101];	// DP[N][M][K] = N * M 체스판에 Rook K개를 놓는 경우의 수

int main() {
	scanf("%d", &N);
	scanf("%d", &M);
	scanf("%d", &K);
}