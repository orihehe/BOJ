/*
BOJ 17514 - Lexicographically Minimum Walk
https://www.acmicpc.net/problem/17514

역방향 간선을 통해 도착지로 도달 가능한 정점을 체크해준다.
그리고나서 출발점에서 도달 가능한 정점들 중 간선값이 작은 것을 그리디하게 골라준다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define mod 1000000007
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
vector<pii> vec[100001];
vector<int> rv[100001], ans;
bool can[100001], visited[100001], fin[100001], flag;
pii to[100001];
int t;
void dfs(int cur) {
	can[cur] = true;
	for (int v : rv[cur]) {
		if (!can[v]) dfs(v);
	}
}
void go(int cur) {
	visited[cur] = true;
	fin[cur] = true;
	if (cur == t) return;
	ans.push_back(to[cur].second);
	if (fin[to[cur].first]) flag = true;
	if (!flag)
		go(to[cur].first);
	fin[cur] = false;
}
int main() {
	int n, m, s, a, b, c;
	scanf("%d %d %d %d", &n, &m, &s, &t);
	while (m--) {
		scanf("%d %d %d", &a, &b, &c);
		vec[a].push_back({ b,c });
		rv[b].push_back(a);
	}
	dfs(t);
	for (int i = 1; i <= n; i++) {
		pii x = { 0,mod };
		for (pii v : vec[i]) {
			if (can[v.first] && v.second < x.second)
				x = v;
		}
		to[i] = x;
	}
	if (!can[s]) printf("IMPOSSIBLE");
	else {
		go(s);
		if (flag) printf("TOO LONG");
		else
			for (int v : ans) printf("%d ", v);
	}

	return 0;
}