/*
BOJ 15459 - Haybale Feast
https://www.acmicpc.net/problem/15459
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#define ll long long
#define pll pair<ll,ll>
#define pli pair<ll,int>
using namespace std;

/* 🐣🐥 */
pll arr[100001];
priority_queue <pli> pq;
int main() {
	int n, ap = 0;
	ll m, ans = 1000000000000000001, sum = 0;
	scanf("%d %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &arr[i].first, &arr[i].second);
	}
	for (int i = 0; i < n; i++) {
		pq.push({ arr[i].second,i });
		sum += arr[i].first;
		while (ap < i && sum - arr[ap].first >= m)
			sum -= arr[ap++].first;
		if (sum < m) continue;
		while (pq.top().second < ap) pq.pop();
		ans = min(ans, pq.top().first);
	}
	printf("%lld", ans);

	return 0;
}