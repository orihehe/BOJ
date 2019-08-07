/*
BOJ 17384 - 대진표
https://www.acmicpc.net/problem/17384
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
void prt(int num, int k) {
	if (k == 1) {
		printf("%c", num ? '#' : '.');
		return;
	}
	if (num <= k / 2) {
		prt(num, k / 2);
		prt(0, k / 2);
	}
	else if (num >= k / 2 + k / 4) {
		prt(k / 2, k / 2);
		prt(num - k / 2, k / 2);
	}
	else {
		prt(num - k / 4, k / 2);
		prt(k / 4, k / 2);
	}
}
int main() {
	int n, k = 1;
	scanf("%d", &n);
	while (k < n) k *= 2;
	prt(n, k);

	return 0;
}