/*
BOJ 17485 - 진우의 달 여행 (Large)
https://www.acmicpc.net/problem/17485
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
int dp[1003][1003][3];
int arr[1003][1003];
int main() {
	int n, m, ans = 1000000;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		arr[i][0] = arr[i][m + 1] = 1000000;
		for (int j = 1; j <= m; j++) scanf("%d", &arr[i][j]);
	}
	memset(dp, 0x3f3f, sizeof(dp));
	for (int j = 1; j <= m; j++) dp[0][j][0] = dp[0][j][1] = dp[0][j][2] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < 3; k++) {
				dp[i][j][k] += arr[i][j];
				if (i == n - 1) ans = min(ans, dp[i][j][k]);
			}
			dp[i + 1][j][0] = min({ dp[i + 1][j][0],dp[i][j][2], dp[i][j][1] });
			dp[i + 1][j - 1][1] = min({ dp[i + 1][j - 1][1] , dp[i][j][0], dp[i][j][2] });
			dp[i + 1][j + 1][2] = min({ dp[i + 1][j + 1][2] , dp[i][j][0], dp[i][j][1] });
		}
	}
	printf("%d", ans);

	return 0;
}