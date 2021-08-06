// 총 F층
// S층에서 G층으로
// U = 위로 U층
// D = 아래로 D층

// 버튼을 적어도 몇 번 눌러야 하는지
// 갈 수 없다면 use the stairs를 출력

#include <cstdio>
#include <queue>
using namespace std;

int F, S, G, U, D;
int dist[1000001];
bool visit[1000001];

void BFS() {
	queue<int> q;
	q.push(S);
	dist[S] = 0;
	visit[S] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == G) {
			printf("%d", dist[now]);
			return;
		}

		if (now + U <= F && !visit[now + U]) {
			dist[now + U] = dist[now] + 1;
			visit[now + U] = true;
			q.push(now + U);
		}

		if (now - D >= 1 && !visit[now - D]) {
			dist[now - D] = dist[now] + 1;
			visit[now - D] = true;
			q.push(now - D);
		}
	}

	printf("use the stairs");
}

int main() {
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	BFS();
}