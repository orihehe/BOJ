/*
BOJ 11932 - 트리와 K번째 수
https://www.acmicpc.net/problem/11932
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
struct node {
	int l, r, val;
} tree[2000000];
int n, p[100001], dep[100001], sps[100001][18], root[100001], arr[100001], num;
vector<int> loc, vec[100001];
int init(int s, int e) {
	int cur = num++;
	tree[cur] = { 0,0,0 };
	if (s != e) {
		tree[cur].l = init(s, (s + e) / 2);
		tree[cur].r = init((s + e) / 2 + 1, e);
	}
	return cur;
}
int update(int idx, int s, int e, int k) {
	if (k < s || k > e) return idx;
	int cur = num++;
	tree[cur] = tree[idx];
	tree[cur].val++;
	if (s == e) return cur;
	tree[cur].l = update(tree[idx].l, s, (s + e) / 2, k);
	tree[cur].r = update(tree[idx].r, (s + e) / 2 + 1, e, k);
	return cur;
}
int kth(int a, int b, int c, int d, int s, int e, int k) {
	if (s == e) return s;
	int kkk = tree[tree[a].l].val + tree[tree[b].l].val
		- tree[tree[c].l].val - tree[tree[d].l].val;
	if (kkk >= k) return kth(tree[a].l, tree[b].l, tree[c].l, tree[d].l, s, (s + e) / 2, k);
	else return kth(tree[a].r, tree[b].r, tree[c].r, tree[d].r, (s + e) / 2 + 1, e, k - kkk);
}
void dfs(int cur, int dd) {
	dep[cur] = dd;
	for (int i = 1; i <= 17; i++)
		sps[cur][i] = sps[sps[cur][i - 1]][i - 1];
	root[cur] = root[p[cur]];
	root[cur] = update(root[cur], 0, n,
		lower_bound(loc.begin(), loc.end(), arr[cur]) - loc.begin());
	for (int v : vec[cur]) {
		if (p[cur] != v) {
			p[v] = sps[v][0] = cur;
			dfs(v, dd + 1);
		}
	}
}
int lca(int a, int b) {
	if (dep[a] > dep[b]) swap(a, b);
	for (int i = 17; i >= 0; i--) {
		if (dep[sps[b][i]] >= dep[a]) b = sps[b][i];
	}
	if (a == b) return a;
	for (int i = 17; i >= 0; i--) {
		if (sps[a][i] != sps[b][i]) {
			a = sps[a][i], b = sps[b][i];
		}
	}
	return sps[a][0];
}
int main() {
	int m, a, b, x;
	scanf("%d %d", &n, &m);
	root[0] = init(0, n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		loc.push_back(arr[i]);
	}
	sort(loc.begin(), loc.end());
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs(1, 1);
	while (m--) {
		scanf("%d %d %d", &a, &b, &x);
		int lc = lca(a, b);
		printf("%d\n", loc[kth(root[a], root[b], root[lc], root[p[lc]], 0, n, x)]);
	}

	return 0;
}