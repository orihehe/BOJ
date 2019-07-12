/*
BOJ 11585 - 속타는 저녁 메뉴
https://www.acmicpc.net/problem/11585

룰렛 문자열을 뒤에 한번 이어 붙여준다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
char st[2000001], w[1000001];
int fail[1000001];
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
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf(" %c", &st[i]);
	for (int i = n; i < 2 * n - 1; i++) st[i] = st[i - n];
	for (int i = 0; i < n; i++) scanf(" %c", &w[i]);
	for (int i = 1, j = 0; i < n; i++) {
		while (j > 0 && w[i] != w[j]) j = fail[j - 1];
		if (w[i] == w[j]) fail[i] = ++j;
	}
	for (int i = 0, j = 0; i < 2 * n - 1; i++) {
		while (j > 0 && st[i] != w[j]) j = fail[j - 1];
		if (st[i] == w[j]) {
			if (j == n - 1) {
				j = fail[j];
				ans++;
			}
			else j++;
		}
	}
	int m = gcd(ans, n);
	printf("%d/%d", ans / m, n / m);

	return 0;
}