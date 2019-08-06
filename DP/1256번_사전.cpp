/*
BOJ 1256 - 사전
https://www.acmicpc.net/problem/1256
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

/* 🐣🐥 */
ll dp[101][101];
int n, m, k;
ll dfs(int a, int z) {
	if (a < 0 || z < 0) return 0;
	if (a == 0 && z == 0) return 1;
	if (dp[a][z] != -1) return dp[a][z];
	return dp[a][z] = min(1LL * k, dfs(a - 1, z) + dfs(a, z - 1));
}
void prt(int a, int z, int k) {
	if (a == 0 && z == 0) return;
	if (z == 0 || (a > 0 && dp[a - 1][z] >= k)) {
		printf("a");
		prt(a - 1, z, k);
	}
	else {
		printf("z");
		prt(a, z - 1, k - (a > 0 ? dp[a - 1][z] : 0));
	}
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d %d", &n, &m, &k);
	if (dfs(n, m) < k) return !printf("-1");
	prt(n, m, k);

	return 0;
}