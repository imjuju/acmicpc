// 왼쪽 줄의 1번칸 위에 서있음

// 0 위험한 칸 (이동 불가)
// 1 안전한 칸

// i -> i + 1
// i -> i - 1
// 왼i -> 오른 i + k or 오른 i- > 왼 i + k

// N번 칸보다 큰 칸으로 이동하면 clear

// 1초에 한 칸씩 사라짐
// 유저가 먼저 움직이고 칸이 사라짐

// 문제 조건 개떡같네 ㅋㅋㅋ
// ㅂㅅ문제

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int N, k;
int map[2][100001];
bool visit[2][100001];
int dist[2][100001];

void BFS() {
	queue<pair<int, int> > q;	// {left = 0 right = 1, idx}
	q.push({ 0,1 });
	visit[0][1] = true;
	dist[0][1] = 1;

	while (!q.empty()) {
		int state = q.front().first;
		int idx = q.front().second;
		q.pop();

		int nstate, nidx;
		// 앞으로 이동
		nstate = state; nidx = idx + 1;
		if (nidx > N) {
			printf("1");
			return;
		}
		else if (nidx == N && map[nstate][nidx] == 1) {
			printf("1");
			return;
		}
		if (dist[state][idx] < nidx && map[nstate][nidx] == 1 && !visit[nstate][nidx]) {
			visit[nstate][nidx] = true;
			dist[nstate][nidx] = dist[state][idx] + 1;
			q.push({ nstate,nidx });
		}

		// 뒤로 이동
		nstate = state; nidx = idx - 1;
		if (dist[state][idx] < nidx && map[nstate][nidx] == 1 && !visit[nstate][nidx]) {
			visit[nstate][nidx] = true;
			dist[nstate][nidx] = dist[state][idx] + 1;
			q.push({ nstate,nidx });
		}

		// 점프
		nstate = 1 - state; nidx = idx + k;
		if (nidx > N) {
			printf("1");
			return;
		}
		else if (nidx == N && map[nstate][nidx] == 1) {
			printf("1");
			return;
		}
		if (dist[state][idx] < nidx && map[nstate][nidx] == 1 && !visit[nstate][nidx]) {
			visit[nstate][nidx] = true;
			dist[nstate][nidx] = dist[state][idx] + 1;
			q.push({ nstate,nidx });
		}
	}

	printf("0");
}

int main() {
	scanf("%d %d", &N, &k);
	
	for (int i = 1; i <= N; i++) scanf("%1d", &map[0][i]);
	for (int i = 1; i <= N; i++) scanf("%1d", &map[1][i]);

	BFS();
}