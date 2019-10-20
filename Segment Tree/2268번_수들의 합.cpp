/*
BOJ 2268 - 수들의 합
https://www.acmicpc.net/problem/2268
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

/* 🐣🐥 */
ll tree[2097152];
void update(int idx, int s, int e, int k, int val) {
	if (k<s || k>e) return;
	if (s == e) {
		tree[idx] = val;
		return;
	}
	update(idx * 2, s, (s + e) / 2, k, val);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, k, val);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}
ll hap(int idx, int s, int e, int l, int r) {
	if (e < l || r < s) return 0;
	if (l <= s && e <= r) return tree[idx];
	return hap(idx * 2, s, (s + e) / 2, l, r) +
		hap(idx * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
int main() {
	int n, m, a, b, c;
	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0) {
			if (b > c) swap(b, c);
			printf("%lld\n", hap(1, 1, n, b, c));
		}
		else
			update(1, 1, n, b, c);
	}

	return 0;
}