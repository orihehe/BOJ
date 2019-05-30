/*
BOJ 1739 - 도로 정비하기
https://www.acmicpc.net/problem/1739

(x1, y1) -> (x2, y2)
(x1 and y2) or (x2 and y1) 이어야 한다.
= ((x1' or y2') and (x2' or y1'))' - 드모르간
= ((x1' and x2') or (x1' and y1') or (y2' and x2') or (y2' and y1'))'
= (x1 or x2) and (x1 or y1) and (y2 or x2) and (y2 or y1) - 드모르간
으로 2-sat 식을 만들 수 있다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/* 🐣🐥 */
vector<int> vec[4001];
stack<int> sta;
int num[4001], fn[4001], scnt, cnt, op;
bool ans;
int getOP(int cur) {
	return cur + (cur > op ? -op : op);
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
	int t, n, m, k, a, b, c, d, x, y;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &k);
		op = n + m;
		cnt = scnt = 0;
		ans = true;
		for (int i = 1; i <= 2 * op; i++) {
			vec[i].clear();
			num[i] = fn[i] = 0;
		}
		for (int i = 1; i <= k; i++) {
			scanf("%d %d %d %d", &a, &b, &c, &d);
			b += n, d += n;
			if (c - a == 0) y = 0;
			else y = (c - a) < 0 ? -1 : 1;
			if (d - b == 0) x = 0;
			else x = (d - b) < 0 ? -1 : 1;
			if (x < 0) a += op, c += op;
			if (y < 0) b += op, d += op;
			if (x == 0) vec[getOP(b)].push_back(b);
			else if (y == 0) vec[getOP(a)].push_back(a);
			else {
				vec[getOP(a)].push_back(c);
				vec[getOP(c)].push_back(a);
				vec[getOP(b)].push_back(d);
				vec[getOP(d)].push_back(b);
				vec[getOP(a)].push_back(b);
				vec[getOP(b)].push_back(a);
				vec[getOP(c)].push_back(d);
				vec[getOP(d)].push_back(c);
			}
		}
		for (int i = 1; i <= 2 * op; i++) if (!num[i]) dfs(i);
		printf("%s\n", ans ? "Yes" : "No");
	}

	return 0;
}