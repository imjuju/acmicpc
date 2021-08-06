// �� F��
// S������ G������
// U = ���� U��
// D = �Ʒ��� D��

// ��ư�� ��� �� �� ������ �ϴ���
// �� �� ���ٸ� use the stairs�� ���

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