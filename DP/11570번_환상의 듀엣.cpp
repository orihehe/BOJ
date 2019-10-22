/*
BOJ 11570 - 환상의 듀엣
https://www.acmicpc.net/problem/11570
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

/* 🐣🐥 */
int arr[2001], dp[2001][2001], n;
int dfs(int le, int ri) {
	int nx = max(le, ri) + 1;
	if (nx == n + 1) return 0;
	if (dp[le][ri] != -1) return dp[le][ri];
	int ret = 2100000000;
	ret = min(ret, dfs(le, nx) + (ri ? abs(arr[ri] - arr[nx]) : 0));
	ret = min(ret, dfs(nx, ri) + (le ? abs(arr[le] - arr[nx]) : 0));
	return dp[le][ri] = ret;
}
int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	printf("%d", dfs(0, 0));

	return 0;
}