/*
BOJ 13538 - XOR 쿼리
https://www.acmicpc.net/problem/13538
*/
#include <cstdio>
#define MAX 500000
using namespace std;

/* 🐣🐥 */
struct node {
	int l, r, val;
} tree[11048576];
int root[MAX + 1], sz = 1, num;
int init(int s,int e) {
	int cur = num++;
	if (s == e) {
		tree[cur].l = tree[cur].r = -1;
		return cur;
	}
	tree[cur].l = init(s, (s + e) / 2);
	tree[cur].r = init((s + e) / 2 + 1, e);
	return cur;
}
int update(int idx, int s,int e, int k) {
	if (s > k || e < k) return idx;
	int cur = num++;
	tree[cur] = tree[idx];
	tree[cur].val++;
	if (s == e) {
		tree[cur].l = tree[cur].r = -1;
		return cur;
	}
	tree[cur].l = update(tree[idx].l, s, (s + e) / 2, k);
	tree[cur].r = update(tree[idx].r, (s + e) / 2 + 1, e, k);
	return cur;
}
int hap(int idx, int s,int e,int l,int r) {
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) {
		return tree[idx].val;
	}
	return hap(tree[idx].l, s, (s + e) / 2, l, r)
		+ hap(tree[idx].r, (s + e) / 2 + 1, e, l, r);
}
int kth(int li,int ri,int s,int e, int k) {
	if (s == e) return s;
	if (tree[tree[ri].l].val - tree[tree[li].l].val >= k) {
		return kth(tree[li].l, tree[ri].l, s,(s+e)/2,k);
	}
	else {
		return kth(tree[li].r, tree[ri].r, (s + e) / 2 + 1, e, k - (tree[tree[ri].l].val - tree[tree[li].l].val));
	}
}
int xoor(int li,int ri,int s,int e,int x,int tt) {
	if (s == e) return s;
	if (x&tt) {
		if (tree[tree[ri].l].val - tree[tree[li].l].val) 
			return xoor(tree[li].l, tree[ri].l, s, (s + e) / 2, x, tt >> 1);
		else 
			return xoor(tree[li].r, tree[ri].r, (s + e) / 2+1,e, x, tt >> 1);
	}
	else {
		if (tree[tree[ri].r].val - tree[tree[li].r].val) 
			return xoor(tree[li].r, tree[ri].r, (s + e) / 2 + 1, e, x, tt >> 1);
		else 
			return xoor(tree[li].l, tree[ri].l, s, (s + e) / 2, x, tt >> 1);
	}
}
int main() {
	int m, x, cm, tn = 0, le, ri;
	while (sz < MAX) sz *= 2;
	root[0] = init(0, sz - 1);
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &cm);
		if (cm == 1) {
			scanf("%d", &x);
			tn++;
			root[tn] = root[tn - 1];
			root[tn] = update(root[tn], 0, sz - 1, x);
		}
		else if (cm == 2) {
			scanf("%d %d %d", &le, &ri, &x);
			printf("%d\n", xoor(root[le - 1], root[ri], 0, sz - 1, x, sz >> 1));
		}
		else if (cm == 3) {
			scanf("%d", &x);
			tn -= x;
		}
		else if (cm == 4) {
			scanf("%d %d %d", &le, &ri, &x);
			printf("%d\n", hap(root[ri], 0, sz - 1, 0, x)
				- hap(root[le - 1], 0, sz - 1, 0, x));
		}
		else if (cm == 5) {
			scanf("%d %d %d", &le, &ri, &x);
			printf("%d\n", kth(root[le - 1], root[ri], 0, sz - 1, x));
		}
	}

	return 0;
}