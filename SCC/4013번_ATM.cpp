/*
BOJ 4013 - ATM
https://www.acmicpc.net/problem/4013

scc로 정점들을 묶고, 레스토랑 위치여부와, ATM현금 합을 저장해둔다.
그리고나서 위상정렬 과정에서 최댓값을 가져오며 레스토랑이 위치해있다면 답 갱신
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

/* 🐣🐥 */
vector<int> vec[500001], grp[500001];
stack<int> sta;
queue<int> q;
int num[500001], fn[500001], arr[500001], aa[500001], dp[500001], ind[500001];
int cnt, scnt, s, t;
bool res[500001], rr[500001];
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
		bool flag = false;
		while (true) {
			int nx = sta.top();
			sta.pop();
			fn[nx] = scnt;
			tmp += aa[nx];
			if (res[nx]) flag = true;
			if (nx == cur) break;
		}
		arr[scnt] = tmp;
		rr[scnt] = flag;
	}
	return ret;
}
int main() {
	int n, m, a, b, ans = 0;
	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &aa[i]);
	}
	scanf("%d %d", &s, &t);
	while (t--) {
		scanf("%d", &a);
		res[a] = true;
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
		if (rr[cur]) ans = max(ans, dp[cur]);
		for (int v : grp[cur]) {
			ind[v]--;
			dp[v] = max(dp[v], dp[cur]);
			if (!ind[v]) {
				q.push(v);
			}
		}
	}
	printf("%d", ans);

	return 0;
}