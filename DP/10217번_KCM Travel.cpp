/*
BOJ 10217 - KCM Travel
https://www.acmicpc.net/problem/10217

dp[정점][비용]으로 두고 현재 정점에서 n에 도착할 최소시간을 저장해둔다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define INF 987654321
using namespace std;

/* 🐣🐥 */
struct info {
	int o, cost, t;
};
int dp[101][10001], n, m;
vector<info> vec[101];
int dfs(int cur, int val) {
	if (cur == n) return 0;
	if (dp[cur][val] != -1) return dp[cur][val];
	int ret = INF;
	for (info v : vec[cur]) {
		if (val + v.cost > m) continue;
		ret = min(ret, dfs(v.o, val + v.cost) + v.t);
	}
	return dp[cur][val] = ret;
}
int main() {
	int t, k, a, b, c, d;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &k);
		memset(dp, -1, sizeof(dp));
		while (k--) {
			scanf("%d %d %d %d", &a, &b, &c, &d);
			vec[a].push_back({ b,c,d });
		}
		int ans = dfs(1, 0);
		if (ans == INF) printf("Poor KCM\n");
		else printf("%d\n", ans);
		for (int i = 1; i <= n; i++) vec[i].clear();
	}

	return 0;
}