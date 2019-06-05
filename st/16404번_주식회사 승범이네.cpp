/*
BOJ 16404 (https://www.acmicpc.net/problem/16404)

dfs로 인덱스를 다시 주어 현재 노드의 자식노드들을 구간을 줄 수 있게 만들어준다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

/* 🐣🐥 */
int *tree;
int child[100001];
int ix[100001], cnt;
vector<int> vec[100001];
int dfs(int cur) {
	ix[cur] = ++cnt;  // cur의 인덱스 시작
	for (int v : vec[cur]) {
		dfs(v);
	}
	return child[cur] = cnt; // cur의 자식노드 마지막 인덱스
}
void update(int idx, int s, int e, int l, int r, int val) {
	if (r < s || l > e) return;
	if (l <= s && e <= r) {
		tree[idx] += val;
		return;
	}
	update(idx * 2, s, (e + s) / 2, l, r, val);
	update(idx * 2 + 1, (e + s) / 2 + 1, e, l, r, val);
}
int money(int idx, int s, int e, int k, int sum) {
	if (k > e || k < s) return 0;
	int tmp = sum + tree[idx];
	if (e==s) {
		return tmp;
	}
	return money(idx * 2, s, (e + s) / 2, k, tmp)
		+ money(idx * 2 + 1, (e + s) / 2 + 1, e, k, tmp);
}
int main() {
	int n, m, h, x, p, cm;
	scanf("%d %d", &n, &m);
	h = ceil(log2(n)) + 1;
	tree = new int[1 << h];
	fill(tree, tree + (1 << h), 0);
	scanf("%d", &p);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &p);
		vec[p].push_back(i);
	}
	dfs(1);
	for (int i = 0; i < m; i++) {
		scanf("%d", &cm);
		if (cm == 1) {
			scanf("%d %d", &x, &p);
			if (child[x]) {
				update(1, 1, n, ix[x], child[x], p);
			}
		}
		else if (cm == 2) {
			scanf("%d", &x);
			printf("%d\n", money(1, 1, n, ix[x], 0));
		}
	}

	return 0;
}