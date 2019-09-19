/*
BOJ 3943 - 헤일스톤 수열
https://www.acmicpc.net/problem/3943
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 1000001
using namespace std;

/* 🐣🐥 */
int dp[MAX];
int dfs(int cur) {
	if (cur < MAX && dp[cur] != -1) return dp[cur];
	if (cur >= MAX) {
		if (cur % 2) return max(cur, dfs(cur * 3 + 1));
		else return max(cur, dfs(cur / 2));
	}
	if (cur % 2) return dp[cur] = max(cur, dfs(cur * 3 + 1));
	else return dp[cur] = max(cur, dfs(cur / 2));
}
int main() {
	int t, x;
	memset(dp, -1, sizeof(dp));
	dp[1] = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &x);
		printf("%d\n", dfs(x));
	}

	return 0;
}