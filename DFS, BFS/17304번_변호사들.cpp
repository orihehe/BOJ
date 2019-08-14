/*
BOJ 17304 - 변호사들
https://www.acmicpc.net/problem/17304

양방향이 아닌 간선의 도착지를 모두 visited체크,
체크 된 정점에서 dfs를 돌려 도착할 수 있는 정점들은 변호사를 선임할 수 있다.
이제 남은 정점들끼리의 각 컴포넌트에서 사이클을 가지고있는지 판별해준다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
set<pii> sss, tmp;
vector<int> vec[200001];
bool visited[200001], suc;
int cnt;
void dfs(int cur, int p, int pp) {
	cnt++;
	visited[cur] = true;
	for (int v : vec[cur]) {
		if (!visited[v]) dfs(v, p, cur);
		else if (v != pp) suc = true;
	}
}
int main() {
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		if (sss.find({ b,a }) != sss.end()) {
			sss.erase({ b,a });
			tmp.insert({ a,b });
		}
		else sss.insert({ a,b });
	}
	for (auto iter = sss.begin(); iter != sss.end(); iter++) {
		visited[(*iter).second] = true;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i]) {
			suc = false;
			dfs(i, i, i);
		}
	}
	for (int i = 1; i <= n; i++)
		vec[i].clear();
	for (auto iter = tmp.begin(); iter != tmp.end(); iter++) {
		vec[(*iter).second].push_back((*iter).first);
		vec[(*iter).first].push_back((*iter).second);
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cnt = 0;
			suc = false;
			dfs(i, i, i);
			if (cnt <= 2 || !suc) return !printf("NO");
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) return !printf("NO");
	}
	printf("YES");

	return 0;
}