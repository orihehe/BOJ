/*
BOJ 11962 - Counting Haybales
https://www.acmicpc.net/problem/11962

최솟값 레이지 구현이 오래걸렸다..
*/
#include <cstdio>
#include <algorithm>
#define ll long long
#define MAX 20000000000000000
using namespace std;

/* 🐣🐥 */
ll tree[524289], lazy[524289], arr[200001], ss[524289], c;
int n, q, a, b;
void init(int idx, int s, int e) {
	if (s == e) {
		tree[idx] = arr[s];
		ss[idx] = arr[s];
		return;
	}
	init(idx * 2, s, (s + e) / 2);
	init(idx * 2 + 1, (s + e) / 2 + 1, e);
	tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
	ss[idx] = ss[idx * 2] + ss[idx * 2 + 1];
}
ll minV(int idx, int s, int e, int l, int r, ll sum) {
	if (r<s || l>e) return MAX;
	sum += lazy[idx];
	if (l <= s && e <= r) {
		return tree[idx] + sum;
	}
	return min(minV(idx * 2, s, (s + e) / 2, l, r, sum),
		minV(idx * 2 + 1, (s + e) / 2 + 1, e, l, r, sum));
}
void update(int idx, int s, int e, int l, int r, ll val) {
	if (r<s || l>e) return;
	if (l <= s && e <= r) {
		lazy[idx] += val;
		return;
	}
	int fl = max(l, s), fr = min(r, e);
	ss[idx] += val * (fr - fl + 1); 
	update(idx * 2, s, (s + e) / 2, l, r, val);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, l, r, val);
	tree[idx] = min(tree[idx * 2] + lazy[idx * 2], 
		tree[idx * 2 + 1] + lazy[idx * 2 + 1]);
}
ll hap(int idx, int s, int e, int l, int r, ll sum) {
	if (r<s || l>e) return 0;
	sum += lazy[idx];
	if (l <= s && e <= r) {
		return ss[idx] + sum * (e - s + 1);
	}
	return hap(idx * 2, s, (s + e) / 2, l, r, sum) +
		hap(idx * 2 + 1, (s + e) / 2 + 1, e, l, r, sum);
}
int main() {
	char cm;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
	}
	init(1, 1, n);
	for (int i = 0; i < q; i++) {
		scanf(" %c %d %d", &cm, &a, &b);
		if (cm == 'M') {
			printf("%lld\n", minV(1, 1, n, a, b, 0));
		}
		else if (cm == 'S') {
			printf("%lld\n", hap(1, 1, n, a, b, 0));
		}
		else if (cm == 'P') {
			scanf("%lld", &c);
			update(1, 1, n, a, b, c);
		}
	}

	return 0;
}