/*
BOJ 2602 - 돌다리 건너기
https://www.acmicpc.net/problem/2602
*/
#include <cstdio>
#include <cstring>
using namespace std;

/* 🐣🐥 */
char st[21], brg[2][101];
int dp[2][21][101], n, m;
int dfs(int w, int p, int cur) {
	if (p == m) return 1;
	if (cur == n) return 0;
	if (dp[w][p][cur] != -1) return dp[w][p][cur];
	int ret = 0;
	for (int i = cur; i < n; i++) {
		if (st[p] == brg[w][i])
			ret += dfs(!w, p + 1, i + 1);
	}
	return dp[w][p][cur] = ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%s %s %s", st, brg[0], brg[1]);
	n = strlen(brg[0]), m = strlen(st);
	printf("%d", dfs(0, 0, 0) + dfs(1, 0, 0));

	return 0;
}