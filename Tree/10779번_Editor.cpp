/*
BOJ 10779 - Editor
https://www.acmicpc.net/problem/10779
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;

/* 🐣🐥 */
struct node {
	int l, r, val;
} tree[14000000];
int num, root[300001];
int init(int s, int e) {
	int cur = num++;
	tree[cur] = { 0,0,INF };
	if (s != e) {
		tree[cur].l = init(s, (s + e) / 2);
		tree[cur].r = init((s + e) / 2 + 1, e);
	}
	return cur;
}
int update(int idx, int s, int e, int k, int v) {
	if (s > k || e < k) return idx;
	int cur = num++;
	if (s == e) {
		tree[cur] = tree[idx];
		tree[cur].val = v;
		return cur;
	}
	tree[cur].l = update(tree[idx].l, s, (s + e) / 2, k, v);
	tree[cur].r = update(tree[idx].r, (s + e) / 2 + 1, e, k, v);
	tree[cur].val = min(tree[tree[cur].l].val, tree[tree[cur].r].val);

	return cur;
}
int undo(int idx, int s, int e, int v) {
	if (s == e) return s;
	if (tree[tree[idx].r].val < v)
		return undo(tree[idx].r, (s + e) / 2 + 1, e, v);
	else return undo(tree[idx].l, s, (s + e) / 2, v);
}
int getAns(int idx, int s, int e) {
	if (s == e) return s;
	if (tree[tree[idx].r].val == 0)
		return getAns(tree[idx].r, (s + e) / 2 + 1, e);
	else return getAns(tree[idx].l, s, (s + e) / 2);
}
int arr[300001];
int main() {
	int n, x;
	scanf("%d", &n);
	init(0, n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] > 0) {
			root[i] = update(root[i - 1], 0, n, i, 0);
			printf("%d\n", arr[i]);
		}
		else {
			int ii = undo(root[i - 1], 0, n, -arr[i]);
			if (arr[ii] > 0) {
				root[i] = update(root[i - 1], 0, n, ii, INF);
				root[i] = update(root[i], 0, n, i, -arr[i]);
			}
			else {
				root[i] = update(root[ii - 1], 0, n, i, -arr[i]);
			}
			printf("%d\n", tree[root[i]].val != 0 ? 0 : arr[getAns(root[i], 0, n)]);
		}
	}

	return 0;
}