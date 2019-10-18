/*
BOJ 17408 - 수열과 쿼리 24
https://www.acmicpc.net/problem/17408
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

/* 🐣🐥 */
int tree[262144][2];
vector<int> vec;
void update(int idx, int s, int e, int k, int val) {
	if (k<s || k>e) return;
	if (s == e) {
		tree[idx][0] = val;
		return;
	}
	update(idx * 2, s, (s + e) / 2, k, val);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, k, val);
	tree[idx][0] = max(tree[idx * 2][0], tree[idx * 2 + 1][0]);
	bool tmp = tree[idx * 2][0] > tree[idx * 2 + 1][0];
	tree[idx][1] = max(tree[idx * 2][tmp], tree[idx * 2 + 1][!tmp]);
}
void find(int idx, int s, int e, int l, int r) {
	if (e<l || s>r) return;
	if (l <= s && e <= r) {
		vec.push_back(tree[idx][0]);
		vec.push_back(tree[idx][1]);
		return;
	}
	find(idx * 2, s, (s + e) / 2, l, r);
	find(idx * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
int main() {
	int n, q, cm, a, b;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &q);
		update(1, 1, n, i, q);
	}
	scanf("%d", &q);
	while (q--) {
		scanf(" %d%d %d", &cm, &a, &b);
		if (cm == 1)
			update(1, 1, n, a, b);
		else {
			vec.clear();
			find(1, 1, n, a, b);
			sort(vec.begin(), vec.end(), greater<int>());
			printf("%d\n", vec[0] + vec[1]);
		}
	}

	return 0;
}