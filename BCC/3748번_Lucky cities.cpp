/*
BOJ 3748 - Lucky cities
https://www.acmicpc.net/problem/3748
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
vector<int> vv[100001];
vector<int> vec[100001];
int num[100001], cnt, bnum, dist[100001], ans;
vector<pii> sta, bcc[100001];
int dfs(int cur, int p) {
	int ret = num[cur] = ++cnt;
	for (int v : vec[cur]) {
		if (v == p) continue;
		if (num[cur] > num[v]) sta.push_back({ cur,v });
		if (num[v]) ret = min(ret, num[v]);
		else {
			int tmp = dfs(v, cur);
			ret = min(ret, tmp);
			if (tmp >= num[cur]) {
				while (true) {
					bcc[bnum].push_back(sta.back());
					sta.pop_back();
					if (bcc[bnum].back() == pii(cur, v)) break;
				}
				bnum++;
			}
		}
	}
	return ret;
}
int bfs(int x) {
	queue<int> q;
	int cnt = 0;
	bool suc = false;
	for (pii v : bcc[x]) {
		dist[v.first] = dist[v.second] = -1;
		vv[v.first].push_back(v.second);
		vv[v.second].push_back(v.first);
	}
	q.push(bcc[x][0].first);
	dist[bcc[x][0].first] = 0;
	while (!q.empty()) {
		if (suc) break;
		int cur = q.front();
		q.pop();
		for (int v : vv[cur]) {
			if (dist[v] == -1) {
				dist[v] = dist[cur] + 1;
				q.push(v);
			}
			else if (dist[cur] == dist[v]) suc = true;
		}
	}
	for (pii v : bcc[x]) {
		vv[v.first].clear(), vv[v.second].clear();
		if (suc) {
			if (num[v.first] != -1) cnt++;
			if (num[v.second] != -1) cnt++;
			num[v.first] = num[v.second] = -1;
		}
	}
	return suc ? cnt : 0;
}
int main() {
	int v, e, a, b, t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &v, &e);
		for (int i = 1; i <= v; i++) {
			vec[i].clear();
			num[i] = 0;
		}
		bnum = cnt = ans = 0;
		while (e--) {
			scanf("%d %d", &a, &b);
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		for (int i = 1; i <= v; i++) {
			if (!num[i]) {
				dfs(i, i);
			}
		}
		for (int i = 0; i < bnum; i++) {
			ans += bfs(i);
			bcc[i].clear();
		}

		printf("%d\n", ans);
	}

	return 0;
}