/*
BOJ 16853 - 필름
https://www.acmicpc.net/problem/16853

0. rc에는 있고, sc에는 없는 단색광이 있다면 불가능.
1. sc에는 있고, rc에도 있는 단색광이라면
   1-1. H이라면 a와 b 둘 다 그 단색광이 있다.
   1-2. L이라면 a 나 b 에 그 단색광이 있다. == a U b
2. sc에는 있고, rc에는 없는 단색광이라면
   2-1. H이라면 a 나 b 에 그 단색광이 없다. == a' U b'
   2-2. L이라면 a와 b 둘 다 그 단색광이 없다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/* 🐣🐥 */
int op, num[300001], fn[300001], cnt, scnt;
int cl[128];
vector<int> vec[300001];
stack<int> sta;
bool ans = true, visited[300001];
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
	int n, m, a, b;
	char sht[7], res[7], w, rc, sc;
	cl['R'] = 4, cl['G'] = 2, cl['B'] = 1;
	cl['P'] = 5, cl['C'] = 3, cl['Y'] = 6, cl['W'] = 7;
	scanf("%d %d", &n, &m);
	op = n * 3;
	while (m--) {
		scanf("%d %d %c %s %s", &a, &b, &w, sht, res);
		a--, b--;
		if (res[0] == 'B' && res[2] == 'A') rc = 'K';
		else rc = res[0];
		if (sht[0] == 'B' && sht[2] == 'A') sc = 'K';
		else sc = sht[0];
		for (int i = 0; i < 3; i++) {
			if (!(cl[sc] & (1 << i)) && (cl[rc] & (1 << i))) ans = false;
			if ((cl[sc] & (1 << i))) {
				if ((cl[rc] & (1 << i))) {
					if (w == 'H') {
						vec[getOP(a * 3 + i)].push_back(a * 3 + i);
						vec[getOP(b * 3 + i)].push_back(b * 3 + i);
					}
					else if (w == 'L') {
						vec[getOP(a * 3 + i)].push_back(b * 3 + i);
						vec[getOP(b * 3 + i)].push_back(a * 3 + i);
					}
				}
				else {
					if (w == 'H') {
						vec[a * 3 + i].push_back(getOP(b * 3 + i));
						vec[b * 3 + i].push_back(getOP(a * 3 + i));
					}
					else if (w == 'L') {
						vec[a * 3 + i].push_back(getOP(a * 3 + i));
						vec[b * 3 + i].push_back(getOP(b * 3 + i));
					}
				}
			}
		}
	}
	for (int i = 0; i < op * 2; i++) if (!num[i]) dfs(i);
	printf("%s", ans ? "ALIEN" : "THINKINGFACE");

	return 0;
}