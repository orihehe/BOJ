/*
BOJ 3747 - 완벽한 선거!
https://www.acmicpc.net/problem/3747
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

/* 🐣🐥 */
vector<int> vec[2001];
stack<int> sta;
bool ans;
int n, num[2001], cnt, scnt, fn[2001];
int dfs(int cur) {
	num[cur] = ++cnt;
	sta.push(cur);

	int ret = num[cur];
	for (int v : vec[cur]) {
		if (!num[v]) ret = min(ret, dfs(v));
		else if (!fn[v]) ret = min(ret, num[v]);
	}
	if (ret == num[cur]) {
		scnt++;
		while (true) {
			int nx = sta.top();
			sta.pop();
			fn[nx] = scnt;
			if (fn[nx] == fn[nx + (nx > n ? -n : n)]) ans = false;
			if (nx == cur) break;
		}
	}
	return ret;
}
int main() {
	int m, a, b;
	char fa, fb;
	while (~scanf("%d %d", &n, &m)) {
		ans = true;
		cnt = scnt = 0;
		memset(num, 0, sizeof(num));
		memset(fn, 0, sizeof(fn));
		for (int i = 1; i <= 2 * n; i++) vec[i].clear();

		for (int i = 0; i < m; i++) {
			scanf(" %c%d %c%d", &fa, &a, &fb, &b);
			if (fa == '-') a = a + n;
			if (fb == '-') b = b + n;
			vec[a + (a > n ? -n : n)].push_back(b);
			vec[b + (b > n ? -n : n)].push_back(a);
		}
		for (int i = 1; i <= 2 * n; i++) if (!num[i]) dfs(i);
		printf("%d\n", ans);
	}

	return 0;
}