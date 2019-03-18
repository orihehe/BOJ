/*
BOJ 15750 - Teleportation
https://www.acmicpc.net/problem/15750

a->b로 바로가는 것이 a->0->y->b 보다 이득일땐 보지않고,
나머지는 각 경우별로 이득이 되는 구간을 계산해준다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
#define pii pair<int,int>
#define MAX 987654321987654321
using namespace std;

/* 🐣🐥 */
priority_queue<pii,vector<pii>,greater<pii>> pq;
int main() {
	int n, a, b, lloc, cur;
	ll ans = MAX, mn = 0, sum=0, cv = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		sum += abs(b - a);
		if (abs(a) > abs(a-b)) continue;
		pq.push({ b,2 });
		if (a < b) {
			if (a <= 0) {
				pq.push({ 0,-1 });
				pq.push({ 2 * b,-1 });
			}
			else {
				pq.push({ 2*a,-1 });
				pq.push({ 2 * b-2*a,-1 });
			}
		}
		else {
			if (a <= 0) {
				pq.push({ 2 * a,-1 });
				pq.push({ 2 * b - 2 * a,-1 });
			}
			else {
				pq.push({ 0,-1 });
				pq.push({ 2 * b,-1 });
			}
		}
	}
	if(!pq.empty()) lloc = pq.top().first;
	while (!pq.empty()) {
		cur = pq.top().first;
		mn += (cur - lloc)*cv;
		ans = min(ans, mn);
		lloc = cur;
		while (!pq.empty() && pq.top().first == cur) {
			cv += pq.top().second;
			pq.pop();
		}
	}
	if (ans < 0) sum += ans;
	printf("%lld", sum);

	return 0;
}