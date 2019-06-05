/*
BOJ 16309 - Financial Planning
https://www.acmicpc.net/problem/16309
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
#define pll pair<ll,ll>
using namespace std;

pll arr[100001];
int main() {
	int n;
	ll l, r, mid, m, ans;
	scanf("%d %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &arr[i].first, &arr[i].second);
	}
	l = 1, r = 4000000000;
	while (l <= r) {
		ll tmp = 0;
		mid = (l + r) / 2;
		for (int i = 0; i < n; i++) {
			tmp += max(1LL * 0, arr[i].first*mid - arr[i].second);
			if (tmp >= m) break;
		}
		if (tmp >= m) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	printf("%lld", ans);

	return 0;
}