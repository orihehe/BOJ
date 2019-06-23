/*
BOJ 16157 - 블로그
https://www.acmicpc.net/problem/16157
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
char st[101], c;
int dp[101][101];
int dfs(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r];
	if (l == r) return 0;
	if (st[l] == st[r]) {
		return dfs(l + 1, r) + 1;
	}
	int ret = 0;
	for (int i = l; i < r; i++) {
		ret = max(ret, dfs(l, i) + dfs(i + 1, r));
	}
	return dp[l][r] = ret;
}
int main() {
	int n, sp = 0;
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		scanf("%c", &c);
		if (st[sp] != c) st[sp++] = c;
	}
	printf("%d", sp - dfs(0, sp - 1));

	return 0;
}