/*
BOJ 1188 - 음식 평론가
https://www.acmicpc.net/problem/1188

gcd만큼 칼질 횟수가 줄어듦.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int gcd(int a, int b) {
	if (a > b) swap(a, b);
	while (a > 0) {
		int tmp = a;
		a = b % a;
		b = tmp;
	}
	return b;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%d", m - gcd(n, m));

	return 0;
}