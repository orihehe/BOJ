/*
BOJ 10131 - FarmCraft
https://www.acmicpc.net/problem/10131

각 서브트리에서의 최댓값을 구하여 정렬 후 그 순서로 배달한다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

/* 🐣🐥 */
int arr[500001], tm[500001], ans, sz[500001];
vector<int> vec[500001];
bool cmp(int a, int b) {
	return tm[b] + sz[a] * 2 < tm[a] + sz[b] * 2;
}
int dfs(int cur, int p) {
	for (int v : vec[cur]) {
		if (p == v) continue;
		sz[cur] += dfs(v, cur);
	}
	sort(vec[cur].begin(), vec[cur].end(), cmp);
	int ttt = 0;
	int ret = arr[cur];
	for (int v : vec[cur]) {
		if (p == v) continue;
		ret = max(ret, tm[v] + ttt + 1);
		ttt += sz[v] * 2;
	}
	tm[cur] = ret;
	ans = max(ans, ret);
	return ++sz[cur];
}
int main() {
	int n, a, b;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	ans = arr[1] + (n - 1) * 2;
	dfs(1, 1);

	printf("%d", ans);

	return 0;
}