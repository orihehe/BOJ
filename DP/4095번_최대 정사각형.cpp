/*
BOJ 4095 - 최대 정사각형
https://www.acmicpc.net/problem/4095
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
int arr[1001][1001], dp[1001][1001];
int main() {
	int n, m, ans;
	while (scanf("%d %d", &n, &m)) {
		if (n == 0 && m == 0) break;
		memset(dp, 0, sizeof(dp));
		ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) scanf("%d", &arr[i][j]);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (arr[i][j]) {
					dp[i][j] = min({ dp[i - 1][j],dp[i][j - 1],dp[i - 1][j - 1] }) + 1;
					ans = max(ans, dp[i][j]);
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}