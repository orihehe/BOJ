/*
BOJ 6543 - 그래프의 싱크
https://www.acmicpc.net/problem/6543

scc로 정점들을 묶은 뒤, 나가는 간선이 없는 정점의 원소들을 모두 출력
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

/* 🐣🐥 */
vector<int> vec[5001], ans;
stack<int> sta;
int num[5001], cnt, scnt, rm[5001], ind[5001];
bool finish[5001];
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
	int n, m, a, b;
	while (scanf("%d", &n)) {
		if (n == 0) break;
		scanf("%d", &m);
		cnt = scnt = 0;
		memset(rm, 0, sizeof(rm));
		memset(ind, 0, sizeof(ind));
		memset(num, 0, sizeof(num));
		memset(finish, false, sizeof(finish));
		ans.clear();
		for (int i = 1; i <= n; i++) vec[i].clear();
		while (m--) {
			scanf("%d %d", &a, &b);
			vec[a].push_back(b);
		}
		for (int i = 1; i <= n; i++) if (!num[i]) dfs(i);
		for (int i = 1; i <= n; i++) {
			for (int v : vec[i]) {
				if (rm[i] != rm[v]) ind[rm[i]]++;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (ind[rm[i]] == 0) ans.push_back(i);
		}
		for (int v : ans) printf("%d ", v);
		printf("\n");
	}

	return 0;
}