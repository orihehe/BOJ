/*
BOJ 2533 - 사회망 서비스(SNS)
https://www.acmicpc.net/problem/2533

부모가 얼리 아답터라면 나는 얼리 아답터이거나 얼리 아답터가 아닐 수 있다.
부모가 얼리 아답터가 아니라면 나는 얼리 아답터여야 한다.
이 사실로 dp를 돌려준다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
int dp[1000001][2];
vector<int> vec[1000001];
int dfs(int cur, int p, int w) {
	if (dp[cur][w] != -1) return dp[cur][w];
	int ret = 1, tret = 0;
	for (int v : vec[cur])
		if (v != p)
			ret += dfs(v, cur, 1);
	if (w) {
		for (int v : vec[cur])
			if (v != p)
				tret += dfs(v, cur, 0);
	}
	else tret = 1000001;
	return dp[cur][w] = min(tret, ret);
}
int main() {
	int n, a, b;
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	printf("%d", min(dfs(1, 1, 1), dfs(1, 1, 0)));

	return 0;
}