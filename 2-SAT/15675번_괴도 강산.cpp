/*
BOJ 15675 - 괴도 강산
https://www.acmicpc.net/problem/15675

위치추적기의 행, 열은 둘 다 사용되거나, 둘 다 사용되지 않아야 한다.
보석의 행, 열은 둘 중 하나만 꼭 사용되어야 한다.
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
bool visited[1001][1001];
char arr[1002][1003];
int n, m, p[400001], op;
int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	p[a] = b;
}
bool isValid() {
	for (int i = 1; i <= n + m; i++) {
		if (find(i) == find(i + op)) return false;
	}
	return true;
}
int main() {
	scanf("%d %d", &n, &m);
	op = n + m;
	for (int i = 1; i <= n; i++) {
		scanf("%s", arr[i] + 1);
	}
	for (int i = 1; i <= 2 * op; i++) p[i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == '*') {
				merge(i, j + n + op);
				merge(j + n, i + op);
			}
			else if (arr[i][j] == '#') {
				merge(i, j + n);
				merge(i + op, j + n + op);
			}
		}
	}
	printf("%d\n", isValid() ? 1 : 0);

	return 0;
}