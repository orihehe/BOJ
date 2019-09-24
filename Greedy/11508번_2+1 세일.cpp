/*
BOJ 11508 - 2+1 세일
https://www.acmicpc.net/problem/11508
*/
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

/* 🐣🐥 */
int arr[100001];
int main() {
	int n;
	long long ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		ans += arr[i];
	}
	sort(arr, arr + n, greater<int>());
	for (int i = 2; i < n; i += 3)
		ans -= arr[i];
	printf("%lld", ans);

	return 0;
}