/*
BOJ 4198 - 열차정렬
https://www.acmicpc.net/problem/4198

i를 기준으로 하는 가장 긴 증가/감소 수열을 구해준다.
*/
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

/* 🐣🐥 */
int arr[2001], dp[2001], fr[2001];
int main() {
	int n, ap, ans = 0;
	scanf("%d", &n);
	if (n == 0) return !printf("0");
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++) {
		ap = 0;
		dp[ap++] = arr[i];
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[i]) continue;
			int idx = lower_bound(dp, dp + ap, arr[j]) - dp;
			dp[idx] = arr[j];
			if (idx == ap) ap++;
		}
		fr[i] = ap;
	}
	for (int i = 0; i < n; i++) {
		ap = 0;
		dp[ap++] = arr[i];
		for (int j = i + 1; j < n; j++) {
			if (arr[j] > arr[i]) continue;
			int idx = lower_bound(dp, dp + ap, arr[j], greater<int>()) - dp;
			dp[idx] = arr[j];
			if (idx == ap) ap++;
		}
		ans = max(ans, fr[i] + ap);
	}
	printf("%d", ans - 1);

	return 0;
}