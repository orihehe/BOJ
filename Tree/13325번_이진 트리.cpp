/*
BOJ 13325 - 이진 트리
https://www.acmicpc.net/problem/13325

루트에서부터 형제노드와 비교하여 큰 값와의 차이만큼 더해준다.
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int tree[2097158], sz;
int ans = 0;
int dfs(int cur) {
	if (cur * 2 + 1 > sz) return 0;
	int r, l;
	l = dfs(cur * 2) + tree[cur * 2], r = dfs(cur * 2 + 1) + tree[cur * 2 + 1];
	if (r < l) tree[cur * 2] += l - r;
	else tree[cur * 2] += r - l;
	ans += tree[cur * 2] + tree[cur * 2 + 1];
	return max(r, l);
}
int main() {
	int n;
	scanf("%d", &n);
	sz = pow(2, n + 1) - 1;
	for (int i = 2; i <= sz; i++) {
		scanf("%d", &tree[i]);
	}
	dfs(1);
	printf("%d", ans);

	return 0;
}