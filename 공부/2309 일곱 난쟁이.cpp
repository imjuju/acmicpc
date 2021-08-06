#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int a[9] = {};
	int sum = 0;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}

	sum -= 100;
	sort(a, a + 9);
	
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum == a[i] + a[j]) {
				a[i] = a[j] = -1;

				for (int k = 0; k < 9; k++) {
					if (a[k] != -1)
						printf("%d\n", a[k]);
				}
				return 0;
			}
		}
	}

}