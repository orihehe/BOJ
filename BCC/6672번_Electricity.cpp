/*
BOJ 6672 - Electricity
https://www.acmicpc.net/problem/6672
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
vector<int> vec[10001], ans;
int num[10001], cnt, bnum, cc[10001], g[10001];
vector<pii> sta, bcc[10001];
int dfs(int cur, int p) {
	int ret = num[cur] = ++cnt;
	for (int v : vec[cur]) {
		if (v == p) continue;
		if (num[cur] > num[v]) sta.push_back({ cur,v });
		if (num[v]) ret = min(ret, num[v]);
		else {
			int tmp = dfs(v, cur);
			ret = min(ret, tmp);
			if (tmp >= num[cur]) {
				while (!sta.empty() && sta.back() != pii(cur, v)) {
					bcc[bnum].push_back(sta.back());
					sta.pop_back();
				}
				bcc[bnum].push_back(sta.back());
				sta.pop_back();
				bnum++;
			}
		}
	}
	return ret;
}
int main() {
	int n, m, a, b, ans, gr;
	while (scanf("%d %d", &n, &m)) {
		if (n == 0 && m == 0) break;
		bnum = cnt = ans = gr = 0;
		for (int i = 0; i < n; i++) {
			vec[i].clear();
			num[i] = cc[i] = g[i] = 0;
		}
		while (m--) {
			scanf("%d %d", &a, &b);
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		for (int i = 0; i < n; i++) {
			if (!num[i]) {
				dfs(i, i);
				gr++;
			}
		}
		for (int i = 0; i < bnum; i++) {
			for (pii v : bcc[i]) {
				if (g[v.first] != i + 1) cc[v.first]++;
				if (g[v.second] != i + 1) cc[v.second]++;
				g[v.first] = g[v.second] = i + 1;
			}
			bcc[i].clear();
		}
		for (int i = 0; i < n; i++) {
			ans = max(ans, cc[i]);
		}
		printf("%d\n", gr + ans - 1);
	}

	return 0;
}