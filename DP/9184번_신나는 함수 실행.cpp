/*
BOJ 9184 - 신나는 함수 실행
https://www.acmicpc.net/problem/9184
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
int dp[21][21][21];
int dfs(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (dp[a][b][c] != -1) return dp[a][b][c];
	if (a < b && b < c)
		return dp[a][b][c] = dfs(a, b, c - 1) + dfs(a, b - 1, c - 1) - dfs(a, b - 1, c);
	return dp[a][b][c] = dfs(a - 1, b, c) + dfs(a - 1, b - 1, c)
		+ dfs(a - 1, b, c - 1) - dfs(a - 1, b - 1, c - 1);
}
int main() {
	int a, b, c;
	while (scanf("%d %d %d", &a, &b, &c)) {
		if (a == -1 && b == -1 && c == -1) break;
		memset(dp, -1, sizeof(dp));
		printf("w(%d, %d, %d) = %d\n", a, b, c, dfs(min(a, 20), min(b, 20), min(c, 20)));
	}

	return 0;
}