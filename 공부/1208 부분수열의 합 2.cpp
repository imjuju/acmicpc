#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, S;
int num;
long long cnt = 0;

vector<int> A;
vector<int> B;

vector<int> sum1;
vector<int> sum2;


void func1(int idx, int sum) {
	if (idx == A.size()) {
		sum1.push_back(sum);
		return;
	}

	func1(idx + 1, sum);
	func1(idx + 1, sum + A[idx]);
}

void func2(int idx, int sum) {
	if (idx == B.size()) {
		sum2.push_back(sum);
		return;
	}

	func2(idx + 1, sum);
	func2(idx + 1, sum + B[idx]);
}

int main() {
	scanf("%d %d", &N, &S);

	for (int i = 0; i < N / 2; i++) {
		scanf("%d", &num);
		A.push_back(num);
	}

	for (int i = 0; i < N - N / 2; i++) {
		scanf("%d", &num);
		B.push_back(num);
	}

	func1(0, 0);
	func2(0, 0);

	sort(sum1.begin(), sum1.end());
	sort(sum2.begin(), sum2.end());
	reverse(sum2.begin(), sum2.end());

	int i = 0, j = 0;
	while (i < sum1.size() && j < sum2.size()) {
		if (sum1[i] + sum2[j] == S) {
			long long cnt1 = 1;
			long long cnt2 = 1;
			
			i++; j++;

			while (i < sum1.size() && sum1[i - 1] == sum1[i]) {
				cnt1++;
				i++;
			}

			while (j < sum2.size() && sum2[j - 1] == sum2[j]) {
				cnt2++;
				j++;
			}

			cnt += cnt1 * cnt2;
		}
		else if (sum1[i] + sum2[j] < S) i++;
		else j++;
	}
	
	if (S == 0) cnt--;
	printf("%lld", cnt);
}