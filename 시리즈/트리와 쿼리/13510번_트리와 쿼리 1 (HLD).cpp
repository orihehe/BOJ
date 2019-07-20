/*
BOJ 13510 - 트리와 쿼리 1
https://www.acmicpc.net/problem/13510
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

/* 🐣🐥 */
struct edge {
	int u, v, val;
} arr[100001];
vector<int> vec[100001];
int p[100001], tree[262144], hld[100001], ch[100001], num[100001], ori[100001];
int n, nb, dep[100001];
int dfs1(int cur, int cnt) {
	dep[cur] = cnt;
	for (int v : vec[cur]) {
		if (!dep[v]) {
			p[v] = cur;
			ch[cur] += dfs1(v, cnt + 1);
		}
	}
	return ++ch[cur];
}
void dfs2(int cur) {
	int c = -1;
	ori[nb] = cur;
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
		if (v != c && p[v] == cur) {
			hld[v] = v;
			dfs2(v);
		}
	}
}
void init(int r) {
	hld[r] = p[r] = r;
	dfs1(r, 1);
	dfs2(r);
}
void update(int idx, int s, int e, int k, int val) {
	if (s > k || e < k) return;
	if (s == e) {
		tree[idx] = val;
		return;
	}
	update(idx * 2, s, (s + e) / 2, k, val);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, k, val);
	tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
}
int getMax(int idx, int s, int e, int l, int r) {
	if (e < l || s > r) return 0;
	if (l <= s && e <= r) return tree[idx];
	return max(getMax(idx * 2, s, (s + e) / 2, l, r),
		getMax(idx * 2 + 1, (s + e) / 2 + 1, e, l, r));
}
int query(int a, int b) {
	int ret = 0;
	while (hld[a] != hld[b]) {
		if (dep[hld[a]] < dep[hld[b]]) {
			ret = max(ret, getMax(1, 0, n - 1, num[hld[b]], num[b]));
			b = p[hld[b]];
		}
		else {
			ret = max(ret, getMax(1, 0, n - 1, num[hld[a]], num[a]));
			a = p[hld[a]];
		}
	}
	if (dep[a] > dep[b]) swap(a, b);
	ret = max(ret, getMax(1, 0, n - 1, num[a] + 1, num[b]));
	return ret;
}
int main() {
	int q, a, b, c;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		vec[a].push_back(b);
		vec[b].push_back(a);
		arr[i] = { a,b,c };
	}
	init(1);
	for (int i = 1; i < n; i++) {
		if (dep[arr[i].u] > dep[arr[i].v]) swap(arr[i].u, arr[i].v);
		update(1, 0, n - 1, num[arr[i].v], arr[i].val);
	}
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) {
			update(1, 0, n - 1, num[arr[b].v], c);
		}
		else if (a == 2) {
			printf("%d\n", query(b, c));
		}
	}

	return 0;
}