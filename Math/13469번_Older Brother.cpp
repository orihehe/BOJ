/*
BOJ 13469 - Older Brother
https://www.acmicpc.net/problem/13469

sqrt(q)까지의 소수들만 봐준다.
*/
#include <cstdio>
#define ll long long
using namespace std;

/* 🐣🐥 */
bool sosu[32001];
bool prime(int n) {
	if (n == 1) return false;
	bool ret = true;
	for (int i = 2; i*i <= n; i++) {
		if (!sosu[i] && n%i == 0) {
			ll tmp = 1;
			ret = false;
			while (n >= tmp) {
				if (n == tmp) return true;
				tmp *= i;
			}
		}
	}
	return ret;
}
int main() {
	sosu[1] = true;
	for (int i = 2; i <= 32000; i++) {
		if (sosu[i]) continue;
		for (int j = 2; j*i <= 32000; j++) {
			sosu[j*i] = true;
		}
	}
	int q;
	scanf("%d", &q);
	if (prime(q)) printf("yes");
	else printf("no");

	return 0;
}