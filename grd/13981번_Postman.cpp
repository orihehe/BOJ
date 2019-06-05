/*
BOJ 13981 - Postman
https://www.acmicpc.net/problem/13981

우체국으로부터 먼 곳부터 먼저 편지를 배달하는 것이 최선이다
*/
#include <cstdio>
#include <algorithm>
#define ll long long
#define pll pair<ll,ll>
using namespace std;

/* 🐣🐥 */
pll arr[1001];
int main() {
	ll n, k, p = -1, rm, ip;
	ll dist = 0;
	scanf("%lld %lld", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &arr[i].first, &arr[i].second);
	}
	sort(arr, arr + n);
	for (ll i = 0; i < n; i++) {
		if (arr[i].first < 0) p = i; // p까지음수
		else break;
	}
	for (ll i = 0; i <= p; i++) {
		dist += (-arr[i].first) * ((arr[i].second + k - 1) / k) * 2;

		rm = (k - arr[i].second%k) % k;
		ip = i + 1;
		while (ip <= p && rm>0) {
			if (rm >= arr[ip].second) {
				rm -= arr[ip].second;
				arr[ip++].second = 0;
			}
			else {
				arr[ip].second -= rm;
				rm = 0;
			}
		}
		i = ip - 1;
	}
	for (ll i = n - 1; i > p; i--) {
		dist += arr[i].first * ((arr[i].second + k - 1) / k) * 2;
		rm = (k - arr[i].second%k) % k;
		ip = i - 1;
		while (ip > p && rm>0) {
			if (rm >= arr[ip].second) {
				rm -= arr[ip].second;
				arr[ip--].second = 0;
			}
			else {
				arr[ip].second -= rm;
				rm = 0;
			}
		}
		i = ip + 1;
	}
	printf("%lld", dist);

	return 0;
}