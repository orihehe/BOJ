/*
BOJ 17038 - The Great Revegetation (Silver)
https://www.acmicpc.net/problem/17038

모순이 있는지 확인, 없다면 연관된 팀 수(n) 라면 2^n이다.
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int p[100001], pp[200001];
int n, m, a, b, x = 0;
int find(int a, int op[]) {
	if (a == op[a]) return a;
	return op[a] = find(op[a], op);
}
void merge(int a, int b, int op[]) {
	a = find(a, op);
	b = find(b, op);
	op[a] = b;
}
bool isV() {
	for (int i = 1; i <= n; i++) {
		if (find(i, pp) == find(i + n, pp)) return false;
	}
	return true;
}
int main() {
	char st;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1; i <= 2 * n; i++) pp[i] = i;
	for (int i = 0; i < m; i++) {
		scanf(" %c %d %d", &st, &a, &b);
		merge(a, b, p);
		if (st == 'S') {
			merge(a, b, pp);
			merge(a + n, b + n, pp);
		}
		else {
			merge(a + n, b, pp);
			merge(a, b + n, pp);
		}
	}
	if (!isV()) return !printf("0");
	for (int i = 1; i <= n; i++) {
		if (find(i, p) == i) x++;
	}
	printf("1");
	while (x--) printf("0");

	return 0;
}