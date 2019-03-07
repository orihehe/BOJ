/*
BOJ 11969 - Breed Counting
https://www.acmicpc.net/problem/11969

세그로 풀었지만 부분합으로 가능하다.
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
struct info {
	int a, b, c;
};
info tree[262145];
info p(info tt, info xx) {
	return { tt.a + xx.a, tt.b + xx.b , tt.c + xx.c };
}
void update(int idx, int s, int e, int k, int x) {
	if (k<s || k>e) return;
	if (x == 1) tree[idx].a++;
	else if (x == 2) tree[idx].b++;
	else if (x == 3) tree[idx].c++;
	if (s == e) return;
	update(idx * 2, s, (s + e) / 2, k, x);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, k, x);
}
info hap(int idx, int s, int e, int l, int r) {
	if (e < l || s > r) return { 0,0,0 };
	if (l <= s && e <= r) return tree[idx];
	return p(hap(idx * 2, s, (s + e) / 2, l, r), hap(idx * 2 + 1, (s + e) / 2 + 1, e, l, r));
}
int main() {
	int n, q, x, ss, ee;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		update(1, 1, n, i, x);
	}
	while (q--) {
		scanf("%d %d", &ss, &ee);
		info ans = hap(1, 1, n, ss, ee);
		printf("%d %d %d\n", ans.a, ans.b, ans.c);
	}

	return 0;
}