#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	long long cnt = 0;
	vector<int> left, right;

	scanf("%d", &n);

	vector<int> A(n);
	vector<int> B(n);
	vector<int> C(n);
	vector<int> D(n);

	for (int i = 0; i < n; i++)
		scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			left.push_back(A[i] + B[j]);
			right.push_back(C[i] + D[j]);
		}
	}

	//sort(left.begin(), left.end());
	sort(right.begin(), right.end());
	
	for (int i = 0; i < left.size(); i++) {
		auto range = equal_range(right.begin(), right.end(), -left[i]);
		cnt += range.second - range.first;
	}

	printf("%lld", cnt);
}