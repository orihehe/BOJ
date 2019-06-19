/*
BOJ 17227 - 그래서 팩 주냐?
https://www.acmicpc.net/problem/17227

준표가 선택한 다음 만영이가 선택할 차례
만영이는 준표가 정색을 많이 하는 화제를 선택하는것이 좋다.
따라서 만영이가 선택할 차례엔 
만영이가 선택한 화제로 갔을 때 정색 수 + 그 정색 수보다 큰 연결된 다른 화제 개수 이다.

만영이가 선택한 다음 준표가 선택할 차례
준표는 정색 수가 적은 화제를 선택한다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define INF 987654321
using namespace std;

/* 🐣🐥 */
int n, dp[100001][2], ind[100001];
vector<int> vec[100001];
int dfs(int cur, int cnt) {
	if (dp[cur][cnt] != -1) return dp[cur][cnt];
	int ret = INF;
	if (cnt) {
		int sz = vec[cur].size();
		for (int v : vec[cur]) {
			dfs(v, cnt ^ 1);
		}
		sort(vec[cur].begin(), vec[cur].end(), [](int a, int b) {
			return dp[a][0] > dp[b][0];
		});
		for (int i = 0; i < sz; i++) {
			ret = min(ret, dp[vec[cur][i]][0] + i);
		}
	}
	else {
		for (int v : vec[cur]) {
			ret = min(ret, dfs(v, cnt ^ 1));
		}
	}
	return dp[cur][cnt] = ret;
}
int main() {
	int e, a, b, ans = INF;
	scanf("%d %d", &n, &e);
	memset(dp, -1, sizeof(dp));
	dp[n][1] = 0, dp[n][0] = INF;
	while (e--) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		ind[b]++;
	}
	for (int i = 1; i <= n; i++) {
		if (!ind[i]) ans = min(ans, dfs(i, 1));
	}
	printf("%d", ans == INF ? -1 : ans);

	return 0;
}