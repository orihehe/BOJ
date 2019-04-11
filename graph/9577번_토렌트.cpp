/*
BOJ 9577 - 토렌트
https://www.acmicpc.net/problem/9577

다운 가능한 시간을 기준으로 조각으로의 간선을 만들어준다.
그리고나서 시간순으로 이분매칭을 하면 마지막으로 매칭이 된 시간이 최소시간이 된다.
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
vector<int> vec[101];
bool visited[101];
int B[101];
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
	int n, m, ans, a, b, t, c, x;
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		memset(B, -1, sizeof(B));
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			vector<int> vv;
			scanf("%d %d %d", &a, &b, &c);
			while (c--) {
				scanf("%d", &x);
				vv.push_back(x);
			}
			for (int j = a; j < b; j++) {
				for (int v : vv) vec[j].push_back(v);
			}
		}

		for (int i = 0; i <= 100; i++) {
			memset(visited, false, sizeof(visited));
			if (dfs(i)) {
				ans = i;
			}
		}
		for (int i = 0; i <= 100; i++) vec[i].clear();
		bool suc = true;
		for (int i = 1; i <= n; i++) 
			if (B[i] == -1) {
			printf("-1\n");
			suc = false;
			break;
			}
		if(suc)
			printf("%d\n", ans+1);
	}

	return 0;
}