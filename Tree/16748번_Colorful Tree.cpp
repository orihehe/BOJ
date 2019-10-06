/*
BOJ 16748 - Colorful Tree
https://www.acmicpc.net/problem/16748

dfs 넘버링으로 수를 다시 부여한 뒤 어떤 노드의 가까운 양옆 노드와의 lca중 가까운 lca가 존재
새 정점이 추가되면 양 옆 노드와 나의 거리 - 양옆끼리의 거리가 추가되는 간선 수 *2가 된다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#define ll long long
using namespace std;

/* 🐣🐥 */
vector<int> vec[100001];
set<int> sss[100001];
set<int> ::iterator aa, bb;
int dist[100001], ii[100001], idx[100001], cnt, sps[100001][18], now[100001];
ll ans[100001];
void dfs(int cur, int dd, int p) {
	idx[cur] = ++cnt;
	ii[cnt] = cur;
	dist[cur] = dd;
	for (int i = 1; i < 18; i++) {
		sps[cur][i] = sps[sps[cur][i - 1]][i - 1];
	}

	for (int v : vec[cur]) {
		if (v == p) continue;
		sps[v][0] = cur;
		dfs(v, dd + 1, cur);
	}
}
int lca(int a, int b) {
	if (dist[a] > dist[b]) swap(a, b);
	for (int i = 17; i >= 0; i--) {
		if (dist[sps[b][i]] >= dist[a])
			b = sps[b][i];
	}
	if (a == b) return a;
	for (int i = 17; i >= 0; i--) {
		if (sps[b][i] != sps[a][i]) {
			b = sps[b][i];
			a = sps[a][i];
		}
	}
	return sps[a][0];
}
int getD(int i, int cl) {
	int ret = 0, la, mla, a, b;

	if (sss[cl].size() == 0) return 0;
	else {
		aa = sss[cl].lower_bound(idx[i]);
		if (aa == sss[cl].begin()) {
			bb = --sss[cl].end();
		}
		else if (aa == sss[cl].end()) {
			--aa;
			bb = sss[cl].begin();
		}
		else {
			bb = prev(aa);
		}
		a = ii[*aa], b = ii[*bb];

		la = lca(i, a);
		ret += dist[a] + dist[i] - 2 * dist[la];
		mla = lca(i, b);
		ret += dist[b] + dist[i] - 2 * dist[mla];

		mla = lca(a, b);
		ret -= dist[a] + dist[b] - 2 * dist[mla];

		return ret;
	}
}
int main() {
	int n, c, a, b, q;
	char cm;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs(1, 0, 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c);

		now[i] = c;
		ans[c] += getD(i, c);
		sss[c].insert(idx[i]);
	}
	int cur, to;
	scanf("%d", &q);
	while (q--) {
		scanf(" %c", &cm);
		if (cm == 'Q') {
			scanf("%d", &c);
			printf("%lld\n", sss[c].size() == 0 ? -1 : ans[c] / 2);
		}
		else if (cm == 'U') {
			scanf("%d %d", &cur, &to);
			c = now[cur];
			sss[c].erase(idx[cur]);
			ans[c] -= getD(cur, c);

			ans[to] += getD(cur, to);
			sss[to].insert(idx[cur]);
			now[cur] = to;
		}
	}

	return 0;
}