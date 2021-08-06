#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int T, n, m, num;
long long cnt;
vector<int> A;
vector<int> B;
vector<int> left;
vector<int> right;


int main() {
	scanf("%d", &T);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		A.push_back(num);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &num);
		B.push_back(num);
	}

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += A[j];
			left.push_back(sum);
		}
	}
	
	for (int i = 0; i < m; i++) {
		int sum = 0;
		for (int j = i; j < m; j++) {
			sum += B[j];
			right.push_back(sum);
		}
	}

	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

	for (int i = 0; i < left.size(); i++) {
		auto range = equal_range(right.begin(), right.end(), T - left[i]);
		cnt += range.second - range.first;
	}

	printf("%lld", cnt);
}