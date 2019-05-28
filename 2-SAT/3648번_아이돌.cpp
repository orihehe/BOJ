/*
BOJ 3648 - 아이돌
https://www.acmicpc.net/problem/3648

(1V1)을 추가하여 풀어준다.
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
int n, num[2001], cnt, fn[2001], scnt;
int getOP(int a) {
	return a + (a > n ? -n : n);
}
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
			if (fn[nx] == fn[getOP(nx)]) ans = false;
			if (nx == cur) break;
		}
	}
	return ret;
}
int main() {
	int m, a, b;
	while (~scanf("%d %d", &n, &m)) {
		ans = true;
		cnt = scnt = 0;
		memset(num, 0, sizeof(num));
		memset(fn, 0, sizeof(fn));
		for (int i = 1; i <= 2 * n; i++)
			vec[i].clear();

		for (int i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			if (a < 0) a = -a + n;
			if (b < 0) b = -b + n;
			vec[getOP(a)].push_back(b);
			vec[getOP(b)].push_back(a);
		}
		vec[1 + n].push_back(1);
		for (int i = 1; i <= 2 * n; i++) if (!num[i]) dfs(i);
		printf("%s\n", ans ? "yes" : "no");
	}

	return 0;
}