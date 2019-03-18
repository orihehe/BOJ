/*
BOJ 9938 - 방 청소
https://www.acmicpc.net/problem/9938

공간을 공유하는 애들 끼리는 공간 크기만 넉넉하다면 잘 정리하면 그 공간만큼 넣을 수 있다.
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int p[300001];
int sz[300001];
int getr(int a) {
	if (p[a] == a) return a;
	return p[a] = getr(p[a]);
}
void merge(int a, int b) {
	a = getr(a);
	b = getr(b);
	if (a == b) return;
	p[a] = b;
	sz[b] += sz[a];
}
int main() {
	int n, m, a, b, ans = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		p[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		merge(a, b);
		if (sz[getr(a)] == 0) printf("SMECE\n");
		else {
			sz[getr(a)]--;
			printf("LADICA\n");
		}
	}

	return 0;
}