/*
BOJ 11414 - LCM
https://www.acmicpc.net/problem/11414

유클리드 호제법의 증명에서 gcd(a,b) = gcd(a,a-b) 임을 알 수 있다.
따라서 gcd(a+k,b+k) = gcd(a+k,a-b) -> 최솟값이 나올 후보는 a-b의 약수들이다.
a를 a-b의 약수들의 배수로 만들어 k값을 구해 gcd가 가장 작은 k를 구한다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

/* 🐣🐥 */
vector<int> vec;
ll gcd(ll x, ll y) {
	ll tmp;
	if (y > x) swap(x, y);
	while (y > 0) {
		tmp = x;
		x = y;
		y = tmp % y;
	}
	return x;
}
void prime(ll cur) {
	for (ll i = 1; i*i <= cur; i++) {
		if (cur%i == 0) {
			vec.push_back((int)i);
			vec.push_back((int)cur / i);
		}
	}
}
int main() {
	ll a, b, x, tmp, cur = 987564321987654321;
	int k, tk;
	scanf("%lld %lld", &a, &b);
	if (b > a) swap(a, b);
	x = a - b;
	k = x;
	if (a == b) k = 1;
	prime(x);
	for (int v : vec) {
		if (a%v) 
			tk = v - (int)a % v;
		else continue;
		tmp = (a + tk)*(b + tk) / v;
		if (tmp < cur) {
			cur = tmp;
			k = tk;
		}
		else if (tmp == cur) {
			k = min(k, tk);
		}
	}

	printf("%d", k);

	return 0;
}