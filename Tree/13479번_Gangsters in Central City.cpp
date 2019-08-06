/*
BOJ 13479 - Gangsters in Central City
https://www.acmicpc.net/problem/13479
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
vector<int> vec[100001];
int sps[100001][18], ch[100001], cc[100001], num[100001], cnt;
int tree[262144], tr[262144], dep[100001];
void dfs(int cur, int dd) {
	dep[cur] = dd;
	num[cur] = ++cnt;
	ch[cur] = (vec[cur].size() == 0);
	for (int i = 1; i < 18; i++) {
		sps[cur][i] = sps[sps[cur][i - 1]][i - 1];
	}
	for (int v : vec[cur]) {
		sps[v][0] = cur;
		dfs(v, dd + 1);
		ch[cur] += ch[v];
		cc[cur] += cc[v] + 1;
	}
}
int myroot(int w) {
	for (int i = 17; i >= 0; i--) {
		if (dep[sps[w][i]] >= 2) w = sps[w][i];
	}
	return w;
}
int lca(int a, int b) {
	if (a == 0 && b == 0) return 0;
	if (a == 0) return b;
	if (b == 0) return a;

	if (dep[a] > dep[b]) swap(a, b);
	for (int i = 17; i >= 0; i--) {
		if (dep[sps[b][i]] >= dep[a]) b = sps[b][i];
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
void upLCA(int idx, int s, int e, int k, int val) {
	if (k < s || k > e) return;
	if (s == e) {
		tr[idx] ^= val;
		return;
	}
	upLCA(idx * 2, s, (s + e) / 2, k, val);
	upLCA(idx * 2 + 1, (s + e) / 2 + 1, e, k, val);
	tr[idx] = lca(tr[idx * 2], tr[idx * 2 + 1]);
}
int getLCA(int idx, int s, int e, int l, int r) {
	if (r < s || l > e) return 0;
	if (l <= s && e <= r) return tr[idx];
	return lca(getLCA(idx * 2, s, (s + e) / 2, l, r),
		getLCA(idx * 2 + 1, (s + e) / 2 + 1, e, l, r));
}
void upTree(int idx, int s, int e, int k) {
	if (k < s || k > e) return;
	if (s == e) {
		tree[idx] ^= 1;
		return;
	}
	upTree(idx * 2, s, (s + e) / 2, k);
	upTree(idx * 2 + 1, (s + e) / 2 + 1, e, k);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}
int hap(int idx, int s, int e, int l, int r) {
	if (r < s || l > e) return 0;
	if (l <= s && e <= r) return tree[idx];
	return hap(idx * 2, s, (s + e) / 2, l, r)
		+ hap(idx * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
int main() {
	int n, q, x, pipe = 0, home = 0;
	char cm;
	scanf("%d %d", &n, &q);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &x);
		vec[x].push_back(i);
	}
	dfs(1, 1);
	while (q--) {
		scanf(" %c %d", &cm, &x);
		if (cm == '+') {
			int lc = myroot(x);
			lc = getLCA(1, 1, n, num[lc], num[lc] + cc[lc]);
			if (lc == 0) pipe++;
			else home -= ch[lc] - hap(1, 1, n, num[lc], num[lc] + cc[lc]);
			upLCA(1, 1, n, num[x], x);
			upTree(1, 1, n, num[x]);
			lc = myroot(x);
			lc = getLCA(1, 1, n, num[lc], num[lc] + cc[lc]);
			home += ch[lc] - hap(1, 1, n, num[lc], num[lc] + cc[lc]);
		}
		else {
			int lc = myroot(x);
			lc = getLCA(1, 1, n, num[lc], num[lc] + cc[lc]);
			home -= ch[lc] - hap(1, 1, n, num[lc], num[lc] + cc[lc]);
			upLCA(1, 1, n, num[x], x);
			upTree(1, 1, n, num[x]);
			lc = myroot(x);
			lc = getLCA(1, 1, n, num[lc], num[lc] + cc[lc]);
			if (lc == 0) pipe--;
			else home += ch[lc] - hap(1, 1, n, num[lc], num[lc] + cc[lc]);
		}
		printf("%d %d\n", pipe, home);
	}

	return 0;
}