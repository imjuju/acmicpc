#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int k;
	while (true) {
		scanf("%d", &k);

		if (k == 0) return 0;
		
		vector<int> n(k);
		vector<int> check(k);	// 0이면 고르기
		
		for (int i = 0; i < k; i++) scanf("%d", &n[i]);
		for (int i = 6; i < k; i++) check[i] = 1;

		do {
			for (int i = 0; i < k; i++)
				if(check[i]==0) printf("%d ", n[i]);
			printf("\n");
		} while (next_permutation(check.begin(), check.end()));
		
		printf("\n");
	}
	
}