/*
BOJ 2150 - Strongly Connected Component
https://www.acmicpc.net/problem/2150
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/* 🐣🐥 */
vector<int> vec[10001], ans[10001];
stack<int> sta;
int cnt, num[10001], scnt;
bool finish[10001];
int dfs(int cur) {
	num[cur] = ++cnt;
	sta.push(cur);

	int ret = num[cur];
	for (int v : vec[cur]) {
		if (!num[v]) ret = min(ret, dfs(v));
		else if (!finish[v]) ret = min(ret, num[v]);
	}

	if (ret == num[cur]) {
		vector<int> tmp;
		int mn = 10001;
		while (!sta.empty()) {
			int nx = sta.top();
			sta.pop();
			tmp.push_back(nx);
			finish[nx] = true;
			mn = min(mn, nx);
			if (nx == cur) break;
		}
		scnt++;
		sort(tmp.begin(), tmp.end());
		ans[mn] = tmp;
	}

	return ret;
}
int main() {
	int v, e, a, b;
	scanf("%d %d", &v, &e);
	while (e--) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
	}
	for (int i = 1; i <= v; i++) {
		if (!num[i]) dfs(i);
	}
	printf("%d\n", scnt);
	for (int i = 1; i <= v; i++) {
		if (ans[i].size()) {
			for (int j : ans[i]) printf("%d ", j);
			printf("-1\n");
		}
	}

	return 0;
}