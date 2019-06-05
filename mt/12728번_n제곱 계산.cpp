/*
BOJ 12728 (https://www.acmicpc.net/problem/12728)

pair로 3+sqrt(5)의 2^31 제곱 까지의 계수를 저장해둔다.
우리는 sqrt(5)를 곱해주는 연산을 할 수 없다. 실수부를 모두 표현할 수 없어 큰 수와 곱하면 정확한 값이 나오지 않기 때문.
따라서 sqrt(5)부분을 없애주어야 한다. 

(3+sqrt(5))^n + (3-sqrt(5))^n 를 해주게 되면 sqrt(5) 부분이 모두 사라지고 정수만 남게 된다.
(3+sqrt(5))^n와 (3-sqrt(5))^n의 정수 부분은 같으므로 2*((3+sqrt(5))^n의 정수부)
(3-sqrt(5))^n 는 0<x<1의 범위이다. 따라서 -1을 빼준 값 출력
*/
#include <cstdio>
#include <algorithm>
#define ll long long
#define pll pair<ll,ll>
#define mod 1000000000
using namespace std;

pll apb[32];
int main() {
	int t, n;
	scanf("%d", &t);

	apb[1] = { 3,1 };
	for (int i = 2; i < 32; i++) {
		apb[i].first = (apb[i - 1].first*apb[i - 1].first % mod
			+ apb[i - 1].second * apb[i - 1].second * 5 % mod) % mod;
		apb[i].second = 2 * apb[i - 1].first * apb[i - 1].second %mod;
	}

	for (int i = 1; i <= t; i++) {
		pll ans = { 0,0 };
		ll bin = 1;
		scanf("%d", &n);
		for (int i = 1; bin <= n; bin *= 2, i++) {
			if ((n | bin) == n) {
				if (ans.first == 0) {
					ans = apb[i];
				}
				else
					ans = { (apb[i].first * ans.first % mod
						+ apb[i].second * ans.second * 5 % mod) % mod,
						(apb[i].first * ans.second %mod
							+ apb[i].second * ans.first %mod) % mod };
			}
		}
		printf("Case #%d: %03lld\n", i, (ans.first * 2 + 999) % 1000);
	}

	return 0;
}