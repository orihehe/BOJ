/*
BOJ 16564 - 히오스 프로게이머
https://www.acmicpc.net/problem/16564

팀 목표레벨을 mid로 설정 후 도달 가능 여부를 판단, 이분탐색
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

/* 🐣🐥 */
int arr[1000000];
int main() {
	int n, l, r, ans;
	ll sum, k;
	scanf("%d %lld", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	l = 1, r = 1000000000;
	while (l <= r) {
		int mid = (l + r) / 2;
		sum = 0;
		for (int i = 0; i < n; i++) {
			sum += max(0, mid - arr[i]);
		}
		if (sum <= k) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	printf("%d", ans);

	return 0;
}