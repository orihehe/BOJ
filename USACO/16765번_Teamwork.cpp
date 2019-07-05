/*
BOJ 16765 - Teamwork
https://www.acmicpc.net/problem/16765
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
int dp[10001], arr[10001], n, k;
int dfs(int cur) {
	if (cur >= n) return 0;
	if (dp[cur] != -1) return dp[cur];
	int mx = 0;
	for (int i = 0; i < k; i++) {
		if (cur + i >= n) break;
		mx = max(mx, arr[cur + i]);
		dp[cur] = max(dp[cur], dfs(cur + i + 1) + (i + 1)*mx);
	}
	return dp[cur];
}
int main() {
	scanf("%d %d", &n, &k);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	printf("%d", dfs(0));

	return 0;
}