/*
BOJ 11495 - 격자 0 만들기
https://www.acmicpc.net/problem/11495

이분그래프를 만들고, 네 방향으로의 간선, 각 정점사이 간선을 만들고 플로우
ans에 최대 유량이 나오고, 주변이 0으로 이루어진 남은 값은 sum-2*ans가 됨.
따라서 sum-ans 출력
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define INF 1000000
#define mx 2500
using namespace std;

/* 🐣🐥 */
int lv[5005], lst[5005], S = 5002, E = 5003, arr[50][50];
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
vector<edg*> vec[5005];
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
				lst[cur] = k;
				return df;
			}
		}
	}
	lst[cur] = sz;
	return 0;
}
int main() {
	int t, n, m, ans, sum;
	scanf("%d", &t);
	while (t--) {
		ans = sum = 0;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &arr[i][j]);
				sum += arr[i][j];
				aed(i*m + j, 0, i*m + j + mx, arr[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if ((i + j) % 2) {
					aed(i*m + j + mx, 0, E, arr[i][j]);
					continue;
				}
				aed(S, 0, i*m + j, arr[i][j]);
				for (int k = 0; k < 4; k++) {
					int nr = i + rgo[k], nc = j + cgo[k];
					if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
					aed(i*m + j, 0, nr*m + nc + mx, INF);
					aed(nr*m + nc, 0, i*m + j + mx, INF);
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
		printf("%d\n", sum - ans);
		for (int i = 0; i < 5005; i++) vec[i].clear();
	}

	return 0;
}