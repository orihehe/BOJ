/*
BOJ 2830 - 행성 X3
https://www.acmicpc.net/problem/2830

i자리의 비트의 개수를 저장해둔다.
i자리의 반대 비트 수 * 1<<i 의 합이 답이 된다.
*/
#include <cstdio>
#define ll long long
using namespace std;

/* 🐣🐥 */
int arr[2][21];
int main() {
	int n, x, tt;
	ll ans = 0;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		for (int i = 0; i < 20; i++) {
			tt = 1 << i;
			if (x&tt) {
				ans += 1LL * arr[0][i] * tt;
				arr[1][i]++;
			}
			else {
				ans += 1LL * arr[1][i] * tt;
				arr[0][i]++;
			}
		}
	}
	printf("%lld", ans);

	return 0;
}