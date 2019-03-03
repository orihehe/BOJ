/*
BOJ 14427 - 수열과 쿼리 15
https://www.acmicpc.net/problem/14427

트리를 pair로 만들어 앞에는 값, 뒤는 인덱스로 관리
자식들 중 최솟값을 저장해준다.
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#define pii pair<int,int>
#define MAX 1000000001
using namespace std;

/* 🐣🐥 */
pii arr[1000001], *tree;
pii init(int idx, int l, int r) {
	if (l == r) return tree[idx] = arr[l];
	return tree[idx] = min(init(idx * 2, l, (l + r) / 2)
		, init(idx * 2 + 1, (l + r) / 2 + 1, r));
}
void renum(int idx, int s, int e, int k, int val) {
	if (k > e || k < s) return;
	if (s == e) {
		tree[idx].first += val;
		arr[k].first += val;
		return;
	}
	renum(idx * 2, s, (s + e) / 2, k, val);
	renum(idx * 2 + 1, (s + e) / 2 + 1, e, k, val);
	tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
}
int main() {
	int n, m, h, cm, b, c;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i].first);
		arr[i].second = i;
	}
	h = ceil(log2(n));
	tree = new pii[1 << (h + 1)];
	init(1, 1, n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &cm);
		if (cm == 2) {
			printf("%d\n", tree[1].second);
		}
		else if (cm == 1) {
			scanf("%d %d", &b, &c);
			renum(1, 1, n, b, c - arr[b].first);
		}
	}

	return 0;
}