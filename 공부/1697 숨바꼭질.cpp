#include <cstdio>
#include <queue>
using namespace std;

int N, K;
bool visit[100001];
int dist[100001];

int main() {
	scanf("%d %d", &N, &K);

	queue<int> q;
	q.push(N);
	visit[N] = true;
	
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		if (front == K) {
			printf("%d", dist[front]);
			return 0;
		}
		if (0 <= front - 1 && visit[front - 1] == false) {
			q.push(front - 1);
			visit[front - 1] = true;
			dist[front - 1] = dist[front] + 1;
		}
		if (front + 1 <= 100000 && visit[front + 1] == false) {
			q.push(front + 1);
			visit[front + 1] = true;
			dist[front + 1] = dist[front] + 1;
		}
		if (front * 2 <= 100000 && visit[front * 2] == false) {
			q.push(front * 2);
			visit[front * 2] = true;
			dist[front * 2] = dist[front] + 1;
		}
	}
}