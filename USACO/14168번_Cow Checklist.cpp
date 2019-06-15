/*
BOJ 14168 - Cow Checklist
https://www.acmicpc.net/problem/14168

dp[h,g중 마지막 선택][h][g]에서 -> h+1, g+1로의 작은 값 저장
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
#define pii pair<int,int>
#define INF 8000000000000
using namespace std;

/* 🐣🐥 */
ll dp[2][1001][1001];
pii H[1001], G[1001];
int h, g;
int dist(pii &a, pii &b) {
	int aa = a.first - b.first;
	int bb = a.second - b.second;
	return aa * aa + bb * bb;
}
ll go(int hc, int gc, int tr) {
	if (hc == h && gc == g) return 0;
	if (hc >= h || gc > g) return INF;
	if (dp[tr][hc][gc] != -1) return dp[tr][hc][gc];
	ll ret = INF;
	if (tr == 0) {
		ret = min(ret, go(hc + 1, gc, 0) + dist(H[hc], H[hc + 1]));
		ret = min(ret, go(hc, gc + 1, 1) + dist(H[hc], G[gc + 1]));
	}
	else {
		ret = min(ret, go(hc, gc + 1, 1) + dist(G[gc], G[gc + 1]));
		ret = min(ret, go(hc + 1, gc, 0) + dist(G[gc], H[hc + 1]));
	}
	return dp[tr][hc][gc] = ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &h, &g);
	for (int i = 1; i <= h; i++)
		scanf("%d %d", &H[i].first, &H[i].second);
	for (int i = 1; i <= g; i++)
		scanf("%d %d", &G[i].first, &G[i].second);
	printf("%lld", go(1, 0, 0));

	return 0;
}