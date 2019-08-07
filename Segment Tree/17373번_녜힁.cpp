/*
BOJ 17373 - 녜힁
https://www.acmicpc.net/problem/17373
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

/* 🐣🐥 */
struct node {
	int le, ri, val;
} tree[4200000];
int root[1000001], num, arr[100001];
ll dp[1000001];
int init(int s, int e) {
	int cur = num++;
	tree[cur] = { 0,0,1 };
	if (s != e) {
		tree[cur].le = init(s, (s + e) / 2);
		tree[cur].ri = init((s + e) / 2 + 1, e);
		tree[cur].val = tree[tree[cur].le].val + tree[tree[cur].ri].val;
	}
	return cur;
}
int update(int idx, int s, int e, int k) {
	if (k < s || k > e) return idx;
	int cur = num++;
	if (s == e) {
		tree[cur] = { 0,0,0 };
		return cur;
	}
	tree[cur].le = update(tree[idx].le, s, (s + e) / 2, k);
	tree[cur].ri = update(tree[idx].ri, (s + e) / 2 + 1, e, k);
	tree[cur].val = tree[tree[cur].le].val + tree[tree[cur].ri].val;
	return cur;
}
int find(int idx, int s, int e, int k) {
	if (s == e) return s;
	if (tree[tree[idx].le].val >= k)
		return find(tree[idx].le, s, (s + e) / 2, k);
	else return find(tree[idx].ri, (s + e) / 2 + 1, e, k - tree[tree[idx].le].val);
}
int main() {
	int n, m, q;
	ll x;
	scanf("%d %d %d", &n, &m, &q);
	init(1, m);
	for (int i = n - 1; i >= 0; i--)
		scanf("%d", &arr[i]);
	for (int i = 1; i < n; i++)
		root[arr[i]] = update(root[arr[i - 1]], 1, m, arr[i - 1]);
	dp[1] = tree[root[1]].val;
	for (int i = 2; i <= m; i++)
		dp[i] = dp[i - 1] + tree[root[i]].val;
	while (q--) {
		scanf("%lld", &x);
		int idx = lower_bound(dp + 1, dp + 1 + m, x) - dp;
		if (idx == m + 1) {
			printf("-1 -1\n");
			continue;
		}
		printf("%d %d\n", idx, find(root[idx], 1, m, x - dp[idx - 1]));
	}

	return 0;
}