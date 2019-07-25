/*
BOJ 14898 - 서로 다른 수와 쿼리 2
https://www.acmicpc.net/problem/14898

PST로 같은 수 중에서는 마지막에 등장한 위치만 현재 시점에 저장해두고 풀어준다.
*/
#include <cstdio>
#include <map>
using namespace std;

/* 🐣🐥 */
struct node {
	int l, r, val;
} tree[45000000];
int num, root[1000001];
map<int, int> mp;
int init(int s, int e) {
	int cur = num++;
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
	if (s == e) {
		tree[cur].val ^= 1;
		return cur;
	}
	tree[cur].l = update(tree[idx].l, s, (s + e) / 2, k);
	tree[cur].r = update(tree[idx].r, (s + e) / 2 + 1, e, k);
	tree[cur].val = tree[tree[cur].l].val + tree[tree[cur].r].val;

	return cur;
}
int hap(int idx, int s, int e, int l, int r) {
	if (e < l || s > r) return 0;
	if (l <= s && e <= r) return tree[idx].val;
	return hap(tree[idx].l, s, (s + e) / 2, l, r)
		+ hap(tree[idx].r, (s + e) / 2 + 1, e, l, r);
}
int main() {
	int n, x, ans = 0, q, l, r;
	scanf("%d", &n);
	init(0, n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		root[i] = update(root[i - 1], 0, n, i);
		if (mp.find(x) != mp.end())
			root[i] = update(root[i], 0, n, mp[x]);
		mp[x] = i;
	}
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d", &l, &r);
		l += ans;
		ans = hap(root[r], 0, n, l, r);
		printf("%d\n", ans);
	}

	return 0;
}