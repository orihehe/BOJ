/*
BOJ 15009 - Going Dutch
https://www.acmicpc.net/problem/15009

간선은 트리형태로 나오고, 만약 간선이 n-2개 있다면 컴포넌트가 두 개가 있다는 뜻
따라서 간선을 가장 적게하려면 컴포넌트를 많이 만들면 된다.

dp[켜진 비트에서 컴포넌트 수 최댓값]으로 두고 
현재 켜진 비트 S에 속한 원소 하나씩을 제외한 집합의 최댓값을 구한다.
그 최댓값에 현재 S의 원소끼리 갚고 받았을 때 더이상 받을것, 갚을것이 안 남았을 때 +1한 값을 리턴
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

/* 🐣🐥 */
int in[20], out[20], dp[1048576], n;
int go(int cur) {
	if (cur == 0) return 0;
	if (dp[cur] != -1) return dp[cur];
	int ret = 0, oo = 0, ii = 0;
	for (int i = 0; i < n; i++) {
		int tt = 1 << i;
		if (tt & cur) {
			oo += out[i], ii += in[i];
			ret = max(ret, go(cur^tt));
		}
	}
	return dp[cur] = ret + (oo == ii);
}
int main() {
	memset(dp, -1, sizeof(dp));
	int m, a, b, c;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		out[b] += c;
		in[a] += c;
	}
	printf("%d", n - go((int)pow(2, n) - 1));

	return 0;
}