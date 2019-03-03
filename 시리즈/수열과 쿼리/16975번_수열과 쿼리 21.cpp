/*
BOJ 16975 - 수열과 쿼리 21
https://www.acmicpc.net/problem/16975

세그의 각 구간이 구하는 구간에 포함되면 노드에 변경 값을 저장해둔다.
x의 값은 트리를 타고 내려가며 구간에 저장된 값을 가져가면된다.
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;

/* 🐣🐥 */
ll x, *tree;
void update(int idx, int s, int e, int l, int r, ll k) {
	if (r <s || l>e)return;
	if (l <= s && e <= r) {
		tree[idx] += k;
		return;
	}
	update(idx * 2, s, (e + s) / 2, l, r, k);
	update(idx * 2 + 1, (e + s) / 2 + 1, e, l, r, k);
}
ll ans(int idx, int s, int e, int k, ll sum) {
	if (k <s || k>e)return 0;
	sum += tree[idx];
	if (s == e) return sum;
	return ans(idx * 2, s, (e + s) / 2, k, sum)
		+ ans(idx * 2 + 1, (e + s) / 2 + 1, e, k, sum);
}
int main() {
	int n, m, a, b, cm, h;
	scanf("%d", &n);
	h = ceil(log2(n)) + 1;
	tree = new ll[1 << h];
	fill(tree, tree + (1 << h), 0);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &x);
		update(1, 1, n, i, i, x);
	}
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &cm);
		if (cm == 1) {
			scanf("%d %d %lld", &a, &b, &x);
			update(1, 1, n, a, b, x);
		}
		else if (cm == 2) {
			scanf("%d", &a);
			printf("%lld\n", ans(1, 1, n, a, 0));
		}
	}

	return 0;
}