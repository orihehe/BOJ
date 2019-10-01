/*
BOJ 17497 - 계산기
https://www.acmicpc.net/problem/17497
*/
#include <cstdio>
#define ll long long
using namespace std;

/* 🐣🐥 */
char ans[100];
int main() {
	ll n;
	int ap = 0;
	scanf("%lld", &n);
	if (n % 2) {
		ans[ap++] = '/';
		n *= 2;
	}
	while (n > 2) {
		if ((n / 2) % 2) {
			ans[ap++] = '+';
			n -= 2;
		}
		else {
			ans[ap++] = '*';
			n /= 2;
		}
	}
	printf("%d\n[+] ", ap + 1);
	for (int i = ap - 1; i >= 0; i--) printf("[%c] ", ans[i]);

	return 0;
}