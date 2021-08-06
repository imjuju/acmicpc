#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;

struct state {
	string a, b, c;
	int cnt;
};

bool check(state s) {
	string a = s.a;
	string b = s.b;
	string c = s.c;

	for (int i = 0; i < a.length(); i++) {
		if (a[i] != 'A') return false;
	}

	for (int i = 0; i < b.length(); i++) {
		if (b[i] != 'B') return false;
	}

	for (int i = 0; i < c.length(); i++) {
		if (c[i] != 'C') return false;
	}

	return true;
}

void BFS(state fs) {
	set<pair<string, pair<string, string> > > visit;
	queue<state> q;
	visit.insert({ fs.a,{fs.b,fs.c} });
	q.push(fs);

	while (!q.empty()) {
		state s = q.front();
		q.pop();

		if (check(s)) {
			cout << s.cnt;
			return;
		}


		state ns;
		if (s.a.length() > 0) {
			// a에서 b로
			ns = s;
			ns.b.push_back(ns.a.back());
			ns.a.pop_back();
			ns.cnt = s.cnt + 1;
			if (visit.count({ ns.a,{ns.b,ns.c} }) == 0) {
				visit.insert({ ns.a,{ns.b,ns.c} });
				q.push(ns);
			}

			// a에서 c로
			ns = s;
			ns.c.push_back(ns.a.back());
			ns.a.pop_back();
			ns.cnt = s.cnt + 1;
			if (visit.count({ ns.a,{ns.b,ns.c} }) == 0) {
				visit.insert({ ns.a,{ns.b,ns.c} });
				q.push(ns);
			}
		}

		if (s.b.length() > 0) {
			// b에서 a로
			ns = s;
			ns.a.push_back(ns.b.back());
			ns.b.pop_back();
			ns.cnt = s.cnt + 1;
			if (visit.count({ ns.a,{ns.b,ns.c} }) == 0) {
				visit.insert({ ns.a,{ns.b,ns.c} });
				q.push(ns);
			}

			// b에서 c로
			ns = s;
			ns.c.push_back(ns.b.back());
			ns.b.pop_back();
			ns.cnt = s.cnt + 1;
			if (visit.count({ ns.a,{ns.b,ns.c} }) == 0) {
				visit.insert({ ns.a,{ns.b,ns.c} });
				q.push(ns);
			}
		}

		if (s.c.length() > 0) {
			// c에서 a로
			ns = s;
			ns.a.push_back(ns.c.back());
			ns.c.pop_back();
			ns.cnt = s.cnt + 1;
			if (visit.count({ ns.a,{ns.b,ns.c} }) == 0) {
				visit.insert({ ns.a,{ns.b,ns.c} });
				q.push(ns);
			}

			// c에서 b로
			ns = s;
			ns.b.push_back(ns.c.back());
			ns.c.pop_back();
			ns.cnt = s.cnt + 1;
			if (visit.count({ ns.a,{ns.b,ns.c} }) == 0) {
				visit.insert({ ns.a,{ns.b,ns.c} });
				q.push(ns);
			}
		}
	}
}

int main() {
	int num;
	state temp;
	cin >> num;
	if (num > 0) cin >> temp.a;
	cin >> num;
	if (num > 0) cin >> temp.b;
	cin >> num;
	if (num > 0) cin >> temp.c;
	temp.cnt = 0;
	BFS(temp);
}

