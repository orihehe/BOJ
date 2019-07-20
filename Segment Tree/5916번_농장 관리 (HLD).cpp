/*
BOJ 5916 - 농장 관리
https://www.acmicpc.net/problem/5916
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;

/* 🐣🐥 */
vector<int> vec[100001];
int num[100001], p[100001], ch[100001], dep[100001], hld[100001], lazy[262144];
int n, nb;
ll tree[262144];
int dfs1(int cur, int cnt) {
	dep[cur] = cnt;
	for (int v : vec[cur]) {
		if (!dep[v]) {
			p[v] = cur;
			ch[cur] = dfs1(v, cnt + 1);
		}
	}
	return ++ch[cur];
}
void dfs2(int cur) {
	int c = -1;
	num[cur] = nb++;
	for (int v : vec[cur]) {
		if (p[v] == cur && (c == -1 || ch[c] < ch[v]))
			c = v;
	}
	if (c != -1) {
		hld[c] = hld[cur];
		dfs2(c);
	}
	for (int v : vec[cur]) {
		if (p[v] == cur && v != c) {
			hld[v] = v;
			dfs2(v);
		}
	}
}
void update(int idx, int s, int e, int l, int r) {
	if (e < l || s > r) return;
	if (l <= s && e <= r) {
		lazy[idx]++;
		return;
	}
	tree[idx] += min(r, e) - max(s, l) + 1;
	update(idx * 2, s, (s + e) / 2, l, r);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
ll hap(int idx, int s, int e, int l, int r, ll sum) {
	if (e < l || s > r) return 0;
	sum += lazy[idx];
	if (l <= s && e <= r) {
		return tree[idx] + sum * (e - s + 1);
	}
	return hap(idx * 2, s, (s + e) / 2, l, r, sum)
		+ hap(idx * 2 + 1, (s + e) / 2 + 1, e, l, r, sum);
}
void cmP(int a, int b) {
	while (hld[a] != hld[b]) {
		if (dep[hld[a]] < dep[hld[b]]) {
			update(1, 0, n, num[hld[b]], num[b]);
			b = p[hld[b]];
		}
		else {
			update(1, 0, n, num[hld[a]], num[a]);
			a = p[hld[a]];
		}
	}
	if (dep[a] > dep[b]) swap(a, b);
	update(1, 0, n, num[a] + 1, num[b]);
}
ll cmQ(int a, int b) {
	ll ret = 0;
	while (hld[a] != hld[b]) {
		if (dep[hld[a]] < dep[hld[b]]) {
			ret += hap(1, 0, n, num[hld[b]], num[b], 0);
			b = p[hld[b]];
		}
		else {
			ret += hap(1, 0, n, num[hld[a]], num[a], 0);
			a = p[hld[a]];
		}
	}
	if (dep[a] > dep[b]) swap(a, b);
	ret += hap(1, 0, n, num[a] + 1, num[b], 0);
	return ret;
}
int main() {
	int m, a, b;
	char cm;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	hld[1] = p[1] = 1;
	dfs1(1, 1);
	dfs2(1);
	while (m--) {
		scanf(" %c %d %d", &cm, &a, &b);
		if (cm == 'P') cmP(a, b);
		else if (cm == 'Q') printf("%lld\n", cmQ(a, b));
	}

	return 0;
}