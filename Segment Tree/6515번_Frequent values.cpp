/*
BOJ 6515 - Frequent values
https://www.acmicpc.net/problem/6515
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
struct node {
	int le, ri, al;
} tree[262144];
int arr[100001];
node merge(node &a, node &b, int s, int e, int md) {
	node ret;
	if (a.al == 0) return b;
	if (b.al == 0) return a;
	ret.le = a.le + (arr[s] == arr[md + 1] ? b.le : 0);
	ret.ri = b.ri + (arr[md] == arr[e] ? a.ri : 0);
	ret.al = max({ ret.le,ret.ri,a.al,b.al });
	if (arr[md] == arr[md + 1]) ret.al = max(ret.al, a.ri + b.le);
	return ret;
}
void init(int idx, int s, int e) {
	if (s == e) {
		tree[idx] = { 1,1,1 };
		return;
	}
	init(idx * 2, s, (s + e) / 2);
	init(idx * 2 + 1, (s + e) / 2 + 1, e);
	tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1], s, e, (s + e) / 2);
}
node find(int idx, int s, int e, int l, int r) {
	if (s > r || e < l) return { 0,0,0 };
	if (l <= s && e <= r) return tree[idx];
	node il = find(idx * 2, s, (s + e) / 2, l, r),
		ir = find(idx * 2 + 1, (s + e) / 2 + 1, e, l, r);
	return merge(il, ir, s, e, (s + e) / 2);
}
int main() {
	int n, q, a, b;
	while (scanf("%d", &n)) {
		if (n == 0) break;
		memset(tree, 0, sizeof(tree));
		scanf("%d", &q);
		for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
		init(1, 1, n);
		while (q--) {
			scanf("%d %d", &a, &b);
			printf("%d\n", find(1, 1, n, a, b).al);
		}
	}

	return 0;
}