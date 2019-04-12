/*
BOJ 3295 - 단방향 링크 네트워크
https://www.acmicpc.net/problem/3295

각 노드는 다른 하나의 노드만을 가르킬수 있고, 하나의 들어오는 간선을 가질 수 있다.
그 매칭 수가 답이된다.
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
vector<int> vec[1000];
int B[1000];
bool visited[1000];
bool dfs(int cur) {
	visited[cur] = true;
	for (int v : vec[cur]) {
		if (B[v] == -1 || !visited[B[v]] && dfs(B[v])) {
			B[v] = cur;
			return true;
		}
	}
	return false;
}
int main() {
	int t, n, m, a, b, ans;
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		memset(B, -1, sizeof(B));
		scanf("%d %d", &n, &m);
		while (m--) {
			scanf("%d %d", &a, &b);
			vec[a].push_back(b);
		}
		for (int i = 0; i < n; i++) {
			memset(visited, false, sizeof(visited));
			if (dfs(i)) ans++;
		}
		printf("%d\n", ans);
		for (int i = 0; i < n; i++) {
			vec[i].clear();
		}
	}

	return 0;
}