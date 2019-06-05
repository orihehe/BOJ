/*
BOJ 15897 - 잘못 구현한 에라토스테네스의 체
https://www.acmicpc.net/problem/15897

sqrt(n)까지 n/i를 계산해둔다.
그렇게되면 (hf[i] - hf[i + 1])개만큼 i가 뒤에 등장한다.
*/
#include <cstdio>
#define ll long long
using namespace std;

/* 🐣🐥 */
ll ans, hf[32000];
int main() {
	int n, mx;
	scanf("%d", &n);
	if (n == 1) return !printf("1");
	ans = n--;
	for (int i = 1; i*i <= n; i++) {
		hf[i] = n / i;
		mx = i;
		ans += hf[i];
	}
	for (int i = mx + 1;; i++) { // 계산되지 않은 애들 
		if (n / i != mx) break;
		ans += mx;
	}
	for (int i = 1; i < mx; i++)
		ans += (hf[i] - hf[i + 1])*i;
	printf("%lld", ans);

	return 0;
}