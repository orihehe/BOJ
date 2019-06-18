/*
BOJ 16283 - Farm
https://www.acmicpc.net/problem/16283
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int main() {
	int a, b, n, w, aa = -1, bb;
	scanf("%d %d %d %d", &a, &b, &n, &w);
	for (int i = 1; i < n; i++) {
		if (a*i + b * (n - i) == w) {
			if (aa != -1) return !printf("-1");
			aa = i, bb = n - i;
		}
	}
	if (aa == -1)printf("-1");
	else printf("%d %d", aa, bb);

	return 0;
}