/*
BOJ 9517 - 아이 러브 크로아티아
https://www.acmicpc.net/problem/9517
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int main() {
	int k, n, t, x = 210;
	char c;
	scanf("%d %d", &k, &n);
	while (n--) {
		scanf("%d %c", &t, &c);
		x -= t;
		if (x <= 0) return !printf("%d", k);
		if (c == 'T') k++;
		if (k == 9) k = 1;
	}

	return 0;
}