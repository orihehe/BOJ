/*
BOJ 16763 - Fine Dining
https://www.acmicpc.net/problem/16763

먹이가 있는 정점 -> n 정점의 거리 - 맛 을 pq에 넣어 다익을 돌린다.
이것이 원래의 최단거리 이하라면 먹이를 먹고 가는게 가능
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int,int>
#define MAX 1000000000
using namespace std;

/* 🐣🐥 */
vector<pii> vec[50001];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int dist[50001], eat[50001];
int main() {
	int n, m, k, a, b, c;
	scanf("%d %d %d", &n, &m, &k);
	while (m--) {
		scanf("%d %d %d", &a, &b, &c);
		a--, b--;
		vec[a].push_back({ c,b });
		vec[b].push_back({ c,a });
	}
	fill(dist, dist + n, MAX);
	fill(eat, eat + n, MAX);
	pq.push({ 0,n - 1 });
	while (!pq.empty()) {
		pii cur = pq.top();
		pq.pop();
		if (cur.first > dist[cur.second]) continue;
		for (pii v : vec[cur.second]) {
			int tmp = v.first + cur.first;
			if (dist[v.second] > tmp) {
				dist[v.second] = tmp;
				pq.push({ tmp, v.second });
			}
		}
	}
	while (k--) {
		scanf("%d %d", &a, &b);
		a--;
		eat[a] = dist[a] - b;
		pq.push({ eat[a],a });
	}
	while (!pq.empty()) {
		pii cur = pq.top();
		pq.pop();
		if (cur.first > eat[cur.second]) continue;
		for (pii v : vec[cur.second]) {
			int tmp = v.first + cur.first;
			if (eat[v.second] > tmp) {
				eat[v.second] = tmp;
				pq.push({ tmp, v.second });
			}
		}
	}
	for (int i = 0; i < n - 1; i++) {
		if (dist[i] >= eat[i]) printf("1\n");
		else printf("0\n");
	}

	return 0;
}