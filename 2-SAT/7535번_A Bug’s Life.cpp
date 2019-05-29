/*
BOJ 7535 - A Bug’s Life
https://www.acmicpc.net/problem/7535

주어진 쌍에서 두 벌레의 성별은 무조건 달라야 하므로 enemy merge를 해준다.
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int p[4001], n;
int find(int a) {
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	p[a] = b;
}
bool isValid() {
	for (int i = 1; i <= n; i++) {
		if (find(i) == find(i + n)) return true;
	}
	return false;
}
int main() {
	int t, m, a, b;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= 2 * n; i++) p[i] = i;
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			merge(a, b + n);
			merge(b, a + n);
		}
		printf("Scenario #%d:\n%s\n\n", tt, isValid() ? "Suspicious bugs found!" : "No suspicious bugs found!");
	}

	return 0;
}