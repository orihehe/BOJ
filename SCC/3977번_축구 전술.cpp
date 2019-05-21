/*
BOJ 3977 - 축구 전술
https://www.acmicpc.net/problem/3977

scc로 정점들을 묶은 뒤, 
들어오는 간선이 없는 정점의 개수가 1이라면 정점을 이루는 원소출력,
그 외엔 Confused
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

/* 🐣🐥 */
vector<int> vec[100001], ans;
stack<int> sta;
int num[100001], cnt, scnt, rm[100001], ind[100001];
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
		scnt = cnt = 0;
		ans.clear();
		for (int i = 1; i <= n; i++) vec[i].clear();
		while (m--) {
			scanf("%d %d", &a, &b);
			a++, b++;
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
				ans.push_back(i);
			}
		}
		if (ans.size() == 1) {
			for (int i = 1; i <= n; i++) {
				if (!ind[rm[i]]) printf("%d\n", i - 1);
			}
		}
		else printf("Confused\n");
		printf("\n");
	}

	return 0;
}