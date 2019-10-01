/*
BOJ 17505 - 링고와 순열
https://www.acmicpc.net/problem/17505
*/
#include <cstdio>
#define ll long long
using namespace std;

/* 🐣🐥 */
int main() {
	int n, x, mx, mn;
	ll k;
	scanf("%d %lld", &n, &k);
	x = n - 1;
	mx = n, mn = 1;
	while (n--) {
		if (k >= x) {
			printf("%d ", mx--);
			k -= x;
		}
		else printf("%d ", mn++);
		x--;
	}

	return 0;
}