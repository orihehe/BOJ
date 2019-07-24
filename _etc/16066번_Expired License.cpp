/*
BOJ 16066 - Expired License
https://www.acmicpc.net/problem/16066
*/
#include <cstdio>
#include <algorithm>
#define MAX 10000000
using namespace std;

/* 🐣🐥 */
bool sosu[MAX + 1];
int gcd(int a, int b) {
	if (a > b) swap(a, b);
	while (a > 0) {
		int tmp = b;
		b = a;
		a = tmp % a;
	}
	return b;
}
int main() {
	for (int i = 2; i <= MAX; i++) {
		if (sosu[i]) continue;
		for (int j = 2; j*i <= MAX; j++) {
			sosu[j*i] = true;
		}
	}
	sosu[1] = sosu[0] = true;
	int n, aa, bb;
	long double a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%Lf %Lf", &a, &b);
		a += 1e-9;
		b += 1e-9;
		aa = a * 100000;
		bb = b * 100000;
		int gc = gcd(aa, bb);
		if (gc == aa && gc == bb) {
			printf("%d %d\n", 2, 2);
			continue;
		}
		aa /= gc, bb /= gc;
		if (!sosu[aa] && !sosu[bb]) {
			printf("%d %d\n", aa, bb);
		}
		else printf("impossible\n");
	}

	return 0;
}