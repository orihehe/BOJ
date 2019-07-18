/*
BOJ 8986 - 전봇대
https://www.acmicpc.net/problem/8986
*/
#include <cstdio>
#include <cmath>
#define ll long long
using namespace std;

/* 🐣🐥 */
int arr[100001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	ll l = 0, r = 1000000000, mid, ans = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		ll fr = 0, ba = 0, loc = 0;
		for (int i = 0; i < n; i++) {
			fr += llabs(arr[i] - loc);
			loc += mid;
		}
		loc = 0;
		for (int i = 0; i < n; i++) {
			ba += llabs(arr[i] - loc);
			loc += mid + 1;
		}
		if (fr <= ba) {
			ans = fr;
			r = mid - 1;
		}
		else {
			ans = ba;
			l = mid + 1;
		}
	}
	printf("%lld", ans);

	return 0;
}