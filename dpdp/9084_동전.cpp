// BOJ 9084 (https://www.acmicpc.net/problem/9084)
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int t, n, coin[21], m, dp[10001];
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &coin[i]);
		}
		scanf("%d", &m);
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++) {
			dp[coin[i]]++;
			for (int j = coin[i] + 1; j <= m; j++) {
				dp[j] += dp[j-coin[i]];
			}
		}
		printf("%d\n", dp[m]);
	}

	return 0;
}