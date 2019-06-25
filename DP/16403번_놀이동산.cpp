/*
BOJ 16403 - 놀이동산
https://www.acmicpc.net/problem/16403

연속한 사람들이 한 버스를 타는것이 비용이 적다.
또한 한 버스를 탄다면 중간 사람의 위치에서 타는것이 비용이 적다.
따라서 현재 사람을 택시태우거나, 40명까지의 사람들과 버스를 타는 것들중 최솟값을 저장해둔다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

/* 🐣🐥 */
int n, A, B, arr[10001];
ll dp[10001];
ll go(int cur) {
	if (cur == n) return 0;
	if (dp[cur] != -1) return dp[cur];
	int lm = min(40, n - cur), mid;
	ll ret = arr[cur] * A + go(cur + 1), tmp = 0;
	for (int i = 1; i <= lm; i++) {
		tmp = 0, mid = (2 * cur + i - 1) / 2;
		for (int k = cur; k < cur + i; k++)
			tmp += abs(arr[k] - arr[mid]);
		ret = min(ret, tmp*A + B + go(cur + i));
	}
	return dp[cur] = ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d %d", &n, &A, &B);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	printf("%lld", go(0));

	return 0;
}