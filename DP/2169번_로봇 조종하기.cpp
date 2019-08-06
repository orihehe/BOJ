/*
BOJ 2169 - 로봇 조종하기
https://www.acmicpc.net/problem/2169
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int dp[2][1001][1002];
int arr[1001][1002];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &arr[i][j]);
	for (int i = 1; i <= m; i++) {
		dp[0][1][i] = dp[0][1][i - 1] + arr[1][i];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[0][i][j] = dp[0][i - 1][j];
			if (j != 1) dp[0][i][j] = max(dp[0][i][j], dp[0][i][j - 1]);
			dp[0][i][j] += arr[i][j];
		}

		for (int j = m; j >= 0; j--) {
			dp[1][i][j] = dp[0][i - 1][j];
			if (j != m) dp[1][i][j] = max(dp[1][i][j], dp[1][i][j + 1]);
			dp[1][i][j] += arr[i][j];
		}

		for (int j = 1; j <= m; j++)
			dp[0][i][j] = max(dp[0][i][j], dp[1][i][j]);
	}
	printf("%d", dp[0][n][m]);

	return 0;
}