/*
BOJ 17420 - 깊콘이 넘쳐흘러
https://www.acmicpc.net/problem/17420
*/
#include <cstdio>
#include <algorithm>
#define ll long long
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
pii arr[100001];
int main() {
	int n;
	ll ans = 0, mx = 0, tmp = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i].first);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i].second);
	sort(arr, arr + n, [](pii a, pii b) {
		if (a.second == b.second) return a.first < b.first;
		return a.second < b.second;
	});

	if (arr[0].first < arr[0].second) {
		ans += (arr[0].second - arr[0].first + 29) / 30;
		tmp = arr[0].first + ans * 30;
	}
	else tmp = arr[0].first;
	for (int i = 1; i < n; i++) {
		if (arr[i].second != arr[i - 1].second) {
			mx = tmp;
		}
		if (max((ll)arr[i].second, mx) > arr[i].first) {
			ll x = (max((ll)arr[i].second, mx) - arr[i].first + 29) / 30;
			ans += x;
			tmp = max(tmp, mx);
			tmp = max(tmp, arr[i].first + x * 30);
		}
		else {
			tmp = max(tmp, (ll)arr[i].first);
		}
	}
	printf("%lld", ans);

	return 0;
}