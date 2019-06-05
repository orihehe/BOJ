/*
dp[i]�� ���� �ּ� Ƚ���� ����ȴ�.
i���� dp[i+(1~x)]�� �ּ� Ƚ���� �������ش�. 
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, dp[1000], x;
	scanf("%d", &n);
	fill(dp, dp + n, 1000);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		for (int j = i + 1; j <= i + x; j++) {
			if (j >= n) break;
			dp[j] = min(dp[i] + 1, dp[j]);
		}
	}
	if (dp[n - 1] == 1000) printf("-1");
	else printf("%d", dp[n - 1]);

	return 0;
}