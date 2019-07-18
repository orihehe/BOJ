/*
BOJ 11012 - Egg
https://www.acmicpc.net/problem/11012
*/
#include <cstdio>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
struct node {
	int l, r, val;
} tree[1500000];
int num, root[100001];
int init(int s, int e) {
	int cur = num++;
	tree[cur].val = 0;
	if (s == e) {
		tree[cur].l = tree[cur].r = -1;
		return cur;
	}
	tree[cur].l = init(s, (s + e) / 2);
	tree[cur].r = init((s + e) / 2 + 1, e);
	return cur;
}
void update(int idx, int k) {
	tree[num] = tree[root[idx]];
	tree[num].val++;
	root[idx] = num++;
	int cur = root[idx];
	int s = 0, e = 100001;
	while (true) {
		int mid = (s + e) / 2;
		if (k <= mid) {
			tree[num] = tree[tree[cur].l];
			tree[num].val++;
			tree[cur].l = num;
			cur = num;
			num++;
			e = mid;
		}
		else {
			tree[num] = tree[tree[cur].r];
			tree[num].val++;
			tree[cur].r = num;
			cur = num;
			num++;
			s = mid + 1;
		}
		if (s == e) break;
	}
}
int hap(int idx, int s, int e, int l, int r) {
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return tree[idx].val;
	return hap(tree[idx].l, s, (s + e) / 2, l, r)
		+ hap(tree[idx].r, (s + e) / 2 + 1, e, l, r);
}
pii arr[10000];
int main() {
	int t, n, m, ans, a, b, c, d;
	scanf("%d", &t);
	while (t--) {
		num = 1;
		ans = 0;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &arr[i].first, &arr[i].second);
			arr[i].first++;
		}
		sort(arr, arr + n);
		root[0] = init(0, 100001);
		int tn = 0;
		for (int i = 0; i < n; i++) {
			while (tn < arr[i].first) {
				++tn;
				root[tn] = root[tn - 1];
			}
			update(tn, arr[i].second);
		}
		while (m--) {
			scanf("%d %d %d %d", &a, &b, &c, &d);
			a++, b++;
			if (a - 1 <= tn)
				ans += hap(root[min(b, tn)], 0, 100001, c, d)
				- hap(root[a - 1], 0, 100001, c, d);
		}
		printf("%d\n", ans);
	}

	return 0;
}