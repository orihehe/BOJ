/*
BOJ 1420 - 학교 가지마!
https://www.acmicpc.net/problem/1420

각 위치의 네 방향으로 간선을 만들어준다. 벽제외
그리고 정점에 벽을 세우니 정점을 막는다 생각하고 각 정점을 두 개로 나누어 그 사이 간선을 1로
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define INF 500001
#define mx 10000
using namespace std;

/* 🐣🐥 */
char b[102][102];
int lv[20005], lst[20005], S, E;
int rgo[4] = { 1,0,0,-1 }, cgo[4] = { 0,1,-1,0 };
queue<int> q;
struct edg {
	int v, c, f;
	edg *op;
	edg() : edg(-1, 0) {}
	edg(int a, int b) : v(a), c(b), f(0), op(0) {}
	void add(int ff) {
		f += ff;
		op->f -= ff;
	}
};
vector<edg*> vec[20005];
void aed(int a, int b, int c, int d) {
	edg *e1 = new edg(a, b), *e2 = new edg(c, d);
	e1->op = e2;
	e2->op = e1;
	vec[a].push_back(e2);
	vec[c].push_back(e1);
}

bool bfs() {
	memset(lv, -1, sizeof(lv));
	lv[S] = 0;
	q.push(S);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (edg *i : vec[cur]) {
			if (lv[i->v] == -1 && i->c - i->f > 0) {
				lv[i->v] = lv[cur] + 1;
				q.push(i->v);
			}
		}
	}
	return lv[E] != -1;
}
int dfs(int cur, int flow) {
	if (cur == E) return flow;
	int sz = vec[cur].size();
	for (int k = lst[cur]; k < sz; k++) {
		edg *i = vec[cur][k];
		if (lv[cur] + 1 == lv[i->v] && i->c - i->f > 0) {
			int df = dfs(i->v, min(flow, i->c - i->f));
			if (df > 0) {
				i->add(df);
				lst[cur] = k + 1;
				return df;
			}
		}
	}
	lst[cur] = sz;
	return 0;
}
int main() {
	int n, m, ans = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &b[i][j]);
			if (b[i][j] == 'K') {
				S = i * m + j + mx;
			}
			if (b[i][j] == 'H') E = i * m + j;
			aed(i*m + j, 0, i*m + j + mx, 1);
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (b[i][j] == 'K') {
				for (int k = 0; k < 4; k++) {
					int nr = i + rgo[k], nc = j + cgo[k];
					if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
					if (b[nr][nc] == 'H') return !printf("-1");
				}
			}
			if (b[i][j] != '#') {
				for (int k = 0; k < 2; k++) {
					int nr = i + rgo[k], nc = j + cgo[k];
					if (nr < 0 || nc < 0 || nr >= n || nc >= m || b[nr][nc] == '#') continue;
					aed(i*m + j + mx, 0, nr*m + nc, 1);
					aed(nr*m + nc + mx, 0, i*m + j, 1);
				}
			}
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
	printf("%d", ans);

	return 0;
}