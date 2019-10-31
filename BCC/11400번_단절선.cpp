/*
BOJ 11400 - 단절선
https://www.acmicpc.net/problem/11400
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
vector<int> vec[100001];
vector<pii> ans;
int num[100001], cnt;
int dfs(int cur, int p) {
	int ret = num[cur] = ++cnt;
	for (int v : vec[cur]) {
		if (v == p) continue;
		if (num[v]) ret = min(ret, num[v]);
		else {
			int tmp = dfs(v, cur);
			ret = min(ret, tmp);
			if (tmp > num[cur]) ans.push_back({ min(cur,v),max(cur,v) });
		}
	}

	return ret;
}
int main() {
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs(1, 1);
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (pii v : ans) printf("%d %d\n", v.first, v.second);

	return 0;
}