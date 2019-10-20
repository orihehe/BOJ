/*
BOJ 2342 - Dance Dance Revolution
https://www.acmicpc.net/problem/2342
*/
#include <cstdio>
#include <algorithm>
#define INF 1987654321
using namespace std;

/* 🐣🐥 */
int dp[100001][5][5], arr[100001];
int pls(int a, int b) {
	if (a == 0) return 2;
	a--, b--;
	if (a == b) return 1;
	if ((a + 2) % 4 == b) return 4;
	return 3;
}
int main() {
	int n = 1, ans = INF;
	while (scanf("%d", &arr[n])) {
		if (arr[n] == 0) break;
		n++;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				dp[i][j][k] = INF;
	dp[0][0][0] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				dp[i][j][arr[i]] = min(dp[i][j][arr[i]], dp[i - 1][j][k] + pls(k, arr[i]));
				dp[i][arr[i]][k] = min(dp[i][arr[i]][k], dp[i - 1][j][k] + pls(j, arr[i]));
			}
		}
	}
	for (int j = 0; j < 5; j++)
		for (int k = 0; k < 5; k++)
			ans = min(ans, dp[n - 1][j][k]);
	printf("%d", ans);

	return 0;
}