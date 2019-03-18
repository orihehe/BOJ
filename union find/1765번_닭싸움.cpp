/*
BOJ 1765 - 닭싸움 팀 정하기
https://www.acmicpc.net/problem/1765

적 배열을 따로 만들어준다.
내 원수의 원수도 내 친구이니 원수의 원수들 끼리는 팀이된다.
따라서 merge후 한 원수만 저장해두면 된다.
*/
#include <cstdio>
#include <cstring>
using namespace std;

/* 🐣🐥 */
int p[1001];
int e[1001];
int getr(int a) {
	if (p[a] == a) return a;
	return p[a] = getr(p[a]);
}
void merge(int a, int b) {
	a = getr(a);
	b = getr(b);
	p[b] = a;
}
int main() {
	int n, m, a, b, ans = 0;
	char s;
	scanf("%d %d", &n, &m);
	memset(e, -1, sizeof(e));
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 0; i < m; i++) {
		scanf(" %c %d %d", &s, &a, &b);
		if (s == 'E') {
			if (e[a] != -1)
				merge(e[a], b);
			if (e[b] != -1)
				merge(e[b], a);
			e[a] = b;
			e[b] = a;
		}
		else if (s == 'F') {
			merge(a, b);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (getr(i) == i) ans++;
	}
	printf("%d", ans);

	return 0;
}