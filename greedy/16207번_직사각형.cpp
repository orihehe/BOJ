/*
BOJ 16207 - 직사각형
https://www.acmicpc.net/problem/16207
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

/* 🐣🐥 */
int rm[100001], arr[100001], x, i;
ll ans;
int main() {
	int n;
	scanf("%d", &n);
	for (int j = 0; j < n; j++) {
		scanf("%d", &x);
		arr[x]++;
		i = max(i, x);
	}
	for (int j = 100000; j >= 2; j--) {
		if (arr[j] && (arr[j]+rm[j]) % 2) {
			rm[j - 1]++;
			arr[j]--;
		}
	}
	while (i >= 2 && !arr[i]) i--;
	while(true) {
		int cur = i;
		while (i>=2 && !arr[--i]){}
		if (rm[cur] && rm[cur] + arr[cur] >= 4) {
			arr[cur] -= 4-rm[cur];
			rm[cur] = 0;
			ans += 1LL * cur*cur;
		}
		while (arr[cur] >= 4) {
			arr[cur] -= 4;
			ans += 1LL * cur*cur;
		}
		if (i == 1) break;
		if (arr[cur]+rm[cur] >= 2 && arr[i]+rm[i] >= 2) {
			ans += 1LL * cur*i;
			arr[cur] = 0, rm[cur] = 0, arr[i] -= 2-rm[i], rm[i] = 0;
		}
		rm[cur - 1] += arr[cur];
	}
	printf("%lld", ans);

	return 0;
}