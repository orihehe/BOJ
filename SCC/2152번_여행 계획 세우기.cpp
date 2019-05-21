/*
BOJ 2152 - 여행 계획 세우기
https://www.acmicpc.net/problem/2152

scc로 정점들을 묶는데, 도시 개수를 저장해둔다.
그리고나서 위상정렬 과정에서 최댓값을 가져온다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

/* 🐣🐥 */
vector<int> vec[10001], grp[10001];
stack<int> sta;
queue<int> q;
int num[10001], cnt, scnt, s, t, fn[10001], arr[10001], dp[10001], ind[10001];
int dfs(int cur) {
	num[cur] = ++cnt;
	sta.push(cur);

	int ret = num[cur];
	for (int v : vec[cur]) {
		if (!num[v]) ret = min(ret, dfs(v));
		else if (!fn[v]) ret = min(ret, num[v]);
	}
	if (ret == num[cur]) {
		scnt++;
		int tmp = 0;
		while (true) {
			int nx = sta.top();
			sta.pop();
			fn[nx] = scnt;
			tmp++;
			if (nx == cur) break;
		}
		arr[scnt] = tmp;
	}
	return ret;
}
int main() {
	int n, m, a, b;
	scanf("%d %d %d %d", &n, &m, &s, &t);
	while (m--) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
	}
	for (int i = 1; i <= n; i++)
		if (!num[i]) dfs(i);
	for (int i = 1; i <= n; i++) {
		for (int v : vec[i]) {
			if (fn[i] != fn[v]) {
				grp[fn[i]].push_back(fn[v]);
				ind[fn[v]]++;
			}
		}
	}
	s = fn[s], t = fn[t];
	for (int i = 1; i <= scnt; i++) {
		if (!ind[i] && i != s) q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int v : grp[cur]) {
			ind[v]--;
			if (v != s && !ind[v]) {
				q.push(v);
			}
		}
	}
	q.push(s);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		dp[cur] += arr[cur];
		for (int v : grp[cur]) {
			ind[v]--;
			dp[v] = max(dp[v], dp[cur]);
			if (!ind[v]) {
				q.push(v);
			}
		}
	}
	printf("%d", dp[t]);

	return 0;
}