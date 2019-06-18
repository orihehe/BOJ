/*
BOJ 16282 - Black Chain
https://www.acmicpc.net/problem/16282
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int main() {
	long long n, cc;
	scanf("%lld", &n);
	for (int i = 1; i <= 54; i++) {
		cc = i;
		for (int j = 0; j <= i; j++) {
			cc += cc + 1;
			if (n <= cc) return !printf("%d", i);
		}
	}

	return 0;
}