/*
BOJ 1563 - 개근상
https://www.acmicpc.net/problem/1563

dp[N][지각][연속 결석 수]
*/
#include <cstdio>
#include <cstring>
using namespace std;

/* 🐣🐥 */
int dp[1001][2][3];
int dfs(int cur, int w, int a) {
	if (cur < 0) return 0;
	if (cur == 0) return 1;
	if (dp[cur][w][a] != -1) return dp[cur][w][a];
	int ret = 0;
	if (w) ret += dfs(cur - 1, 0, 0);
	if (a != 2) ret += dfs(cur - 1, w, a + 1);
	ret += dfs(cur - 1, w, 0);
	return dp[cur][w][a] = ret % 1000000;
}
int main() {
	int n;
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	printf("%d", dfs(n, 1, 0));

	return 0;
}