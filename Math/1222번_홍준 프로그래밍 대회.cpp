/*
BOJ 1222 - 홍준 프로그래밍 대회
https://www.acmicpc.net/problem/1222
*/
#include <cstdio>
#include <algorithm>
#define MAX 2000001
using namespace std;

/* 🐣🐥 */
int arr[MAX];
int main() {
	int n, x;
	long long ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		arr[x]++;
	}
	for (int i = 1; i < MAX; i++) {
		int cur = 0;
		for (int j = i; j < MAX; j += i)
			cur += arr[j];
		if (cur >= 2) ans = max(ans, 1LL * cur*i);
	}
	printf("%lld", ans);

	return 0;
}