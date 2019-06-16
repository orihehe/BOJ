/*
BOJ 1693 - 트리 색칠하기
https://www.acmicpc.net/problem/1693

https://blog.encrypted.gg/144 - 색 가짓수 증명 (바킹독님)
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
vector<int> vec[100001];
int dp[100001][19];
int dfs(int cur, int p, int c) {
	int ret = 0, tmp;
	if (dp[cur][c] != -1) return dp[cur][c];
	for (int v : vec[cur]) {
		if (v != p) {
			tmp = 987654321;
			for (int i = 1; i <= 18; i++) {
				if (c == i) continue;
				tmp = min(tmp, dfs(v, cur, i));
			}
			ret += tmp;
		}
	}
	return dp[cur][c] = ret + c;
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
	vec[0].push_back(1);
	printf("%d", dfs(0, 0, 0));

	return 0;
}