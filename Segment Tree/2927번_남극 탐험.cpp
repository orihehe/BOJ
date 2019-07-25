/*
BOJ 2927 - 남극 탐험
https://www.acmicpc.net/problem/2927

쿼리를 다 받아서 트리를 만들어 HLD 구축해둔뒤, 쿼리를 다시 봐준다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
struct query {
	char cm[11];
	int a, b;
} Q[300001];
char st[11];
int n, arr[30001], p[30001], hld[30001], tree[65536], pp[30001];
int ch[30001], dep[30001], num[30001], cnt;
vector<int> vec[30001];
int dfs1(int cur, int dd) {
	ch[cur] = 1;
	dep[cur] = dd;
	for (int v : vec[cur]) {
		if (!dep[v]) {
			ch[cur] += dfs1(v, dd + 1);
			p[v] = cur;
		}
	}
	return ch[cur];
}
void dfs2(int cur) {
	int c = -1;
	num[cur] = cnt++;
	for (int v : vec[cur]) {
		if (p[v] == cur && (c == -1 || ch[v] > ch[c])) c = v;
	}
	if (c != -1) {
		hld[c] = hld[p[c]];
		dfs2(c);
	}
	for (int v : vec[cur]) {
		if (p[v] == cur && v != c) {
			hld[v] = v;
			dfs2(v);
		}
	}
}
int hap(int idx, int s, int e, int l, int r) {
	if (e < l || s > r) return 0;
	if (l <= s && e <= r) return tree[idx];
	return hap(idx * 2, s, (s + e) / 2, l, r)
		+ hap(idx * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
void update(int idx, int s, int e, int k, int val) {
	if (k < s || k > e) return;
	if (s == e) {
		tree[idx] = val;
		return;
	}
	update(idx * 2, s, (s + e) / 2, k, val);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, k, val);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}
int getAns(int a, int b) {
	int ret = 0;
	while (hld[a] != hld[b]) {
		if (dep[hld[a]] > dep[hld[b]]) {
			ret += hap(1, 0, n, num[hld[a]], num[a]);
			a = p[hld[a]];
		}
		else {
			ret += hap(1, 0, n, num[hld[b]], num[b]);
			b = p[hld[b]];
		}
	}
	if (dep[a] > dep[b]) swap(a, b);
	ret += hap(1, 0, n, num[a], num[b]);
	return ret;
}
int find(int a) {
	if (pp[a] == -1) return a;
	return pp[a] = find(pp[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return;
	pp[a] = b;
}
int main() {
	memset(pp, -1, sizeof(pp));
	int q;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%s %d %d", Q[i].cm, &Q[i].a, &Q[i].b);
		if (Q[i].cm[0] == 'b') {
			if (find(Q[i].a) != find(Q[i].b)) {
				merge(Q[i].a, Q[i].b);
				vec[Q[i].a].push_back(Q[i].b);
				vec[Q[i].b].push_back(Q[i].a);
			}
		}
	}
	memset(pp, -1, sizeof(pp));
	for (int i = 1; i <= n; i++) {
		if (!hld[i]) {
			p[i] = hld[i] = i;
			dfs1(i, 1);
			dfs2(i);
		}
	}
	for (int i = 1; i <= n; i++) update(1, 0, n, num[i], arr[i]);
	for (int i = 0; i < q; i++) {
		if (Q[i].cm[0] == 'b') {
			if (find(Q[i].a) == find(Q[i].b)) printf("no\n");
			else printf("yes\n");
			merge(Q[i].a, Q[i].b);
		}
		else if (Q[i].cm[0] == 'e') {
			if (find(Q[i].a) != find(Q[i].b)) printf("impossible\n");
			else printf("%d\n", getAns(Q[i].a, Q[i].b));
		}
		else if (Q[i].cm[0] == 'p') {
			update(1, 0, n, num[Q[i].a], Q[i].b);
		}
	}

	return 0;
}