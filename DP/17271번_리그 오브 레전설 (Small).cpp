/*
BOJ 17271 - 리그 오브 레전설 (Small)
https://www.acmicpc.net/problem/17271

dp[i] = dp[i-1]+dp[i-m] (현재 시간 스킬 A선택경우 + B선택경우)
*/
#include <cstdio>
#include <cstring>
#define mod 1000000007
using namespace std;

/* 🐣🐥 */
int n, m;
int dp[10001];
int dfs(int cur) {
	if (cur < m) return dp[cur] = 1;
	if (dp[cur] != -1) return dp[cur];
	dp[cur] = (dfs(cur - 1) + dfs(cur - m)) % mod;
	return dp[cur];
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &m);
	printf("%d", dfs(n));

	return 0;
}