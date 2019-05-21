/*
BOJ 4196 - 도미노
https://www.acmicpc.net/problem/4196

scc로 정점을 묶어준 뒤, 들어오는 간선이 없는 노드의 개수를 세준다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

/* 🐣🐥 */
vector<int> vec[100001];
stack<int> sta;
int cnt, num[100001], ind[100001], scnt, rm[100001], ans;
bool finish[100001];
int dfs(int cur) {
	num[cur] = ++cnt;
	sta.push(cur);

	int ret = num[cur];
	for (int v : vec[cur]) {
		if (!num[v]) ret = min(ret, dfs(v));
		else if (!finish[v]) ret = min(ret, num[v]);
	}
	if (ret == num[cur]) {
		while (true) {
			int nx = sta.top();
			sta.pop();
			finish[nx] = true;
			num[nx] = num[cur];
			rm[nx] = scnt;
			if (nx == cur) break;
		}
		scnt++;
	}
	return ret;
}
int main() {
	int t, n, m, a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		memset(finish, false, sizeof(finish));
		memset(ind, 0, sizeof(ind));
		memset(num, 0, sizeof(num));
		memset(rm, 0, sizeof(rm));
		ans = scnt = cnt = 0;
		for (int i = 1; i <= n; i++) vec[i].clear();
		while (m--) {
			scanf("%d %d", &a, &b);
			vec[a].push_back(b);
		}
		for (int i = 1; i <= n; i++) if (!num[i]) dfs(i);
		for (int i = 1; i <= n; i++) {
			for (int v : vec[i]) {
				if (rm[i] != rm[v]) {
					ind[rm[v]]++;
				}
			}
		}
		for (int i = 0; i < scnt; i++) {
			if (!ind[i]) {
				ans++;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}