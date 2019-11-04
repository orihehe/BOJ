/*
BOJ 9520 - NP-hard
https://www.acmicpc.net/problem/9520
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
int arr[1501][1501], dp[1501][1501];
int main() {
	int n;
	scanf("%d", &n);
	memset(dp, 0x3f, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	dp[1][1] = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + arr[i - 1][i]);
			dp[i][i - 1] = min(dp[i][i - 1], dp[j][i - 1] + arr[j][i]);
			dp[i - 1][i] = min(dp[i - 1][i], dp[i - 1][j] + arr[i][j]);
			dp[j][i] = min(dp[j][i], dp[j][i - 1] + arr[i][i - 1]);
		}
	}
	int mn = 1987654231;
	for (int i = 1; i <= n; i++) {
		mn = min(mn, dp[i][n]);
		mn = min(mn, dp[n][i]);
	}
	printf("%d", mn);

	return 0;
}