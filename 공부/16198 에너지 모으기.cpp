#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int W[10] = {};
	int ans = -1;
	vector<int> v;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &W[i]);
	
	for (int i = 1; i < N - 1; i++) v.push_back(i);
	do {
		int energy = 0;
		int w[10] = {};
		for (int i = 0; i < N; i++) w[i] = W[i];

		for (int i = 0; i < v.size(); i++) {
			w[v[i]] = 0;
			int left = -1, right = -1;
			for (int j = v[i] - 1; j >= 0; j--) {
				if (w[j] != 0) {
					left = j;
					break;
				}
			}

			for (int j = v[i] + 1; j <= N - 1; j++) {
				if (w[j] != 0) {
					right = j;
					break;
				}
			}

			if (left != -1 && right != -1) energy += w[left] * w[right];
			else {
				energy = -1;
				break;
			}
		}

		if (energy == -1) continue;
		else ans = max(ans, energy);
	
	} while (next_permutation(v.begin(), v.end()));

	printf("%d", ans);
}