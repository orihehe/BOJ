/*
BOJ 17301 - NC 문자열
https://www.acmicpc.net/problem/17301

NC가 만들어지지 않는 문자열 개수를 구해 전체 경우에서 빼준다.
*/
#include <cstdio>
#include <cstring>
#define mod 1000000007
using namespace std;

/* 🐣🐥 */
int arr[4]; // n, c, nc, cn
char st[11];
int main() {
	int n, ans = 0, ori = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", st);
		int len = strlen(st);
		int nn = 0, cc = 0;
		bool suc = false;
		for (int j = 0; j < len; j++) {
			if (st[j] == 'N') {
				nn++;
				if (cc) {
					suc = true;
				}
			}
			else if (st[j] == 'C') {
				cc++;
				if (nn) {
					arr[2]++;
					suc = false;
					break;
				}
			}
		}
		if (suc) arr[3]++;
		if (nn && !cc) arr[0]++;
		if (cc && !nn) arr[1]++;
	}
	int cur = 1;
	for (int i = n; i >= 1; i--) {
		cur = 1LL * cur * i % mod;
		ori = (ori + cur) % mod;
	}
	cur = 1;
	int fr = 1, ba = 1;
	for (int i = arr[0]; i >= 1; i--) {
		cur = 1LL * cur * i % mod;
		fr = (fr + cur) % mod;
	}
	cur = 1;
	for (int i = arr[1]; i >= 1; i--) {
		cur = 1LL * cur * i % mod;
		ba = (ba + cur) % mod;
	}
	printf("%lld", (ori - (1LL * fr*ba%mod*(arr[3] + 1) - 1 + mod) % mod + mod) % mod);

	return 0;
}