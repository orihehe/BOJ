/*
BOJ 15458 - Barn Painting
https://www.acmicpc.net/problem/15458
*/
#include <cstdio>
#include <cstring>
#include <vector>
#define ll long long
#define mod 1000000007
using namespace std;

/* 🐣🐥 */
ll dp[100001][4];
vector<int> vec[100001];
int arr[100001];
ll dfs(int cur, int c, int p) {
	if (dp[cur][c] != -1) return dp[cur][c];
	ll ret = 1, tmp;
	for (int v : vec[cur]) {
		if (p == v) continue;
		tmp = 0;
		if (arr[v]) {
			if (arr[v] == c) return 0;
			tmp = dfs(v, arr[v], cur);
		}
		else {
			for (int i = 1; i <= 3; i++) {
				if (c == i) continue;
				tmp += dfs(v, i, cur);
			}
			tmp %= mod;
		}
		ret = ret * tmp %mod;
	}
	return dp[cur][c] = ret;
}
int main() {
	int n, k, a, b;
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &k);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	vec[0].push_back(1);
	while (k--) {
		scanf("%d %d", &a, &b);
		arr[a] = b;
	}
	printf("%d", dfs(0, 0, 0));

	return 0;
}