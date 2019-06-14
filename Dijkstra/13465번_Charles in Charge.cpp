/*
BOJ 13465 - Charles in Charge
https://www.acmicpc.net/problem/13465

이용한 도로의 길이 max가 작게 만들어야하니 이분탐색으로 길이를 선택하여
그 mid값 이하의 도로만 이용하여 다익스트라를 돌려준다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
#define pli pair<ll,int>
#define INF 10000000000000
using namespace std;

/* 🐣🐥 */
ll dist[10001];
priority_queue<pli, vector<pli>, greater<pli>> pq;
int n, mid;
vector<pli> vec[10001];
void dijk() {
	fill(dist, dist + n + 1, INF);
	dist[1] = 0;
	pq.push({ 0,1 });
	while (!pq.empty()) {
		pli cur = pq.top();
		pq.pop();
		if (cur.first > dist[cur.second]) continue;
		for (pli v : vec[cur.second]) {
			if (v.first > mid) continue;
			ll tmp = cur.first + v.first;
			if (tmp < dist[v.second]) {
				dist[v.second] = tmp;
				pq.push({ tmp,v.second });
			}
		}
	}
}
int main() {
	int m, x, l, r, a, b, c, ans;
	ll ori;
	scanf("%d %d %d", &n, &m, &x);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		vec[a].push_back({ c, b });
		vec[b].push_back({ c, a });
	}
	l = 1, r = 1000000000;
	mid = r;
	dijk();
	ori = dist[n];
	while (l <= r) {
		mid = (l + r) / 2;
		dijk();
		if (dist[n] * 100 <= ori * (100 + x)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	printf("%d", ans);

	return 0;
}