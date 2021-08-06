// 정수 s의 값을 t로 바꾸는
// 최소 연산 횟수를 구하라

// 1. s = s * s; (출력:*)
// 2. s = s + s; (출력: +)
// 3. s = s - s; (출력: -)
// 4. s = s / s; (출력: / ) (s가 0이 아닐때만 사용 가능)

#include <iostream>
#include <queue>
#include <string>
#include <set>
using namespace std;

long long s, t;
set<long long> check;

void BFS() {
	queue<pair<long long, string> >  q;
	check.insert(s);
	q.push({ s,"" });

	while (!q.empty()) {
		long long now = q.front().first;
		string exp = q.front().second;
		q.pop();

		if (now == t) {
			cout << exp;
			return;
		}

		long long next;
		next = now * now;
		if (check.count(next) == 0) {
			check.insert(next);
			q.push({ next,exp + "*" });
		}

		next = now + now;
		if (check.count(next) == 0) {
			check.insert(next);
			q.push({ next,exp + "+" });
		}

		next = now - now;
		if (check.count(next) == 0) {
			check.insert(next);
			q.push({ next,exp + "-" });
		}

		if (now != 0) {
			next = now / now;
			if (check.count(next) == 0) {
				check.insert(next);
				q.push({ next,exp + "/" });
			}
		}
		
	}

	cout << -1;
}

int main() {
	cin >> s >> t;

	if (s == t) {
		cout << 0;
		return 0;
	}

	BFS();
}