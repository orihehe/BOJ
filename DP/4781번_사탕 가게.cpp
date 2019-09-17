/*
BOJ 4781 - 사탕 가게
https://www.acmicpc.net/problem/4781
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int dp[10001];
vector<pii> vec;
int dfs(int cur) {
	if (cur < 0) return -50005000;
	if (dp[cur] != -1) return dp[cur];
	int ret = 0;
	for (pii &v : vec) {
		ret = max(ret, dfs(cur - v.second) + v.first);
	}
	return dp[cur] = ret;
}
int main() {
	int n, m, w;
	double x;
	while (scanf("%d %lf", &n, &x)) {
		m = (x + 1e-8) * 100;
		if (n == 0 && m == 0) break;
		vec.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d %lf", &w, &x);
			vec.push_back({ w,(int)((x + 1e-8) * 100) });
		}
		memset(dp, -1, sizeof(dp));
		printf("%d\n", dfs(m));
	}

	return 0;
}