#include <cstdio>
#include <queue>
using namespace std;

int N, K;
int time = 999999;	// ������ ã�� ���� ���� �ð�
int cnt[200001];	// ����� ��
bool visit[200001];
int dist[200001];

int main() {
	scanf("%d %d", &N, &K);

	queue<int> q;
	q.push(N);
	visit[N] = true;
	cnt[N] = 1;

	while (!q.empty()) {
		int front = q.front();
		q.pop();

		int step[3] = { -1,1,front };

		for (int i = 0; i < 3; i++) {
			int next = front + step[i];
			if (0 <= next && next <= 200000) {
				if (visit[next] == false) {
					q.push(next);
					visit[next] = true;
					dist[next] = dist[front] + 1;
					cnt[next] = cnt[front];
				}
				else {
					if (dist[next] == dist[front] + 1) {
						cnt[next] += cnt[front];
					}
				}
			}
		}
	}

	printf("%d\n%d", dist[K], cnt[K]);
	
}