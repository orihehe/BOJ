/*
BOJ 11280 - 2-SAT - 3
https://www.acmicpc.net/problem/11280
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

/* 🐣🐥 */
vector<int> vec[20001];
stack<int> sta;
int n, m, a, b, num[20001], cnt;
bool fn[20001], w[20001], ans;
int dfs(int cur) {
	num[cur] = ++cnt;
	sta.push(cur);

	int ret = num[cur];
	for (int v : vec[cur]) {
		if (!num[v]) ret = min(ret, dfs(v));
		else if (!fn[v]) ret = min(ret, num[v]);
	}
	if (ret == num[cur]) {
		memset(w, false, sizeof(w));
		while (true) {
			int nx = sta.top();
			sta.pop();
			if (nx > n && w[nx - n]) ans = true;
			else if (nx <= n && w[nx + n]) ans = true;
			w[nx] = true;
			fn[nx] = true;
			if (nx == cur) break;
		}
	}
	return ret;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		if (a < 0) a = -a + n;
		if (b < 0) b = -b + n;
		if (a > n) vec[a - n].push_back(b);
		else vec[a + n].push_back(b);
		if (b > n) vec[b - n].push_back(a);
		else vec[b + n].push_back(a);
	}
	for (int i = 1; i <= 2 * n; i++) if (!num[i]) dfs(i);
	printf("%d", !ans);

	return 0;
}