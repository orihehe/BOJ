/*
BOJ 2166 - 다각형의 면적
https://www.acmicpc.net/problem/2166
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define ll long long
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
ll cr(int x1, int y1, int x2, int y2) {
	return 1LL * x1 * y2 - 1LL * y1 * x2;
}
pii arr[10001];
int main() {
	int n, a, b;
	ll ans = 0;
	scanf("%d", &n);
	scanf("%d %d", &a, &b);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}
	for (int i = 1; i < n - 1; i++) {
		ans += cr(arr[i].first - a, arr[i].second - b,
			arr[i + 1].first - a, arr[i + 1].second - b);
	}
	ans = llabs(ans);
	if (ans % 2)
		printf("%lld.5", ans / 2);
	else
		printf("%lld.0", ans / 2);

	return 0;
}