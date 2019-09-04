/*
BOJ 17397 - FLEX
https://www.acmicpc.net/problem/17397
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define INF 987654321
using namespace std;

/* 🐣🐥 */
int dp[1001][11][201], arr[1001];
int n, m;
int dfs(int cur, int num, int rm) {
	if (rm < 0) return INF;
	if (cur == n - 1) return 0;
	if (dp[cur][num][rm] != -1) return dp[cur][num][rm];
	int ret = INF;
	for (int i = arr[cur + 1]; i <= 10; i++) {
		if (i < num) {
			ret = min(ret, (num - i) * (num - i) + dfs(cur + 1, i, rm - (i - arr[cur + 1])));
		}
		else {
			ret = min(ret, dfs(cur + 1, i, rm - (i - arr[cur + 1])));
		}
	}
	return dp[cur][num][rm] = ret;
}
int main() {
	int ans = INF;
	scanf("%d %d", &n, &m);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = arr[0]; i <= 10; i++) {
		ans = min(ans, dfs(0, i, m - (i - arr[0])));
	}
	printf("%d", ans);

	return 0;
}