/*
BOJ 13161 - 분단의 슬픔
https://www.acmicpc.net/problem/13161

소스-A, B-싱크를 잇고, 정점들을 모두 이어준다.
디닉 후 민컷을 하면 두 컴포넌트로 나뉘고 앞부분은 A그룹, 뒤는 B그룹으로 나누어 준 셈이 된다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define INF 1000000
using namespace std;

/* 🐣🐥 */
int c[502][502], f[502][502], S, E = 501, lv[502], lst[502], ss[502];
vector<int> arr[3], vec[502], at, bt;
queue<int> q;
bool visited[502];
bool bfs() {
	memset(lv, -1, sizeof(lv));
	lv[S] = 0;
	q.push(S);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int v : vec[cur]) {
			if (lv[v] == -1 && c[cur][v] - f[cur][v] > 0) {
				lv[v] = lv[cur] + 1;
				q.push(v);
			}
		}
	}
	return lv[E] != -1;
}
int dfs(int cur, int flow) {
	if (cur == E) return flow;
	int sz = vec[cur].size();
	for (int i = lst[cur]; i < sz; i++) {
		int v = vec[cur][i];
		if (lv[v] == lv[cur] + 1 && c[cur][v] - f[cur][v] > 0) {
			int df = dfs(v, min(flow, c[cur][v] - f[cur][v]));
			lst[cur] = i;
			if (df > 0) {
				f[cur][v] += df;
				f[v][cur] -= df;
				return df;
			}
		}
	}
	lst[cur] = sz;
	return 0;
}
int main() {
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &ss[i]);
		arr[ss[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &c[i][j]);
	for (int v : arr[1]) {
		vec[v].push_back(S);
		vec[S].push_back(v);
		c[S][v] = INF;
	}
	for (int v : arr[2]) {
		vec[v].push_back(E);
		vec[E].push_back(v);
		c[v][E] = INF;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (ss[i] == ss[j])
				c[i][j] = c[j][i] = INF;
			vec[i].push_back(j);
			vec[j].push_back(i);
		}
	}
	while (bfs()) {
		memset(lst, 0, sizeof(lst));
		while (true) {
			int ret = dfs(S, INF);
			if (ret == 0) break;
			ans += ret;
		}
	}
	q.push(S);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int v : vec[cur]) {
			if (!visited[v] && c[cur][v] - f[cur][v] > 0) {
				visited[v] = true;
				q.push(v);
			}
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) {
		if (visited[i]) printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) printf("%d ", i);
	}
	printf("\n");

	return 0;
}