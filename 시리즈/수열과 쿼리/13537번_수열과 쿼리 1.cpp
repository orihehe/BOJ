/*
BOJ 13537 - 수열과 쿼리 1
https://www.acmicpc.net/problem/13537

오프라인 쿼리로 풀었다.
arr배열엔 수열을, q배열엔 쿼리를 저장해두고 sort
쿼리를 val이 큰 값부터 봐주며 수열에서 val보다 큰 값을 세그트리에 넣어줬다.
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
struct node {
	int le, ri, val, idx;
	bool operator <(const node &a) const {
		return val < a.val;
	}
}q[100001];
int *tree, ans[100001];
pii arr[100001];
void update(int idx, int s, int e, int k) {
	if (e<k || s>k) return;
	tree[idx]++;
	if (s == e) return;

	update(idx * 2, s, (s + e) / 2, k);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, k);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}
int num(int idx, int s, int e, int l, int r) {
	if (e<l || s>r) return 0;
	if (l <= s && e <= r) {
		return tree[idx];
	}
	return num(idx * 2, s, (s + e) / 2, l, r)
		+ num(idx * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
int main() {
	int n, m, h, ap, qp;
	scanf("%d", &n);
	h = ceil(log2(n)) + 1;
	h = 1 << h;
	tree = new int[h];
	fill(tree, tree + h, 0);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i].first);
		arr[i].second = i;
	}
	sort(arr + 1, arr + n + 1);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &q[i].le, &q[i].ri, &q[i].val);
		q[i].idx = i;
	}
	sort(q + 1, q + m + 1);

	ap = n, qp = m;
	while (qp > 0) {
		while (ap >0 && arr[ap].first > q[qp].val) {
			update(1, 1, n, arr[ap--].second);
		}
		ans[q[qp].idx] = num(1, 1, n, q[qp].le, q[qp].ri);
		qp--;
	}
	for (int i = 1; i <= m; i++) {
		printf("%d\n", ans[i]);
	}

	return 0;
}