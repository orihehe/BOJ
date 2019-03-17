/*
BOJ 1790 (https://www.acmicpc.net/problem/1790)

k번째 자리 숫자가 어느 수에 들어있는지 그 수를 찾는다.
*/
#include <cstdio>
#define ll long long
using namespace std;

int main() {
	ll x = 9, n, k, s = 1, sum = 0, tmp = 1, op = 0;
	char ori[10];
	scanf("%lld %lld", &n, &k);
	while (sum + x*s < k) {
		sum += x * s;
		x *= 10; // 자릿수별 숫자 개수
		s++;  // 자릿수
	}
	k -= sum; // s자릿수 이전에 나온 숫자 개수 빼줌

	for (int i = 2; i <= s; i++) 
		tmp *= 10;
	tmp += (k-1) / s; // 이 수에서 나온거
	if (tmp > n) printf("-1");
	else {
		ll mn = 100000000;
		while (mn > tmp) mn /= 10;
		while (mn > 0) {
			ori[op++] = tmp / mn + '0';
			tmp %= mn;
			mn /= 10;
		}
		printf("%c", ori[(k - 1) % s]);
	}

	return 0;
}