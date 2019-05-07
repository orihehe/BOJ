/*
BOJ 4002 - 닌자배치
https://www.acmicpc.net/problem/4002

한 노드는 자식노드의 정보를 모두 포함한다.
따라서 자식에서 이미 버려진 정보는 올려주지 않아도되고,
사이즈가 큰 것에 작은것을 넣어주는식으로 시간을 줄일 수 있다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
vector<int> vec[100001];
priority_queue<int> pq[100001];
pii arr[100001];
ll ans, sum[100001];
int t;
int dfs(int cur) {
	int o = cur;
	pq[o].push(arr[o].first);
	sum[o] = arr[o].first;
	for (int v : vec[cur]) {
		int nx = dfs(v);
		if (pq[nx].size() > pq[o].size()) swap(o, nx);
		while (!pq[nx].empty()) {
			pq[o].push(pq[nx].top());
			pq[nx].pop();
		}
		sum[o] += sum[nx];
	}
	while (sum[o] > t) {
		sum[o] -= pq[o].top();
		pq[o].pop();
	}
	ans = max(ans, (ll)pq[o].size()*arr[cur].second);
	return o;
}
int main() {
	int n, a, b, c;
	scanf("%d %d", &n, &t);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		vec[a].push_back(i);
		arr[i] = { b,c };
	}
	dfs(1);
	printf("%lld", ans);

	return 0;
}