/*
BOJ 14438 - 수열과 쿼리 17
https://www.acmicpc.net/problem/14438

두 자식 노드중 작은 값을 현재 노드에 저장
minV에서 구간의 최솟값을 구한다.
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAX 1000000001
using namespace std;

/* 🐣🐥 */
int arr[1000001], *tree;
int init(int idx, int l, int r) {
	if (l == r) return tree[idx] = arr[l];
	return tree[idx] = min(init(idx * 2, l, (l + r) / 2)
		, init(idx * 2 + 1, (l + r) / 2 + 1, r));
}
void renum(int idx, int s, int e, int k, int val) {
	if (k > e || k < s) return;
	if (s == e) {
		tree[idx] += val;
		arr[k] += val;
		return;
	}
	renum(idx * 2, s, (s + e) / 2, k, val);
	renum(idx * 2 + 1, (s + e) / 2 + 1, e, k, val);
	tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
}
int minV(int idx, int s, int e, int l, int r) {
	if (l > e || r < s) return MAX;
	if (l <= s && r >= e) return tree[idx];
	return min(minV(idx * 2, s, (s + e) / 2, l, r),
		minV(idx * 2 + 1, (s + e) / 2 + 1, e, l, r));
}
int main() {
	int n, m, h, cm, b, c;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	h = ceil(log2(n));
	tree = new int[1 << (h + 1)];
	init(1, 1, n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &cm, &b, &c);
		if (cm == 2) {
			printf("%d\n", minV(1, 1, n, b, c));
		}
		else if (cm == 1) {
			renum(1, 1, n, b, c - arr[b]);
		}
	}

	return 0;
}