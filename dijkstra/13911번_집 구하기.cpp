/*
BOJ 13911 (https://www.acmicpc.net/problem/13911)

모든 맥도날드지점을 pq에 넣고 한번에 다익, 스타벅스도 마찬가지로!
가장 가까운 맥세권을 찾으면 되니 하나씩 할 필요가 없다.
맥도날드, 스타벅스가 아닌 지점이 맥세권이고 스세권인 합이 최소인 값 출력
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define P pair<int, int>
#define INF 100000001
using namespace std;

vector<P> vec[10001];
bool Mnum[10001], Snum[10001];
priority_queue<P, vector<P>, greater<P>> pq;
int dist[2][10001], msd[2];
int v, e, a, b, c, M, S;
void dijk(int w) {
	while (!pq.empty()) {
		P nx = pq.top(); pq.pop();
		if (nx.first > dist[w][nx.second]) continue;
		for (P &t : vec[nx.second]) {
			int tmp = t.first + dist[w][nx.second];
			// 맥세권, 스세권 범위를 넘지 않고, 거리가 더 작을 때
			if (tmp <= msd[w] && tmp < dist[w][t.second]) {
				dist[w][t.second] = tmp;
				pq.push({ tmp, t.second });
			}
		}
	}
}
int main() {
	int ans = INF;
	scanf("%d %d", &v, &e);
	while (e--) {
		scanf("%d %d %d", &a, &b, &c);
		vec[a].push_back({ c,b });
		vec[b].push_back({ c,a });
	}
	fill(dist[0], dist[0] + v + 1, INF);
	fill(dist[1], dist[1] + v + 1, INF);
	scanf("%d %d", &M, &msd[0]);
	for (int i = 0; i < M; i++) {
		scanf("%d", &a);
		Mnum[a] = true;
		pq.push({ 0,a });
		dist[0][a] = 0;
	}
	dijk(0);
	scanf("%d %d", &S, &msd[1]);
	for (int i = 0; i < S; i++) {
		scanf("%d", &a);
		Snum[a] = true;
		pq.push({ 0,a });
		dist[1][a] = 0;
	}
	dijk(1);
	for (int i = 1; i <= v; i++) {
		if (!Mnum[i] && !Snum[i]) {
			ans = min(dist[0][i] + dist[1][i], ans);
		}
	}
	if (ans >= INF) printf("-1");
	else printf("%d", ans);

	return 0;
}