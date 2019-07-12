/*
BOJ 1305 - 광고
https://www.acmicpc.net/problem/1305
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
char st[1000001];
int fail[1000001];
int main() {
	int n, ans = 0;
	scanf("%d %s", &n, st);
	for (int i = 1, j = 0; i < n; i++) {
		while (j > 0 && st[i] != st[j]) j = fail[j - 1];
		if (st[i] == st[j]) {
			fail[i] = ++j;
		}
	}
	printf("%d", n - fail[n - 1]);

	return 0;
}