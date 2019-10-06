/*
BOJ 10982 - 행운쿠키 제작소
https://www.acmicpc.net/problem/10982
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
pii dp[50001];
int main() {
	int t, n, a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(dp, -1, sizeof(dp));
		dp[0] = { 0,0 };
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &a, &b);
			for (int j = 50000; j >= 0; j--) {
				if (j - a >= 0 && dp[j - a].second == i) {
					if (dp[j].second == i)
						dp[j] = { min(dp[j - a].first, dp[j].first + b),i + 1 };
					else dp[j] = { dp[j - a].first,i + 1 };
				}
				else if (dp[j].second == i)
					dp[j] = { dp[j].first + b,i + 1 };
			}
		}
		int ans = 100000;
		for (int i = 0; i <= 50000; i++) {
			if (dp[i].second == n) ans = min(ans, max(i, dp[i].first));
		}
		printf("%d\n", ans);
	}

	return 0;
}