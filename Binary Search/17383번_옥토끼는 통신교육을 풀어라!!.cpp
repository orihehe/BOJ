/*
BOJ 17383 - 옥토끼는 통신교육을 풀어라!!
https://www.acmicpc.net/problem/17383
*/
#include <cstdio>
#include <algorithm>
#include <functional>
#define ll long long
using namespace std;

/* 🐣🐥 */
int arr[100001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n, greater<int>());
	ll l = 1, r = 1000000000, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if ((arr[0] + mid - 1) / mid > n) {
			l = mid + 1;
			continue;
		}
		int cnt = (arr[0] + mid - 1) / mid, idx = 1;
		for (int i = 1; i < n; i++) {
			cnt += arr[i] / mid - (arr[i] % mid == 0);
			if (cnt > n) break;
			idx = i + 1;
		}
		if (arr[idx] > mid) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
			ans = mid;
		}
	}
	printf("%lld", ans);

	return 0;
}